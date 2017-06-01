#pragma once
#include <stdio.h>


typedef int KeyType;
typedef int DataType;
typedef struct _RecordType {
	KeyType key;
	DataType data;
} RecordType;

void ShowArr(RecordType* arr, int length) {
	for (int i = 0; i < length; ++i) {
		printf("%d ", arr[i].key);
	}
	printf("\n");
}
void _InsertSort(RecordType*arr, int length, int delta, int * ct, int* mt) {
	RecordType temp;
	for (int i = delta; i < length; i += delta) {
		temp = arr[i];
		int j = i;
		while (++*ct, arr[j - delta].key > temp.key && j > 0) {
			arr[j] = arr[j - delta];
			j -= delta;
			++*mt;
		}
		arr[j] = temp;
		++*mt;
	}
}
void InsertSort(RecordType*arr, int length, int * ct, int* mt) {
	*ct = *mt = 0;
	_InsertSort(arr, length, 1, ct, mt);
}
void ShellSort(RecordType*arr, int length, int * ct, int* mt) {
	*ct = *mt = 0;
	int d = length / 2;
	while (d >= 1) {
		//printf("d = %d \n",d);
		for (int i = 0; i < d; ++i) {
			_InsertSort(arr + i, length - i, d, ct, mt);
		}
		//ShowArr(arr, length);
		d /= 2;
	}
}
void BubbleSort(RecordType*arr, int length, int *ct, int* mt) {
	*ct = *mt = 0;
	for (int end = length - 1; end > 0; --end) {
		for (int i = 0; i < end; ++i) {
			if (++*ct, arr[i].key > arr[i + 1].key) {
				RecordType temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				(*mt) += 3;
			}
		}
	}
}
void _QuickSort(RecordType*arr, int length, int *ct, int* mt) {
	RecordType pivot = arr[0];
	if (length <= 1)return;
	//printf("SortArr : ");
	//ShowArr(arr, length);
	int i = 1, j = length - 1;
	while (j >= i) {
		while (++*ct, arr[i].key <= pivot.key && j >= i)++i;
		while (++*ct, arr[j].key > pivot.key && j >= i)--j;
		if (j < i) {
			//printf("Swap %d and %d\n", arr[0].key, arr[j].key);
			RecordType temp = arr[0];
			arr[0] = arr[j];
			arr[j] = temp;
			(*mt) += 1;
			break;
		}
		//printf("Swap %d and %d\n", arr[i].key, arr[j].key);
		RecordType temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		(*mt) += 3;
	}
	//printf("AfterSort : ");
	//ShowArr(arr, length);
	_QuickSort(arr, j, ct, mt);
	_QuickSort(arr + j + 1, length - j - 1, ct, mt);
}
void QuickSort(RecordType*arr, int length, int *ct, int* mt) {
	*ct = *mt = 0;
	_QuickSort(arr, length, ct, mt);
}
void _SelectSort(RecordType*arr, int length, int *ct, int* mt) {
	int id = 0;
	for (int i = 1; i < length; ++i) {
		if (++*ct,arr[i].key < arr[id].key) {
			id = i;
		}
	}
	RecordType temp = arr[0];
	arr[0] = arr[id];
	arr[id] = temp;
	++*mt;
}
void SelectSort(RecordType*arr, int length, int *ct, int* mt) {
	*ct = *mt = 0;
	for (int i = 0; i < length - 1; ++i) {
		_SelectSort(arr+i, length-i, ct, mt);
	}
}