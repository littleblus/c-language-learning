#define _CRT_SECURE_NO_WARNINGS 1

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



//3-2

//int Sum(char* start, int digit) {
//	int ret = 0;
//	int n = 0;
//
//	for (int i = digit - 1; i >= 0; i--) {
//		int f = start[i] - '0';
//		ret += f * (int)pow(10, n);
//		n++;
//	}
//	return ret;
//}
//
//int main() {
//	//freopen("input.txt", "r", stdin);
//	int n = 0;
//	scanf("%d", &n);//输入个数
//	const double g[4] = { 12.01,1.008,16.00,14.01 };
//	char sub[100];
//	while (n--) {
//		double ans = 0;
//		scanf("%s", sub);
//		for (int i = 0; i < strlen(sub); i++) {
//			int count = 1;//元素个数
//			int digit = 0;//数字位数
//			int flag = 0;//元素个数是否不为1
//			//查找字母后面的数字并统计
//			int p = i;
//			while ((p < strlen(sub) - 1 && sub[p + 1] >= '1' && sub[p + 1] <= '9') != 0) {
//				digit++;
//				p++;
//				flag = 1;
//			}
//			if (flag == 1)
//				count = Sum(&sub[i + 1], digit);
//			switch (sub[i]) {
//			case 'C':
//				ans += g[0] * count;
//				break;
//			case 'H':
//				ans += g[1] * count;
//				break;
//			case 'O':
//				ans += g[2] * count;
//				break;
//			case 'N':
//				ans += g[3] * count;
//				break;
//			default:
//				break;
//			}
//			if (flag == 1)
//				i++;
//		}
//		memset(sub, 0, strlen(sub));
//		printf("%.3f\n", ans);
//	}
//
//	return 0;
//}



//3-3

//int single(int x) {
//	if (x >= 0 && x <= 9) {
//		return -1;
//	}
//	else
//		return x % 10;
//}
//
//int main() {
//	//freopen("input.txt", "r", stdin);
//	int times = 0;
//	scanf("%d", &times);
//	int n;
//	while (times--) {
//		scanf("%d", &n);
//		int ret[10] = { 0 };
//		for (int i = 1; i <= n; i++) {
//			int j = i;
//			while (1) {
//				if (single(j) == -1) {
//					ret[j]++;
//					break;
//				}
//				ret[single(j)]++;
//				j /= 10;
//			}
//		}
//		for (int i = 0; i < 9; i++) {
//			printf("%d ", ret[i]);
//		}
//		printf("%d", ret[9]);
//		printf("\n");
//	}
//
//	return 0;
//}



//3-4

//int main() {
//	//freopen("input.txt", "r", stdin);
//	int n;
//	scanf("%d", &n);
//	while (n--) {
//		char str[100];
//		scanf("%s", str);
//		for (int len = 1; len <= strlen(str); len++) {
//			if (strlen(str) % len != 0)
//				continue;
//			char tmp[100] = { 0 };
//			char dest[100] = { 0 };
//			strncpy(tmp, str, len);
//			int offset = 0;
//			int flag = 0;
//			while (1) {
//				strncpy(dest, str + offset, len);
//				if (strcmp(dest, tmp) != 0) {
//					break;
//				}
//				offset += len;
//				if (offset == strlen(str)) {
//					flag = 1;
//					break;
//				}
//			}
//			if (flag == 1) {
//				printf("%d\n", len);
//				break;
//			}
//		}
//		if (n)
//			printf("\n");
//	}
//
//	return 0;
//}



//3-5(WA)

