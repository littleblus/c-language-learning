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
//	printf("请输入数字>");
//	scanf("%d", &flag);
//	
//}
//
//void game()
//{
//	//生成1-100的随机数（使用时间戳）
//	printf("猜数字，请输入一个1-100的整数\n");
//	srand((unsigned int)time(NULL));
//	int ret = rand() % 100 + 1;
//	int input = 0;
//	for (;;) 
//	{
//		scanf("%d", &input);
//		if (input > ret)
//			printf("猜大了\n");
//		else if (input < ret)
//			printf("猜小了\n");
//		else 
//		{
//			printf("恭喜你猜对了\n");
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
//				printf("输错了，请重新输入\n");
//				goto start;
//
//		}
//		break;
//	}
//	printf("祝您生活愉快，再见\n");
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


//小乐乐排电梯
int main() 
{
    //初始化等待人数
    int n = 0;
    int ret = 0;
    scanf("%d", &n);
    ret = n / 12 * 4 + 2;
    printf("%d", ret);
    return 0;
}