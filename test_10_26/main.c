#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


//�������
int main()
{
    double sum1 = 0;//��ʼ����
    double sum2 = 0;//��ʼ����
    //����1+1/3+1/5+...+1/99
    for (int a = 1; a < 100; a += 2) {
        sum1 += (1.0 / a);
    }
    //����1/2+1/4+...+1/100
    for (int b = 2; b <= 100; b += 2) {
        sum2 += (1.0 / b);
    }
    double ret = sum1 - sum2;
    printf("%lf", ret);
    return 0;
}


//����1-100���ֶ��ٴ�9
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


//��ӡ�˷��ھ���
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



//��10�����������ֵ
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



//���ֲ���
//int main() {
//    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//    int left = 0;
//    int right = 9;
//    int p = 0;
//    int k = 0; //Ҫ���ҵ�����
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
//            printf("�ҵ��ˣ��±�Ϊ>%d\n", mid);
//            p = 1;
//            break;
//        }
//    }
//    if (p == 0)
//        printf("û���ҵ�\n");
//    return 0;
//}
