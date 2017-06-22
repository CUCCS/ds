#include "Sort.h"
int main()
{
	srand(time(0));
	int length = rand() % 9 + 2;
	RecordType *counts;
	RecordType *count;
	counts = (RecordType*)malloc(length*(sizeof(RecordType)));
	count = (RecordType*)malloc(length*(sizeof(RecordType)));
	int mov_count = 0;
	int cmp_count = 0;
	int i;
	for (i = 0; i < length; i++)
	{
		int a = rand() % 9 + 1;
		counts[i].key = a;
		counts[i].data = 0;
	}
	for (i = 0; i < length; i++)
	{
		printf("%d ", counts[i]);
	}

	/*=========ֱ�Ӳ����������=========*/
	printf("\nֱ�Ӳ�������\n");
	Inital(counts, count, length, &cmp_count, &mov_count);
	InsSort(count, length, &cmp_count, &mov_count);
	print(count, length, cmp_count, mov_count);
	/*==========ϣ���������=========*/
	printf("ϣ������\n");
	Inital(counts, count, length, &cmp_count, &mov_count);
	ShellSort(count, length, &cmp_count, &mov_count);
	print(count, length, cmp_count, mov_count);
	/*=========ð���������=========*/
	printf("ð������\n");
	Inital(counts, count, length, &cmp_count, &mov_count);
	BubbleSort(count, length, &cmp_count, &mov_count);
	print(count, length, cmp_count, mov_count);
	/*=========�����������=========*/
	printf("��������\n");
	Inital(counts, count, length, &cmp_count, &mov_count);
	QKSort(count, 0, length - 1, &cmp_count, &mov_count);
	print(count, length, cmp_count, mov_count);
	/*=========��ѡ������=========*/
	printf("��ѡ������\n");
	Inital(counts, count, length, &cmp_count, &mov_count);
	SelectSort(count, length, &cmp_count, &mov_count);
	print(count, length, cmp_count, mov_count);
}

