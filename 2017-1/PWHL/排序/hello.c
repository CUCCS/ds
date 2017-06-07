#include "hello.h"
void copy(int *a, int *b, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = b[i];
	}
}
void print(int *p, int n, int sum1, int sum2)//打印数组
{
	int i;
	if (sum1 != 0 && sum2 != 0)
	{
		printf("\n总的比较次数 %d\n", sum1);
		printf("\n总的移动次数 %d\n", sum2);
		printf("\n二者次数之和为 %d\n", sum1 + sum2);
		printf("\n打印排序后的数组\n");
	}
	for (i = 0; i < n; i++)
	{
		printf("%d ", p[i]);
	}
	printf("\n");
}
int Make(int *p)//随机生成数组
{
	int i, temp;
	int n;
	do
	{
		temp = rand() % 20 + 1;
	} while (temp <= 0);
	n = temp;
	for (i = 0; i < n; i++)
	{
		do
		{
			temp = rand() % 100 + 1;
		} while (temp <= 0);
		p[i] = temp;
	}
	return n;
}
//冒泡排序
void BubbleSort(int *p, int n)
{
	int i, j;
	int temp;
	int sum1 = 0;
	int sum2 = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; (++sum1) && j < n - 1; j++)   //比较,找出本趟最小关键字的记录
			if (p[j] < p[j + 1])
			{
				temp = p[j];  //R[j]与R[j-1]进行交换,将最小关键字记录前移
				p[j] = p[j + 1];
				p[j + 1] = temp;
				sum2 = sum2 + 3;
			}
	}
	printf("\n");
	printf("冒泡排序\n");
	print(p, n, sum1, sum2);
	printf("\n\n");
}
//直接插入排序
void insertSort(int *p, int n)
{
	int i, j;
	int sum1 = 0;//总比较次数
	int sum2 = 0;//总移动次数
	int temp;
	for (i = 1; i < n; i++)
	{

		if ((++sum1) && p[i] > p[i - 1])
		{
			temp = p[i];
			for (j = i - 1; (sum1++), temp>p[i], j >= 0; j--)
			{
				p[j + 1] = p[j];
				sum2++;
			}
			p[j + 1] = temp;
		}
	}
	printf("\n");
	printf("直接插入排序\n");
	print(p, n, sum1, sum2);
	printf("\n\n");
}
void ShellInsert(int *q, int d, int *sum1, int *sum2, int n)
{//对顺序表进行一趟希尔 位置增量变成 dk  而不是1 
 //q[0] 只是暂存单元  不是哨兵 当j<=0  时 插入位置已经找到 
	int i, j;
	int temp;
	for (i = d; i < n; i++)
	{
		if ((++(*sum1)) && q[i] >q[i - d])
		{
			temp = q[i];
			(*sum1)++;
			for (j = i - d; (++(*sum1)) && temp > q[j] && j >= 0; j -= d)
			{
				q[j + d] = q[j];
				(*sum2)++;
			}
			q[j + d] = temp;
		}
	}
}
//希尔排序
void ShellSort(int *p, int n)   //希尔排序算法
{
	int i;
	int temp;
	int sum1 = 0;
	int sum2 = 0;
	i = (n - 1) / 2;
	for (i = n / 2; i > 0; i = i / 2) //对所有相隔gap位置的所有元素组进行排序
	{

		ShellInsert(p, i, &sum1, &sum2, n);
	}
	printf("\n");
	printf("希尔排序\n");
	print(p, n, sum1, sum2);
	printf("\n\n");
}

//快速排序
int Partition(int *q, int n, int low, int high, int *sum1, int *sum2)
{
	int p;//枢纽值
	p = q[low];
	while (low < high)
	{
		while (++(*sum1) && low < high&&q[high] <= p)
		{
			--high;
			(*sum2)++;
		}
		q[low] = q[high];
		while (++(*sum1) && low < high && q[low] >= p)
		{
			++low;
			(*sum2)++;
		}
		q[high] = q[low];
	}
	q[low] = p;
	return low;
}
void QSort(int *q, int n, int low, int high, int *sum1, int *sum2)
{
	int p;
	if (low < high)
	{
		p = Partition(q, n, low, high, sum1, sum2);
		QSort(q, n, low, p - 1, sum1, sum2);
		QSort(q, n, p + 1, high, sum1, sum2);
	}
}
void QuickSort(int *q, int n)
{
	int sum1 = 0;
	int sum2 = 0;
	QSort(q, n, 0, n - 1, &sum1, &sum2);
	printf("\n");
	printf("快速排序\n");
	print(q, n, sum1, sum2);
	printf("\n\n");
}

int change(int *q, int n, int low, int high)
{
	int  p;
	p = q[low];//枢轴值 
	while (low < high)
	{
		while (low < high && q[high] <= p)
		{
			high--;
		}
		q[low] = q[high];
		while (low < high && q[low] >= p)
		{
			low++;
		}
		q[high] = q[low];
	}
	q[low] = p;
}
void SelectSort(int *p, int n)//简单选择排序
{
	int i, j;
	int temp;
	int sum1 = 0;
	int sum2 = 0;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if ((++sum1) && p[i] < p[j])
			{
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
				sum2 = sum2 + 3;
			}
		}
	}
	printf("\n");
	printf("简单选择排序\n");
	print(p, n, sum1, sum2);
	printf("\n\n");
}
int main()
{
	srand(time(0));
	int list[Maxsize];
	int list_copy[Maxsize];
	int length = Make(&list);//制造需要打印的数组 并返回长 
	printf("打印初始数组\n");
	print(list, length, 0, 0);
	printf("\n\n");
	copy(list_copy, list, length);
	insertSort(list_copy, length);//进行直接插入 
	copy(list_copy, list, length);
	ShellSort(list_copy, length);//进行希尔排序	 
	copy(list_copy, list, length);
	BubbleSort(list_copy, length);//进行起泡排序 
	copy(list_copy, list, length);
	QuickSort(list_copy, length);//快速排序 
	copy(list_copy, list, length);
	SelectSort(list_copy, length);//简单选择排序 
	return 0;
}
