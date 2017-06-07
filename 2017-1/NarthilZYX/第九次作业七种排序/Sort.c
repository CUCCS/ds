#include "Sort.h"
int Move = 0;
int Compare = 0;
//刷新数组
int *Fresh(int a[])
{
	int *a2;
	a2 = (int *)malloc(sizeof(int)*MAXSIZE);
	for(int i = 0; i < MAXSIZE; i++)
	{
		a2[i] = a[i];
	}
	return a2;
}

//直接插入排序
void InsertSort(int a[], int n)
{
	int i, j;
	int compare = 0, move = 0;
	for(i = 1; i < n; i++)
		if(a[i] < a[i - 1]){
			int temp = a[i];
			compare++;
			for(j = i - 1; j >= 0 && a[j] > temp; j--){
				a[j + 1] = a[j];
				move++;
			}
			a[j + 1] = temp;
		}
		printf("move = %d, compare = %d, total = %d\n", move, compare, move+compare);
}

//希尔排序
void ShellSort( int a[], int n )
{
	int j, gap;
	int compare = 0, move = 0;
	for(gap = n / 2; gap > 0; gap /= 2)
		for (j = gap; j < n; j++)//从数组第gap个元素开始  
			if (a[j] < a[j - gap])//每个元素与自己组内的数据进行直接插入排序
			{
				compare++;
				int temp = a[j];
				int k = j - gap;
				while(k >= 0 && a[k] > temp)
				{
					a[k + gap] = a[k];
					k -= gap;
					move++;
				}
				a[k + gap] = temp;
			}
			printf("move = %d, compare = %d, total = %d\n", move, compare, move+compare);
}

//起泡排序
void BubbleSort( int a[], int n )
{
	int i, j;
	int compare = 0, move = 0;
	for(i = 0; i < n; i++)
		for(j = 1; j < n - i; j++){
			if (a[j - 1] > a[j]){
				compare++;
				int temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
			}
			move+=3;
		}
		printf("move = %d, compare = %d, total = %d\n", move, compare, move+compare);
}

//快速排序
void QuickSort( int a[], int l, int r)
{
	if(l < r)
	{
		int temp = a[l];
		a[l] = a[(l+r)/2];
		a[(l+r)/2] = temp;
		int i = l, j = r, x = a[l];
		while(i < j)
		{
			while(i < j && a[j] >= x)// 从右向左找第一个小于x的数
			{
				j--;
				Compare++;
			}
			if(i < j){
				a[i++] = a[j];
				Move++;
			}
			while(i < j && a[i] < x)// 从左向右找第一个大于等于x的数
			{
				i++;
				Compare++;
			}
			if(i < j){
				a[j--] = a[i];
				Move++;
			}
		}
		a[i] = x;
		QuickSort(a, l, i -1);// 递归调用
		QuickSort(a, i+ 1, r );
	}
}

//简单选择排序
void SelectSort( int a[], int n )
{
	int min;
	int move = 0;
	int compare = 0;
	for(int i = 0; i < n - 1; i++)
	{
		min = i;
		for(int j = i + 1; j < n ; j++)
		{
			if(a[j] < a[min])//使得min总是指向最小元素
			{
				compare++;
				min = j;
			}
		}
		if(min != i)//即min有移动过
		{
			int temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}
		move+=3;
	}
	printf("move = %d, compare = %d, total = %d\n", move, compare, move+compare);
}

//堆排序
void HeapAdjust(int a[], int i, int n)
{
	int Child;
	int temp;
	for(;2 * i + 1 < n; i = Child)
	{
		//子节点的位置 = 2 * (parent(父结点)) + 1
		Child = 2 * i + 1;
		//得到子结点中较大的结点
		if(Child < n - 1 && a[Child + 1] > a[Child]){
			++Child;
			Compare++;
		}
		//如果较大的子结点大于父结点那么把较大的子结点往上移动
		//替换它的父结点
		if(a[i] < a[Child])
		{
			temp = a[i];
			a[i] = a[Child];
			a[Child] = temp;
			Move+=3;
		}else{
			break;
		}
	}
}
//堆排序算法
void HeapSort(int a[], int n)
{
	int i;
	//调整序列的前半部分元素，调整完之后第一个元素
	//是序列的最大元素，n/2-1是最后一个非叶子结点
	for(i = n/2 - 1; i >= 0; --i){
		HeapAdjust(a, i, n);
	}
	for(i = n - 1; i > 0; --i)
	{
		a[i] = a[0]+a[i];
		a[0] = a[i]-a[0];
		a[i] = a[i]-a[0];
	    Move+=3;
		HeapAdjust(a,0,i);//递归调整
	}
}

