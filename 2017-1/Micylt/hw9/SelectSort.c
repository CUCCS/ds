#include<stdio.h>
#include<time.h>
int move, compare = 0;
void SelectSort(int a[],int n)
{
	for (int i = 0; i < n - 1; i++) 
	{
		int j = i;
		int min = a[j];
		for (int k = i; k < n; k++) 
		{
			if (a[k] < min)
			{
				j = k;
				min = a[k];
				move++;
			}
			compare++;
		}
		int t = a[i];
		a[i] = a[j];
		a[j] = t;
		move++;
	}
}

void sran(int a[], int n)
{
	int i, count = 0;

	srand(time(NULL));
	for (i = 0; i<n; i++)
	{
		a[i] = rand() % 100 + 1;
		count++;
		if (count % 5 == 0)
		{
		}
	}
}

int main()
{
	int array[20];
	int n;
	srand(time(0));
	n = rand() % 20 + 1;
	sran(array, n);
	printf("原始顺序为：");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", array[i]);

	}
	printf("\n");
	printf("排序后的结果为：");
	SelectSort(array, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", array[i]);

	}
	printf("\n");
	printf("总比较次数为：%d \n", compare);
	printf("总移动次数为：%d \n", move);
	printf("总次数之和：%d \n", compare + move);
	return 0;
}

