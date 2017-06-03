#include "sw.h"
//��������
void copy(int *a, int *b,int length)
{
	int i;
	for (i = 0; i < length; i++)
	{
		a[i] = b[i];
	}
}
//��ӡ����
 void print_(int *  q,int length,int num1,int num2)
 {
	 int i;
	 if (num1 != 0 && num2 != 0)
	 {
     printf("\n�ܱȽϴ���    %d\n", num1);
	 printf("���ƶ���¼����    %d\n", num2);
	 printf("���ߴ���֮��Ϊ  %d\n", num1 + num2);
     printf("\n��ӡ������ɵ�����\n");
	 }
	 for (i = 0; i < length; i++)
	 {
		 printf("%d ", q[i]);
	 }
	 printf("\n");
 }
 //��������
int  make(int *q)
{
	int temp;
	int length;
	int i;
	do
	{
	    temp = rand() % 20 + 1;
	} while (temp <= 0);
     length = temp;
   for (i = 0; i <length; i++)
   {
	   do
	   {
		   temp = rand() % 100 + 1;
	   } while (temp <= 0);
	    q[i]= temp; 
   }
   return length;
}
//��������
void Sort(int *q,int length)
{
	int i, j;
	int num1=0, num2=0;
	int temp;
	for (i = 0; i < length; i++)
	{
		for (j = 0; (++num1)&&j < length - 1;j++)
		{
			if (q[j] < q[j + 1])//�������ĵıȽϴ���
			{
				temp =q[j];
				q[j] =q[j + 1];
				q[j + 1] = temp;
				 num2 += 3;
			}
		}
	}
	printf("\n");
	printf("��������\n\n");
	print_(q, length,num1,num2);
	printf("\n\n");
}
//����ֱ�Ӳ�������
void InsertSort(int *q,int length)
{
	int i;
	int j;
	int  num1 = 0;//�ܱȽϴ���
	int num2 = 0;//���ƶ���¼����
	int temp;//�ڱ�
	for (i = 1; i < length; i++)
	{

		if ((++num1) && q[i] > q[i - 1])//�����Ӽ�  ��Ϊnum1 ��ֵΪ0 ��һ�����������
		{
			temp = q[i];
			for (j = i - 1; (++num1) && temp > q[j] && j >=0; j--)
			{
				q[j+1] = q[j];//�Ӻ��濪ʼŲ �ܺ�
				num2++;
			}
			q[j + 1] = temp;
		}
	}
	printf("\n");
	printf("ֱ�Ӳ�������\n\n");
	print_(q, length, num1, num2);
	printf("\n\n");
}
//ϣ������
void ShellInsert(int *q, int dk, int *num1, int *num2,int length)
{//��˳������һ��ϣ�� λ��������� dk  ������1
 //q[0] ֻ���ݴ浥Ԫ  �����ڱ� ��j<=0  ʱ ����λ���Ѿ��ҵ�
	int i, j;
	int temp;
	for (i = dk; i < length; i++)
	{
		if ((++(*num1)) && q[i] >q[i - dk])
		{
			temp =q[i];
			(*num1)++;
			for (j = i - dk;  (++(*num1))&&temp > q[j]&&j>=0; j -= dk)
			{
				q[j + dk] = q[j];	
				(*num2)++;
			}
			q[j + dk] = temp;
		}
	}
}
void ShellSort(int *q,int length)
{//��������˳������ϣ������
	int num1 = 0, num2 = 0;
	int k;
	int t = (length - 1) / 2;
	for (t = length / 2; t>0; t = t / 2)
	{
		ShellInsert(q, t, &num1, &num2,length);
	}
	printf("\n");
	printf("ϣ������\n\n");
	print_(q, length, num1, num2);
	printf("\n\n");
}
//endϣ������
//��������
int Partition(int *q, int length, int low, int high,int *num1,int *num2)
{
	int p;//��Ŧֵ
	p = q[low];
	while (low < high)
	{
		while (++(*num1)&&low < high&&q[high] <= p)
		{
			--high;
			(*num2)++;
		}
		q[low] = q[high];
		while (++(*num1) &&low < high&&q[low] >= p)
		{
	     ++low;
		 (*num2)++;
		}	
		q[high] = q[low];
	}
	q[low] = p;
	return low;//�൱�ڸ��ڵ�
}
void QSort(int *q, int length, int low, int high,int *num1,int *num2)
{
	int p;
	if (low < high)
	{
		p = Partition(q, length, low, high,num1,num2);//һ��Ϊ��  �����ҷֱ��������
		QSort(q, length, low, p - 1,num1,num2);//�Ե��ӱ��������
		QSort(q, length, p + 1, high, num1, num2);//�Ը��ӱ��������
	}
}
void QuickSort(int*q, int length)
{
	int num1=0, num2=0;
	QSort(q, length, 0, length-1,&num1,&num2);
	printf("\n");
	printf("��������\n\n");
	print_(q, length, num1, num2);
	printf("\n\n");
}
//end��������
int change(int *q, int length, int low, int high)
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
void SelectSort(int *q, int length)
{
	int i, j;
	int num1 = 0, num2 = 0;
	int temp;
	for (i = 0; i<length; i++)
	{
		for (j = i + 1; j<length; j++)
		{
			if ((++num1)&&q[i]<q[j])
			{
				temp= q[i];
				q[i] = q[j];
				q[j] = temp;
				num2 += 3;
			}
		}
	}
	printf("\n");
	printf("��ѡ������\n\n");
	print_(q, length, num1, num2);
	printf("\n\n");
}
int main()
{
	srand(time(0));
	int list[ListNum];
	int list_cpoy[ListNum];
	int length = make(&list);//������Ҫ��ӡ������ �����س�
	printf("��ӡ��ʼ����\n");
	print_(list, length,0,0);
	printf("\n\n");
	copy(list_cpoy, list, length);
	InsertSort(list_cpoy, length);//����ֱ�Ӳ���
	copy(list_cpoy, list, length);
	ShellSort(list_cpoy, length);//����ϣ������	
	copy(list_cpoy, list, length);
	Sort(list_cpoy,length);//������������
	copy(list_cpoy, list, length);
	QuickSort(list_cpoy, length);//��������
	copy(list_cpoy, list, length);
	SelectSort(list_cpoy, length);//��ѡ������
	return 0;
}