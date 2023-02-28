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
	PeoInfo* data;//指向存放人的空间
	int sz;//已存放的人数
	int capacity;//当前通讯录的最大容量
}Contact;

//初始化通讯录
void initcon(Contact* pc);

//添加联系人
void addcon(Contact* pc);

//删除联系人
void delcon(Contact* pc);

//查找联系人
void searchcon(Contact* pc);

//修改联系人
void modifycon(Contact* pc);

//排序联系人
void sortcon(Contact* pc);

//显示联系人
int showcon(Contact* pc);

//清空通讯录
void destorycon(Contact* pc);

//保存通讯录
void savecon(Contact* pc);