#define _CRT_SECURE_NO_WARNINGS 1


//矩阵转置
//#include <stdio.h>
//
//int main()
//{
//    int n = 0;
//    int m = 0;
//    scanf("%d %d", &n, &m);//2 3
//    int arr1[10][10] = { 0 };
//    int arr2[10][10] = { 0 };
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            scanf("%d ", &arr1[i][j]);
//        }
//    }
//    //数组二为转置后的数组一
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            arr2[i][j] = arr1[j][i];
//        }
//    }
//    //打印数组二
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            printf("%d ", arr2[i][j]);
//        }
//        printf("\n");
//    }
//
//    return 0;
//}


////序列中删除指定数字
////第一行输入要输入的数字个数
////第二行输入N个整数，用空格分开（N<=50）
////第三行输入想要进行删除的一个整数
////输出为1行，删除指定数字之后的序列
//
//#include <stdio.h>
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr1[50] = { 0 };
//	int arr2[50] = { 0 };
//	//输入N个整数
//	for (int i = 0; i < n; i++) {
//		scanf("%d ", &arr1[i]);
//	}
//	//输入要删除的数
//	int del = 0;
//	scanf("%d", &del);
//	//将符合条件的数保存至数组2
//	int count = 0;
//	for (int i = 0; i < n; i++) {
//		if (del != arr1[i]) {
//			arr2[count] = arr1[i];
//			count++;
//		}
//	}
//	//打印数组2
//	for (int i = 0; i < count; i++) {
//		printf("%d ", arr2[i]);
//	}
//	printf("\n");
//	return 0;
//}


////喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水
//
//#include <stdio.h>
//
//int main()
//{
//	int money = 0;
//	scanf("%d", &money);
//	//不考虑空瓶，能喝几瓶汽水
//	int init = 0;
//	init = money;
//	//空瓶兑换的汽水
//	int plus = init / 2;
//	printf("%d\n", init + plus);
//	return 0;
//}


////上三角矩阵判定
////上三角矩阵即主对角线以下的元素都为0的矩阵
////主对角线为从矩阵的左上角至右下角的连线
////第一行包含一个整数n，表示一个方阵包含n行n列，用空格分隔。(1≤n≤10)
////从2到n + 1行，每行输入n个整数（范围 - 231~231 - 1），用空格分隔，共输入n * n个数。
//
//#include <stdio.h>
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	//将数字输入进数组
//	int arr[10][10] = { 0 };
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			scanf("%d ", &arr[i][j]);
//		}
//	}
//	//判断
//	int flag = 0;
//	for (int i = n-1; i > 0; i--) {
//		for (int j = 0; j < i; j++) {
//			if (arr[i][j] != 0)
//				flag = 1;
//		}
//	}
//	if (flag == 1)
//		printf("NO\n");
//	else if (flag == 0)
//		printf("YES\n");
// 
//	return 0;
//}


//矩阵相等判定
//第一行包含两个整数n和m，表示两个矩阵包含n行m列，用空格分隔
//从2到n+1行，每行输入m个整数（范围-231~231-1），用空格分隔，共输入n*m个数，表示第一个矩阵中的元素。
//从n + 2行到2n + 1，每行输入m个整数（范围 - 231~231 - 1），用空格分隔，共输入n * m个数，表示第二个矩阵中的元素。
//1 < n, m < 10

#include <stdio.h>

int main()
{
	int n = 0;
	int m = 0;
	scanf("%d %d", &n, &m);
	//创建两个数组
	int arr1[9][9] = { 0 };
	int arr2[9][9] = { 0 };
	//将第一组数据储存到arr1
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d ", &arr1[i][j]);
		}
	}
	//将第二组数据储存到arr2
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d ", &arr2[i][j]);
		}
	}
	//依次比较两个数组的数据
	int flag = 0;//0为相同，1为不同
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr1[i][j] != arr2[i][j])
				flag = 1;
		}
	}
	if (flag == 0)
		printf("Yes\n");
	else if (flag == 1)
		printf("No\n");

	return 0;
}