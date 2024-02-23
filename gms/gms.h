#pragma once
#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define ENDCOLOR "\033[0m"
#define FILENAME "data.txt"
#define PWD_FILE "pwd.bin"

#define ELEMS_PER_PAGE 10
#define EXCELLENCE_RATE 0.1
#define WARNING_RATE 0.2 // 挂科学分占总学分的比例

enum Privilege {
	FAILED,
	ADMIN,
	USER,
	WRONG
};

// 登录
enum Privilege login(const char* pwd_path, char* login_name_out);

// 打印在除了最后一行之外的所有行
void safe_print(const char* format, ...);
// 打印到屏幕底部
void print_to_bottom(char* text);
// 清屏
void clearScreen();

typedef struct course {
	char name[50]; // 课程名
	float score; // 成绩
	float credit; // 学分
	struct course* next;
} Course;

typedef struct student {
	char id[20]; // id使用字符串，因为可能有前导0
	char name[50]; // 姓名
	Course* courses; // 课程链表
	struct student* next;
} Student;

Student* get_students();

float point(float score);

float gpa(Student* student);

bool is_warning(Student* student);

void add_student(char* id, char* name);

void del_student(char* id);

void add_course(char* student_id, char* course_name, float score, float credit);

void del_course(char* student_id, char* course_name);

int init_from_file(char* filename);

void save_to_file(char* filename);

Student* find_student_by_id(char* id);

Student* find_student_by_name(char* stu_name);

Course* find_course(Student* student, char* course_name);

void print_course(Course* course);

void print_stu(Student* student);

void print_all();