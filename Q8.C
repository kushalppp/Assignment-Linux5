#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<pthread.h>

pthread_mutex_t mutex;

void input()
{
pthread_mutex_lock(&mutex);
char mess[100];
key_t key=ftok("progfile",65);
int msgid=msgget(key,0666);
printf("write msg\n");
scanf("%s",mess);
msgsnd(msgid,&mess,sizeof(mess),NULL);
printf("Data is send:-%s\n",mess);
pthread_mutex_unlock(&mutex);
}

void display()
{
pthread_mutex_lock(&mutex);
char c[100];
key_t key=ftok("progfile",65);
int msgid=msgget(key,0666);
msgrcv(msgid,&c,sizeof(c),1,0);
printf("Data is received:-%s\n",c);
msgctl(msgid,IPC_RMID,NULL);
pthread_mutex_unlock(&mutex);
}

main()
{
pthread_mutex_init(&mutex,NULL);
{
pthread_mutex_lock(&mutex);
input();
printf("PID:-%d\n",getpid());
pthread_mutex_unlock(&mutex);
}
if(fork()==0)
{
display();
printf("PID:-%d\n",getpid());
}
pthread_mutex_destroy(&mutex);
}

Output:-
write msg
Hello
Data is send:-Hello
PID:-300
Data is received:-Hello
PID:-301



