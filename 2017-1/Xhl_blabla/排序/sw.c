#include "sw.h"
//复制数组
void copy(int *a, int *b,int length)
{
	int i;
	for (i = 0; i < length; i++)
	{
		a[i] = b[i];
	}
}
//打印数组
 void print_(int *  q,int length,int num1,int num2)
 {
	 int i;
	 if (num1 != 0 && num2 != 0)
	 {
     printf("\n总比较次数    %d\n", num1);
	 printf("总移动记录次数    %d\n", num2);
	 printf("二者次数之和为  %d\n", num1 + num2);
     printf("\n打印排序完成的数组\n");
	 }
	 for (i = 0; i < length; i++)
	 {
		 printf("%d ", q[i]);
	 }
	 printf("\n");
 }
 //制造数组
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
//起泡排序
void Sort(int *q,int length)
{
	int i, j;
	int num1=0, num2=0;
	int temp;
	for (i = 0; i < length; i++)
	{
		for (j = 0; (++num1)&&j < length - 1;j++)
		{
			if (q[j] < q[j + 1])//计数核心的比较次数
			{
				temp =q[j];
				q[j] =q[j + 1];
				q[j + 1] = temp;
				 num2 += 3;
			}
		}
	}
	printf("\n");
	printf("起泡排序法\n\n");
	print_(q, length,num1,num2);
	printf("\n\n");
}
//进行直接插入排序
void InsertSort(int *q,int length)
{
	int i;
	int j;
	int  num1 = 0;//总比较次数
	int num2 = 0;//总移动记录次数
	int temp;//哨兵
	for (i = 1; i < length; i++)
	{

		if ((++num1) && q[i] > q[i - 1])//如果后加加  因为num1 初值为0 第一个排序会跳过
		{
			temp = q[i];
			for (j = i - 1; (++num1) && temp > q[j] && j >=0; j--)
			{
				q[j+1] = q[j];//从后面开始挪 很好
				num2++;
			}
			q[j + 1] = temp;
		}
	}
	printf("\n");
	printf("直接插入排序\n\n");
	print_(q, length, num1, num2);
	printf("\n\n");
}
//希尔排序
void ShellInsert(int *q, int dk, int *num1, int *num2,int length)
{//对顺序表进行一趟希尔 位置增量变成 dk  而不是1
 //q[0] 只是暂存单元  不是哨兵 当j<=0  时 插入位置已经找到
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
{//按增量对顺序表进行希尔排序
	int num1 = 0, num2 = 0;
	int k;
	int t = (length - 1) / 2;
	for (t = length / 2; t>0; t = t / 2)
	{
		ShellInsert(q, t, &num1, &num2,length);
	}
	printf("\n");
	printf("希尔排序\n\n");
	print_(q, length, num1, num2);
	printf("\n\n");
}
//end希尔排序
//快速排序
int Partition(int *q, int length, int low, int high,int *num1,int *num2)
{
	int p;//枢纽值
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
	return low;//相当于根节点
}
void QSort(int *q, int length, int low, int high,int *num1,int *num2)
{
	int p;
	if (low < high)
	{
		p = Partition(q, length, low, high,num1,num2);//一分为二  对左右分别进行排序
		QSort(q, length, low, p - 1,num1,num2);//对低子表进行排序
		QSort(q, length, p + 1, high, num1, num2);//对高子表进行排序
	}
}
void QuickSort(int*q, int length)
{
	int num1=0, num2=0;
	QSort(q, length, 0, length-1,&num1,&num2);
	printf("\n");
	printf("快速排序\n\n");
	print_(q, length, num1, num2);
	printf("\n\n");
}
//end快速排序
int change(int *q, int length, int low, int high)
{
	int  p;//
	p = q[low];//枢轴值
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
//简单选择排序
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
	printf("简单选择排序\n\n");
	print_(q, length, num1, num2);
	printf("\n\n");
}
int main()
{
	srand(time(0));
	int list[ListNum];
	int list_cpoy[ListNum];
	int length = make(&list);//制造需要打印的数组 并返回长
	printf("打印初始数组\n");
	print_(list, length,0,0);
	printf("\n\n");
	copy(list_cpoy, list, length);
	InsertSort(list_cpoy, length);//进行直接插入
	copy(list_cpoy, list, length);
	ShellSort(list_cpoy, length);//进行希尔排序	
	copy(list_cpoy, list, length);
	Sort(list_cpoy,length);//进行起泡排序
	copy(list_cpoy, list, length);
	QuickSort(list_cpoy, length);//快速排序
	copy(list_cpoy, list, length);
	SelectSort(list_cpoy, length);//简单选择排序
	return 0;
}