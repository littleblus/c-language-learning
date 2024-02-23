#include "gms.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int exitcode = 0;

static void menu_a() {
	safe_print("\n");
	safe_print("Student performance management system\n");
	safe_print("0.Exit and save\n");
	safe_print("1.Add\n");
	safe_print("2.Modify\n");
	safe_print("3.Delete\n");
	safe_print("4.Query\n");
	safe_print("5.Sort\n");
	safe_print("6.Excellence selection\n");
	safe_print("7.Forewarning\n");
	safe_print("8.Display\n");
	safe_print("\n");
}

static void menu_u() {
	safe_print("\n");
	safe_print("Student performance management system\n");
	safe_print("0.Exit\n");
	safe_print("4.Query myself\n");
	safe_print("5.Sort myself\n");
	safe_print("\n");
}

enum {
	EXIT = 0,
	ADD,
	MODIFY,
	DELETE,
	QUERY,
	SORT,
	EXCELLENCE,
	FOREWARNING,
	DISPLAY
};

static Student* find_stu() {
	print_to_bottom(GREEN"input id or name, if don't know, please input n"ENDCOLOR);
	safe_print("input id>");
	char id[20];
	scanf("%s", id);
	safe_print("input name>");
	char stu_name[50];
	scanf("%s", stu_name);
	bool byId = strcmp(id, "n") != 0;
	bool byName = strcmp(stu_name, "n") != 0;
	if (!byId && !byName) {
		print_to_bottom(RED"input error!"ENDCOLOR);
		return NULL;
	}
	Student* student;
	if(byId) student = find_student_by_id(id);
	else student = find_student_by_name(stu_name);
	if (student == NULL) {
		print_to_bottom(RED"student not exists!"ENDCOLOR);
		return NULL;
	}
	return student;
}

static void add() {
	char id[20];
	char c;
	char course_name[50];
	safe_print("input id>");
	scanf("%s", id);
	// 添加学生查重
	if (find_student_by_id(id) != NULL) {
		print_to_bottom(GREEN"student exists!"ENDCOLOR);
		safe_print("continue add course?(y/n)");
		scanf(" %c", &c);
		if (c == 'y' || c == 'Y') {
			float score, credit;
			safe_print("input course name>");
			scanf("%s", course_name);
			// 添加课程查重
			Course* course = find_course(find_student_by_id(id), course_name);
			if (course != NULL) {
				print_to_bottom(RED"course exists!"ENDCOLOR);
				safe_print("want to modify?(y/n)");
				scanf(" %c", &c);
				// 确定修改就把就的删除，添加新的
				if (c == 'y' || c == 'Y') {
					del_course(id, course_name);
				}
				else {
					print_to_bottom(RED"add failed!"ENDCOLOR);
					return;
				}
			}
			safe_print("input score>");
			scanf("%f", &score);
			safe_print("input credit>");
			scanf("%f", &credit);
			add_course(id, course_name, score, credit);
		}
		else {
			print_to_bottom(RED"add failed!"ENDCOLOR);
			return;
		}
	}
	else {
		print_to_bottom(RED"student not exists!"ENDCOLOR);
		safe_print("continue add student?(y/n)");
		char c;
		scanf(" %c", &c);
		if (c == 'y' || c == 'Y') {
			char name[50];
			safe_print("input name>");
			scanf("%s", name);
			add_student(id, name);
		}
		else {
			print_to_bottom(RED"add failed!"ENDCOLOR);
			return;
		}
	}
	print_to_bottom(GREEN"add success!"ENDCOLOR);
}

static void modify() {
	Student* student = find_stu();
	if (student == NULL) {
		return;
	}
	safe_print("want to modify student?(y/n)");
	char c;
	scanf(" %c", &c);
	if (c == 'y' || c == 'Y') {
		safe_print("id: %s, name: %s\n", student->id, student->name);
		safe_print("input new id>");
		scanf("%s", student->id);
		safe_print("input new name>");
		scanf("%s", student->name);
		print_to_bottom(GREEN"modify success!"ENDCOLOR);
		return;
	}
	safe_print("input course name>");
	char course_name[50];
	scanf("%s", course_name);
	Course* course = find_course(student, course_name);
	if (course == NULL) {
		print_to_bottom(RED"course not exists!"ENDCOLOR);
		return;
	}
	safe_print("course: %s, score: %.2f, credit: %.2f\n", course->name, course->score, course->credit);
	safe_print("input new course name>");
	scanf("%s", course->name);
	safe_print("input new score>");
	scanf("%f", &course->score);
	safe_print("input new credit>");
	scanf("%f", &course->credit);
	print_to_bottom(GREEN"modify success!"ENDCOLOR);
}

