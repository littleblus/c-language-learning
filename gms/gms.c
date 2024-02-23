#include "gms.h"
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <stdint.h>

void sha256(const unsigned char* data, size_t len, unsigned char* hash) {
	// 这个函数使用Windows的API计算SHA-256哈希值，需要链接crypt32.lib
	HCRYPTPROV hProv = 0; // 加密服务提供者
	HCRYPTHASH hHash = 0; // 哈希对象
	DWORD cbHash = 32; // 哈希值的大小，单位为字节，即256位
	// 获取加密服务提供者的句柄
	if (!CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_AES, CRYPT_VERIFYCONTEXT)) {
		perror("CryptAcquireContext");
		exit(1);
	}
	// 创建哈希对象
	if (!CryptCreateHash(hProv, CALG_SHA_256, 0, 0, &hHash)) {
		perror("CryptCreateHash");
		exit(1);
	}
	// 计算哈希值
	if (!CryptHashData(hHash, data, len, 0)) {
		perror("CryptHashData");
		exit(1);
	}
	// 获取哈希值
	if (!CryptGetHashParam(hHash, HP_HASHVAL, hash, &cbHash, 0)) {
		perror("CryptGetHashParam");
		exit(1);
	}
	// 释放哈希对象
	CryptDestroyHash(hHash);
	CryptReleaseContext(hProv, 0);
}

typedef struct {
	char name[50];
	unsigned char md5[32];
	enum Privilege privilege;
} account;

enum Privilege login(const char* pwd_path, char* login_name_out) {
	FILE* file = fopen(pwd_path, "rb+");
	if (!file) { // 文件不存在，创建新的管理员账户
		safe_print("Admin account does not exist, creating a new one.");
		file = fopen(pwd_path, "wb+");
		if (!file) {
			perror("fopen");
			exit(EXIT_FAILURE);
		}
		account admin;
		safe_print("Please input the admin name>");
		scanf("%49s", admin.name);
		unsigned int pwd;
		safe_print("Please input the admin password (numeric)>");
		scanf("%u", &pwd);
		sha256((unsigned char*)&pwd, sizeof(pwd), admin.md5);
		admin.privilege = ADMIN;
		fwrite(&admin, sizeof(account), 1, file);
		strcpy(login_name_out, admin.name);
		fclose(file);
		return ADMIN;
	}

	// 检查文件第一个账户是否为管理员
	account firstAccount;
	rewind(file);
	if (fread(&firstAccount, sizeof(account), 1, file) == 1) {
		if (firstAccount.privilege != ADMIN) {
			print_to_bottom("ERROR: First account is not an admin. Data corruption suspected.");
			fclose(file);
			return FAILED;
		}
	}

	int choice;
	safe_print("Please input 1 to login, 2 to create or modify an account: ");
	scanf("%d", &choice);

	if (choice == 1) { // 登录逻辑
		safe_print("Please input the username>");
		char username[50];
		scanf("%49s", username);
		unsigned int pwd;
		safe_print("Please input the password (numeric)>");
		scanf("%u", &pwd);
		unsigned char inputMd5[32];
		sha256((unsigned char*)&pwd, sizeof(pwd), inputMd5);

		// 寻找对应账户并核对密码
		rewind(file);
		account acc;
		while (fread(&acc, sizeof(account), 1, file) == 1) {
			if (strcmp(acc.name, username) == 0) {
				if (memcmp(acc.md5, inputMd5, 32) == 0) {
					strcpy(login_name_out, acc.name);
					fclose(file);
					return acc.privilege;
				}
				else {
					fclose(file);
					return WRONG;
				}
			}
		}

		fclose(file);
		return FAILED; // 用户不存在
	}
	else if (choice == 2) { // 创建或修改账户逻辑
		safe_print("Please input the username>");
		char username[50];
		scanf("%49s", username);
		unsigned int pwd;
		safe_print("Please input the password (numeric)>");
		scanf("%u", &pwd);
		unsigned char inputMd5[32];
		sha256((unsigned char*)&pwd, sizeof(pwd), inputMd5);

		rewind(file);
		account acc;
		while (fread(&acc, sizeof(account), 1, file) == 1) {
			if (strcmp(acc.name, username) == 0) {
				// 判断密码是否相同
				if (memcmp(acc.md5, inputMd5, 32) != 0) {
					fclose(file);
					return WRONG;
				}
				safe_print("User already exists, do you want to change the password? 1 for yes, 2 for no: ");
				scanf("%d", &choice);
				if (choice == 1) {
					safe_print("Please input the new password (numeric)>");
					scanf("%u", &pwd);
					sha256((unsigned char*)&pwd, sizeof(pwd), inputMd5);
					// 修改密码
					rewind(file);
					FILE* temp = fopen("temp.bin", "wb+");
					if (!temp) {
						perror("fopen");
						exit(EXIT_FAILURE);
					}
					account newAcc;
					while (fread(&newAcc, sizeof(account), 1, file) == 1) {
						if (strcmp(newAcc.name, username) == 0) {
							newAcc.privilege = acc.privilege;
							memcpy(newAcc.md5, inputMd5, 32);
						}
						fwrite(&newAcc, sizeof(account), 1, temp);
					}
					fclose(file);
					fclose(temp);
					remove(pwd_path);
					rename("temp.bin", pwd_path);
					print_to_bottom(GREEN"Password changed successfully."ENDCOLOR);
					strcpy(login_name_out, username);
					return acc.privilege;
				}
				else if (choice == 2) {
					strcpy(login_name_out, username);
					fclose(file);
					return acc.privilege;
				}
				else {
					print_to_bottom("Invalid input, please input 1 or 2");
					fclose(file);
					return FAILED;
				}
			}
		}
		// 用户不存在，直接写入新的用户名和密码
		acc.privilege = USER;
		strcpy(acc.name, username);
		memcpy(acc.md5, inputMd5, 32);
		fwrite(&acc, sizeof(account), 1, file);
		strcpy(login_name_out, username);
		fclose(file);
		return USER;
	}
	else { // 非法输入
		safe_print("Invalid input.");
		fclose(file);
		return FAILED;
	}
}

