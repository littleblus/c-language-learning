#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

static void CheckCapacity(SL* s) {
	assert(s);
	if (s->size == s->capacity) {
		SLDataType* tmp = (SLDataType*)realloc(s->a, sizeof(int) * s->capacity * ADDTIMES);
		if (!tmp) {
			perror("realloc failed");
			return;
		}
		s->a = tmp;
		s->capacity *= ADDTIMES;
	}
}

void SLinit(SL* s) {
	assert(s);
	SLDataType* tmp = (SLDataType*)malloc(sizeof(int) * INIT_N);
	if (!tmp) {
		perror("malloc failed");
		return;
	}
	s->a = tmp;
	s->capacity = 4;
	s->size = 0;
}

void SLdestory(SL* s) {
	assert(s);
	free(s->a);
	s->a = NULL;
	s->size = 0;
	s->capacity = 0;
}

void SLprint(SL* s) {
	assert(s);
	for (int i = 0; i < s->size; i++) {
		printf("%d ", s->a[i]);
	}
	printf("\n");
}

void SLpushback(SL* s, SLDataType val) {
	assert(s);
	CheckCapacity(s);
	s->a[s->size++] = val;
}

void SLpopback(SL* s) {
	assert(s);
	assert(s->size);
	s->size--;
}

void SLpushfront(SL* s, SLDataType val) {
	assert(s);
	CheckCapacity(s);
	for (int i = s->size - 1; i >= 0; i--) {
		s->a[i + 1] = s->a[i];
	}
	s->a[0] = val;
	s->size++;
}

void SLpopfront(SL* s) {
	assert(s);
	assert(s->size);
	for (int i = 1; i < s->size; i++) {
		s->a[i - 1] = s->a[i];
	}
	s->size--;
}

void SLinsert(SL* s, int pos, SLDataType val) {
	assert(s);
	assert(pos >= 0 && pos <= s->size);
	CheckCapacity(s);
	int i = s->size;
	while (i > pos) {
		s->a[i] = s->a[i - 1];
		i--;
	}
	s->a[pos] = val;
	s->size++;
}

void SLerase(SL* s, int pos) {
	assert(s);
	assert(s->size);
	assert(pos >= 0 && pos < s->size);
	int i = pos + 1;
	while (i < s->size) {
		s->a[i - 1] = s->a[i];
		i++;
	}
	s->size--;
}

int SLfindpos(SL* s, SLDataType val) {
	assert(s);
	for (int i = 0; i < s->size; i++) {
		if (s->a[i] == val) {
			return i;
		}
	}
	return -1;
}