static void delete() {
	Student* student = find_stu();
	if (student == NULL) {
		return;
	}
	safe_print("want to delete student?(y/n)");
	char c;
	scanf(" %c", &c);
	if (c == 'y' || c == 'Y') {
		del_student(student->id);
		print_to_bottom(GREEN"delete success!"ENDCOLOR);
		return;
	}
	safe_print("input course name>");
	char course_name[50];
	scanf("%s", course_name);
	Course* course = find_course(student, course_name);
	if (course == NULL) {
		print_to_bottom(RED"course not exists!"ENDCOLOR);
		return;
	}
	safe_print("course: %s, score: %.2f, credit: %.2f\n", course->name, course->score, course->credit);
	safe_print("want to delete course?(y/n)");
	scanf(" %c", &c);
	if (c == 'y' || c == 'Y') {
		del_course(student->id, course_name);
		print_to_bottom(GREEN"delete success!"ENDCOLOR);
	}
	else {
		print_to_bottom(RED"delete failed!"ENDCOLOR);
	}
}

static void query() {
	Student* student = find_stu();
	if (student == NULL) {
		return;
	}
	safe_print("continue query course?(y/n)");
	char c;
	scanf(" %c", &c);
	if (c == 'y' || c == 'Y') {
		safe_print("input course name>");
		char course_name[50];
		scanf("%s", course_name);
		Course* course = find_course(student, course_name);
		if (course == NULL) {
			print_to_bottom(RED"course not exists!"ENDCOLOR);
			return;
		}
		print_course(course);
	}
	else {
		print_stu(student);
	}
}

// 降序
static int gpa_cmp(const void* a, const void* b) {
	Student* stu1 = *(Student**)a;
	Student* stu2 = *(Student**)b;
	float gpa1 = gpa(stu1);
	float gpa2 = gpa(stu2);
	if (gpa1 > gpa2) return -1;
	else if (gpa1 < gpa2) return 1;
	else return 0;
}

static int score_cmp(const void* a, const void* b) {
	Student* stu1 = *(Student**)a;
	Student* stu2 = *(Student**)b;
	Course* course1 = stu1->courses;
	Course* course2 = stu2->courses;
	// 只有一个课程，直接比较
	if (course1->score > course2->score) return -1;
	else if (course1->score < course2->score) return 1;
	else return 0;
}

// 可选两种排序方式，针对学生的GPA排序，针对单个课程的成绩排序，显示详细信息和排名位次(位次/总人数，百分比)
static void sort() {
	safe_print("input 1 to sort by gpa, 2 to sort by course score>");
	int choice;
	scanf("%d", &choice);
	if (choice == 1) {
		Student* student = get_students();
		int count = 0;
		while (student != NULL) {
			count++;
			student = student->next;
		}
		Student** sorted_students = (Student**)malloc(sizeof(Student*) * count);
		student = get_students(); // 指向恢复到头部
		for(int i = 0; i < count && student; i++) {
			sorted_students[i] = student;
			student = student->next;
		}

		// 对数组进行排序
		qsort(sorted_students, count, sizeof(Student*), gpa_cmp);

		// 找出GPA排名前百分之x的学生
		int top_x_count = (int)(count * EXCELLENCE_RATE);

		// 打印出这些学生的缩略信息
		printf("Total %d, Top %d students:\n", count, top_x_count);
		for (int i = 0; i < count; i++) {
			printf("No. %d, ID: %s, Name: %s, GPA: %.2f, Rank: %.1f%%\n",
			       i + 1, sorted_students[i]->id, sorted_students[i]->name,
			       gpa(sorted_students[i]), (i + 1) * 100 / (double)count);
		}

		free(sorted_students);
	}
	else if (choice == 2) {
		// 遍历所有学生的所有课程，找到相同课程名的课程，存储在一个数组中，然后对数组进行排序
		// 为了方便排序，先统计学生总数
		Student* student = get_students();
		int count = 0;
		while (student != NULL) {
			count++;
			student = student->next;
		}
		Student** sorted_students = (Student**)malloc(sizeof(Student*) * count);
		student = get_students(); // 指向恢复到头部
		char course_name[50];
		safe_print("input course name>");
		scanf("%s", course_name);
		count = 0;
		for (int i = 0; student; student = student->next) {
			Course* course = find_course(student, course_name);
			if (course != NULL) {
				count++;
				// 新建一个临时学生，只指向这个课程
				Student* temp = (Student*)malloc(sizeof(Student));
				strcpy(temp->id, student->id);
				strcpy(temp->name, student->name);
				temp->courses = course;
				sorted_students[i++] = temp;
			}
		}
		qsort(sorted_students, count, sizeof(Student*), score_cmp);
		// 打印出这些学生的缩略信息
		printf("Total %d students:\n", count);
		for (int i = 0; i < count; i++) {
			printf("No. %d, ID: %s, Name: %s, Score: %.2f, Point: %.1f\n",
			       i + 1, sorted_students[i]->id, sorted_students[i]->name,
			       sorted_students[i]->courses->score, point(sorted_students[i]->courses->score));
		}
		// 释放临时学生以及之中的课程
		for (int i = 0; i < count; i++) {
			free(sorted_students[i]);
		}
		free(sorted_students);
	}
	else {
		print_to_bottom(RED"input error!"ENDCOLOR);
	}
}

