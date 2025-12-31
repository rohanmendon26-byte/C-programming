#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<sys/types.h>
#define MAX_BUF 1024

int main()
{
    int fd;
    char buf[MAX_BUF];
    char *myfifo="/tmp/myfifo";
    mkfifo("myfifo",0666);
    fd=open("myfifo",O_RDONLY);
    read(fd,buf,MAX_BUF);

    printf("Reader Recieved:%s",buf);
    close(fd);
}