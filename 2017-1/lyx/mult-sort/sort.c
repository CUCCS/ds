//�ο�jackcily��ҵ
#include <stdio.h>
#include <stdlib.h>
#include <time.h>//�����������������
#define Maxsize 25 //�������������ֵ

void copy(int *a, int *b, int n)
{//��a����������Ƶ�b�����У�ʹ�ÿ��Ի���һ������ʽ�ٴ�����
	for (int i = 0; i < n; i++)
	{
		a[i] = b[i];
	}
}//copy

void print(int *p, int n, int count1, int count2)
{//��ӡ���� count1Ϊ�ܵıȽϴ��� count2Ϊ�ܵ��ƶ�����
	if (count1 != 0 && count2 != 0)
	{
		printf("\n�ܵıȽϴ��� %d\n", count1);
		printf("\n�ܵ��ƶ����� %d\n", count2);
		printf("\n���ߴ���֮��Ϊ %d\n", count1 + count2);
		printf("\n��ӡ����������\n");
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", p[i]);//��ӡ����
	}
	printf("\n");
}//print
int Make(int *p)//�����������
{
	int temp;//�������
	int n;
	do
	{
		temp = rand() % 20 + 1;//����������20����
	} while (temp <= 0);
	n = temp;//���temp��������
	for (int i = 0; i < n; i++)
	{
		do
		{
			temp = rand() % 100 + 1;////����������100����
		} while (temp <= 0);//���temp������Ԫ��
		p[i] = temp;//��������
	}
	return n;
}//Make

//ð������
void BubbleSort(int *p, int n)
{
	int i, j;
	int temp;
	int count1 = 0;
	int count2 = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; (++count1) && j < n - 1; j++)   //�Ƚ�,�ҳ�������С�ؼ��ֵļ�¼
			if (p[j] < p[j + 1])
			{
				temp = p[j];  //R[j]��R[j-1]���н���,����С�ؼ��ּ�¼ǰ��
				p[j] = p[j + 1];
				p[j + 1] = temp;
				count2 = count2 + 3;//������һ�����ٱȽ�
			}
	}
	printf("\n");
	printf("ð������\n");
	print(p, n, count1, count2);//���ú������������
	printf("\n\n");
}//BubbleSort

//ֱ�Ӳ�������
void InsertSort(int *p, int n)
{
	int i, j;
	int count1 = 0;//�ܱȽϴ���
	int count2 = 0;//���ƶ�����
	int temp;
	for (i = 1; i < n; i++)
	{
		if ((++count1) && p[i] > p[i - 1])//�����Ԫ�ش�����һ��Ԫ��
		{
			temp = p[i];//��ʱ����
			for (j = i - 1; (count1++), temp>p[i], j >= 0; j--)//��ǰ�Ƚϣ��ȵĴ�����һ
			{
				p[j + 1] = p[j];//��һ������ǰһ��
				count2++;//�ƶ�������
			}
			p[j + 1] = temp;//��һ��������ʱ��������ԭ����ǰһ��
		}
	}
	printf("\n");
	printf("ֱ�Ӳ�������\n");
	print(p, n, count1, count2);//���ú������������
	printf("\n\n");
}//InsertSort

void ShellInsert(int *q, int d, int *count1, int *count2, int n)
{//��˳������һ��ϣ�� λ��������� d 
	//q[0]���ݴ浥Ԫ�������ڱ�����j <= 0ʱ ����λ���Ѿ��ҵ� 
	int i, j;
	int temp;
	for (i = d; i < n; i++)
	{
		if ((++(*count1)) && q[i] >q[i - d])//�������Ԫ�ش�����ǰ��d��Ԫ��
		{
			temp = q[i];//��ʱ����
			(*count1)++;//�ܱȽϴ�����һ
			for (j = i - d; (++(*count1)) && temp > q[j] && j >= 0; j -= d)//��ǰ��d�Ƚϣ��ȵĴ�����һ
			{
				q[j + d] = q[j];//��d���������
				(*count2)++;//���ƶ�������һ
			}
			q[j + d] = temp;//��d������q[i]
		}
	}
}//ShellInsert

