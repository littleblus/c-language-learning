#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <string.h>
//
////将一句话的单词进行倒置，标点不倒置
//void reverse(char* pa, char* pb)
//{
//    char tmp = 0;
//    while (pa < pb) {
//        tmp = *pa;
//        *pa = *pb;
//        *pb = tmp;
//        pa++;
//        pb--;
//    }
//}
//
//int main()
//{
//    char str[100] = { 0 };
//    gets(str);
//    char* pa = str;
//    int sz = strlen(str);
//    char* pb = str + sz - 1;
//    reverse(pa, pb);
//    //char* s = str;
//    //for (int i = 0; i <= sz; i++) {
//    //    if (str[i] == ' ' || str[i] == '\0') {
//    //        reverse(s, str + i - 1);
//    //        s = str + i + 1;
//    //    }
//    //}
//    printf("%s", str);
//
//    return 0;
//}