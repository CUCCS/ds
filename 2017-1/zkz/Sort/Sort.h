#pragma once

typedef int KeyType;
typedef int DataType;
typedef struct _RecordType {
	KeyType key;
	DataType data;
} RecordType;

void ShowArr(RecordType* arr, int length);
void InsertSort(RecordType*arr, int length, int * ct, int* mt);
void ShellSort(RecordType*arr, int length, int * ct, int* mt);
void BubbleSort(RecordType*arr, int length, int *ct, int* mt);
void QuickSort(RecordType*arr, int length, int *ct, int* mt);
void SelectSort(RecordType*arr, int length, int *ct, int* mt);
void HeapSort(RecordType* arr, int length, int*ct, int* mt);
void MergeSort(RecordType* arr, int length, int *ct, int* mt);