//����ϣ����������ƶ��������ܱȽϴ����ļ����Ҳ��Ǻ�ȷ�����鷳ʦ���æָ��һ��~
#include<stdio.h>
#include<time.h>
int move, compare=0;
void shellSort(int a[], int n)
{
	int increment=0;
	int i, j,k=0;
	int temp=0;
	for (increment = n / 2; increment > 0; increment /= 2)  //������ֳ���������
	{
		for (i = 0; i < increment; i++) //����Щ���ɸ����н���ֱ�Ӳ�������
		{
			for (j = i + increment; j < n; j = j + increment) //������һ�β�������
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
	printf("ԭʼ˳��Ϊ��");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", array[i]);

	}
	printf("\n");
	printf("�����Ľ��Ϊ��");
	shellSort(array, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	printf("���ƶ�����Ϊ%d�� \n",move);
	printf("�ܱȽϴ���Ϊ%d�� \n", compare);
	printf("���ߴ���֮��Ϊ:%d \n", compare+move);
}