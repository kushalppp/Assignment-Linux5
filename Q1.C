#include<stdio.h>
#include<unistd.h>

main()
{
int fd[2],ret=0,n;
pipe(fd);
if(fork()!=0)
{
close(fd[0]); 
printf("enter a num\n");
scanf("%d",&ret);
write(fd[1],&ret,sizeof(ret));
printf("Send num=%d\n",ret);
close(fd[1]);
}
else
{
close(fd[1]);
read(fd[0],&n,sizeof(n));
printf("Received num %d\n",n);
close(fd[0]);
}
return 0;
}

Output:-
enter a num
45
Send num=45
Received num 45