#include"OHash.h"
bool isSushu(int a)
{
	for (int i = 2; i < sqrt(a)+2; i++)

	{
		if (a%i == 0)return false;
	}
	return true;
}
int hashsize(int size)
{
	int p = size;
	if (p == 1)return 1;
	while (!isSushu(p--));//从size开始往下的遇到的第一个素数，此处借鉴钟总
	return p + 1;
}
int Hash(KeyType K, int size)
{
	int p = hashsize(size);
	return K%p;
}
bool EQ(int a, int b) { return(a == b); }
void collision(int *p, int *c){ (*p)++ ; (*c)++; }

HashTable NewHashTable(int size)
{
	HashTable temp;
	temp.count = 0;
	temp.sizeindex = size;
	temp.elem = (ElemType*)malloc(size * sizeof(ElemType));
	for (int i = 0; i < size; i++)
	{
		temp.elem[i].key = -1;
		temp.elem[i].val = 0;
	}
	return temp;
}
void RecreateHashTable(HashTable *H)
{
	HashTable temp = NewHashTable(H->sizeindex * 2);
	int a = H->sizeindex;
	for (int i = 0; i <a; i++)
	{
		temp.elem[i] = H->elem[i];
	}
	H->sizeindex *= 2;
	H->elem= (ElemType*)malloc(H->sizeindex * sizeof(ElemType));
	for (int i = 0; i < H->sizeindex; i++)
	{
		H->elem[i].key = -1; H->elem[i].val = 0;
	}
	for (int i = 0; i < a; i++)
	{
		int p = Hash(temp.elem[i].key, H->sizeindex);
		H->elem[p] = temp.elem[i];
	}
}
Status SearchHash(HashTable H, KeyType K, int *p, int *c)
{
	*p = Hash(K,H.sizeindex); // 求得哈希地址
	while (H.elem[*p].key != NULLKEY && !EQ(K, H.elem[*p].key)) {
		collision(p, c);       //冲突，求得下一探查地址 p
		//printf("***");
	}

	if (EQ(K, H.elem[*p].key)) { // 查找成功，p返回待查数据元素位置
		return SUCCESS;
	}
	else {
		return FAILED;   // 查找不成功
	}
}
Status InsertHash(HashTable &H, ElemType e)
{
	// 查找不成功时插入数据元素e到开放地址哈希表H中，并返回OK
	// 若冲突次数过大，则重建哈希表
	int a = 0,b=0;
	int *c ;//用于记录冲突次数
	c = &a;
	int *p ;
	p = &b;
	if (SearchHash(H, e.key, p, c) == SUCCESS) { // 表中已有与 e 有相同关键字的元素
		if ((*c) != 0)
		{
			printf("\n哈希冲突！次数：%d，关键字值：%d->%d\n", *c, e.key, e.val);
		}
		return DUPLICATE;
	}

	else if (*c < hashsize(H.sizeindex) / 2) {
		// 冲突次数 c 未达到上限，（阀值可调，此处仅为示例）
		H.elem[*p] = e;
		++H.count;
		return OK;
	}
	else {
		// 重建哈希表，极端情况下可能哈希表“已满”。
		// 所以通常的重建过程都是先增大新哈希表的容量
		RecreateHashTable(&H);
	}
}