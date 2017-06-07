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

	/*=========Ö±½Ó²åÈëÅÅÐòÊä³ö=========*/
	printf("\nÖ±½Ó²åÈëÅÅÐò£º\n");
	Inital(counts, count, length, &cmp_count, &mov_count);
	InsSort(count, length, &cmp_count, &mov_count);
	print(count, length, cmp_count, mov_count);
	/*==========Ï£¶ûÅÅÐòÊä³ö=========*/
	printf("Ï£¶ûÅÅÐò£º\n");
	Inital(counts, count, length, &cmp_count, &mov_count);
	ShellSort(count, length, &cmp_count, &mov_count);
	print(count, length, cmp_count, mov_count);
	/*=========Ã°ÅÝÅÅÐòÊä³ö=========*/
	printf("Ã°ÅÝÅÅÐò£º\n");
	Inital(counts, count, length, &cmp_count, &mov_count);
	BubbleSort(count, length, &cmp_count, &mov_count);
	print(count, length, cmp_count, mov_count);
	/*=========¿ìËÙÅÅÐòÊä³ö=========*/
	printf("¿ìËÙÅÅÐò£º\n");
	Inital(counts, count, length, &cmp_count, &mov_count);
	QKSort(count, 0, length - 1, &cmp_count, &mov_count);
	print(count, length, cmp_count, mov_count);
	/*=========¼òµ¥Ñ¡ÔñÅÅÐò=========*/
	printf("¼òµ¥Ñ¡ÔñÅÅÐò£º\n");
	Inital(counts, count, length, &cmp_count, &mov_count);
	SelectSort(count, length, &cmp_count, &mov_count);
	print(count, length, cmp_count, mov_count);
}

