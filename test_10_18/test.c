#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//ȡ�������ε����ֵ
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int m = (a > b ? a : b);
//	printf("%d\n", m);
//	return 0;
//}


//����һ�����룬�жϲ�����������εĴ�С��ϵ
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



//�ж�������ż��
//int main() {
//    int a = 0;
//    while (scanf("%d", &a) != EOF) {
//        if (a % 2 == 0) printf("Even\n");
//        else printf("Odd\n");
//    }
//    return 0;
//}

//����������ж�
//int main() {
//    int a, b;
//    while (scanf("%d", &a) != EOF) {
//        if (a >= 60) printf("Pass\n");
//        else printf("Fail\n");
//    }
//    return 0;
//}

//�߼����ʹ��
int main() {
    int a = 0;
    while (scanf("%d", &a) != EOF) {
        if (a >= 90 && a <= 100)
            printf("Perfect\n");
    }
    return 0;
}