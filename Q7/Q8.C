#include<stdio.h>
#include<unistd.h>
#include<string.h>
#define SIZE 10
char queue[SIZE];
int Rear=-1;
int front=-1;

main()
{
char temp;
if(fork()!=0)
{
   printf("//Parent side//\n");
     if(Rear == SIZE-1)
     {
     printf("Over Flow\n");
      }
    else
    {
    if(front== -1)
    front=0;
    scanf("%s",temp);
    strcpy(queue[front],temp);
    }
}
else
{
printf("//Child side//");
if(front== -1)
printf("EMPTY");
else
{
printf("Queue:-");
printf("%s",queue[front]);
}
}
}
