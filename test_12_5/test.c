#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <math.h>

//void print(int n,char* str,int sz) 
//{
//	//填充13个'*'
//	for (int i = 0; i < 13; i++) {
//		str[i] = '*';
//	}
//	//填补两侧' '
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

//打印水仙花数
//求出0～100000之间的所有“水仙花数”并输出。
//“水仙花数”是指一个n位数，
//其各位数字的n次方之和确好等于该数本身，
//如:153＝1 ^ 3＋5 ^ 3＋3 ^ 3，则153是一个“水仙花数”。

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
//        //判断输入是几位数
//        int k = digit(i);
//        //若为水仙花数，则输出
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

//计算求和
//求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和
//其中a是一个数字

int main()
{
	int a = 0;
	int ret = 0;
	printf("请输入一个正整数\n");
	while (1) {
		scanf("%d", &a);
		if (a > 0)
			break;
		else
			printf("输入错误，请输入正整数！\n");
	}
	//创建一个一维数组放下5个数字
	int arr[5] = { 0 };
	//填充5个数字
	for (int i = 0; i < 5; i++) {
		int tmp = 0;
		//生成an
		int k = i;
		while (k >= 0) {
			tmp += a * pow(10, k);
			k--;
		}
		arr[i] = tmp;
	}
	//相加5个数字
	for (int i = 0; i < 5; i++) {
		ret += arr[i];
	}
	printf("%d\n", ret);

	return 0;
}