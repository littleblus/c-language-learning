#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <math.h>

//3-1

//#define maxn 1000
//
//char s[maxn];
//int main()
//{
//	freopen("input.txt", "r", stdin);
//	int n = 0;
//	scanf("%d", &n);
//	while (n--) {
//		int sum = 0;
//		int score = 0;
//		memset(s, 0, strlen(s));
//		scanf("%s", s);
//		for (int i = 0; i < strlen(s); i++) {
//			if (s[i] == 'O')
//				score++;
//			if (s[i] == 'X')
//				score = 0;
//			sum += score;
//		}
//		printf("%d\n", sum);
//	}
//
//	return 0;
//}



//3-2(wrong answer)

int Sum(char* start, int digit)
{
	int ret = 0;
	int n = 0;
	
	for (int i = digit - 1; i >= 0; i--) {
		int f = start[i] - '0';
		ret += f * pow(10, n);
		n++;
	}
	return ret;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int n = 0;
	scanf("%d", &n);//输入个数
	const double g[4] = { 12.01,1.008,16.00,14.01 };
	char sub[100];
	while (n--) {
		double ans = 0;
		scanf("%s", sub);
		for (int i = 0; i < strlen(sub); i++) {
			int count = 1;//元素个数
			int digit = 0;//数字位数
			int flag = 0;//元素个数是否不为1
			//查找字母后面的数字并统计
			int p = i;
			while ((p < strlen(sub) - 1 && sub[p + 1] >= '1' && sub[p + 1] <= '9') != 0) {
				digit++;
				p++;
				flag = 1;
			}
			if (flag == 1)
				count = Sum(&sub[i+1], digit);
			switch (sub[i]) {
			case 'C':
				ans += g[0] * count;
				break;
			case 'H':
				ans += g[1] * count;
				break;
			case 'O':
				ans += g[2] * count;
				break;
			case 'N':
				ans += g[3] * count;
				break;
			default:
				break;
			}
			if (flag == 1)
				i++;
		}
		memset(sub, 0, strlen(sub));
		printf("%.3f\n", ans);
	}

	return 0;
}