#include "Hash.h"

/* 初始化哈希表 */
void InitHashTable(HashTable *H) {
	int i;
	H->count = 0;
	H->sizeindex = SizeIndex;
	H->elem = (ElemType*)malloc(H->sizeindex * sizeof(ElemType));
	for (i = 0; i < H->sizeindex; i++) {
		H->elem[i].key = NULLKEY;
		H->elem[i].val = NULLKEY;
	}
}

/* 用随机生成的正整数序列填充Hash表 */
void CreateHashTable(HashTable * H) {
	int i;
	ElemType e;
	for (i = 0; i < H->sizeindex; i++) {
		e.val = rand() % 1024;
		e.key = e.val % H->sizeindex;
		InsertHash(H, e);
	}
	return;
}

/* 查找for本题 */
void _Search(HashTable T) {
	int i, p = 0, c = 0;
	ElemType e;
	printf("\n");
	for (i = 0; i < 5; i++)
	{
		e.val = (T.elem[i].key + 1 + rand())%1024;
		e.key = e.val % T.sizeindex;
		if (SearchHash(T, e, &p, &c)) {
			printf("关键字%d查找成功! 冲突次数%d\n", e.key, c);
		}
		else {
			printf("关键字%d查找失败!\n", e.key);
		}
	}

}

/* 返回哈希地址 */
int Hash(HashTable H,ValueType k) {
	int p;
	p = k%H.sizeindex;
	return p;
}

/* 解决哈希冲突 */
void collision(HashTable H,int *p, int *c) {
	*c++;
	*p = (*p + 1) % H.sizeindex;
}

/* 哈希表的查找 */
Status SearchHash(HashTable H, ElemType e, int *p, int *c) {
	// 在开放定址哈希表H中查找关键码为K的记录
	// c用于记录冲突次数，初值置0
	*p = e.key; // 求得哈希地址
	while (H.elem[*p].key != NULLKEY && e.key != H.elem[*p].key) {
		if(*p == H.sizeindex -1 )
			return  FAILED;
		collision(H,p, c);       // 求得下一探查地址 p
	}
	if (e.key == H.elem[*p].key) { // 查找成功，p返回待查数据元素位置
		return SUCCESS;
	}
	else {
		return FAILED;   // 查找不成功
	}
}

/* 向哈希表中插入数据 */
Status InsertHash(HashTable *H, ElemType e) {
	// 查找不成功时插入数据元素e到开放地址哈希表H中，并返回OK
	// 若冲突次数过大，则重建哈希表
	int p, c;
	c = 0;//记录冲突次数
	if (SearchHash(*H, e, &p, &c) == SUCCESS) {
		collision(*H,&p, &c);       // 表中已有与 e 有	相同关键字的元素
		while ((*H).elem[p].key != NULLKEY /*&& e.key != (*H).elem[p].key*/) {
			collision(*H,&p, &c);       // 求得下一探查地址 p
		}
		H->elem[p].val = e.val;
		H->elem[p].key = e.key;
		++H->count;
		return DUPLICATE;
	}
	else if (c < H->sizeindex / 2) {
		// 冲突次数 c 未达到上限，（阀值可调，此处仅为示例）
		H->elem[e.key].val = e.val;
		H->elem[e.key].key = e.key;
		++H->count;
		return SUCCESS;
	}
	else {
		// 重建哈希表，极端情况下可能哈希表“已满”。
		// 所以通常的重建过程都是先增大新哈希表的容量
		RecreateHashTable(H);
	}
	return SUCCESS;
}

/* 重建哈希表 */
void RecreateHashTable(HashTable *H) // 重建哈希表代码参考了csdn徐留根的发表 -【数据结构】哈希表
{
	printf("\n重建哈希表:\n");
	int i, count = (*H).count,n = (*H).sizeindex;
	ElemType *p , *elem = (ElemType*)malloc(count * sizeof(ElemType));
	p = elem;
	
	(*H).count = 0;
	for (i = 0; i < n; i++) { // 保存原有的数据到elem中   
		if (((*H).elem + i)->key != NULLKEY) { // 该单元有数据   
			*p++ = *((*H).elem + i);
			/*p->val = ((*H).elem + i)->val;
			p->key = Hash(*H, ((*H).elem + i)->val);
			p++;*/
		}
	}

	(*H).sizeindex += SizeIndex;
	for (i = 0; i < n; i++) { 
		if (((*H).elem + i)->key != NULLKEY) {
			p->val = ((*H).elem + i)->val;
			p->key = Hash(*H, ((*H).elem + i)->val);
			p++;
		}
	}
	 // 增大存储容量   
	p = (ElemType*)malloc((*H).sizeindex * sizeof(ElemType));
	if (!p)
		exit(1); // 存储分配失败   
   (*H).elem = p;
	for (i = 0; i < (*H).sizeindex; i++) {
		(*H).elem[i].key = -1; // 初始化   
	    (*H).elem[i].val = -1;
	}
	for (p = elem; p < elem + count ; p++) // 将原有的数据按照新的表长插入到重建的哈希表中   
		InsertHash(H, *p);
}

/* 打印哈希表 */
void PrintHashTable(HashTable H){
	int i = 0,j = 0;
	for (; i < H.sizeindex; i++) {
		// {[元素所在Hash表中的索引位置] : 关键字->值}
		printf("{[%d] : %d->%d}   ", i, H.elem[i].key, H.elem[i].val);
		j++;
		if(j%3 == 0)
			printf("\n");
	}
	printf("\n");
}
