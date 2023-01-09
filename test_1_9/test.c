#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

//模拟实现strlen
size_t my_strlen(const char* str) {
	assert(str);
	int count = 0;
	while (*str++ != 0)
		count++;
	return count;
}

//模拟实现strcpy
char* my_strcpy(char* dest, const char* src) {
	assert(dest && src);
	char* d = dest;
	do {
		*dest++ = *src;
	} while (*src++ != 0);
	return dest;
}

//模拟实现strcmp
int my_strcmp(const char* a, const char* b) {
	assert(a && b);
	while (*a == *b) {
		if (*a == 0 && *b == 0)
			return 0;
		a++;
		b++;
	}
	if (*a > *b)
		return 1;
	else
		return -1;
}

//模拟实现strcat
char* my_strcat(char* dest, const char* src) {
	assert(dest && src);
	char* d = dest;
	//将dest位移到'\0'
	while (*dest != 0) {
		dest++;
	}
	while (*src != 0) {
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return d;
}

////模拟实现strstr,采用暴力匹配算法
// 
//char* my_strstr(const char* haystack, const char* needle) {
//	assert(haystack && needle);
//	char* pc = haystack;
//	char* s1;
//	char* s2;
//	if (!*needle)
//		return haystack;
//	while (*pc) {
//		s1 = pc;
//		s2 = needle;
//		//若*s1与*s2不相等，则两个指针后移
//		while (*s1 && *s2 && !(*s1 - *s2))
//			s1++, s2++;
//		//若s2指向'\0'，返回位移后的pc指针
//		if (!*s2)
//			return(pc);
//		pc++;
//	}
//	//没有完整的while循环完成则返回NULL
//	return(NULL);
//}

//模拟实现strstr,采用KMP算法
 
void GetNext(int* arr, int num, char* str) {
	arr[0] = -1;
	arr[1] = 0;
	for (int i = 1; i < num - 1; i++) {
		int k = arr[i];
	con:
		if (*(str + i) == *(str + k))
			arr[i + 1] = k + 1;
		else if (k != -1) {
			k = arr[k];
			goto con;
		}
	}
}

char* my_strstr(const char* haystack, const char* needle) {
	assert(haystack && needle);
	int len = strlen(needle);
	//创建next数组
	int* next = (int*)malloc(sizeof(int) * len);
	memset(next, 0, sizeof(int) * len);
	//求next数组的值
	GetNext(next, len, needle);
	//遍历
	int i = 0;
	int j = 0;
	while (haystack[i] != 0) {
		if (j == -1 || haystack[i] == needle[j]) {//j=-1时越界访问，我们直接判断一下
			i++;
			j++;
		}
		else {
			j = next[j];
		}
		if (j >= len) {//找到了
			return &haystack[i] - len;
		}
	}
	//没找到
	return NULL;
}

void test1() {
	char str[] = "littleblus";
	int len = my_strlen(str);
	printf("%d\n", len);
}

void test2() {
	char str[] = "littleblus";
	const char* p = "tyf";
	my_strcpy(str, p);
	printf("%s\n", str);
}

void test3() {
	char str[] = "littleblus";
	const char* p1 = "tyf";
	const char* p2 = "littleblus";
	int ret1 = my_strcmp(str, p1);
	printf("%d\n", ret1);
	int ret2 = my_strcmp(str, p2);
	printf("%d\n", ret2);
}

void test4() {
	char str[20] = "littleblus";
	const char* p1 = " tyf";
	my_strcat(str, p1);
	printf("%s\n", str);
}

void test5() {
	char str1[30] = "littleblus";
	char str2[30] = "littlebluslovetangyifei";
	const char* p = "tangyifei";
	char* ret1 = my_strstr(str2, p);
	if (ret1 == &str2[14])
		printf("Congratulations\n");
	else
		printf("it looks not right\n");
}

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	test5();

	return 0;
}