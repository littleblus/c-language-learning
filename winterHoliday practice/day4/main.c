#define _CRT_SECURE_NO_WARNINGS 1

//第一题

int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    //冒泡排序
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsSize - 1 - i; j++) {
            //交换
            if (nums[j] > nums[j + 1]) {
                int tmp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = tmp;
            }
        }
    }
    *returnSize = 2;
    int* ret = malloc(sizeof(int) * 2);
    //查看数组中是否有1，若没有1，则缺失的数字是1
    int flag1 = 0;
    int flag2 = 0;
    int tmp = 0;
    if (nums[0] == 1)
        flag1 = 1;
    for (int i = 0; i < numsSize - 1; i++) {
        //查找重复的数字
        if (nums[i] == nums[i + 1]) {
            tmp = i;
            ret[0] = nums[i];
            if (i == 0 && flag1 == 1)
                ret[1] = nums[i] + 1;
            if (i >= 1) {
                if (nums[i] == nums[i - 1] + 1)
                    ret[1] = nums[i] + 1;
                if (nums[i] == nums[i - 1] + 2)
                    ret[1] = nums[i] - 1;
            }
            //若出现型为4 5 5 6，则分别查找重复前后确定缺失的数字
            //1 1 2
            //8 9 9
            if (numsSize >= 4 && i >= 1 && i <= numsSize - 2 && nums[i - 1] + 1 == nums[i] && nums[i + 2] - 1 == nums[i])
                flag2 = 1;
            if (numsSize >= 4 && i == 0 && nums[2] - 1 == nums[i])
                flag2 = 1;
            if (numsSize >= 4 && i == numsSize - 2 && nums[numsSize - 3] + 1 == nums[i])
                flag2 = 1;
        }
    }
    //查找数组中是否出现过预计缺失的数字，若出现，则缺失的数字为n
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == ret[1]) {
            ret[1] = nums[numsSize - 1] + 1;
            break;
        }
    }
    //4556型
    if (flag2 == 1) {
        for (int i = 0; i < tmp; i++) {
            if (nums[i] != i + 1) {
                ret[1] = i + 1;
                goto end;
            }
        }
        for (int i = tmp + 2; i < numsSize; i++) {
            if (nums[i] != i) {
                ret[1] = i;
                goto end;
            }
        }
    }
end:
    if (flag1 == 0)
        ret[1] = 1;
    return ret;
}



//第二题

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    char psd[100] = { 0 };
    for (int i = 0; i < n; i++) {
        scanf("%s", &psd);
        //不能以数字开头
        if (isdigit(psd[0]) != 0) {
            printf("NO\n");
            continue;
        }
        //密码长度至少为8
        if (strlen(psd) < 8) {
            printf("NO\n");
            continue;
        }
        //大写字母，小写字母，数字中的两种
        int flag1 = 0;
        int flag2 = 0;
        int flag3 = 0;
        for (int i = 0; i < strlen(psd); i++) {
            if (flag1 == 0 && isupper(psd[i]) != 0)
                flag1++;
            if (flag2 == 0 && islower(psd[i]) != 0)
                flag2++;
            if (flag3 == 0 && isdigit(psd[i]) != 0)
                flag3++;
        }
        if (flag1 + flag2 + flag3 >= 2)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}