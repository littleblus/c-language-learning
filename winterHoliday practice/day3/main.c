#define _CRT_SECURE_NO_WARNINGS 1

//第一题

//#include <stdio.h>
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr1[2000];
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &arr1[i]);
//	}
//	int count1 = 0;
//	int count2 = 0;
//	int sum = 0;
//	for (int i = 0; i < n; i++) {
//		if (arr1[i] < 0)
//			count1++;
//		if (arr1[i] > 0) {
//			sum += arr1[i];
//			count2++;
//		}
//	}
//	if (count2 != 0)
//		printf("%d %.1f\n", count1, (float)sum / count2);
//	else
//		printf("%d %.1f\n", count1, 0.0);
//
//	return 0;
//}



//第二题

int minNumberInRotateArray(int* rotateArray, int rotateArrayLen) {
    int left = 0;
    int right = rotateArrayLen - 1;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (rotateArray[mid] < rotateArray[right])
            right = mid;
        else if (rotateArray[mid] > rotateArray[right])
            left = mid + 1;
        else
            right -= 1;
    }
    return rotateArray[left];
}

#define SZ 2
#include <stdio.h>
int main()
{
	freopen("input.txt", "r", stdin);
	int arr[SZ];
	for (int i = 0; i < SZ; i++) {
		scanf("%d", &arr[i]);
	}
	printf("%d\n", minNumberInRotateArray(arr, sizeof(arr) / sizeof(arr[0])));

	return 0;
}