//void swap(char* a, char* b) {
//	char tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//
//int main() {
//	//freopen("input.txt", "r", stdin);
//	int count = 0;
//	while (1) {
//		char board[5][6] = { 0 };
//		char tmp = 0;
//		int flag = 0;
//		//输入数组
//		for (int i = 0; i < 5; i++) {
//			//gets(board[i]);
//			scanf("%[^\n]%*c", board[i]);
//		}
//		//遇到Z结束
//		for (int i = 0; i < 5; i++) {
//			if (board[i][0] == 'Z')
//				return 0;
//		}
//		//判断空格位置
//		int i = 0, j = 0;
//		for (i = 0; i < 5; i++) {
//			for (j = 0; j < 5; j++) {
//				if (board[i][j] == ' ') {
//					goto out;
//				}
//				if (j == 4 && board[i][4] == '\0') {
//					board[i][4] = ' ';
//					goto out;
//				}
//			}
//		}
//	out:
//		//执行动作
//		while (1) {
//			scanf("%c", &tmp);
//			if (tmp == '0') {
//				//取掉之后的换行
//				scanf("%c", &tmp);
//				break;
//			}
//			flag = 0;
//			switch (tmp) {
//			case 'A':
//				if (i == 0) {
//					flag = 1;
//					goto final;
//				}
//				swap(&board[i][j], &board[i - 1][j]);
//				i--;
//				break;
//			case 'B':
//				if (i == 4) {
//					flag = 1;
//					goto final;
//				}
//				swap(&board[i][j], &board[i + 1][j]);
//				i++;
//				break;
//			case 'L':
//				if (j == 0) {
//					flag = 1;
//					goto final;
//				}
//				swap(&board[i][j], &board[i][j - 1]);
//				j--;
//				break;
//			case 'R':
//				if (j == 4) {
//					flag = 1;
//					goto final;
//				}
//				swap(&board[i][j], &board[i][j + 1]);
//				j++;
//				break;
//			}
//		}
//		final:
//		//打印结果
//		printf("Puzzle #%d:\n", ++count);
//		if (flag == 1) {
//			printf("This puzzle has no final configuration.\n");
//		}
//		else {
//			for (int i = 0; i < 5; i++) {
//				for (int j = 0; j < 4; j++) {
//					printf("%c ", board[i][j]);
//				}
//				printf("%c", board[i][4]);
//				printf("\n");
//			}
//		}
//		//相邻结果之间加空行
//		printf("\n");
//	}
//
//	return 0;
//}



//3-9

//int main() {
//	char s[100000], t[100000], * ps, * pt;
//	while (scanf("%s %s", s, t) != EOF) {
//		for (ps = s, pt = t; *ps && *pt; pt++) {
//			if (*ps == *pt) {
//				ps++;
//			}
//		}
//		if (*ps == '\0')
//			printf("Yes\n");
//		else
//			printf("No\n");
//	}
//
//	return 0;
//}



//3-10

#include <stdio.h>
#include <stdlib.h>

struct node {
    int x, y;
} rec[6];

int cmpnode(const void* a, const void* b) {
    node* a1 = (node*)a;
    node* b1 = (node*)b;
    if (a1->x == b1->x)
        return a1->y - b1->y;
    else
        return a1->x - b1->x;
}

void swap(int& a, int& b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int is_true() {
    for (int i = 1; i < 4; i++) {
        //确保前4个面的宽相等
        if (rec[i].x != rec[0].x)
            return 0;
        //确保后4个面的长相等
        if (rec[5 - i].y != rec[5].y)
            return 0;
    }
    //确保后2个面的宽相等
    if (rec[4].x != rec[5].x)
        return 0;
    //确保前2个面的长相等
    if (rec[0].y != rec[1].y)
        return 0;
    //确保前2个面的长和后4个面的宽相等
    if (rec[0].y != rec[5].x)
        return 0;
    return 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    while (scanf("%d%d", &rec[0].x, &rec[0].y) != EOF) {
        //让每个结构体内部 x <= y
        if (rec[0].x > rec[0].y)
            swap(rec[0].x, rec[0].y);
        for (int i = 1; i < 6; i++) {
            scanf("%d%d", &rec[i].x, &rec[i].y);
            if (rec[i].x > rec[i].y)
                swap(rec[i].x, rec[i].y);
        }
        //让长方形按照边长从小到大排序
        qsort(rec, 6, sizeof(rec[0]), cmpnode);
        if (is_true() == 1)
            printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}