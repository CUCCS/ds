#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Sort.h"
int main() {
	int a[20], b[20], i;
	srand(time(NULL));
	for (i = 1; i < len + 1; i++) {
		a[i] = rand() % 128;
		b[i] = a[i];
	}
	int cCount = 0, mCount = 0;//记录比较次数和移动次数
	PrintArray(a, len, mCount, cCount);

	printf("\n希尔排序: ");
	ShellSort(a, len, &mCount, &cCount);
	PrintArray(a, len, mCount, cCount);

	printf("\n直接插入排序: ");
	for (i = 1; i < len + 1; i++) {
		a[i] = b[i];
	}
	cCount = 0;
	mCount = 0;
	InsSort(a, len, &mCount, &cCount);
	PrintArray(a, len, mCount, cCount);

	printf("\n冒泡排序: ");
	for (i = 1; i < len + 1; i++) {
		a[i] = b[i];
	}
	cCount = 0, mCount = 0;
	BubbleSort(a, len, &mCount, &cCount);
	PrintArray(a, len, mCount, cCount);

	printf("\n快速排序: ");
	for (i = 1; i < len + 1; i++) {
		a[i] = b[i];
	}
	cCount = 0, mCount = 0;
	QKSort(a, 1, len, &mCount, &cCount);
	PrintArray(a, len, mCount, cCount);

	printf("\n选择排序: ");
	for (i = 1; i < len + 1; i++) {
		a[i] = b[i];
	}
	cCount = 0, mCount = 0;
	SelectSort(a, len, &mCount, &cCount);
	PrintArray(a, len, mCount, cCount);

	return 0;
}