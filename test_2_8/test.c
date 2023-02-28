#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stddef.h>

/*

//写一个宏，用来交换二进制的奇数位和偶数位
//10101010101010101010101010101010 按位与保留奇数位
//01010101010101010101010101010101 按位与保留偶数位
//然后分别右移、左移后相加
#define SWAPODDEVEN(x) (((0xaaaaaaaa&x)>>1)+((0x55555555&x)<<1))

int main() {
	//测试一个数13
	//二进制位为1101
	//奇偶交换后1110 -> 14
	int test = 13;
	printf("%d\n", SWAPODDEVEN(test));
	return 0;
}

*/




//写一个宏，计算结构体中某变量相对于首地址的偏移，并给出说明

//说明，先取0转化为结构体指针，然后引用该结构并取地址
//由于结构初始偏移为0的地址就是0，所以引用的成员地址即为偏移量
//最后强转为size_t
#define MYOFFSETOF(s,m) ((size_t)(&(((s*)0)->m)))

//定义结构体
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