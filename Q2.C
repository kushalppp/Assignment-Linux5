#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#define SIZE 2
int queue[SIZE];
int rear=-1;
int front =-1;

sem_t mutex;

void* enter(void* p)
{
sem_wait(&mutex);
int temp;
if(rear == SIZE-1)
printf("overflow\n");
else
{
if(front== -1)
front=0;
printf("Enter data:-");
scanf("%d",&temp);
rear=rear+1;
queue[rear]=temp;
}
sem_post(&mutex);
}

void* displ(void* q)
{
sem_wait(&mutex);
if(front==-1)
printf("EMPTY\n");
else
{
printf("Queue:-");
printf("%d\n",queue[front]);
sem_post(&mutex);
}
}
int main()
{
sem_init(&mutex,0,1);
int ret, ret1;
pthread_t t1,t2;
ret=pthread_create(&t1,NULL,enter,NULL);
ret1=pthread_create(&t2,NULL,displ,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
if(ret == ret1 == 0)
{
printf(" Threade is created");
}
sem_destroy(&mutex);
}

Output:-
Enter data:-105
Queue:-105
