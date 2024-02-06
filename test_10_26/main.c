#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


//分数求和
int main()
{
    double sum1 = 0;//初始化加
    double sum2 = 0;//初始化减
    //计算1+1/3+1/5+...+1/99
    for (int a = 1; a < 100; a += 2) {
        sum1 += (1.0 / a);
    }
    //计算1/2+1/4+...+1/100
    for (int b = 2; b <= 100; b += 2) {
        sum2 += (1.0 / b);
    }
    double ret = sum1 - sum2;
    printf("%lf", ret);
    return 0;
}


//计算1-100出现多少次9
//int main()
//{
//	int n = 1;
//	int a = 0;
//	while(n<=100) {
//		if (n % 10 == 9 || n / 10 == 9) {
//			a++;
//		}
//		n++;
//	}
//	printf("%d\n", a);
//	return 0;
//}


//打印乘法口诀表
//int main()
//{
//    int b = 1; for (int a = 1; a <= 9; a++) {
//        b = 1; while (a >= b) {
//            printf("%d x %d = %d\n", a, b, a * b);
//            b++;
//        }
//    }
//    return 0;
//}



//求10个整数中最大值
//int main() {
//    int input = 0;
//    int output = 0;
//    while (scanf("%d", &input) != EOF) {
//        if (input > output) {
//            output = input;
//        }
//    }
//    printf("%d\n", output);
//}



//二分查找
//int main() {
//    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//    int left = 0;
//    int right = 9;
//    int p = 0;
//    int k = 0; //要查找的数字
//    scanf("%d", &k);
//    int mid = (left + right) / 2;
//    while (left <= right) {
//        mid = (left + right) / 2;
//        if (arr[mid] < k) {
//            left++;
//        }
//        else if (arr[mid] > k) {
//            right--;
//        }
//        else {
//            printf("找到了，下标为>%d\n", mid);
//            p = 1;
//            break;
//        }
//    }
//    if (p == 0)
//        printf("没有找到\n");
//    return 0;
//}
