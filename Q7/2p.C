#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>

main()
{
key_t key= ftok("shmfile",65);
int shmid =shmget(key,1024,0666|IPC_CREAT);
char *str =(char*) shmat(shmid,(void*)0,0);
printf(" %s\n",str);
scanf("%s",str);
shmdt(str);
}