//ϣ������
void ShellSort(int *p, int n)   //ϣ�������㷨
{
	int i;
	int temp;
	int count1 = 0;
	int count2 = 0;
	i = (n - 1) / 2;
	for (i = n / 2; i > 0; i = i / 2) //���������gapλ�õ�����Ԫ�����������
	{

		ShellInsert(p, i, &count1, &count2, n);//���ú���
	}
	printf("\n");
	printf("ϣ������\n");
	print(p, n, count1, count2);//�������
	printf("\n\n");
}//ShellSort

//��������
int Partition(int *q, int n, int low, int high, int *count1, int *count2)
{
	int p;//��Ŧֵ
	p = q[low];//ָ��low
	while (low < high)
	{//low<high
		while (++(*count1) && low < high&&q[high] <= p)//��lowС��high��ʱ�������λС����Ŧֵʱ
		{
			--high;//high��ǰ��
			(*count2)++;//�ƶ�������2
		}
		q[low] = q[high];//ʹlowָ��highλ
		while (++(*count1) && low < high && q[low] >= p)
		{
			++low;//low������
			(*count2)++;//�ƶ�������2
		}
		q[high] = q[low];//ʹhighָ��lowλ
	}
	q[low] = p;//���λΪ��Ŧֵ
	return low;//�������λ
}//Partition
void QSort(int *q, int n, int low, int high, int *count1, int *count2)
{
	int p;
	if (low < high)//��λ�ȸ�λ��
	{
		p = Partition(q, n, low, high, count1, count2);//���ú������бȽ�
		QSort(q, n, low, p - 1, count1, count2);//�ݹ� ʹ��λ��ǰ��
		QSort(q, n, p + 1, high, count1, count2);//�ݹ�//ʹ��λ������
	}
}//QSort

void QuickSort(int *q, int n)
{
	int count1 = 0;
	int count2 = 0;
	QSort(q, n, 0, n - 1, &count1, &count2);//���ú������п�������
	printf("\n");
	printf("��������\n");
	print(q, n, count1, count2);
	printf("\n\n");
}//QuickSort

void change(int *q, int length, int low, int high)

{

	int  p;//

	p = q[low];//����ֵ

	while (low < high)

	{

		while (low < high&&q[high] <= p)

		{

			high--;

		}

		q[low] = q[high];

		while (low < high&&q[low] >= p)

		{

			low++;

		}

		q[high] = q[low];

	}

	q[low] =p;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               

}

//��ѡ������
void SelectSort(int *p, int n)
{
	int i, j;
	int temp;
	int count1 = 0;
	int count2 = 0;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if ((++count1) && p[i] < p[j])
			{
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;//��ֵ����
				count2 = count2 + 3;//����������
			}
		}
	}
	printf("\n");
	printf("��ѡ������\n");
	print(p, n, count1, count2);
	printf("\n\n");
}//SelectSort
int main()
{
	srand(time(0));
	int list[Maxsize];
	int list_copy[Maxsize];
	int length = Make(list);//������Ҫ��ӡ������ �����س� 
	printf("��ӡ��ʼ����\n");
	print(list, length, 0, 0);
	printf("\n\n");
	copy(list_copy, list, length);
	InsertSort(list_copy, length);//����ֱ�Ӳ��� 
	copy(list_copy, list, length);
	ShellSort(list_copy, length);//����ϣ������	 
	copy(list_copy, list, length);
	BubbleSort(list_copy, length);//������������ 
	copy(list_copy, list, length);
	QuickSort(list_copy, length);//�������� 
	copy(list_copy, list, length);
	SelectSort(list_copy, length);//��ѡ������ 
	return 0;
}