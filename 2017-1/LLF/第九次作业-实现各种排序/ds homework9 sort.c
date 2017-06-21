//实现第九次作业 各种排序(必选+归并排序) 其中插入排序、希尔排序、冒泡排序、简单选择排序均未改变原测试数组顺序
//在快速排序和归并排序中使用了递归，直接对原测试数组进行了排序
#include<stdio.h>
#include<time.h>
#include<malloc.h>

void Print(int *t, int len,int c,int m);
void swap(int *a, int *b);
int c = 0; 
int m = 0;//记录排序的比较与移动次数

//copy函数
int * Copy(int s[],int len)
{
	int *r;//copy原数组
	r = (int *)malloc(len * sizeof(int));
	for (int m = 0; m < len; m++)
		r[m] = s[m];
	return r;
}

//直接插入排序
void InsertSort(int s[], int len) 
{
	int insertVal = 0;
	int i = 0, j = 0;
	 c = 0; 
	 m = 0;
	for (i = 1; i < len; ++i) 
	{
		insertVal = s[i];
		//若第i-1个元素大于第i个元素，则移动后插入；  
		//否则无需任何操作  
		if (s[i - 1] > insertVal) 
		{
			j = i - 1;
			//寻找插入位置，一边寻找一边后移  
			while (j >= 0 && s[j] > insertVal) 
			{
				s[j + 1] = s[j];
				--j;
				c++;
			}
			s[j + 1] = insertVal;
			m++;
		}

	}

}

//希尔排序
void ShellSort(int s[], int len)
{
	int i, j, k;
	 c = 0;
	 m = 0;
	int gap;    //gap是分组的长度  
	int temp;   //因为希尔排序是在直接插入排序的基础上实现的,所以仍然需要监视哨 
	for (gap = len / 2; gap>0; gap = gap / 2) 
	{
		for (i = 0; i<gap; i++) 
		{
			for (j = i + gap; j<len; j = j + gap) 
			{ //单独一次的插入排序  
				if (s[j] < s[j - gap]) 
				{
					temp = s[j];    //监视哨
					k = j - gap;
					while (k >= 0 && s[k]>temp) 
					{
						s[k + gap] = s[k];
						k = k - gap;
					}
					s[k + gap] = temp;
					
				}
				c++;
			}m++;
		}
	}
}


//冒泡排序
void BubbleSort(int s[], int len)
{
	int i, j,t;
	 c = 0; 
	 m = 0;
	for (i = 0; i < len; i++)
	{
		for (j = i + 1; j < len; j++)
		{
			if (s[i] > s[j])
			{
				swap(&s[i], &s[j]);
			}
			c++;
		}
		m++;
	}
}

//交换
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;

	return;
}

//简单选择排序
void SelectSort(int s[], int len)//n为数组a的元素个数 
{
	 c = 0;
	 m = 0;
	//进行N-1轮选择 
	for (int i = 1 - 1; i<len ; i++)
	{
		int min = i;
		//找出第i小的数所在的位置 
		for (int j = len - 1 ; j >= i; j--)
		{
			if (s[j] < s[min])
			{
				min = j;
			}
			m++;
		}
		//将第i小的数，放在第i个位置；如果刚好，就不用交换 
		if (i != min)
		{
			swap(&s[i], &s[min]);
		}
		c++;
	}
}

//快速排序
void QuickSort(int s[], int len, int low, int high)
{
	int i, j;
	if (low < high)
	{
		i = low + 1;  // 将s[low]作为基准数，因此从s[low+1]开始与基准数比较！  
		j = high;        // s[high]是数组的最后一位  

		while (i < j)
		{
			if (s[i] > s[low])  // 如果比较的数组元素大于基准数，则交换位置。  
			{
				swap(&s[i], &s[j]);  // 交换两个数  
				j--;
				c++;
			}
			else
			{
				i++;  // 将数组向后移一位，继续与基准数比较。  
				m++;
			}
			
		}

		/* 跳出while循环后，i = j。
		* 此时数组被分割成两个部分  -->  s[low+1] ~ s[i-1] < s[low]
		*                           -->  s[i+1] ~ s[high] > s[low]
		* 这个时候将数组s分成两个部分，再将s[i]与s[low]进行比较，决定s[i]的位置。
		* 最后将s[i]与s[low]交换，进行两个分割部分的排序！以此类推，直到最后i = j不满足条件就退出！
		*/

		if (s[i] >= s[low])  // 这里必须要取等“>=”，否则数组元素由相同的值时，会出现错误！  
		{
			i--;
			m++;
		}

		swap(&s[low], &s[i]);  // 交换s[i]与s[low]  

		QuickSort(s, len, low, i);
		QuickSort(s, len, j, high);
	}
}

