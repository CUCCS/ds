#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define maxsize 5
typedef enum
{
	false,
	true
}bool;
typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;
typedef struct
{
	int r[maxsize];
	int length;
}SqList;

Status output(SqList a)
{
	int i;
	for(i = 0;i < maxsize;i++)
	{
		printf("%d ",a.r[i]);
	}
	printf("\n");
	return OK;
};

Status Initarray(SqList* a,SqList* b,int* comtimes,int* movetimes)
{
	int i;
	for(i = 0;i < maxsize;i++)
	{
		b->r[i] = a->r[i] ;
	}
	*comtimes = 0;
	*movetimes = 0;
	return OK;
};

Status InsertSort(SqList* L,int* comtimes,int* movetimes)
{
	int j,i;
	int temp;
	for(i = 1;i < L->length;i++)
	{
		if(L->r[i] < L->r[i-1])
		{
			j = i-1;
			(*comtimes)++;
			temp = L->r[i];
			L->r[i] = L->r[i-1];
			(*movetimes)++;
			while(temp < L->r[j])
			{
				L->r[j+1] = L->r[j];
				(*movetimes)++;
				j--;
			}
			
			L->r[j+1] = temp;
			(*comtimes)++;
		}
	}
	return OK;
};


Status ShellSort(SqList* L,int *comtimes,int* movetimes)
{
	int j, gap,temp,k;
	for(gap = L->length/2; gap > 0;gap /= 2)
		for(j = gap;j < L->length;j++)//从数组第gap个元素开始
		{
			if(L->r[j] < L->r[j-gap])//每个元素与自己组内的数据进行直接插入排序
			{
				(*comtimes)++;
				temp = L->r[j];
				k = j-gap;
				while(k >= 0 && L->r[k] > temp)
				{
					L->r[k+gap] = L->r[k];
					k -= gap;
					(*movetimes)++;
				}
				L->r[k+gap] = temp;
			}
		}
	return OK;
};

Status BubbleSort(SqList* L,int* comtimes,int* movetimes)
{
	int temp,i,j;
	for(i = 0;i < L->length;i++)
	{
		for(j = 0;j < L->length-i-1;j++)
		{
			if(L->r[j] > L->r[j+1])
			{
				(*comtimes)++;
				temp = L->r[j];
				L->r[j] = L->r[j+1];
				L->r[j+1] = temp;
				(*movetimes) += 3;
			}
		}
	}
	return OK;
}
int QKPass(SqList *L, int left, int right, int* comtimes,int* movetimes)
{ 
	int key = L->r[left]; 
	int low = left; 
	int high = right; 
	while (low < high) 
	{ 
		while (low < high&&L->r[high] >= key&&(*comtimes)++) 
		{
			high--; 
		} 
		L->r[low] = L->r[high]; 
		++(*movetimes); 
		while (low < high&&L->r[low] < key && ((*comtimes)++)) 
		{ 
			low++; 
        } 
        L->r[high] = L->r[low]; 
        ++(*movetimes);
    } 
    L->r[low] = key; 
    (*movetimes)++; 
    return low; 
};

Status QuickSort(SqList* L, int low, int high, int *comtimes, int *movetimes)
{
	int pivotlo; 
	if (low < high) 
	{
		pivotlo = QKPass(L, low, high, comtimes, movetimes); 
		QuickSort(L, low, pivotlo - 1, comtimes, movetimes); 
		QuickSort(L, pivotlo + 1, high, comtimes, movetimes); 
	}
	return OK; 
} 

int SelectMinKey(SqList* L , int i,int* comtimes,int* movetimes)
{
	int k = i;
    int j;
	for(j = i+1 ;j < L->length; ++j)
	{
		if(L->r[k] > L->r[j])
		{
			(*comtimes)++;
			k = j;
		}
	}
	return k;
};

Status SelectSort(SqList* L,int* comtimes,int* movetimes)
{
	int i;
	int key,temp;
	for(i=0;i<L->length;i++)
	{
		key = SelectMinKey(L,i,comtimes,movetimes);
		if(key!=1)
		{
			temp = L->r[i];
			L->r[i] = L->r[key];
			L->r[key] = temp;
			(*movetimes)+=3;
		}
	}
	return OK;
};

int main()
{
	int comtimes, movetimes;
	int i;
	SqList a,b;
	comtimes = movetimes = 0;

	srand((unsigned)time(NULL));
	a.length = b.length = 0;
	for(i = 0;i < maxsize;i++)
	{
		a.r[i] = rand() % 100 + 1;
		b.r[i] = a.r[i];
		a.length++;
		b.length++;
	}

	printf("测试数组为：\n");
	output(a);

	printf("经过直接排序后的数组为：");
	InsertSort(&b,&comtimes,&movetimes);
	output(b);
	printf("总比较次数：%d\n总排序次数：%d\n两者之和：%d\n\n",comtimes,movetimes,comtimes+movetimes);

	Initarray(&a,&b,&comtimes,&movetimes);

	
	printf("经过希尔排序后的数组为：");
	ShellSort(&b,&comtimes,&movetimes);
	output(b);
	printf("总比较次数：%d\n总排序次数：%d\n两者之和：%d\n\n",comtimes,movetimes,comtimes+movetimes);

	Initarray(&a,&b,&comtimes,&movetimes);

	printf("经过气泡排序后的数组为：");
	BubbleSort(&b,&comtimes,&movetimes);
	output(b);
	printf("总比较次数：%d\n总排序次数：%d\n两者之和：%d\n\n",comtimes,movetimes,comtimes+movetimes);

	Initarray(&a,&b,&comtimes,&movetimes);

	printf("经过快速排序后的数组为：");
	QuickSort(&b,0,4,&comtimes,&movetimes);
	output(b);
	printf("总比较次数：%d\n总排序次数：%d\n两者之和：%d\n\n",comtimes,movetimes,comtimes+movetimes);

	Initarray(&a,&b,&comtimes,&movetimes);

	printf("经过简单排序后的数组为：");
	SelectSort(&b,&comtimes,&movetimes);
	output(b);
	printf("总比较次数：%d\n总排序次数：%d\n两者之和：%d\n\n",comtimes,movetimes,comtimes+movetimes);

	return 0;
}