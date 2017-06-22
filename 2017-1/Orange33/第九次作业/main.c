#include "sort.h"
int main() 
{
	int compare = 0, move = 0;
	int length = rand()%30+1;
	int *origin = (int*)malloc(length * sizeof(int));
	int *arr = (int*)malloc(length * sizeof(int));

	printf("随机生成数据：\n");
	input(origin, length);
	output(origin, length);
	printf("\n");

	printf("直接插入排序：\n排序后：");
	originArray(arr, origin, length);
	InsertSort(arr, length, &compare, &move);
	output(arr, length);
	outTime(compare, move);

	printf("希尔排序：\n排序后：");
	originArray(arr, origin, length);
	ShellSort(arr, length, &compare, &move);
	output(arr, length);
	outTime(compare, move);

	printf("起泡排序：\n排序后：");
	originArray(arr, origin, length);
	BubbleSort(arr, length, &compare, &move);
	output(arr, length);
	outTime(compare, move);
	
    compare = 0, move = 0;
	printf("快速排序：\n排序后：");
	originArray(arr, origin, length);
	int left = 0, count = 0;
	QuickSort(arr,left,length-1,count, &compare, &move);
	output(arr, length);
	outTime(compare, move);

	printf("简单选择排序：\n排序后：");
	originArray(arr, origin, length);
	SelectSort(arr, length, &compare, &move);
	output(arr, length);
	outTime(compare, move);
}