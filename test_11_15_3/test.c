#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//����Ҫ����㲢���������n������k�������Լ����ǵĺ͡�
//������һ���и���n(10<n<10000)��k(1<k<10)��ֵ
//��һ���а����и�ʽ���:
//����1 + ����2 + . + ����k = �ܺ�ֵ
//�ݼ����

int main()
{
	int n = 0;
	int k = 0;
	int flag1 = 0;
	int flag2 = 0;
	int count = 0;
	int sum = 0;
	scanf("%d %d", &n, &k);
	//�Գ����ж�����
	//���ж���ż��ͨ��ֻ����ż�����ټ�������
	for (int i = n; i >= 2; i--) {
		//�жϴ�ӡ���������Ƿ�ﵽ����Ҫ��������
		if (count == k) {
			printf("=%d\n", sum);
			flag2 = 1;
			break;
		}
		//�ж�����������sqrt�ӿ�ʱ�䣬�����math�⣩
		for (int j = 2; j < i; j++) {
			flag1 = 0;
			if (i % j == 0) {
				flag1 = 1;
				break;
			}
			else
				continue;
		}
		//�������Ӻ�sum������
		if (flag1 == 0) {
			count++;
			sum = sum + i;
			printf("%d", i);
			//�ж�δ�ﵽ���Ҫ��ʱ���+��
			if(count < k)
				printf("+");
		}

	}
	//��û�дﵽ��������ɾ������+�Ų����sum
	if(flag2==0)
		printf("\b=%d\n", sum);
	
	return 0;
}
