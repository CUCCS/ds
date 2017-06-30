//关于希尔排序的总移动次数和总比较次数的计算我不是很确定，麻烦师哥帮忙指正一下~
#include<stdio.h>
#include<time.h>
int move, compare=0;
void shellSort(int a[], int n)
{
	int increment=0;
	int i, j,k=0;
	int temp=0;
	for (increment = n / 2; increment > 0; increment /= 2)  //将数组分成若干序列
	{
		for (i = 0; i < increment; i++) //对这些若干个序列进行直接插入排序
		{
			for (j = i + increment; j < n; j = j + increment) //单独的一次插入排序
			{
				
				if (a[j] < a[j - increment])
				{
					compare++;
					temp = a[j];
					k = j - increment;
					move++;
					while (k >= 0 && a[k] > temp)
					{
						compare++;
						a[k + increment] = a[k];
						k = k - increment;
						move++;
					}
					a[k + increment] = temp;
					compare++;
				}
			}
		}
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
	shellSort(array, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	printf("总移动次数为%d： \n",move);
	printf("总比较次数为%d： \n", compare);
	printf("二者次数之和为:%d \n", compare+move);
}