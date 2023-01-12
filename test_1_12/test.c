#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

//memcpy模拟实现

void* my_memcpy(void* dest, const void* src, size_t n) {
	void* ret = dest;
	while (n--) {
		*(char*)dest = *(char*)src;
		((char*)dest)++;
		((char*)src)++;
	}
	return ret;
}

//memmove模拟实现

void* my_memmove(void* dest, const void* src, size_t n) {
	void* ret = dest;
	if (dest < src) {
		while (n--) {
			*(char*)dest = *(char*)src;
			((char*)dest)++;
			((char*)src)++;
		}
	}
	else if (dest > src) {
		(char*)dest += n - 1;
		(char*)src += n - 1;
		while (n--) {
			*(char*)dest = *(char*)src;
			((char*)dest)--;
			((char*)src)--;
		}
	}
	return dest;
}

void test1() {
	char a[] = "littleblus";
	char b[] = "tyf";
	//memcpy(a, b, sizeof(b));
	my_memcpy(a, b, sizeof(b));
	printf("%s\n", a);
}

void test2() {
	const char* p = "littleblus";
	char a[] = "littleblus";
	my_memmove(a, a + 3, 5);
	printf("%s\n", a);
	my_memcpy(a, p, 11);
	printf("%s\n", a);
	my_memmove(a + 3, a, 5);
	printf("%s\n", a);
}

int main() {
	//test1();
	test2();

	return 0;
}