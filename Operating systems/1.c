#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    pid_t pid;
    pid=fork();
    if(pid<0)
    {
        printf("\nerror\n");
    }

    else if(pid==0)
    {
        printf("\n Child having id %d\n",getpid());
        printf("\nparent having pid %d\n",getppid());

        execlp("/bin/ls","ls",NULL);
        perror("execlp failed\n");
    }

    else
    {
        wait(NULL);
        printf("\n i am parent having id %d\n",getpid());
        printf("\n The child having id %d",pid);
    }
}