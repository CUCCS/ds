#include<stdio.h>
#include<time.h>
int compare, move = 0; //记录比较次数和移动次数

int partition(int arr[], int low, int high) { //将数组一分为二
	int key;
	key = arr[low];
	while (low<high) 
	{
		while (low < high && arr[high] >= key)
		{
			high--;
		}
		compare++;
		if (low < high)
		{
			arr[low++] = arr[high];
			move++;

		}
		while (low < high && arr[low] <= key)
		{
			low++;
		}
		compare++;
		if (low < high)
		{
			arr[high--] = arr[low];
			move++;
		}
		
	}
	arr[low] = key;
	return low;
}

void QuickSort(int a[], int low,int high)    //仿照课本275页编写
{
	int pos;
	if (low<high) 
	{
		pos = partition(a, low, high);
		QuickSort(a, low, pos - 1);
		QuickSort(a, pos + 1, high);
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
	QuickSort(array, 0, n - 1);
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