#include "hash.h"

int hashsize[] = { 11,19,29,37 };///哈希表容量递增表 一个合适的素数序列
int m = 0;//哈希表表长 全局变量

ElemType newElemType(KeyType key, ValueType value)
{
	ElemType temp = { key,value };
	return temp;
}
int initHashTable(HashTable *H)
{
	int i;
	(*H).count = 0;//当前元素个数为0
	(*H).size_index = 0;//初始存储容量为hashsize[0]
	m = hashsize[0];
	(*H).elem = (ElemType *)malloc(m * sizeof(ElemType));
	if (!(*H).elem)
		exit(0);//存储分配失败
	for (i = 0; i < m; i++)
		(*H).elem[i].key = NULLKEY;//未填记录的标记

	return 1;
}

/*销毁哈希表*/
void destroyHashTable(HashTable *H)
{
	free((*H).elem);
	(*H).elem = NULL;
	(*H).count = 0;
	(*H).size_index = 0;
}

/* 一个简单的哈希函数(m为表长 全局变量)*/
unsigned Hash(KeyType K)
{
	return K%m;
}

/*线性探测再散列*/
void collision(int *p, int d)
{
	collisiontime = 0;
	*p = (*p + d) % m;
	collisiontime++;//开放定址法处理冲突
}

/* 在开放定址哈希表H中查找关键码为K的元素,若查找成功,以p指示待查数据 */
/* 元素在表中位置,并返回SUCCESS;否则,以p指示插入位置,并返回UNSUCCESS */
/* c用以计冲突次数，其初值置零，供建表插入时参考 */
int searchHash(HashTable H, KeyType K, int *p, int *c)
{
	*p = Hash(K);//求得哈希地址
	while (H.elem[*p].key != NULLKEY && !EQ(K, H.elem[*p].key))//该位置中填有记录 并且关键字不相等
	{
		(*c)++;
		if (*c < m)
			collision(p, *c);//求得下一探查地址p
		else
			break;
	}
	if EQ(K, H.elem[*p].key)
		return SUCCESS;//查找成功 p返回待查数据元素位置
	else
		return UNSUCCESS;//查找不成功(H.elem[p].key==NULLKEY p返回的是插入的位置)
}

void recreateHashTable(HashTable *H)//重建哈希表
{
	int i, count = (*H).count;
	ElemType *p, *elem = (ElemType *)malloc(count * sizeof(ElemType));
	p = elem;
	printf("\n重建哈希表\n\n");
	for (i = 0; i < m; i++)//保存原有的数据到elem中
		if (((*H).elem + i)->key != NULLKEY)//该单元有数据
			*p++ = *((*H).elem + i);
	(*H).count = 0;
	(*H).size_index++;//增大存储容量
	m = hashsize[(*H).size_index];
	p = (ElemType *)realloc((*H).elem, m * sizeof(ElemType));
	if (!p)
		exit(0);//存储分配失败
	(*H).elem = p;
	for (i = 0; i < m; i++)
		(*H).elem[i].key = NULLKEY;//未填记录标志（初始化）
	for (p = elem; p < elem + count; p++)//将原有的数据按照新的表长插入到重建的哈希表中
		insertHash(H, *p);
}

/* 查找不成功时插入数据元素e到开放定址哈希表H中，并返回1 */
/* 若冲突次数过大，则重建哈希表 */
int insertHash(HashTable *H, ElemType e)
{
	int c, p;

	c = 0;
	if (searchHash(*H, e.key, &p, &c))//表中已有与e有相同关键字的元素
		return DUPLICATE;
	else if (c < hashsize[(*H).size_index] / 2)//冲突次数c未达到上线 c的阀值可调
	{
		(*H).elem[p] = e;//插入e
		++(*H).count;
		return 1;
	}
	else
	{
		recreateHashTable(H);//重建哈希表
	}
	return 0;
}

/* 按哈希地址的顺序遍历哈希表 */
void traverseHash(HashTable H, void(*Vi)(int, ElemType))
{
	int i;
	printf("哈希地址0~%d\n", m - 1);
	for (i = 0; i < m; i++)
	{
		if (H.elem[i].key != NULLKEY)//有数据
			Vi(i, H.elem[i]);
		else
		{
			H.elem[i].key = -1;
			H.elem[i].val = 0;
			Vi(i, H.elem[i]);
		}
	}
}

/* 在开放定址哈希表H中查找关键码为K的元素,若查找成功,以p指示待查数据 */
/* 元素在表中位置,并返回SUCCESS;否则,返回UNSUCCESS */
int find(HashTable H, KeyType K, int *p)
{
	int c = 0;
	*p = Hash(K);//求得哈希地址
	while (H.elem[*p].key != NULLKEY && !EQ(K, H.elem[*p].key))//该位置中填有记录．并且关键字不相等
	{
		c++;
		if (c < m)
			collision(p, c); //求得下一探查地址p
		else
			return UNSUCCESS; // 查找不成功(H.elem[p].key==NULLKEY)
	}
	if EQ(K, H.elem[*p].key)
		return SUCCESS; //查找成功，p返回待查数据元素位置
	else
		return UNSUCCESS; // 查找不成功(H.elem[p].key==NULLKEY)
}

void printHash(int p, ElemType r)
{
	printf("{ [%d] : %d->%d }\n", p, r.key, r.val);
}