#pragma once

#include <stdbool.h>

//≤Â»Î≈≈–Ú
void InsertSort(int* a, int n);

//œ£∂˚≈≈–Ú
void ShellSort(int* a, int n);

//—°‘Ò≈≈–Ú
void SelectSort(int* a, int n);

//∂—≈≈–Ú
void AdjustDown(int* a, int parent, int n);
void HeapSort(int* a, int n);

//√∞≈›≈≈–Ú
void BubbleSort(int* a, int n);

//øÏÀŸ≈≈–Ú
void QuickSort(int* a, int left, int right);
void QuickSortNonR(int* a, int left, int right);

//πÈ≤¢≈≈–Ú
void MergeSort(int* a, int n);
void MergeSortNonR(int* a, int n);

//∫Ô◊”≈≈–Ú
void MonkeySort(int* a, int n);