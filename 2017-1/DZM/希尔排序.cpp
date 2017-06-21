#include <stdio.h>
#include <stdlib.h>
void ShellSort(int a[], int length)
{
	int increment;
	int i,j;
	int temp;
	for(increment = length/2; increment > 0; increment /= 2) //�������Ʋ���,���ݼ���1
	{
		// i�ӵ�step��ʼ���У�ӦΪ��������ĵ�һ��Ԫ��
		// �����Ȳ������ӵڶ�����ʼ����
		for(i = increment; i < length; i++)
		{
			temp = a[i];
			for(j = i - increment; j >= 0 && temp < a[j]; j -= increment)
			{
				a[j + increment] = a[j];
			}
			a[j + increment] = temp; //����һ��λ������
		}
	}
}

int main()
{
	printf("==============ϣ������===============\n\n");
	int i, j;
	int a[] = {5, 18, 151, 138, 160, 63, 174, 169, 79, 200};	
	printf("�������������: \n");
	for(i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	ShellSort(a, 10);
	printf("\n������������: \n");
	for(j = 0; j < 10; j++)
	{
		printf("%d ", a[j]);
	}
	printf("\n");
	return 0;
}

