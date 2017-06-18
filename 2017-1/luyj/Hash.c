#include "Hash.h"


int getP(int length)  
{
	//找到不大于表长的最大质数
	int p = 0;
	int flag = 0;
	int i,j;
	for (i = length; i > 0; i--)
	{
		flag = 0;
		for (j = 2; j <i; j++)
		{
			if (i%j == 0)
			{
				flag = 1;
				break;
			}
		}
		if (0 == flag)
		{
			p = i;
			break;
		}
	}
	return p;
}

int Hash(int k, int p) 
{
	//关键字被不大于表长的最大质数求余后的结果,即获取关键字所在位置

	return k%p;
}

Bool EQ(KeyType k, KeyType key)
{
	if (k == key)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

Status collision(int *q,int p)
{
	(*q)++;
	(*q) = (*q) % p;
	return OK;
}

Status RecreateHashTable(HashTable *h)
{
	int i;
	int count = h->count;
	ElemType *x;
	ElemType *elem = (ElemType*)malloc(count*(sizeof(ElemType)));
	x = elem;
	for (i = 0; i < count; i++)//复制表数据到elem中
	{
		*x = h->elem[i];
		x++;
	}
	h->count = 0;
	h->sizeindex = h->sizeindex * 2;
	x = (ElemType*)realloc(h->elem, h->sizeindex * sizeof(ElemType));
	if (!x)
	{
		return ERROR;
	}
	h->elem = x;
	for (i = 0; i < h->sizeindex; i++)
	{
		h->elem->key = NULL;
	}
	x = elem;
	for (i = 0; i < count; i++)
	{
		InsertHash(h, *x);
	}
	

}
int SearchHash(HashTable h, KeyType k, int *q, int *c, int p) 
{
	// 在开放定址哈希表H中查找关键码为K的记录
	// c用于记录冲突次数，初值置0

	*q = Hash(k,p); // 求得哈希地址
	while (-1 != h.elem[*q].key && !EQ(k, h.elem[*q].key))
	{
		(*c)++;
		collision(q, p);
		if ((*c) > h.sizeindex)
		{
			break;
		}
	}// 求得下一探查地址 p
	if (EQ(k, h.elem[*q].key))
	{ // 查找成功，p返回待查数据元素位置
		return SUCCESS;
	}
	else if (-1 == h.elem[*q].key)
	{
		return FAILED;   // 查找不成功
	}
}

int InsertHash(HashTable *h, ElemType e) 
{
	// 查找不成功时插入数据元素e到开放地址哈希表H中，并返回OK
	// 若冲突次数过大，则重建哈希表
	int c = 0;//记录冲突次数
	int q;
	int p;
	p = getP(h->sizeindex);
	if (SUCCESS == SearchHash(*h, e.key, &q, &c, p))
	{ 
		// 表中已有与 e 有相同关键字的元素
		return DUPLICATE;
	}
	else if (c < p) 
	{
		// 冲突次数 c 未达到上限
		h->elem[q] = e;
		++h->count;
		return OK;
	}
	else 
	{
		// 重建哈希表，极端情况下可能哈希表“已满”。
		// 所以通常的重建过程都是先增大新哈希表的容量
		RecreateHashTable(h);
	}
}

Status InitHashTable(HashTable *h,int num)
{

	int i;
	h->count = 0;
	h->sizeindex = num;
	h->elem = (ElemType*)malloc(h->sizeindex * sizeof(ElemType));
	if (!(h->elem))
		return ERROR;
	ElemType*p = h->elem;
	for (i = 0; i < h->sizeindex; i++)
	{
		p->key = NULL;
		p->val = 0;
		p++;
	}
}
