#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//��һ��

//�����㷨����ʱ��
int main() {
	int n, k, count = 0;
	scanf("%d%d", &n, &k);
	for (int i = k; i <= n; i++) {
		for (int j = k; j <= n; j++) {
			if (i % j >= k)
				count++;
		}
	}
	printf("%d\n", count);

	return 0;
}

//��ѧ��ʽ��
int main() {
	long n, k;
	scanf("%ld%ld", &n, &k);

	if (k == 0) {
		printf("%ld\n", n * n);//�������Ե�ȡģ������Ǵ��ڵ���0��
		return 0;
	}
	long count = 0;
	for (long y = k + 1; y <= n; y++) {
		count += ((n / y) * (y - k)) + ((n % y < k) ? 0 : (n % y - k + 1));
	}
	printf("%ld\n", count);

	return 0;
}



//�ڶ���

int main() {
	char str[1000];
	scanf("%s", str);
	int n;
	scanf("%d", &n);
	char* pc = str;
	for (int i = 0; i < n; i++) {
		printf("%c", *pc++);
	}

	return 0;
}