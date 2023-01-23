#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//4-5

int cmpint(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int main() {
	int region = 0;
	int n, m;
	while ((scanf("%d%d",&n,&m))!=EOF) {
		int* level = calloc(n * m, sizeof(int));
		for (int i = 0; i < n * m; i++) {
			scanf("%d", &level[i]);
		}
		qsort(level, n * m, sizeof(int), cmpint);
		int volume;
		scanf("%d", &volume);
		////Êä³ö
		//printf("Region %d\n", ++region);
		//printf("Water level is %.2f meters.\n", );
		//printf("%.2f percent of the region is under water.\n", );
		//printf("\n");
	}

	return 0;
}