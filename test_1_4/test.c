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


//5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：
//
//A选手说：B第二，我第三；
//B选手说：我第二，E第四；
//C选手说：我第一，D第二；
//D选手说：C最后，我第三；
//E选手说：我第四，A第一；
//
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。

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
//		printf("A的名次是：%d\n", a);
//		printf("B的名次是：%d\n", b);
//		printf("C的名次是：%d\n", c);
//		printf("D的名次是：%d\n", d);
//		printf("E的名次是：%d\n", e);
//	}
//	else
//		printf("not found!\n");
//
//	return 0;
//}



//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
//以下为4个嫌疑犯的供词:
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。

//int main()
//{
//	//1为凶手，0无罪
//	int a, b, c, d;
//	int count = 0;
//	int flag = 0;
//	for(a=0;a<=1;a++)
//		for(b=0;b<=1;b++)
//			for(c=0;c<=1;c++)
//				for (d = 0; d <= 1; d++) {
//					count = a + b + c + d;
//					//c,d冲突，只有一人说假话则c,d中肯定有一人说假话
//					if (count == 1 &&(/*c说假话*/(a == 0 && c == 1 && d == 0) ||/*d说假话*/(a == 0 && c == 1 && d == 1))) {
//						flag = 1;
//						goto found;
//					}
//				}
//found:
//	if (flag == 1) {
//		if (a == 1)
//			printf("A是凶手\n");
//		if (b == 1)
//			printf("B是凶手\n");
//		if (c == 1)
//			printf("C是凶手\n");
//		if (d == 1)
//			printf("D是凶手\n");
//	}
//	else
//		printf("not found!\n");
//
//	return 0;
//}



//在屏幕上打印杨辉三角。
//1
//1 1
//1 2 1
//1 3 3 1
//1 4 6 4 1
//……

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