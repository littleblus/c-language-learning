#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stddef.h>

/*

//дһ���꣬�������������Ƶ�����λ��ż��λ
//10101010101010101010101010101010 ��λ�뱣������λ
//01010101010101010101010101010101 ��λ�뱣��ż��λ
//Ȼ��ֱ����ơ����ƺ����
#define SWAPODDEVEN(x) (((0xaaaaaaaa&x)>>1)+((0x55555555&x)<<1))

int main() {
	//����һ����13
	//������λΪ1101
	//��ż������1110 -> 14
	int test = 13;
	printf("%d\n", SWAPODDEVEN(test));
	return 0;
}

*/




//дһ���꣬����ṹ����ĳ����������׵�ַ��ƫ�ƣ�������˵��

//˵������ȡ0ת��Ϊ�ṹ��ָ�룬Ȼ�����øýṹ��ȡ��ַ
//���ڽṹ��ʼƫ��Ϊ0�ĵ�ַ����0���������õĳ�Ա��ַ��Ϊƫ����
//���ǿתΪsize_t
#define MYOFFSETOF(s,m) ((size_t)(&(((s*)0)->m)))

//����ṹ��
struct S {
	int a;//0
	char b;//4
	short c;//6
	int d;//8
}s1;

int main() {
	printf("%zd\n", offsetof(struct S, c));
	printf("%zd\n", MYOFFSETOF(struct S, c));
	return 0;
}