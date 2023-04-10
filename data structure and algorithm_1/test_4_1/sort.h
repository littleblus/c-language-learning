#pragma once

#include <stdbool.h>

//��������
void InsertSort(int* a, int n);

//ϣ������
void ShellSort(int* a, int n);

//ѡ������
void SelectSort(int* a, int n);

//������
void AdjustDown(int* a, int parent, int n);
void HeapSort(int* a, int n);

//ð������
void BubbleSort(int* a, int n);

//��������
void QuickSort(int* a, int left, int right);
void QuickSortNonR(int* a, int left, int right);

//�鲢����
void MergeSort(int* a, int n);
void MergeSortNonR(int* a, int n);

//��������
void CountSort(int* a, int n);

//��������
void MonkeySort(int* a, int n);