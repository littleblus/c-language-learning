#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

#define MAX_LEN 1024
#define MAX_ARG 32
#define EXIT_CODE 0
#define PATH_MAX 4096

char command[MAX_LEN];

const char* getUser() {
    if (getuid() == 0) {
        return "root";            
    }
    return getenv("USER");
}

const char* getHostname() {
    return getenv("HOSTNAME");
}

const char* getHome() {
    return getenv("HOME");
}

const char* getBackPwd() {
    char* path = getenv("PWD");
    char* ret = path + strlen(path);
    while (*ret != '/') {
        ret--;
    }
    return ret + 1;
}

const char* getOldPwd() {
    return getenv("OLDPWD");
}

char isRoot() {
    if (getuid() == 0) {
        return '#';
    }
    else {
        return '$';
    }
}

// 从标准输入读取一行
void input(char* write, int size) {
    char* s = fgets(write, size, stdin);
    assert(s);
    (void)s; // 抵御编译器的警告
    write[strlen(write) - 1] = '\0'; // 去掉末尾的换行符
}

// 将命令行按空格分割为若干个参数
int split(char* command, char* argv[]) {
    int i = 0;
    char* token = strtok(command, " ");
    while (token != NULL) {
        argv[i++] = token;
        // 若为空指针，则从上一次调用 strtok 的位置继续向后查找
        token = strtok(NULL, " ");
    }
    // 最后一个参数后面跟着一个空指针
    argv[i] = NULL;
    return i;
}

void addArg(int* argc, char* argv[], char* add) {
    argv[*argc] = add;
    (*argc)++;
    argv[*argc] = NULL;
}

void changeDirectory(int argc, char* argv[]) {
    // 内建命令 cd
    char* realpath(const char* path, char* resolved_path);
    int setenv(const char* name, const char* value, int overwrite);
    if (argc == 1) {
        chdir(getHome());
        setenv("OLDPWD", getenv("PWD"), 1);
        setenv("PWD", getHome(), 1);
    }
    else if (strcmp(argv[1], ".") == 0) {
        return;
    }
    else if (strcmp(argv[1], "~") == 0) {
        chdir(getHome());
        setenv("OLDPWD", getenv("PWD"), 1);
        setenv("PWD", getHome(), 1);
    }
    else if (strcmp(argv[1], "-") == 0) {
        char* oldpwd = getenv("OLDPWD");
        if (oldpwd == NULL) {
            printf("myshell: cd: OLDPWD not set\n");
            return;
        }
        setenv("OLDPWD", getenv("PWD"), 1);
        chdir(oldpwd);
        setenv("PWD", oldpwd, 1);
        printf("%s\n", oldpwd);
    }
    else {
        char oldpwd[PATH_MAX];
        strcpy(oldpwd, getenv("PWD"));
        if (strcmp(argv[1], "..") == 0) {
            char* path = (char*)getenv("PWD");
            if (strcmp(path, "/") != 0) {
                // 截取最后一个 / 之前的字符串
                char* ret = path + strlen(path);
                while (*ret != '/') {
                    ret--;
                }
                *ret = '\0';
                argv[1] = path;
            }
            else {
                // 若当前目录为根目录，则不再向上跳转
                // 也无需更新环境变量
                return;
            }
        }
        char buf[PATH_MAX];
        if (realpath(argv[1], buf) == NULL) {
            perror("realpath");
            return;
        }
        //printf("(pwd):%s\n", getenv("PWD"));
        setenv("OLDPWD", oldpwd, 1);
        //printf("(oldpwd):%s\n", getenv("OLDPWD"));
        chdir(buf);
        setenv("PWD", buf, 1);
    }
}

int main() {
    int execvpe(const char* file, char* const argv[], char* const envp[]);

    while (1) {
        printf("[%s@%s %s]%c ", getUser(), getHostname(), getBackPwd(), isRoot());
        input(command, sizeof(command));
        char* argv[MAX_ARG];
        int argc = split(command, argv);
        // 若输入为空行，则重新输入
        if (argc == 0) {
            continue;
        }
        // for (int i = 0; i < argc; i++) {
        //     printf("[%d] : %s\n", i, argv[i]);
        // }

        // exit
        if (strcmp(argv[0], "exit") == 0) {
            break;
        }
        // 执行
        if (strcmp(argv[0], "cd") == 0) {
            changeDirectory(argc, argv);
            // printf("(pwd):%s\n", getenv("PWD"));
            // printf("(oldpwd):%s\n", getenv("OLDPWD"));
            continue;
        }
        if (strcmp(argv[0], "ls") == 0) {
            addArg(&argc, argv, "--color");
        }
        if (strcmp(argv[0], "ll") == 0) {
            addArg(&argc, argv, "--color");
            addArg(&argc, argv, "-l");
            argv[0] = "ls";
        }
        // 其他命令
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(1);
        }
        else if (pid == 0) {
            // 子进程，程序替换
            execvp(argv[0], argv);
            // 若 execvp 执行失败，则直接退出
            exit(EXIT_CODE);
        }
        else {
            // 父进程
            int status;
            pid_t rid = waitpid(pid, &status, 0);
            // 等待失败
            if (rid == -1) {
                perror("waitpid");
                exit(1);
            }
        }
    }

    return 0;
}
