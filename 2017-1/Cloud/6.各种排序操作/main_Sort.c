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
	int cCount = 0, mCount = 0;//��¼�Ƚϴ������ƶ�����
	PrintArray(a, len, mCount, cCount);

	printf("\nϣ������: ");
	ShellSort(a, len, &mCount, &cCount);
	PrintArray(a, len, mCount, cCount);

	printf("\nֱ�Ӳ�������: ");
	for (i = 1; i < len + 1; i++) {
		a[i] = b[i];
	}
	cCount = 0;
	mCount = 0;
	InsSort(a, len, &mCount, &cCount);
	PrintArray(a, len, mCount, cCount);

	printf("\nð������: ");
	for (i = 1; i < len + 1; i++) {
		a[i] = b[i];
	}
	cCount = 0, mCount = 0;
	BubbleSort(a, len, &mCount, &cCount);
	PrintArray(a, len, mCount, cCount);

	printf("\n��������: ");
	for (i = 1; i < len + 1; i++) {
		a[i] = b[i];
	}
	cCount = 0, mCount = 0;
	QKSort(a, 1, len, &mCount, &cCount);
	PrintArray(a, len, mCount, cCount);

	printf("\nѡ������: ");
	for (i = 1; i < len + 1; i++) {
		a[i] = b[i];
	}
	cCount = 0, mCount = 0;
	SelectSort(a, len, &mCount, &cCount);
	PrintArray(a, len, mCount, cCount);

	return 0;
}