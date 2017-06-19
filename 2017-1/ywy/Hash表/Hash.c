#include"Hash.h"
bool SuS(int n)
{
	int i;
	if(n==2)
	{
		return TRUE;
	}
	for (i = 2; i < n; i++)
	{
		if(n%i==0)
		{
			return FALSE;
		}
	}
	return TRUE;
}
Status InitHashTable(HashTable*H,int size)
{
	int i;
	ElemType temp;
	H->count = 0;
	H->maxsize = size;
	H->elem = (ElemType*)malloc(sizeof(ElemType)*size);
	if (!(H->elem))
	{
		return error;
	}
	for (i = 0; i < size; i++)
	{
		H->elem[i].key = UNKEY;
		H->elem[i].val = UNVAL;
	}
	srand((unsigned)time(NULL));
	for (i = 0; H->count<size/2; i++)//装载因子0.5
	{
		
		temp.key = (int) rand() % size;
		temp.val = (int) rand() % size;
		InsertHashTable(H, temp);
		//printf("%d---%d",temp.key,temp.val);
	}
	return ok;
}
bool Empty(HashTable H)
{
	if (H.count == 0)
	{
		return TRUE;
	}
	return FALSE;
}
bool Equal(KeyType a, KeyType b)
{
	if(a==b)
	{
		return TRUE;
	}
	return FALSE;
}
int SearchHashTable(HashTable H, KeyType key, int*add, int*count)
{
	*add = key% H.maxsize;
	*count = 0;//冲突次数
	while (H.elem[*add].key != UNKEY && !Equal(key, H.elem[*add].key))//发生冲突
	{
		if ((*add) < H.maxsize)
		{
			//与Hash表中发生冲突的元素
			printf("冲突： 关键字--值%d->%d\n", H.elem[*add].key, H.elem[*add].val);
			(*add)++;
			(*count)++;
		}
		else
			break;
	}
	
	if (Equal(key, H.elem[*add].key))
	{
		return SUCCESS;
	}
	else
	{
		return UNSUCCESS;
	}
}
Status InsertHashTable(HashTable*H, ElemType e)
{
	int add, count;
	if (SearchHashTable(*H, e.key, &add, &count) == SUCCESS)
	{ 
		return DUPLICATE;
	}
	else {
		if (add == H->maxsize || count > H->maxsize / 2)
		{
			ReHash(H);
		}
		H->elem[add] = e;
	    H->count++;
		printf("插入[%d]:%d->%d", add, H->elem[add].key, H->elem[add].val);
		printf("碰撞次数:%d\n", count);
		return ok;
	}
	
}
Status ReHash(HashTable *H)
{
	int i, n;
	HashTable temp; 
	if (Empty(*H)) 
	{
		return error;
	}
	n = 2 * H->maxsize;
	while (!SuS(n)) 
	{
		n++;
	}
	temp.maxsize = n;
	temp.count = H->count;
	temp.elem = (ElemType *)malloc(sizeof(ElemType)*n);
	for (i = 0; i < n; i++)
	{
		temp.elem[i].key = UNKEY;
		temp.elem[i].val = UNVAL;
	}

	for (i = 0; i < H->maxsize; i++) {
		temp.elem[i].key = H->elem[i].key;
		temp.elem[i].val = H->elem[i].val;
	}

	H->maxsize = temp.maxsize;

	H->count = temp.count;

	H->elem = (ElemType *)malloc(sizeof(ElemType)*n);

	for (i = 0; i < n; i++) 
	{
		H->elem[i].key = temp.elem[i].key;
		H->elem[i].val = temp.elem[i].val;
	}

	free(temp.elem);
	return ok;
}
Status PrintHash(HashTable H)
{
	int i;
	if(Empty(H))
	{
		return error;
	}
	printf("print hash\n");
	for (i = 0; i < H.maxsize; i++)
	{
		printf("[%d]: %d->%d\n", i, H.elem[i].key, H.elem[i].val);
	}
	return ok;
}





