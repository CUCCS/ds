#include "sort.h"

void input(RecordType*r, int length)
{
	for (int i = 0; i < length; ++i) 
	{
		r[i].key = rand() % 100 + 10;
	}
}

void Print(RecordType *r, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", r[i].key);
	}
	printf("\n");
}

void Showtimes(int *compare,int *move)
{
	printf("compareTimes : %d\n", compare);
	printf("moveTimes : %d\n", move);
}

void CopyArr(RecordType* dest, const RecordType* source, int length) 
{
	for (int i = 0; i < length; ++i) 
	{
		dest[i] = source[i];
	}
}
int main()
{
		srand(time(0));
		int compare = 0, move = 0;
		int length = rand() % 15 + 5;   //随机生成数组长度
		RecordType* origin = (RecordType*)malloc(length * sizeof(RecordType));
		RecordType* r = (RecordType*)malloc(length * sizeof(RecordType));

		input(origin, length);
		printf("------Before sort------\n");
		Print(origin, length);   //生成一组待排序数据
                    
		printf("\n------After InsertSort------\n");
		CopyArr(r, origin, length);
		InsertSort(r, length, &compare, &move);
		Print(r, length);
		Showtimes(compare, move);

		printf("\n------After ShellSort------\n");
		CopyArr(r, origin, length);
		ShellSort(r, length, &compare, &move);
		Print(r, length);
		Showtimes(compare, move);

		printf("\n------After BubbleSort------\n");
		CopyArr(r, origin, length);
		BubbleSort(r, length, &compare, &move);
		Print(r, length);
		Showtimes(compare, move);

		printf("\n------After QuickSort------\n");
		CopyArr(r, origin, length);
		QuickSort(r, length, &compare, &move);
		Print(r, length);
		Showtimes(compare, move);

		printf("\n------After SelectSort------\n");
		CopyArr(r, origin, length);
		SelectSort(r, length, &compare, &move);
		Print(r, length);
		Showtimes(compare, move);
	return 0;

}