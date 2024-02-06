#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int is_leap_year(int y)
//{
//    if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
//        return 1;
//    else
//        return 0;
//}
//
//int num_days(int y, int m, int d)
//{
//    int ret = 0;
//    int mon[] = { 0,0,31,59,90,120,151,181,212,243,273,304,334 };
//    ret = mon[m] + d;
//    if (m >= 3 && is_leap_year(y) == 1)
//        return ret + 1;
//    else
//        return ret;
//}
//
//int main()
//{
//    int y, m, d;
//    scanf("%d%d%d", &y, &m, &d);
//    printf("%d\n", num_days(y, m, d));
//
//    return 0;
//}


int main()
{
	char s[] = "\\123456\123456\t";
	printf("\\123456\123456\t");
	printf("%d\n", strlen(s));

	return 0;
}