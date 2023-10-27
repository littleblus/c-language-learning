#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 第一题

int min(const int a, const int b) {
    return a > b ? b : a;
}

int* masterMind(char* solution, char* guess, int* returnSize) {
    int* arr = (int*)calloc(2, sizeof(int));
    if (arr == NULL) {
        perror("masterMind:calloc");
        return NULL;
    }
    int count = 0;
    int rs = 0;
    int ys = 0;
    int gs = 0;
    int bs = 0;
    int rg = 0;
    int yg = 0;
    int gg = 0;
    int bg = 0;
    for (int i = 0; i < 4; i++) {
        if (solution[i] == guess[i])
            arr[0]++;
    }
    for (int i = 0; i < 4; i++) {
        if (solution[i] == 'R')
            ++rs;
        else if (solution[i] == 'G')
            ++gs;
        else if (solution[i] == 'B')
            ++bs;
        else if (solution[i] == 'Y')
            ++ys;
    }
    for (int i = 0; i < 4; i++) {
        if (guess[i] == 'R')
            ++rg;
        else if (guess[i] == 'G')
            ++gg;
        else if (guess[i] == 'B')
            ++bg;
        else if (guess[i] == 'Y')
            ++yg;
    }
    count = min(rs, rg) + min(ys, yg) + min(gs, gg) + min(bs, bg);
    arr[1] = count - arr[0];
    *returnSize = 2;
    return arr;
}

// 第二题

int* twoSum(int* numbers, int numbersLen, int target, int* returnSize) {
    int* arr = (int*)calloc(2, sizeof(int));
    if (arr == NULL) {
        perror("twoSum:calloc");
        return NULL;
    }
    int sum = 0;
    int flag = 0; // 处理负数相加情况，此时不跳过
    for (int i = 0; i < numbersLen; i++) {
        flag = 0;
        if (numbers[i] > target)
            continue;
        if (numbers[i] < 0)
            flag = 1;
        for (int j = i + 1; j < numbersLen; j++) {
            if (numbers[j] > target && flag == 0)
                continue;
            if (numbers[i] + numbers[j] == target) {
                arr[0] = i + 1;
                arr[1] = j + 1;
                i = numbersLen;
                break;
            }
        }
    }
    *returnSize = 2;
    return arr;
}

int main() {
    int arr[] = { -3, 4, 3, 90 };
    int num = 0;
    int* ret = twoSum(arr, 4, 0, &num);
    for (int i = 0;i < 2;i++) {
        printf("%d ", ret[i]);
    }

    return 0;
}