#include <unistd.h>
#include <stdio.h>

int main() {
    int pid = fork();
    if (pid) {
        printf("%d: I am the parent\n", pid);
    }
    else {
        printf("%d: I am the child\n", pid);
    }
    return 0;
}