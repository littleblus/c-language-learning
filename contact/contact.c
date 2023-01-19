#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

static int findbyname(Contact* pc, char* str) {
	assert(pc);
	for (int i = 0; i < pc->sz; i++) {
		if (strcmp(pc->data[i].name, str) == 0) {
			return i;
		}
	}
	return -1;
}

void initcon(Contact* pc) {
	assert(pc);
	pc->sz = 0;
	PeoInfo* ptr = calloc(DEFAULT_SZ, sizeof(PeoInfo));
	if (ptr == NULL) {
		perror("initcon::calloc");
		return;
	}
	pc->data = ptr;
	pc->capacity = DEFAULT_SZ;
	FILE* p = fopen("contact.txt", "rb");
	if (!p) {
		perror("initcon:fopen");
		exit(0);
	}
	PeoInfo tmp = { 0 };
	int i = 0;
	while (1 == (fread(&tmp, sizeof(PeoInfo), 1, p))) {
		if (pc->sz == pc->capacity) {
			PeoInfo* tmp = realloc(pc->data, sizeof(PeoInfo) * (pc->capacity + DUFAULT_ADD));
			if (tmp == NULL) {
				perror("addcon::realloc");
				return;
			}
			pc->data = tmp;
			pc->capacity += DUFAULT_ADD;
		}
		pc->data[i] = tmp;
		pc->sz++;
		i++;
	}
	fclose(p);
	p = NULL;
}

void addcon(Contact* pc) {
	assert(pc);
	if (pc->sz == pc->capacity) {
		PeoInfo* tmp = realloc(pc->data, sizeof(PeoInfo) * (pc->capacity + DUFAULT_ADD));
		if (tmp == NULL) {
			perror("addcon::realloc");
			return;
		}
		pc->data = tmp;
		pc->capacity += DUFAULT_ADD;
	}
	printf("����������>");
	scanf("%s", pc->data[pc->sz].name);
	printf("�������Ա�>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("����������>");
	scanf("%d", &pc->data[pc->sz].age);
	printf("������绰>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("�������ַ>");
	scanf("%s", pc->data[pc->sz].addr);
	pc->sz++;
	printf("��ӳɹ���\n");
}

void delcon(Contact* pc) {
	assert(pc);
	if (showcon(pc) == -1) {
		return;
	}
	printf("������Ҫɾ������ϵ��>");
	char tmp[NAME_MAX] = { 0 };
	scanf("%s", tmp);
	int ret = findbyname(pc, tmp);
	if (ret == -1) {
		printf("δ�ҵ�����ϵ�ˣ�\n");
		return;
	}
	//ɾ��ѡ�񽫺������ϵ��������ǰ����
	for (int i = ret; i < pc->sz - 1; i++) {
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("ɾ���ɹ���\n");
}

void searchcon(Contact* pc) {
	assert(pc);
	printf("��������ϵ������>");
	char tmp[NAME_MAX] = { 0 };
	scanf("%s", tmp);
	int ret = findbyname(pc, tmp);
	if (ret == -1) {
		printf("δ�ҵ�����ϵ�ˣ�\n");
		return;
	}
	printf("%-20s\t%-7s\t%s\t%-12s\t%-30s\t\n", "����", "�Ա�", "����", "�绰", "��ַ");
	printf("%-20s\t%-7s\t%d\t%-12s\t%-30s\t\n", pc->data[ret].name, pc->data[ret].sex, pc->data[ret].age, pc->data[ret].tele, pc->data[ret].addr);
}

void modifycon(Contact* pc) {
	assert(pc);
	printf("������Ҫ�޸ĵ���ϵ������>");
	char tmp[NAME_MAX] = { 0 };
	scanf("%s", tmp);
	int ret = findbyname(pc, tmp);
	if (ret == -1) {
		printf("δ�ҵ�����ϵ�ˣ�\n");
		return;
	}
	printf("����������>");
	scanf("%s", pc->data[ret].name);
	printf("�������Ա�>");
	scanf("%s", pc->data[ret].sex);
	printf("����������>");
	scanf("%d", &pc->data[ret].age);
	printf("������绰>");
	scanf("%s", pc->data[ret].tele);
	printf("�������ַ>");
	scanf("%s", pc->data[ret].addr);
	printf("�޸ĳɹ���\n");
}

static int cmpname(const PeoInfo* a, const PeoInfo* b) {
	return strcmp(a->name, b->name);
}

void sortcon(Contact* pc) {
	assert(pc);
	qsort(pc->data, pc->sz, sizeof(PeoInfo), cmpname);
	printf("����������ɹ���\n");
}

int showcon(Contact* pc) {
	assert(pc);
	if (pc->sz == 0) {
		printf("ͨѶ¼Ϊ��,�޷�������\n");
		return -1;
	}
	printf("%-20s\t%-7s\t%s\t%-12s\t%-30s\t\n", "����", "�Ա�", "����", "�绰", "��ַ");
	for (int i = 0; i < pc->sz; i++) {
		printf("%-20s\t%-7s\t%d\t%-12s\t%-30s\t\n", pc->data[i].name, pc->data[i].sex, pc->data[i].age, pc->data[i].tele, pc->data[i].addr);
	}
	return 0;
}

void destorycon(Contact* pc) {
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}

void savecon(Contact* pc) {
	assert(pc);
	FILE* p = fopen("contact.txt", "wb");
	if (!p) {
		perror("savecon:fopen");
		return;
	}
	fwrite(pc->data, sizeof(PeoInfo), pc->sz, p);
	fclose(p);
	if (ferror(p)) {
		printf("����ʱ���ִ���!\n");
		perror("savecon:");
		return;
	}
	p = NULL;
	printf("����ɹ���\n");
}