//归并排序
void MergeArray(int a[], int first, int mid, int last, int temp[])
{
	int i = first, j = mid + 1;
	int m = mid, n = last;
	int k = 0;
	while(i <= m && j <=n )
	{
		if(a[i] <= a[j]){
			Compare++;
			temp[k++] = a[i++];
		}
		else{
			Compare++;
			temp[k++] = a[j++];
		}
	}
	while(i <= m)
	{
		temp[k++] = a[i++];
	}
	while(j <= n)
	{
		temp[k++] = a[j++];
	}
	for(i = 0; i < k; i++)
	{
		a[first + i] = temp[i];
		Move++;
	}
}
void MergeSort(int a[], int first, int last, int temp[])
{
	if(first < last)
	{
		int mid = (first + last) / 2;
		MergeSort(a, first, mid, temp);//左边有序
		MergeSort(a, mid + 1, last, temp);//右边有序
		MergeArray(a, first, mid, last, temp);//再将二个有序数列合并
	}
}

Bool MergeSort(int a[], int n)
{
	int *p = (int *)malloc(sizeof(int)*MAXSIZE);
	if(p == NULL){
		return FALSE;
	}
	MergeSort(a, 0, n - 1, p);
	return TRUE;
}

void printSort(int a[])
{
	for(int i = 0; i < MAXSIZE; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	int a[MAXSIZE], *b;
	srand((int)time(NULL));
	for(int i = 0; i < MAXSIZE; i++){
		
		a[i] = rand()%101 + 5*i;
	}
	b = (int *)malloc(sizeof(int)*MAXSIZE);
	int move = 0;
    int compare = 0;

	//test1
	b = Fresh(a);
	printf("InsertSort:\n");
	printf("Before sorted:\n");
	printSort(b);
	printf("After sorted:\n");
	InsertSort( b, MAXSIZE );
	printSort(b);

	//test2
	b = Fresh(a);
   printf("\nShellSort:\n");
   printf("Before sorted:\n");
	printSort(b);
	printf("After sorted:\n");
   ShellSort( b, MAXSIZE );
   printSort(b);

   //test3
   b = Fresh(a);
   printf("\nBubbleSort:\n");
   printf("Before sorted:\n");
	printSort(b);
	printf("After sorted:\n");
   BubbleSort( b, MAXSIZE );
   printSort(b);

   //test4
   b = Fresh(a);
   printf("\nQuickSort:\n");
   printf("Before sorted:\n");
	printSort(b);
	printf("After sorted:\n");
   QuickSort( b, 0, MAXSIZE-1);
   printf("move = %d, compare = %d, total = %d\n", Move, Compare, Move+Compare);
   printSort(b);

   //test5
   b = Fresh(a);
   printf("\nSelectSort:\n");
   printf("Before sorted:\n");
	printSort(b);
	printf("After sorted:\n");
   SelectSort( b, MAXSIZE );
   printSort(b);

   //test6
   b = Fresh(a);
   Move = 0;
   Compare = 0;
   printf("\nHeapSort:\n");
   printf("Before sorted:\n");
	printSort(b);
	printf("After sorted:\n");
   HeapSort( b, MAXSIZE );
   printf("move = %d, compare = %d, total = %d\n", Move, Compare, Move+Compare);
   printSort(b);

   //test7
   b = Fresh(a);
   Move = 0;
   Compare = 0;
   printf("\nMergeSort:\n");
   printf("Before sorted:\n");
	printSort(b);
	printf("After sorted:\n");
	
   if(MergeSort( b, MAXSIZE )){
	   printf("move = %d, compare = %d, total = %d\n", Move, Compare, Move+Compare);
	   printSort(b);
   }
   

	return 0;
}