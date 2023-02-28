#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

int removeDuplicates(int* nums, int numsSize) {
    int src = 1;
    int dest = 1;
    while (src < numsSize) {
        if (nums[src] == nums[src - 1]) {
            src++;
            continue;
        }
        else {
            nums[dest] = nums[src];
            dest++;
            src++;
        }
    }
    return dest;
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int src1 = m - 1;
    int src2 = n - 1;
    int dest = m + n - 1;
    while (src1 >= 0 && src2 >= 0) {
        if (nums1[src1] > nums2[src2]) {
            nums1[dest] = nums1[src1];
            dest--;
            src1--;
        }
        else {
            nums1[dest] = nums2[src2];
            dest--;
            src2--;
        }
    }
    if (src2 >= 0) {
        memmove(nums1, nums2, sizeof(int) * (src2 + 1));
    }
}