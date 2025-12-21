#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    pid = fork();

    if (pid < 0) {
        printf("Error\n");
    } 
    else if (pid == 0) {
        // Child process
        printf("\nChild having id %d\n", getpid());
        printf("My parent pid is %d\n", getppid());

        execlp("/bin/ls", "ls", NULL);
        perror("execlp failed"); // only runs if execlp fails
    } 
    else {
        // Parent process
        wait(NULL);
        printf("\nI am parent having id %d\n", getpid());
        printf("My child is %d\n", pid);
    }

    return 0;
}
