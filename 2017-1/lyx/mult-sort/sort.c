//参考jackcily作业
#include <stdio.h>
#include <stdlib.h>
#include <time.h>//随机生成正整数序列
#define Maxsize 25 //正整数序列最大值

void copy(int *a, int *b, int n)
{//将a数组的数复制到b数组中，使得可以换下一个排序方式再次排序
	for (int i = 0; i < n; i++)
	{
		a[i] = b[i];
	}
}//copy

void print(int *p, int n, int count1, int count2)
{//打印数组 count1为总的比较次数 count2为总的移动次数
	if (count1 != 0 && count2 != 0)
	{
		printf("\n总的比较次数 %d\n", count1);
		printf("\n总的移动次数 %d\n", count2);
		printf("\n二者次数之和为 %d\n", count1 + count2);
		printf("\n打印排序后的数组\n");
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", p[i]);//打印数组
	}
	printf("\n");
}//print
int Make(int *p)//随机生成数组
{
	int temp;//随机的数
	int n;
	do
	{
		temp = rand() % 20 + 1;//把数限制在20以内
	} while (temp <= 0);
	n = temp;//这个temp是数组编号
	for (int i = 0; i < n; i++)
	{
		do
		{
			temp = rand() % 100 + 1;////把数限制在100以内
		} while (temp <= 0);//这个temp是数组元素
		p[i] = temp;//生成数组
	}
	return n;
}//Make

//冒泡排序
void BubbleSort(int *p, int n)
{
	int i, j;
	int temp;
	int count1 = 0;
	int count2 = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; (++count1) && j < n - 1; j++)   //比较,找出本趟最小关键字的记录
			if (p[j] < p[j + 1])
			{
				temp = p[j];  //R[j]与R[j-1]进行交换,将最小关键字记录前移
				p[j] = p[j + 1];
				p[j + 1] = temp;
				count2 = count2 + 3;//跳到下一个，再比较
			}
	}
	printf("\n");
	printf("冒泡排序\n");
	print(p, n, count1, count2);//调用函数，输出数列
	printf("\n\n");
}//BubbleSort

//直接插入排序
void InsertSort(int *p, int n)
{
	int i, j;
	int count1 = 0;//总比较次数
	int count2 = 0;//总移动次数
	int temp;
	for (i = 1; i < n; i++)
	{
		if ((++count1) && p[i] > p[i - 1])//如果该元素大于上一个元素
		{
			temp = p[i];//临时变量
			for (j = i - 1; (count1++), temp>p[i], j >= 0; j--)//往前比较，比的次数加一
			{
				p[j + 1] = p[j];//下一个等于前一个
				count2++;//移动了两次
			}
			p[j + 1] = temp;//下一个等于临时变量等于原来的前一个
		}
	}
	printf("\n");
	printf("直接插入排序\n");
	print(p, n, count1, count2);//调用函数，输出数列
	printf("\n\n");
}//InsertSort

void ShellInsert(int *q, int d, int *count1, int *count2, int n)
{//对顺序表进行一趟希尔 位置增量变成 d 
	//q[0]是暂存单元，不是哨兵。当j <= 0时 插入位置已经找到 
	int i, j;
	int temp;
	for (i = d; i < n; i++)
	{
		if ((++(*count1)) && q[i] >q[i - d])//若如果该元素大于往前隔d个元素
		{
			temp = q[i];//临时变量
			(*count1)++;//总比较次数加一
			for (j = i - d; (++(*count1)) && temp > q[j] && j >= 0; j -= d)//往前个d比较，比的次数加一
			{
				q[j + d] = q[j];//下d个等于这个
				(*count2)++;//总移动次数加一
			}
			q[j + d] = temp;//下d个等于q[i]
		}
	}
}//ShellInsert

//希尔排序
void ShellSort(int *p, int n)   //希尔排序算法
{
	int i;
	int temp;
	int count1 = 0;
	int count2 = 0;
	i = (n - 1) / 2;
	for (i = n / 2; i > 0; i = i / 2) //对所有相隔gap位置的所有元素组进行排序
	{

		ShellInsert(p, i, &count1, &count2, n);//调用函数
	}
	printf("\n");
	printf("希尔排序\n");
	print(p, n, count1, count2);//输出数组
	printf("\n\n");
}//ShellSort

//快速排序
int Partition(int *q, int n, int low, int high, int *count1, int *count2)
{
	int p;//枢纽值
	p = q[low];//指向low
	while (low < high)
	{//low<high
		while (++(*count1) && low < high&&q[high] <= p)//当low小于high的时候且最高位小于枢纽值时
		{
			--high;//high往前移
			(*count2)++;//移动次数加2
		}
		q[low] = q[high];//使low指向high位
		while (++(*count1) && low < high && q[low] >= p)
		{
			++low;//low往后移
			(*count2)++;//移动次数加2
		}
		q[high] = q[low];//使high指向low位
	}
	q[low] = p;//最低位为枢纽值
	return low;//返回最低位
}//Partition
void QSort(int *q, int n, int low, int high, int *count1, int *count2)
{
	int p;
	if (low < high)//低位比高位低
	{
		p = Partition(q, n, low, high, count1, count2);//调用函数进行比较
		QSort(q, n, low, p - 1, count1, count2);//递归 使高位往前移
		QSort(q, n, p + 1, high, count1, count2);//递归//使地位往后移
	}
}//QSort

void QuickSort(int *q, int n)
{
	int count1 = 0;
	int count2 = 0;
	QSort(q, n, 0, n - 1, &count1, &count2);//调用函数进行快速排序
	printf("\n");
	printf("快速排序\n");
	print(q, n, count1, count2);
	printf("\n\n");
}//QuickSort

void change(int *q, int length, int low, int high)

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
				p[j] = temp;//两值交换
				count2 = count2 + 3;//交换了三次
			}
		}
	}
	printf("\n");
	printf("简单选择排序\n");
	print(p, n, count1, count2);
	printf("\n\n");
}//SelectSort
int main()
{
	srand(time(0));
	int list[Maxsize];
	int list_copy[Maxsize];
	int length = Make(list);//制造需要打印的数组 并返回长 
	printf("打印初始数组\n");
	print(list, length, 0, 0);
	printf("\n\n");
	copy(list_copy, list, length);
	InsertSort(list_copy, length);//进行直接插入 
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