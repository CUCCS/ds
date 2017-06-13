#include <stdio.h>
#include <stdlib.h>
#include "Sort.h"
#define min(a,b) ((a)<(b) ? (a) : (b))


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
			(*mt) += 3;
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
		if (++*ct, arr[i].key < arr[id].key) {
			id = i;
		}
	}
	RecordType temp = arr[0];
	arr[0] = arr[id];
	arr[id] = temp;
	(*mt) += 3;
}
void SelectSort(RecordType*arr, int length, int *ct, int* mt) {
	*ct = *mt = 0;
	for (int i = 0; i < length - 1; ++i) {
		_SelectSort(arr + i, length - i, ct, mt);
	}
}

int getLeft(int id, int length) {
	id = 2 * id + 1;
	return id < 0 || id >= length ? -1 : id;
}
int getRight(int id, int length) {
	id = 2 * id + 2;
	return id < 0 || id >= length ? -1 : id;
}
void CreateHeap(RecordType* arr, int size, int*ct, int*mt) {
	int left, right, toSwap = -1;
	for (int j = size / 2 - 1; j >= 0; --j) {
		int current = j;
		do {
			//ShowArr(temp, size);
			//printf("当前元素 : 第%2d个元素%2d\n",current+1,temp[current]);
			left = getLeft(current, size);
			right = getRight(current, size);
			//printf(left == -1 ? "它没有左孩子\n" : "它的左孩子为%d\n", left == -1 ? 999 : temp[left].key);
			//printf(right == -1 ? "它没有右孩子\n" : "它的右孩子为%d\n", right == -1 ? 999 : temp[right].key);
			++*ct;
			if (left == -1 && right != -1)toSwap = right;
			else if (left != -1 && right == -1)toSwap = left;
			else if (left != -1 && right != -1)toSwap = arr[left].key < arr[right].key ? left : right;
			if (arr[toSwap].key >= arr[current].key)toSwap = -1;
			if (toSwap == -1)break;
			RecordType t = arr[current];
			arr[current] = arr[toSwap];
			arr[toSwap] = t;
			(*mt) += 3;
			current = toSwap;
			toSwap = -1;
		} while (1);
	}//end for
}
void _HeapSort(RecordType* arr, int length, int*ct, int* mt) {
	if (length <= 1)return;
	CreateHeap(arr, length, ct, mt);
	_HeapSort(arr + 1, length - 1, ct, mt);
}
void HeapSort(RecordType* arr, int length, int*ct, int* mt) {
	*ct = *mt = 0;
	_HeapSort(arr, length, ct, mt);
}

/*合并一个数组中的两个有序部分*/
void _Merge(RecordType* left, RecordType*right, RecordType* end, int*ct, int*mt) {
	//printf(__FUNCTION__);
	//ShowArr(left, end - left + 1);
	RecordType* temp = (RecordType*)malloc((end - left + 1) * sizeof(RecordType));
	RecordType* pl = left, *pr = right, *p = temp;
	while (pl < right && pr <= end) {
		if (++*ct, pl->key < pr->key) {
			*p = *pl; ++p; ++pl;
			++*mt;
		}
		else {
			*p = *pr; ++p; ++pr;
			++*mt;
		}
	}
	while (pl < right) {
		*p = *pl; ++p; ++pl;
		++*mt;
	}
	while (pr <= end) {
		*p = *pr; ++p; ++pr;
		++*mt;
	}
	--p;
	while (p >= temp) {
		left[p - temp] = *p;
		--p;
		++*mt;
	}
}
void _MergeSort(RecordType* arr, int length, int *ct, int* mt) {
	//printf(__FUNCTION__);
	//ShowArr(arr, length);
	if (length >= 3) {
		_MergeSort(arr, length / 2, ct, mt);
		_MergeSort(arr + length / 2, length - length / 2, ct, mt);
	}
	_Merge(arr, arr + length / 2, arr + length - 1, ct, mt);
	//ShowArr(arr, length);
}
void MergeSort(RecordType* arr, int length, int *ct, int* mt) {
	*ct = *mt = 0;
	_MergeSort(arr, length, ct, mt);
}