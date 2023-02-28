#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int digit(const int n) {
    int tmp = n;
    int ret = 1;
    while (tmp > 9) {
        ret++;
        tmp /= 10;
    }
    return ret;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        char numstr[20];
        sprintf(numstr, "%d", n);
        char* p = numstr;
        //计算位数
        int d = digit(n);
        //计算逗号数量
        int douhao = (d - 1) / 3;
        //输出并加逗号
        for (int i = 0; i < douhao; i++) {
            int printi = d % 3; //打印数字个数
            if (printi == 0)
                printi = 3;
            if(i > 0) {
                printi = 3;
            }
            while (printi > 0) {
                printf("%c", *p);
                p++;
                printi--;
            }
            printf(",");
        }
        if (d <= 3) {
            printf("%d", n);
        }
        else {
            for (int i = 0; i < 3; i++) {
                printf("%c", *p);
                p++;
            }
        }
        printf("\n");
    }
    return 0;
}



#include <stdio.h>
#include <string.h>

int main() {
    char str1[105];
    char str2[105];
    gets(str1);
    gets(str2);
    char* p1 = str1;
    char* p2 = str2;
    while (*p2 != '\0') {
        p1 = str1;
        while (*p1 != '\0') {
            if (*p1 == *p2) {
                memmove(p1, p1 + 1, strlen(p1));
                p1--;
            }
            p1++;
        }
        p2++;
    }
    printf("%s\n", str1);
    return 0;
}