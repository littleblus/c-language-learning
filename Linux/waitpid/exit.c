#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
    int pid = fork();
    if (pid) {
        int status;
        wait(&status);
        if (WIFEXITED(status)) {
            printf("Child process exited with code %d\n", WEXITSTATUS(status));
            printf("core dump %d\n", (status >> 7) & 1);
        }
        else {
            printf("Child process exited abnormally\n");
            printf("core dump %d\n", (status >> 7) & 1);
        }
    }
    else {
        printf("I am child process\n");
        sleep(5);
        return 55; // 自己设定的退出码
    }
    return 0;
}