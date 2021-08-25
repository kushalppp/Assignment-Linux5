#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>

main()
{
int i;
key_t key= ftok("shmfile",65);
int shmid =shmget(key,1024,0666|IPC_CREAT);
char *str =(char*) shmat(shmid,(void*)0,0);
printf("Address is %d",&str);
printf("Data stored in memory:%s\n",str);
shmdt(str);
}