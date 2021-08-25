#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
int fd;
FILE *fp;
fp=fopen("file1.text","a");
fp=fopen("file2.text","a");
mkfifo("file1.text",0666);
mkfifo("file2.text",0666);
char arr1[80],arr2[80];
fd=open("file1.text",O_RDONLY);
read(fd,arr1,sizeof(arr1));
printf("File1 Successfully Copied into File2.");
close(fd);
fd=open("file2.text",O_WRONLY);
write(fd,arr1,strlen(arr1)+1);
close(fd);
close(fp);
}


