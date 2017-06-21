#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SUCCESS 1 
#define UNSUCCESS 0 
#define DUPLICATE -1 

typedef int KeyType; 
typedef int ValueType; 

typedef struct _ElemType { 
	KeyType key;      // 关键字 
	ValueType val;    // 值 
#ifdef CHAINED_HASH 
	struct _ElemType *next; 
#endif 
} ElemType; 

typedef struct 
{ 
	ElemType *elem;//数据元素存储基址 动态分配数组 
	int count;//当前数据元素个数 
	int size_index;//hashsize[size_index]为当前容量 
}HashTable; 


typedef enum { // 函数返回值 
	OK, 
	ERROR 
}Status; 

typedef enum { // 布尔返回值 
	FALSE, 
	TRUE 
}Bool; 

int InsertHash(HashTable *H, ElemType e)
{
	int c,p;
	if(SearchHash(*H,e.key,&p,&c) == SUCCESS)
	{
		return DUPLICATE;
	}
	else
	{
		if(p == (*H).size_index || c > (*H).size_index / 2)
		{
			RecreateHashTable(H);
		}
		(*H).elem[p] = e;
		++(*H).count;
		printf("冲突次数: %d\n",c);
		printf("Insert:%d->%d\n",H->elem[p].key, H->elem[p].val);
		printf("\n");
		return 0;
	}
}

Status CreateHash(HashTable *H,int size)
{
	ElemType temp;
	int i;

	(*H).size_index = size;
	(*H).count = 0;
	(*H).elem = (ElemType *)malloc(sizeof(ElemType) * size);

	if(!((*H).elem))
	{
		return ERROR;
	}
	for(i = 0; i < size; i++)
	{
		(*H).elem[i].key = -1;
		(*H).elem[i].val = 0;
	}
	printf("---------------Hash表建立----------------\n");
	printf("HashTable 大小 : %d\n",(*H).size_index);
	for(i = 0; H->count < size / 2; i++)
	{
		temp.key = rand() % 501;    //产生随机数据
		temp.val = rand() % 501;
		InsertHash(H, temp);
	}
	printf("建立完成！\n\n");
	return OK;
}

Bool Empty(HashTable H)    //判断哈希表是否为空
{
	if(H.count == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

Bool Prime(int n)          //判断是否为素数
{
	int i;

	if(n == 2)
	{
		return TRUE;
	}
	for(i = 2; i <= (int)sqrt((double)n); i++)
	{
		if(n % i == 0)
		{
			return FALSE;
		}
	}
	return TRUE;
}

Bool hash(KeyType a,KeyType b)
{
	if(a == b)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int SearchHash(HashTable H, KeyType K, int *p, int *w)
{
	*p = K % H.size_index;
	*w = 0;
	while(H.elem[*p].key != -1 && !hash(K,H.elem[*p].key))
	{
		if((*p) < H.size_index)
		{
			printf("冲突： %d->%d\n",H.elem[*p].key,H.elem[*p].val);
			(*p)++;
			(*w)++;
		}
		else
		{
			break;
		}
	}
	if(hash(K,H.elem[*p].key))
	{
		return SUCCESS;
	}
	else
	{
		return UNSUCCESS;
	}
}

Status RecreateHashTable(HashTable *H)
{
	int i,n;
	HashTable temp;
	ElemType e;
	if(Empty(*H))
	{
		return ERROR;
	}
	e.key = -1;
	e.val = 0;
	n = 2 * (*H).size_index;
	while (!Prime(n))
	{
		n++;
	};
	temp.size_index = n;
	temp.count = (*H).count;
	temp.elem = (ElemType *)malloc(sizeof(ElemType)*n); 
	for(i = 0; i < n; i++)
	{
		temp.elem[i].key = -1;
		temp.elem[i].val = 0;
	}
	for(i = 0; i < (*H).size_index; i++)
	{
		(*H).elem[i].key = temp.elem[i].key;
		(*H).elem[i].val = temp.elem[i].val; 
	}
	(*H).size_index = temp.size_index;
	(*H).count = temp.count;
	(*H).elem = (ElemType *)malloc(sizeof(ElemType)*n);
	for(i = 0; i < n; i++)
	{
		(*H).elem[i].key = temp.elem[i].key;
		(*H).elem[i].val = temp.elem[i].val;
	}
	free(temp.elem);
	return OK;
}

Status Print(HashTable H)
{
	int i;
	if(Empty(H))
	{
		return ERROR;
	}

	printf("---------------打印哈希表---------------\n");
	for(i = 0; i < H.size_index; i++)
	{
		printf("[%d] : %d->%d\n", i, H.elem[i].key, H.elem[i].val); 
	}
		printf("打印完成！\n");
		printf("\n");
		return OK;
}

int main()
{
	int size = 0,i;
	int p,c;
	HashTable H;
	ElemType e;
	srand(time(NULL));
	while(Prime(size))
	{
		size = rand() % 11 + 20;
	}
	CreateHash(&H,size);
	Print(H);

	p = c = 0;
	printf("-------------查找---------------\n");
	for(i = 0; i < H.size_index; i++)
	{
		e.key = rand() % 501;
		printf("查找：%d\n",e.key);
		if(SearchHash(H,e.key,&p,&c) == SUCCESS)
		{
			printf("查找到：%d\n",e.key);
			printf("The Element Is : %d->%d\n", H.elem[p].key, H.elem[p].val); 
			printf("----------------------------------\n");
		}
		else
		{
			printf("查找不存在：%d\n",e.key);
			printf("----------------------------------\n");
		}
	}
	printf("查找结束！\n");

	printf("-----------------------重新建立哈希表--------------------\n");
	if(!RecreateHashTable(&H))
	{
		printf("\n");
		Print(H);
		printf("重新建立结束！\n");
		
	}
	return 0;
}