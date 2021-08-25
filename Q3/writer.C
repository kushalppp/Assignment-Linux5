#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>

main(int argc, char** argv)
{
int i,k=1;
key_t key= ftok("shmfile",65);
int shmid =shmget(key,1024,0666|IPC_CREAT);
char *str =(char*) shmat(shmid,(void*)0,0);
for(i=0;i<argc;i++)
{
strcpy(str,argv[i]);
}
printf("Address is %d",&str);
printf("Data written in memory:%s\n",str);
shmdt(str);
}