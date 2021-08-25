#include<stdio.h>
#include<unistd.h>

main()
{
int fd[2];
char str[20],str1[20];
pipe(fd);
if(fork()!=0)
{
close(fd[0]);
printf("enter a string\n");
scanf("%s",str);
write(fd[1],str,sizeof(str));
printf("send:- %s\n",str);
close(fd[1]);
}
else
{
close(fd[1]);
read(fd[0],str1,sizeof(str1));
printf("Received string by Child process is %s\n",str1);
close(fd[0]);
}
}

Output:-
enter a string
hello
send:- hello
Received string by Child process is hello