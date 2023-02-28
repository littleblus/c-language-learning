#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

////由malloc创建数组，请在使用后进行free操作
//int* Bachelor(int* arr, int sz) {
//	int tmp = 0;
//	int* ret = (int*)malloc(8);
//	int r = 0;
//	if(ret!=NULL)
//		for (int i = 0; i < sz; i++) {
//			int count = 0;
//			tmp = arr[i];
//			for (int j = 0; j < sz; j++) {
//				if (arr[j] == tmp) {
//					count++;
//				}
//				if (count == 2)
//					break;
//			}
//			if (count == 1) {
//				ret[r] = arr[i];
//				r++;
//			}
//		}
//	return ret;
//}
//
//int main() {
//	int t[] = { 1,3,5,1,2,3,4,5 };
//	int sz = sizeof(t) / sizeof(t[0]);
//	int* arr = Bachelor(t, sz);
//	for (int i = 0; i < 2; i++) {
//		printf("%d ", arr[i]);
//	}
//	if (arr != NULL)
//		free(arr);
//
//	return 0;
//}



//strncpy模拟实现
char* my_strncpy(char* dest, const char* src, size_t n) {
	char* ret = dest;
	while (n--) {
		*dest = *src;
		dest++;
		src++;
	}
	return ret;
}

//strncat模拟实现
char* my_strncat(char* dest, const char* src, size_t n) {
	char* ret = dest;
	dest += strlen(dest);
	while (n--) {
		*dest = *src;
		dest++;
		src++;
	}
	return ret;
}

int main()
{
	char src[50], dest[50];
	strcpy(src, "This is source");
	strcpy(dest, "This is destination");
	my_strncat(dest, src, 15);
	printf("最终的目标字符串： |%s|", dest);

	return(0);
}