static int cmpBySingleStudentCourseScore(const void* a, const void* b) {
	Course* course1 = *(Course**)a;
	Course* course2 = *(Course**)b;
	if (course1->score > course2->score) return -1;
	else if (course1->score < course2->score) return 1;
	else return 0;
}

static void sort_u(Student* student) {
	// 把这个学生的所有课程放在课程数组里排序
	Course* course = student->courses;
	int count = 0;
	while (course != NULL) {
		count++;
		course = course->next;
	}
	Course** sorted_courses = (Course**)malloc(sizeof(Course*) * count);
	course = student->courses; // 指向恢复到头部
	for(int i = 0; i < count && course; i++) {
		sorted_courses[i] = course;
		course = course->next;
	}
	qsort(sorted_courses, count, sizeof(Course*), cmpBySingleStudentCourseScore);
	// 打印出这些课程的缩略信息
	printf("Total %d courses:\n", count);
	for (int i = 0; i < count; i++) {
		printf("No. %d, Course: %s, Score: %.2f, Point: %.1f\n",
		       i + 1, sorted_courses[i]->name, sorted_courses[i]->score, point(sorted_courses[i]->score));
	}
	free(sorted_courses);
}

static void excellence() {
	// 计算所有学生的GPA并存储在一个数组中
	// 为了方便排序，先统计学生总数
	Student* student = get_students();
	int count = 0;
	while (student != NULL) {
		count++;
		student = student->next;
	}
	Student** sorted_students = (Student**)malloc(sizeof(Student*) * count);
	student = get_students(); // 指向恢复到头部
	for(int i = 0; i < count && student; i++) {
		sorted_students[i] = student;
		student = student->next;
	}

	// 对数组进行排序
	qsort(sorted_students, count, sizeof(Student*), gpa_cmp);

	// 找出GPA排名前百分之x的学生
	int top_x_count = (int)(count * EXCELLENCE_RATE);

	// 打印出这些学生的缩略信息
	printf("Total %d, Top %d students:\n", count, top_x_count);
	for (int i = 0; i < count; i++) {
		if(i < top_x_count)
			printf(GREEN"No. %d, ID: %s, Name: %s, GPA: %.2f, Rank: %.1f%%\n"ENDCOLOR,
				   i + 1, sorted_students[i]->id, sorted_students[i]->name,
				   gpa(sorted_students[i]), (i + 1) * 100 / (double)count);
		else
			printf("No. %d, ID: %s, Name: %s, GPA: %.2f, Rank: %.1f%%\n",
				   i + 1, sorted_students[i]->id, sorted_students[i]->name,
				   gpa(sorted_students[i]), (i + 1) * 100 / (double)count);
	}

	free(sorted_students);
}

