#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//4-10

int cmpint(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int main() {
	int region = 0;
	int n, m;
	while ((scanf("%d%d", &n, &m)) != EOF && n && m) {
		int* level = (int*)calloc(n * m, sizeof(int));
		if (!level) {
			perror("calloc:");
			return -1;
		}
		for (int i = 0; i < n * m; i++) {
			scanf("%d", &level[i]);
		}
		qsort(level, n * m, sizeof(int), cmpint);
		int volume;
		scanf("%d", &volume);
		int water = 0;
		int watertmp = 0;
		int area = 0;
		double height = 0;
		for (int i = 0; i < n * m; i++) {
			if (i == n * m - 1) {
				area = n * m;
				height = level[n * m - 1] + (double)(volume - watertmp) / (10 * 10 * n * m);
				break;
			}
			water += 10 * 10 * (i + 1) * (level[i + 1] - level[i]);
			if (water > volume) {
				area = i + 1;
				height = level[i] + (double)(volume - watertmp) / (10 * 10 * (i + 1));
				break;
			}
			watertmp = water;
		}
		//Êä³ö
		printf("Region %d\n", ++region);
		printf("Water level is %.2f meters.\n", height);
		printf("%.2f percent of the region is under water.\n", (float)area / (n * m) * 100);
		printf("\n");
		free(level);
		level = NULL;
	}

	return 0;
}