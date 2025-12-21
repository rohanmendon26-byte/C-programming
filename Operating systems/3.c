#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#define MAX_BUF 1024

int main()
{
    int fd;
    char *myfifo = "/tmp/myfifo";
    char buf[MAX_BUF];

    mkfifo(myfifo, 0666);

    fd = open(myfifo, O_RDONLY);
    read(fd, buf, MAX_BUF);

    printf("Reader received: %s\n", buf);

    close(fd);
    return 0;
}