static void forewarning() {
	// 计算所有学生的GPA并存储在一个数组中
	// 为了方便排序，先统计学生总数
	Student* student = get_students();
	int count = 0;
	while (student != NULL) {
		count++;
		student = student->next;
	}
	Student** sorted_students = (Student**)malloc(sizeof(Student*) * count);
	student = get_students(); // 指向恢复到头部
	count = 0;
	for(int i = 0; student; student = student->next) {
		if (is_warning(student)) {
			sorted_students[i++] = student;
			count++;
		}
	}

	// 对数组进行排序
	qsort(sorted_students, count, sizeof(Student*), gpa_cmp);
	// 逆序数组
	for (int i = 0; i < count / 2; i++) {
		Student* temp = sorted_students[i];
		sorted_students[i] = sorted_students[count - i - 1];
		sorted_students[count - i - 1] = temp;
	}

	// 打印出这些学生的缩略信息
	printf("Total %d students:\n", count);
	for (int i = 0; i < count; i++) {
		printf(RED"No. %d, ID: %s, Name: %s, GPA: %.2f\n"ENDCOLOR,
		       i + 1, sorted_students[i]->id, sorted_students[i]->name,
		       gpa(sorted_students[i]));
	}

	free(sorted_students);
}

int main() {
	char* login_name = (char*)malloc(sizeof(char) * 50);
	memset(login_name, 0, sizeof(char) * 50);
	enum Privilege p = login(PWD_FILE, login_name);
	if (p == WRONG) {
		print_to_bottom(RED"the account name or password is incorrect!"ENDCOLOR);
		exitcode = 3;
		goto error;
	}
	else if (p == FAILED) {
		print_to_bottom(RED"login failed!"ENDCOLOR);
		exitcode = 3;
		goto error;
	}

	int ret = init_from_file(FILENAME);
	if (ret == -1) {
		print_to_bottom(RED"file not exists!"ENDCOLOR);
		exitcode = 1;
		goto error;
	}
	else if (ret == -2) {
		print_to_bottom(RED"file format error!"ENDCOLOR);
		exitcode = 2;
		goto error;
	}
	else {
		print_to_bottom(GREEN"file loaded successfully!"ENDCOLOR);
	}

	if (p == ADMIN) {
		safe_print("Welcome admin, %s\n", login_name);
		int choice;
		do {
			menu_a();
		reEnter_a:
			safe_print("input please>");
			scanf("%d", &choice);
			clearScreen();
			switch (choice) {
				case ADD:add();break;
				case MODIFY:modify();break;
				case DELETE:delete();break;
				case QUERY:query();break;
				case SORT:sort();break;
				case EXCELLENCE:excellence();break;
				case FOREWARNING:forewarning();break;
				case DISPLAY:print_all();break;
				case EXIT:
					save_to_file(FILENAME);
					print_to_bottom(GREEN"file saved successfully!"ENDCOLOR);
					break;
				default:
					print_to_bottom(RED"Input error, please re-enter!"ENDCOLOR);
					goto reEnter_a;
			}
		} while (choice);
	}
	else { // USER
		safe_print("Welcome user, %s\n", login_name);
		Student* student = find_student_by_name(login_name);
		if (student == NULL) {
			print_to_bottom(RED"student's data not exists, auto exit!"ENDCOLOR);
			exitcode = 4;
			goto error;
		}
		int choice;
		char c;
		char course_name[50];
		do {
			menu_u();
		reEnter_u:
			safe_print("input please>");
			scanf("%d", &choice);
			clearScreen();
			switch (choice) {
				case QUERY:
					safe_print("continue query course?(y/n)");
					scanf(" %c", &c);
					if (c == 'y' || c == 'Y') {
						safe_print("input course name>");
						scanf("%s", course_name);
						Course* course = find_course(student, course_name);
						if (course == NULL) {
							print_to_bottom(RED"course not exists!"ENDCOLOR);
							break;
						}
						print_course(course);
					}
					else {
						print_stu(student);
					}
					break;
				case SORT:
					sort_u(student);
					break;
				case EXIT:
					save_to_file(FILENAME);
					print_to_bottom(GREEN"file saved successfully!"ENDCOLOR);
					break;
				default:
					print_to_bottom(RED"Input error, please re-enter!"ENDCOLOR);
					goto reEnter_u;
			}
		} while (choice);
	}

error:
	free(login_name);
	safe_print("bye!\n");
	getchar();getchar(); // 暂停
	return exitcode;
}