#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//取两个整形的最大值
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int m = (a > b ? a : b);
//	printf("%d\n", m);
//	return 0;
//}


//对于一组输入，判断并输出两个整形的大小关系
//int main()
//{
//    int a, b;
//    while (scanf("%d %d", &a, &b) != EOF) {
//        if (a == b)
//            printf("%d=%d\n", a, b);
//        else if (a > b)
//            printf("%d>%d\n", a, b);
//            else printf("%d<%d\n", a, b);
//    }
//    return 0;
//}



//判断整数奇偶性
//int main() {
//    int a = 0;
//    while (scanf("%d", &a) != EOF) {
//        if (a % 2 == 0) printf("Even\n");
//        else printf("Odd\n");
//    }
//    return 0;
//}

//及格分数的判断
//int main() {
//    int a, b;
//    while (scanf("%d", &a) != EOF) {
//        if (a >= 60) printf("Pass\n");
//        else printf("Fail\n");
//    }
//    return 0;
//}

//逻辑与的使用
int main() {
    int a = 0;
    while (scanf("%d", &a) != EOF) {
        if (a >= 90 && a <= 100)
            printf("Perfect\n");
    }
    return 0;
}