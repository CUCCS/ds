#include<stdio.h>
#include<time.h>
int move, compare = 0;
void GuluSort(int a[], int n)
{
	int i, j;
	int temp = 0;
	for (i = 0; i < n-1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				
				temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
				move++;
			}	
			compare++;
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
	printf("ԭʼ˳��Ϊ��");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", array[i]);

	}
	printf("\n");
	printf("�����Ľ��Ϊ��");
	GuluSort(array, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", array[i]);

	}
	printf("\n");
	printf("�ܱȽϴ���Ϊ��%d \n", compare );
	printf("���ƶ�����Ϊ��%d \n", move);
	printf("�ܴ���֮�ͣ�%d \n", compare + move);
	return 0;
}
