#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <math.h>

//void print(int n,char* str,int sz) 
//{
//	//���13��'*'
//	for (int i = 0; i < 13; i++) {
//		str[i] = '*';
//	}
//	//�����' '
//	for (int i = 0; i < (sz - n) / 2; i++) {
//		str[i] = ' ';
//		str[sz - i - 1] = ' ';
//	}
//	printf("%s\n", str);
//}
//
//int main()
//{
//	char str[14] = { 0 };
//	for (int i = 0; i < 13; i++) {
//		str[i] = '*';
//	}
//	int len = strlen(str);
//	for (int i = 1; i <= 13; i += 2) {
//		print(i, str, len);
//	}
//	for (int i = 11; i >= 1; i -= 2) {
//		print(i, str, len);
//	}
//	return 0;
//

//��ӡˮ�ɻ���
//���0��100000֮������С�ˮ�ɻ������������
//��ˮ�ɻ�������ָһ��nλ����
//���λ���ֵ�n�η�֮��ȷ�õ��ڸ�������
//��:153��1 ^ 3��5 ^ 3��3 ^ 3����153��һ����ˮ�ɻ�������

//
//int shuixian(int x, int k) {
//    int ret = 0;
//    for (int i = 0; i < k; i++) {
//        int n = pow(10, k - i - 1);
//        ret += pow(x / n, k);
//        x = x % (int)pow(10, k - i - 1);
//    }
//    return ret;
//}
//
//int digit(int x) {
//    int k = 0;
//    int n = (int)pow(10, k);
//    while (1) {
//        n = (int)pow(10, k);
//        if (x / n >= 1 && x / n <= 9)
//            return k + 1;
//        if (x == 0)
//            return 1;
//        k++;
//    }
//}
//
//int main() {
//    for (int i = 0; i <= 100000; i++) {
//        //�ж������Ǽ�λ��
//        int k = digit(i);
//        //��Ϊˮ�ɻ����������
//        if (i == shuixian(i, k))
//            printf("%d ", i);
//    }
//    return 0;
//}
//
////int main() {
////    int a = 0;
////    scanf("%d", &a);
////    int n = shuixian(a,3);
////    printf("%d\n", n);
////    return 0;
////}

//�������
//��Sn=a+aa+aaa+aaaa+aaaaa��ǰ5��֮��
//����a��һ������

int main()
{
	int a = 0;
	int ret = 0;
	printf("������һ��������\n");
	while (1) {
		scanf("%d", &a);
		if (a > 0)
			break;
		else
			printf("���������������������\n");
	}
	//����һ��һά�������5������
	int arr[5] = { 0 };
	//���5������
	for (int i = 0; i < 5; i++) {
		int tmp = 0;
		//����an
		int k = i;
		while (k >= 0) {
			tmp += a * pow(10, k);
			k--;
		}
		arr[i] = tmp;
	}
	//���5������
	for (int i = 0; i < 5; i++) {
		ret += arr[i];
	}
	printf("%d\n", ret);

	return 0;
}