#include<stdio.h>
#include<unistd.h>

struct my
{
char name[15];
char addr[20];
 int no;
};

main()
{
struct my d1={"Romak Kakati","Gokuldham Mumbai",123456789},d2;
int  fd[2];
pipe(fd);
if(fork()!=0)
{
close(fd[0]);
write(fd[1],&d1,sizeof(d1));
printf("Sending struct successfully\n");
close(fd[1]);
}
else
{
close(fd[1]);
read(fd[0],&d2,sizeof(d2));
printf("Received struct\n");
printf("Name:-%s\n",d2.name);
printf("Address:-%s\n",d2.addr);
printf("Mobile NO:-%d\n",d2.no);
printf("Copy structure Successfully Using unnamedPipe");
close(fd[0]);
}
}

Output:-
Sending struct successfully
Received struct
Name:-Romak Kakati
Address:-Gokuldham Mumbai
Mobile NO:-123456789
Copy structure Successfully Using unnamedPipe



