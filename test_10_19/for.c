#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//单位阶跃函数
//int main() {
//    int a = 0;
//    while (scanf("%d", &a) != EOF) {
//        if (a > 0) printf("1\n");
//        else if (a == 0) printf("0.5\n");
//        else printf("0\n");
//    }
//    return 0;
//}


//时间转换
//int main() {
//    int sec = 0;
//    scanf("%d", &sec);
//    int h, m, s;
//    h = sec / 3600;
//    m = (sec % 3600) / 60;
//    s = (sec % 3600) % 60;
//    printf("%d %d %d", h, m, s);
//
//    return 0;
//}



//线段图案（for循环的使用）
//int main()
//{
//    int a = 0;
//    while (scanf("%d", &a) != EOF) {
//        for (int i = 0; i < a; i++) {
//            printf("*");
//        }
//        printf("\n");
//    }
//    return 0;
//}

//班级成绩输入输出（小数点的保留）
int main() {
    float a, b, c, d, e;
    while (scanf("%f %f %f %f %f", &a, &b, &c, &d, &e) != EOF) {
        printf("%.1f %.1f %.1f %.1f %.1f %.1f\n", a, b, c, d, e, a + b + c + d + e);
    }
    return 0;
}
