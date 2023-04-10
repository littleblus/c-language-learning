#pragma once

#include <stdbool.h>

//²åÈëÅÅĞò
void InsertSort(int* a, int n);

//Ï£¶ûÅÅĞò
void ShellSort(int* a, int n);

//Ñ¡ÔñÅÅĞò
void SelectSort(int* a, int n);

//¶ÑÅÅĞò
void AdjustDown(int* a, int parent, int n);
void HeapSort(int* a, int n);

//Ã°ÅİÅÅĞò
void BubbleSort(int* a, int n);

//¿ìËÙÅÅĞò
void QuickSort(int* a, int left, int right);
void QuickSortNonR(int* a, int left, int right);

//¹é²¢ÅÅĞò
void MergeSort(int* a, int n);
void MergeSortNonR(int* a, int n);

//¼ÆÊıÅÅĞò
void CountSort(int* a, int n);

//ºï×ÓÅÅĞò
void MonkeySort(int* a, int n);