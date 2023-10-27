#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//��һ��

int GetNumberOfK(int* data, int dataLen, int k) {
	if (dataLen == 0)
		return 0;
	int left = 0;
	int right = dataLen - 1;
	int mid = (left + right) / 2;
	//���ֲ����ҵ�k
	while (left < right) {
		mid = (left + right) / 2;
		if (data[mid] > k) {
			right--;
		}
		else {
			left++;
		}
	}
	//��λ����һ��k
	while (data[mid] == k) {
		mid--;
	}
	//����
	int count = 0;
	while (data[++mid] == k) {
		count++;
	}
	return count;
}



//�ڶ���

int convertInteger(int A, int B) {
	//����A��B�Ĳ�ͬλ��
	//����A��B��λ���
	unsigned int t = A ^ B;
	//֮�����t��1�ĸ���
	int count = 0;
	while (t) {
		t = t & (t - 1);
		count++;
	}
	return count;
}