//归并排序
void merge(int s[], int low, int mid, int high) 
{
	int i, k;
	int *tmp = (int *)malloc((high - low + 1) * sizeof(int));
	//申请空间，使其大小为两个
	int left_low = low;
	int left_high = mid;
	int right_low = mid + 1;
	int right_high = high;
	for (k = 0; left_low <= left_high && right_low <= right_high; k++)
	{  // 比较两个指针所指向的元素
		if (s[left_low] <= s[right_low]) 
		{
			tmp[k] = s[left_low++];
			m++;
		}
		else 
		{
			tmp[k] = s[right_low++];
			m++;
		}
		c++;
	}
	if (left_low <= left_high) 
	{  
								
		for (i = left_low; i <= left_high; i++)
		{
			tmp[k++] = s[i];
			m++;
		}
	}
	if (right_low <= right_high)
	{
	
		for (i = right_low; i <= right_high; i++)
		{
			tmp[k++] = s[i];
			m++;
		}
	}
	for (i = 0; i < high - low + 1; i++)
	{
		s[low + i] = tmp[i];
		m++;
	}
	free(tmp);
	return;
}

void MergeSort(int s[], int first, int last)
{
	int mid = 0;
	if (first<last) 
	{
		mid = (first + last) / 2; //注意防止溢出 
								  //mid = first/2 + last/2;
								  //mid = (first & last) + ((first ^ last) >> 1);
		MergeSort(s, first, mid);
		MergeSort(s, mid + 1, last);
		merge(s, first, mid, last);
	}
	return;
}

void Print(int *t,int len,int c,int m)
{

	for (int j = 0; j < len; j++)
		printf("%d  ", t[j]);
	printf("care: %d   m: %d   total: %d\n", c, m, c + m);
	
}

int main()
{
	int n;
	srand((int)time(NULL)); /*定义这个可以产生不同的随机数*/
	n = rand() %5+10;
	printf("%d\n", n);
	int *t;
	t = (int *)malloc(n*sizeof(int));
	for (int i = 0; i < n; i++)
	{
		t[i] = rand() % 200;
	}

	//copy测试数组
	int *a,*b,*d,*e,*h;
	a = Copy(t,n);
	b = Copy(t, n);
	e = Copy(t, n);
	d = Copy(t, n);
	h = Copy(t, n);

	printf("Example: ");
	for (int j = 0; j < n; j++)
		printf("%d  ", t[j]);
	printf("\n\n");

	//直接插入排序
	printf("InsertSort: ");
	InsertSort(a, n);
	Print(a, n, c, m);

	//希尔排序
	printf("ShellSort:  ");
	ShellSort(b, n);
	Print(b, n, c, m);

	//冒泡排序
	printf("BubbleSort: ");
	BubbleSort(d, n);
	Print(d, n, c, m);


	//简单选择排序
	printf("SelectSort: ");
	SelectSort(e, n);
	Print(e, n, c, m);

	//快速排序
	c = 0; 
	m = 0;
	printf("QuickSort:  ");
	QuickSort(h,n,0,n-1);
	Print(h, n, c, m);
	
	//归并排序
	c = 0;
	m = 0;
	printf("MergeSort:  ");
	MergeSort(t, 0, n - 1);
	Print(t, n, c, m);

	free(t);
	free(a);
	free(b);
	free(d);
	free(e);
	free(h);
	return 0;
}