#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int move, count=0;//����ȫ�ֱ����������ƶ��ͱȽϵĴ���
void InsertSort(int p[],int size)  //ʵ����û�����������ü�����
{
	int i, j;
	int temp;
	for (i = 0; i < size; i++)
	{
		temp = p[i];
		j = i - 1;
		while ((j >= 0) && (temp < p[j]))  //����j>=0��Ϊ�˷�ֹ�±�Խ��
		{
			p[j + 1] = p[j];
			count = count + 1;
			j--;
			move = move + 1;
		}
		p[j + 1] = temp;
		count++;
	}
	

 }
void sran(int a[],int n)
{
	int i, count = 0;
	
	srand(time(NULL));
	for (i = 0; i<n; i++)
	{
		a[i] = rand() % 100 + 1;
		count++;
		if (count % 5 == 0)
		{ }
	}
}

int main()
{
	int array[20];
	int n;
	srand(time(0));
	n= rand()%20+1;
	sran(array,n);
	printf("ԭʼ˳��Ϊ��");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", array[i]);

	}
	printf("\n");
	printf("�����Ľ��Ϊ��");
	InsertSort(array, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", array[i]);

	}
	printf("\n");
	printf("�ܱȽϴ���Ϊ��%d \n", count-1);
	printf("���ƶ�����Ϊ��%d \n", move);
	return 0;
}