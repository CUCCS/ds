#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Sort.h"

#define ShowTimes() printf("compareTime : \t%d\nmoveTime : \t%d\ntotal : \t%d\n\n",compareTime,moveTime,compareTime+moveTime);
/*���ɲ�������*/
void GenTestInputs(RecordType*arr, int size) {
	for (int i = 0; i < size; ++i) {
		arr[i].key = rand() % 90 + 10;
		arr[i].data = -1;
	}
}
void CopyArr(RecordType* dest, const RecordType* source, int size) {
	for (int i = 0; i < size; ++i) {
		dest[i] = source[i];
	}
}
int main() {
	srand(time(0) ^ rand());
	int compareTime = 0, moveTime = 0;
	const int length = rand() % 5 ? rand() % 9 + 1 : rand() % 19 + 80;
	RecordType* origin = (RecordType*)malloc(length * sizeof(RecordType));
	RecordType* arr = (RecordType*)malloc(length * sizeof(RecordType));
	GenTestInputs(origin, length);

	printf("��Before sort��\n");
	ShowArr(origin, length);
	printf("\n");

	/*��������*/
	printf("��After InsertSort��\n");
	CopyArr(arr, origin, length);
	InsertSort(arr, length, &compareTime, &moveTime);
	ShowArr(arr, length);
	ShowTimes();

	/*ϣ������*/
	printf("��After ShellSort��\n");
	CopyArr(arr, origin, length);
	ShellSort(arr, length, &compareTime, &moveTime);
	ShowArr(arr, length);
	ShowTimes();

	/*ð������*/
	printf("��After BubbleSort��\n");
	CopyArr(arr, origin, length);
	BubbleSort(arr, length, &compareTime, &moveTime);
	ShowArr(arr, length);
	ShowTimes();

	/*��������*/
	printf("��After QuickSort��\n");
	CopyArr(arr, origin, length);
	QuickSort(arr, length, &compareTime, &moveTime);
	ShowArr(arr, length);
	ShowTimes();

	/*ѡ������*/
	printf("��After SelectSort��\n");
	CopyArr(arr, origin, length);
	SelectSort(arr, length, &compareTime, &moveTime);
	ShowArr(arr, length);
	ShowTimes();

	/*������*/
	printf("��After HeapSort��\n");
	CopyArr(arr, origin, length);
	HeapSort(arr, length, &compareTime, &moveTime);
	ShowArr(arr, length);
	ShowTimes();

	/*�鲢����*/
	printf("��After MergeSort��\n");
	CopyArr(arr, origin, length);
	MergeSort(arr, length, &compareTime, &moveTime);
	ShowArr(arr, length);
	ShowTimes();

}