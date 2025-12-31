#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<sys/types.h>

int main()
{
    int fd;
    char buf[1024];
    char *myfifo="/tmp/myfifo";

    printf("Run reader process to read the fifo file:\n");
    mkfifo("myfifo",0666);

    fd=open("myfifo",O_WRONLY);
    strcpy(buf,"Hello from writer process:");
    write(fd,buf,sizeof(buf));
    
    close(fd);
    unlink(myfifo);
}