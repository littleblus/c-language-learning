#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>

//第一题

int main() {
	char num[11];
	scanf("%s", num);
	//逆序
	int len = strlen(num);
	int left = 0;
	int right = len - 1;
	while (left < right) {
		char tmp = num[left];
		num[left] = num[right];
		num[right] = tmp;
		left++;
		right--;
	}
	printf(num);

	return 0;
}



//第二题

//scanf界定读入法
int main() {
    char str[100][22];
    int i = 0;
    int x;
    while (1) {
        x = scanf("%[a-z|A-Z]", str[i]);
        if (getchar() == '\n')
            break;
        if (x)
            i++;
    }
    for (int j = i; j >= 0; j--) {
        printf("%s ", str[j]);
    }

    return 0;
}

//双指针法
int main()
{
    char s[10000];
    gets(s);
    int len = strlen(s);
    int p1 = len - 1, p2 = len;
    while (p1 >= 0)
    {
        while (p1 >= 0 && !isalpha(s[p1]))
            p1--;
        p2 = p1;
        while (p1 >= 0 && isalpha(s[p1]))
            p1--;
        for (int i = p1 + 1; i <= p2; i++)
            printf("%c", s[i]);
        printf(" ");
    }

    return 0;
}
