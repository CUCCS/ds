#include <stdio.h>
#include <stdlib.h>
void ShellSort(int a[], int length)
{
	int increment;
	int i,j;
	int temp;
	for(increment = length/2; increment > 0; increment /= 2) //用来控制步长,最后递减到1
	{
		// i从第step开始排列，应为插入排序的第一个元素
		// 可以先不动，从第二个开始排序
		for(i = increment; i < length; i++)
		{
			temp = a[i];
			for(j = i - increment; j >= 0 && temp < a[j]; j -= increment)
			{
				a[j + increment] = a[j];
			}
			a[j + increment] = temp; //将第一个位置填上
		}
	}
}

int main()
{
	printf("==============希尔排序===============\n\n");
	int i, j;
	int a[] = {5, 18, 151, 138, 160, 63, 174, 169, 79, 200};	
	printf("待排序的序列是: \n");
	for(i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	ShellSort(a, 10);
	printf("\n排序后的序列是: \n");
	for(j = 0; j < 10; j++)
	{
		printf("%d ", a[j]);
	}
	printf("\n");
	return 0;
}

