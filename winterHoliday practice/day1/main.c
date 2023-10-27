#define _CRT_SECURE_NO_WARNINGS 1

//第一题

//static int c[100005];
//
//int* printNumbers(int n, int* returnSize) {
//    int max = 0;
//    while (n) {
//        max += 9 * pow(10, n - 1);
//        n--;
//    }
//    for (int i = 1; i <= max; i++) {
//        c[i - 1] = i;
//    }
//    *returnSize = max;
//    return c;
//}



//第二题

#include <stdio.h>

int is_leap_year(int y)
{
    if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
        return 1;
    else
        return 0;
}

int num_days(int y, int m, int d)
{
    int ret = 0;
    int mon[] = { 0,0,31,59,90,120,151,181,212,243,273,304,334 };
    ret = mon[m] + d;
    if (m >= 3 && is_leap_year(y) == 1)
        return ret + 1;
    else
        return ret;
}

int main()
{
    int y, m, d;
    scanf("%d%d%d", &y, &m, &d);
    printf("%d\n", num_days(y, m, d));

    return 0;
}