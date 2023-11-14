#include <unistd.h>
#include <stdio.h>

// ps命令可以看当前bash的进程
// ps -l可以展示出进程的状态
int main() {
    int pid = fork();
    if (pid) {
        printf("I am parent process, my pid is %d\n", getpid());
        printf("I am parent process, my child pid is %d\n", pid);
    }
    else {
        while (1) {
            printf("I am child process, my pid is %d\n", getpid());
            sleep(1);
        }
    }

    return 0;
}