void safe_print(const char* format, ...) {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	// 获取控制台屏幕缓冲区的信息
	GetConsoleScreenBufferInfo(hStdOut, &csbi);

	// 如果光标已经在最后一行，那么就先清除最后一行的内容，然后再向上滚动一行
	if (csbi.dwCursorPosition.Y == csbi.dwSize.Y - 1) {
		// 保存最后一行的内容
		DWORD length = csbi.dwSize.X;
		CHAR_INFO* buffer = (CHAR_INFO*)malloc(length * sizeof(CHAR_INFO));
		COORD bufferSize = { length, 1 };
		COORD bufferCoord = { 0, 0 };
		SMALL_RECT readRegion = { 0, csbi.dwCursorPosition.Y, length - 1, csbi.dwCursorPosition.Y };
		ReadConsoleOutput(hStdOut, buffer, bufferSize, bufferCoord, &readRegion);

		// 清除最后一行的内容
		DWORD written;
		FillConsoleOutputCharacter(hStdOut, ' ', length, csbi.dwCursorPosition, &written);
		FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, length, csbi.dwCursorPosition, &written);

		SMALL_RECT scrollRect;
		scrollRect.Left = 0;
		scrollRect.Top = 1;
		scrollRect.Right = csbi.dwSize.X - 1;
		scrollRect.Bottom = csbi.dwSize.Y - 1;

		COORD scrollTarget;
		scrollTarget.X = 0;
		scrollTarget.Y = 0;

		CHAR_INFO fill;
		fill.Char.UnicodeChar = ' ';
		fill.Attributes = csbi.wAttributes;

		ScrollConsoleScreenBuffer(hStdOut, &scrollRect, NULL, scrollTarget, &fill);

		// 将光标移动到倒数第二行
		csbi.dwCursorPosition.Y--;
		SetConsoleCursorPosition(hStdOut, csbi.dwCursorPosition);

		// 重新打印最后一行的内容
		WriteConsoleOutput(hStdOut, buffer, bufferSize, bufferCoord, &readRegion);
		free(buffer);
	}

	// 打印文本
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}

void print_to_bottom(char* text) {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	// 获取控制台屏幕缓冲区的信息
	GetConsoleScreenBufferInfo(hStdOut, &csbi);

	// 保存当前光标位置
	COORD oldPos = csbi.dwCursorPosition;

	// 移动光标到最后一行
	csbi.dwCursorPosition.X = 0;
	csbi.dwCursorPosition.Y = csbi.dwSize.Y - 1;
	SetConsoleCursorPosition(hStdOut, csbi.dwCursorPosition);

	// 清除当前行的内容
	DWORD length = csbi.dwSize.X;
	DWORD written;
	FillConsoleOutputCharacter(hStdOut, ' ', length, csbi.dwCursorPosition, &written);
	FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, length, csbi.dwCursorPosition, &written);

	// 打印新的文本
	printf("%s", text);

	// 将光标移回原来的位置
	SetConsoleCursorPosition(hStdOut, oldPos);
}

void clearScreen() {
	system("cls");
}

Student* students = NULL;

Student* get_students() {
	return students;
}

float point(float score) {
	if (score >= 90) return 4.0f;
	else if (score >= 87) return 3.7f;
	else if (score >= 84) return 3.3f;
	else if (score >= 80) return 3.0f;
	else if (score >= 77) return 2.7f;
	else if (score >= 74) return 2.3f;
	else if (score >= 70) return 2.0f;
	else if (score >= 67) return 1.7f;
	else if (score >= 64) return 1.3f;
	else if (score >= 60) return 1.0f;
	else return 0.0f;
}

float gpa(Student* student) {
	Course* course = student->courses;
	float total_point = 0, total_credit = 0;
	while (course != NULL) {
		total_point += point(course->score) * course->credit;
		total_credit += course->credit;
		course = course->next;
	}
	return total_point / total_credit;
}

