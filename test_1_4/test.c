#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

//int main()
//{
//	unsigned int a = 0x1234;
//	unsigned char b = *(unsigned char*)&a;
//	printf("%x\n", b);
//
//	return 0;
//}

//int main()
//{
//    char a[1000] = { 0 };
//    int i = 0;
//    for (i = 0; i < 1000; i++)
//    {
//        a[i] = -1 - i;
//    }
//    printf("%d", strlen(a));
//    return 0;
//}


//5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ����������
//
//Aѡ��˵��B�ڶ����ҵ�����
//Bѡ��˵���ҵڶ���E���ģ�
//Cѡ��˵���ҵ�һ��D�ڶ���
//Dѡ��˵��C����ҵ�����
//Eѡ��˵���ҵ��ģ�A��һ��
//
//����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�

//int main()
//{
//	int a, b, c, d, e;
//	int flag = 0;
//	for (a = 1; a < 6; a++)
//		for (b = 1; b < 6; b++)
//			for (c = 1; c < 6; c++)
//				for (d = 1; d < 6; d++)
//					for (e = 1; e < 6; e++)
//						if (a != b && a != c && a != d && a != e && b != c && b != d && b != e && c != d && c != e && d != e && (b == 2 || a == 3) && (b == 2 || e == 4) && (c == 1 || d == 2) && (c == 5 || d == 3) && (e == 4 || a == 1)) {
//							flag = 1;
//							goto found;
//						}
//found:
//	if (flag == 1) {
//		printf("A�������ǣ�%d\n", a);
//		printf("B�������ǣ�%d\n", b);
//		printf("C�������ǣ�%d\n", c);
//		printf("D�������ǣ�%d\n", d);
//		printf("E�������ǣ�%d\n", e);
//	}
//	else
//		printf("not found!\n");
//
//	return 0;
//}



//�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�����ɷ���һ����
//����Ϊ4�����ɷ��Ĺ���:
//A˵�������ҡ�
//B˵����C��
//C˵����D��
//D˵��C�ں�˵
//��֪3����˵���滰��1����˵���Ǽٻ���
//�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�

//int main()
//{
//	//1Ϊ���֣�0����
//	int a, b, c, d;
//	int count = 0;
//	int flag = 0;
//	for(a=0;a<=1;a++)
//		for(b=0;b<=1;b++)
//			for(c=0;c<=1;c++)
//				for (d = 0; d <= 1; d++) {
//					count = a + b + c + d;
//					//c,d��ͻ��ֻ��һ��˵�ٻ���c,d�п϶���һ��˵�ٻ�
//					if (count == 1 &&(/*c˵�ٻ�*/(a == 0 && c == 1 && d == 0) ||/*d˵�ٻ�*/(a == 0 && c == 1 && d == 1))) {
//						flag = 1;
//						goto found;
//					}
//				}
//found:
//	if (flag == 1) {
//		if (a == 1)
//			printf("A������\n");
//		if (b == 1)
//			printf("B������\n");
//		if (c == 1)
//			printf("C������\n");
//		if (d == 1)
//			printf("D������\n");
//	}
//	else
//		printf("not found!\n");
//
//	return 0;
//}



//����Ļ�ϴ�ӡ������ǡ�
//1
//1 1
//1 2 1
//1 3 3 1
//1 4 6 4 1
//����

void yanghui(const int n) {
	int arr[100][100];
	memset(arr, 0, 100 * 100 * sizeof(int));
	for (int i = 0; i < n; i++) {
		arr[i][0] = 1;
		arr[i][i] = 1;
	}
	for (int i = 2; i < n; i++) {
		for (int j = 0; j <= i - 2; j++) {
			arr[i][j + 1] = arr[i - 1][j] + arr[i - 1][j + 1];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	yanghui(n);

	return 0;
}