#include "sort.h"
int main() 
{
	int compare = 0, move = 0;
	int length = rand()%30+1;
	int *origin = (int*)malloc(length * sizeof(int));
	int *arr = (int*)malloc(length * sizeof(int));

	printf("����������ݣ�\n");
	input(origin, length);
	output(origin, length);
	printf("\n");

	printf("ֱ�Ӳ�������\n�����");
	originArray(arr, origin, length);
	InsertSort(arr, length, &compare, &move);
	output(arr, length);
	outTime(compare, move);

	printf("ϣ������\n�����");
	originArray(arr, origin, length);
	ShellSort(arr, length, &compare, &move);
	output(arr, length);
	outTime(compare, move);

	printf("��������\n�����");
	originArray(arr, origin, length);
	BubbleSort(arr, length, &compare, &move);
	output(arr, length);
	outTime(compare, move);
	
    compare = 0, move = 0;
	printf("��������\n�����");
	originArray(arr, origin, length);
	int left = 0, count = 0;
	QuickSort(arr,left,length-1,count, &compare, &move);
	output(arr, length);
	outTime(compare, move);

	printf("��ѡ������\n�����");
	originArray(arr, origin, length);
	SelectSort(arr, length, &compare, &move);
	output(arr, length);
	outTime(compare, move);
}