bool is_warning(Student* student) {
	Course* course = student->courses;
	float total_credit = 0, warning_credit = 0;
	while (course != NULL) {
		total_credit += course->credit;
		if (course->score < 60) {
			warning_credit += course->credit;
		}
		course = course->next;
	}
	if (total_credit == 0) return false;
	return warning_credit / total_credit >= WARNING_RATE;
}

void add_student(char* id, char* name) {
	Student* student = (Student*)malloc(sizeof(Student));
	if (student == NULL) { // 检查
		perror("malloc");
		save_to_file(FILENAME);
		exit(1);
	}
	strcpy(student->id, id);
	strcpy(student->name, name);
	student->courses = NULL;
	// 插入到链表头部
	student->next = students;
	students = student;
}

void del_student(char* id) {
	Student* student = students;
	Student* prev = NULL;
	while (student != NULL && strcmp(student->id, id) != 0) {
		prev = student;
		student = student->next;
	}
	if (student != NULL) {
		if (prev == NULL) {
			students = student->next;
		}
		else {
			prev->next = student->next;
		}
		Course* course = student->courses;
		while (course != NULL) {
			Course* next = course->next;
			free(course);
			course = next;
		}
		free(student);
	}
}

void add_course(char* student_id, char* course_name, float score, float credit) {
	Student* student = students;
	while (student != NULL && strcmp(student->id, student_id) != 0) {
		student = student->next;
	}
	if (student != NULL) {
		Course* course = (Course*)malloc(sizeof(Course));
		if (course == NULL) { // 检查
			perror("malloc");
			exit(1);
		}
		strcpy(course->name, course_name);
		course->score = score;
		course->credit = credit;
		course->next = student->courses;
		student->courses = course;
	}
}

void del_course(char* student_id, char* course_name) {
	Student* student = students;
	while (student != NULL && strcmp(student->id, student_id) != 0) {
		student = student->next;
	}
	if (student != NULL) {
		Course* course = student->courses;
		Course* prev = NULL;
		while (course != NULL && strcmp(course->name, course_name) != 0) {
			prev = course;
			course = course->next;
		}
		if (course != NULL) {
			if (prev == NULL) {
				student->courses = course->next;
			}
			else {
				prev->next = course->next;
			}
			free(course);
		}
	}
}

// -1: 文件不存在,-2: 格式错误,0: 成功
int init_from_file(char* filename) {
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		perror("fopen");
		return -1;
	}
	char line[100];
	while (fgets(line, 100, file) != NULL) {
		char* id = strtok(line, ",");
		char* name = strtok(NULL, ",");
		char* course_name = strtok(NULL, ",");
		float score = atof(strtok(NULL, ","));
		float credit = atof(strtok(NULL, ","));
		// 检查格式
		if (id == NULL || name == NULL || course_name == NULL) {
			return -2;
		}
		if (score < 0 || score > 100 || credit < 0) {
			return -2;
		}
		Student* student = find_student_by_id(id);
		if (student == NULL) {
			add_student(id, name);
			student = students;
		}
		add_course(id, course_name, score, credit);
	}
	fclose(file);
	return 0;
}

void save_to_file(char* filename) {
	FILE* file = fopen(filename, "w");
	Student* student = students;
	while (student != NULL) {
		Course* course = student->courses;
		while (course != NULL) {
			fprintf(file, "%s,%s,%s,%.2f,%.2f\n", student->id, student->name, course->name, course->score, course->credit);
			course = course->next;
		}
		student = student->next;
	}
	fclose(file);
}

Student* find_student_by_id(char* id) {
	Student* student = students;
	while (student != NULL && strcmp(student->id, id) != 0) {
		student = student->next;
	}
	return student;
}

Student* find_student_by_name(char* stu_name) {
	Student* student = students;
	while (student != NULL && strcmp(student->name, stu_name) != 0) {
		student = student->next;
	}
	return student;
}

Course* find_course(Student* student, char* course_name) {
	Course* course = student->courses;
	while (course != NULL && strcmp(course->name, course_name) != 0) {
		course = course->next;
	}
	return course;
}

void print_course(Course* course) {
	if(course == NULL) return;
	printf("Course: %s, Score: %.2f, Credit: %.2f, ", course->name, course->score, course->credit);
	printf("point: %.2f\n", point(course->score));
}

void print_stu(Student* student) {
	if(student == NULL) return;
	printf("ID: %s, Name: %s\n", student->id, student->name);
	Course* course = student->courses;
	float total_point = 0, total_credit = 0;
	while (course != NULL) {
		print_course(course);
		total_point += point(course->score) * course->credit;
		total_credit += course->credit;
		course = course->next;
	}
	printf("GPA: %.2f\n", total_point / total_credit);
	printf("\n");
}

void print_all() {
	Student* student = students;
	int count = 0;
	while (student != NULL) {
		print_stu(student);
		count++;
		if (count % ELEMS_PER_PAGE == 0) {
			printf(GREEN"press any key to continue, q to quit"ENDCOLOR);
			int c = _getch();
			if (c == 'q' || c == 'Q') {
				printf(GREEN"quit success!"ENDCOLOR);
				return;
			}
			clearScreen();
		}
		student = student->next;
	}
}