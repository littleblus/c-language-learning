#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//int flag = 0;
//void menu()
//{
//	printf("********************\n");
//	printf("****    1.play  ****\n");
//	printf("****    0.exit  ****\n");
//	printf("********************\n");
//	printf("����������>");
//	scanf("%d", &flag);
//	
//}
//
//void game()
//{
//	//����1-100���������ʹ��ʱ�����
//	printf("�����֣�������һ��1-100������\n");
//	srand((unsigned int)time(NULL));
//	int ret = rand() % 100 + 1;
//	int input = 0;
//	for (;;) 
//	{
//		scanf("%d", &input);
//		if (input > ret)
//			printf("�´���\n");
//		else if (input < ret)
//			printf("��С��\n");
//		else 
//		{
//			printf("��ϲ��¶���\n");
//			break;
//		}
//	}
//}
//
//int main()
//{
//	while (1)
//	{
//	start:
//		menu();
//		switch (flag)
//		{
//			case 0:
//				break;
//			case 1:
//				game();
//				goto start;
//			default:
//				printf("����ˣ�����������\n");
//				goto start;
//
//		}
//		break;
//	}
//	printf("ף��������죬�ټ�\n");
//	return 0;
//}

//int main() {
//    long long n = 0;
//    long long ret = 0;
//    scanf("%lld", &n);
//    ret = (1 + n) * n / 2;
//    printf("%lld", ret);
//    return 0;
//}


//С�����ŵ���
int main() 
{
    //��ʼ���ȴ�����
    int n = 0;
    int ret = 0;
    scanf("%d", &n);
    ret = n / 12 * 4 + 2;
    printf("%d", ret);
    return 0;
}