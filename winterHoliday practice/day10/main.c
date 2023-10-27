#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//第一题

int Add(int num1, int num2) {
    int and = (num1 & num2) << 1;
    int xor = num1 ^ num2;
    while (and & xor) {
        num1 = and;
        num2 = xor;
        and = (num1 & num2) << 1;
        xor = num1 ^ num2;
    }
    return and | xor;
}



//第二题

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int* arr = (int*)malloc(sizeof(int) * 1);
    assert(arr);
    int num = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    int tmp = nums[0];
    if (nums[0] != 1) {
        int j = nums[0] - 1;
        for (int i = 1; i < j + 1; i++) {
            num++;
            arr = (int*)realloc(arr, sizeof(int) * num);
            arr[num - 1] = i;
        }
    }
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i + 1] > nums[i])
            tmp++;
        if (nums[i + 1] == nums[i])
            continue;
        if (nums[i + 1] != tmp) {
            num++;
            arr = (int*)realloc(arr, sizeof(int) * num);
            arr[num - 1] = tmp;
            i--;
        }
        if (tmp > numsSize)
            break;
    }
    if (nums[numsSize - 1] != numsSize) {
        int j = numsSize - nums[numsSize - 1];
        for (int i = nums[numsSize - 1] + 1; i < nums[numsSize - 1] + 1 + j; i++) {
            num++;
            arr = (int*)realloc(arr, sizeof(int) * num);
            arr[num - 1] = i;
        }
    }
    *returnSize = num;
    return arr;
}