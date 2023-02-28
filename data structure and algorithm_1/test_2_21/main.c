#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

int removeElement(int* nums, int numsSize, int val) {
    int ret = numsSize;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == val) {
            //交换最后一个非val数
            int j, tmp, flag = 0;
            for (j = ret - 1; j > i; j--) {
                if (nums[j] != val) {
                    tmp = nums[j];
                    flag = 1;
                    break;
                }
            }
            //判断是否全部遍历,代表没有找到非val数
            if (flag == 0) {
                return i;
            }
            //交换
            nums[j] = nums[i];
            nums[i] = tmp;
            tmp = nums[j];
            nums[j] = nums[ret - 1];
            nums[ret - 1] = tmp;
            //个数减一
            ret--;
        }
    }
    return ret;
}

int main() {
    SL nums = { 0 };
    SLinit(&nums);
    SLpushback(&nums, 1);
    SLpushback(&nums, 2);
    SLpushback(&nums, 3);
    SLpushback(&nums, 4);
    SLpushfront(&nums, 5);
    SLprint(&nums);
    SLpopfront(&nums);
    SLprint(&nums);
    SLerase(&nums, 2);
    SLprint(&nums);
    SLinsert(&nums, 1, 100);
    SLprint(&nums);
    printf("%d\n", SLfindpos(&nums, 100));

<<<<<<< HEAD
    SLdestory(&nums);

=======
>>>>>>> 椤哄簭琛╝ll finished
	return 0;
}