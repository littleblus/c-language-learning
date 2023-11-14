#include <stdio.h>
#include <unistd.h>

// ps -el | head -1 && ps -el | grep zombieTest
int main() {
    int pid = fork();
    if (pid) {
        while (1) {
            printf("I am parent, pid = %d, child = %d\n", getpid(), pid);
            sleep(1);
        }
    }
    else {
        return 0; // 提前退出，子进程成为僵尸进程
    }
    return 0;
}