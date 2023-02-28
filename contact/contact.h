#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX 20
#define SEX_MAX 7
#define TELE_MAX 12
#define ADDR_MAX 30
#define DEFAULT_SZ 3
#define DUFAULT_ADD 2

typedef struct PeoInfo {
	char name[NAME_MAX];
	char sex[SEX_MAX];
	int age;
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
}PeoInfo;

typedef struct Contact {
	PeoInfo* data;//ָ�����˵Ŀռ�
	int sz;//�Ѵ�ŵ�����
	int capacity;//��ǰͨѶ¼���������
}Contact;

//��ʼ��ͨѶ¼
void initcon(Contact* pc);

//�����ϵ��
void addcon(Contact* pc);

//ɾ����ϵ��
void delcon(Contact* pc);

//������ϵ��
void searchcon(Contact* pc);

//�޸���ϵ��
void modifycon(Contact* pc);

//������ϵ��
void sortcon(Contact* pc);

//��ʾ��ϵ��
int showcon(Contact* pc);

//���ͨѶ¼
void destorycon(Contact* pc);

//����ͨѶ¼
void savecon(Contact* pc);