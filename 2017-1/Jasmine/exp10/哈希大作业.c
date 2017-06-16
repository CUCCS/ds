#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include<time.h>

#define  SUCCESS    1
#define  FAILED     0
#define  DUPLICATE -1 
#define  NULLKEY   -1 
#define  NONEVALUE  0 

typedef int KeyType;
typedef int ValueType;

typedef enum {
	OK,
	ERROR
}Status;

typedef enum
{
	FALSE, TRUE
}bool;

typedef struct _ElemType
{
	KeyType key;      // 关键字
	ValueType val;    // 值
#ifdef CHAINED_HASH
	struct _ElemType *next;
#endif
} ElemType;

typedef struct {
	ElemType  *elem; // 储存哈希表元素
	int  count;     // 元素个数
	int  sizeindex; // 容量
} HashTable;

Status CreateHash(HashTable *H, int size); // 构建Hash表
bool Empty(HashTable H); // 判断Hash表是否为空
bool Prime(int n); // 判断是否为素数
int SearchHash(HashTable H, KeyType K, int *p, int *c); // 在Hash表中查找关键字为K的元素
Status InsertHash(HashTable *H, ElemType e); // 往Hash表中插入新的元素
bool EQ(KeyType a, KeyType b); // 判断关键字是否相等
Status RecreateHashTable(HashTable *H); // 重建Hash表
Status Print(HashTable H); // 输出Hash表

Status CreateHash(HashTable *H, int size) {
	// 构建Hash表
	ElemType temp;
	int i;

	(*H).sizeindex = size;
	(*H).count = 0;
	(*H).elem = (ElemType *)malloc(sizeof(ElemType) * size);

	if (!((*H).elem)) {
		return ERROR;
	}

	for (i = 0; i < size; i++) {
		(*H).elem[i].key = NULLKEY;
		(*H).elem[i].val = NONEVALUE;
	}

	printf("==========Creating HashTable==========\n");
	printf("HashTable size:%d\n", (*H).sizeindex);
	for (i = 0; H->count < size / 2; i++) {
		temp.key = (int)rand() % 501;
		temp.val = (int)rand() % 501;
		InsertHash(H, temp);
	}
	printf("Crating Over\n\n");

	return OK;
}

bool Empty(HashTable H) {
	// 判断Hash表是否为空，即没有元素
	if (H.count == 0) {
		return TRUE;
	}

	return FALSE;
}

bool Prime(int n) {
	// 判断一个数是否为素数
	if (n == 2) {
		return TRUE;
	}

	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return FALSE;
		}
	}

	return TRUE;
}

int SearchHash(HashTable H, KeyType K, int *p, int *c) {
	// 在开放定址哈希表H中查找关键值为K的记录
	*p = K % H.sizeindex; // 求得哈希地址
	*c = 0; // c用于记录冲突次数，初值置0
	while (H.elem[*p].key != NULLKEY && !EQ(K, H.elem[*p].key)) {
		if ((*p) < H.sizeindex) {
			printf("Collide  with %d->%d\n", H.elem[*p].key, H.elem[*p].val);
			(*p)++;
			(*c)++;
		}
		else
			break;
	}
	if (EQ(K, H.elem[*p].key)) { // 查找成功，p返回待查数据元素位置
		return SUCCESS;
	}
	else {
		return FAILED;   // 查找不成功
	}
}

Status InsertHash(HashTable *H, ElemType e) {
	// 查找不成功时插入数据元素e到开放地址哈希表H中，并返回OK
	// 若冲突次数过大或找到末尾，则重建哈希表
	int c, p;
	if (SearchHash(*H, e.key, &p, &c) == SUCCESS)
		//表中已有与 e 有相同关键字的元素
	{
		return ERROR;
	}
	else {
		if (p == (*H).sizeindex || c > (*H).sizeindex / 2) {
			RecreateHashTable(H);
		}
		(*H).elem[p] = e;
		++(*H).count;
		printf("Collision times:%d\n", c);
		printf("Insert:%d->%d\n", H->elem[p].key, H->elem[p].val);
		printf("--------------------------\n");
		return OK;
	}
}

bool EQ(KeyType a, KeyType b) {
	// 判断关键值a是否等于b
	if (a == b) {
		return TRUE;
	}

	return FALSE;
}

Status RecreateHashTable(HashTable *H) {
	// 重建Hash表，即扩充（一个麻烦的做法）
	int i, n;
	HashTable temp; // 临时Hash表
	ElemType e;

	if (Empty(*H)) {
		return ERROR;
	}

	e.key = NULLKEY;
	e.val = NONEVALUE;
	n = 2 * (*H).sizeindex;

	while (!Prime(n)) {
		n++;
	};

	temp.sizeindex = n;
	temp.count = (*H).count;
	temp.elem = (ElemType *)malloc(sizeof(ElemType)*n);
	for (i = 0; i < n; i++) {
		temp.elem[i].key = NULLKEY;
		temp.elem[i].val = NONEVALUE;
	}
	for (i = 0; i < (*H).sizeindex; i++) {
		temp.elem[i].key = (*H).elem[i].key;
		temp.elem[i].val = (*H).elem[i].val;
	}

	(*H).sizeindex = temp.sizeindex;
	(*H).count = temp.count;
	(*H).elem = (ElemType *)malloc(sizeof(ElemType)*n);
	for (i = 0; i < n; i++) {
		(*H).elem[i].key = temp.elem[i].key;
		(*H).elem[i].val = temp.elem[i].val;
	}

	free(temp.elem);

	return OK;
}

Status Print(HashTable H) {
	// 遍历输出Hash表
	if (Empty(H)) {
		return ERROR;
	}

	printf("==========Print HashTable==========\n");
	for (int i = 0; i < H.sizeindex; i++)
		printf("[%d] : %d->%d\n", i, H.elem[i].key, H.elem[i].val);
	printf("Print Over\n");
	printf("\n");

	return OK;
}

int main()
{
	int size, i;
	int p, c;
	HashTable H;
	ElemType e;

	srand(time(NULL)); // 随机种子

	do {
		size = (int)rand() % 11 + 20; // 构建哈希表，大小在20~30之间
	} while (!Prime(size));

	CreateHash(&H, size);
	Print(H);

	p = c = 0;
	printf("==========Searching==========\n");
	for (i = 0; i < H.sizeindex; i++) {
		e.key = (int)rand() % 501;
		printf("Search : %d\n", e.key);
		if (SearchHash(H, e.key, &p, &c) == SUCCESS) {
			printf("Find %d\n", e.key);
			printf("The Element Is : %d->%d\n", H.elem[p].key, H.elem[p].val);
			printf("--------------------------\n");
		}
		else {
			printf("Didn't Find %d\n", e.key);
			printf("--------------------------\n");
		}
	}
	printf("Search Over\n\n");

	printf("==========Rebuild HashTable==========\n");
	if (!RecreateHashTable(&H)) {
		printf("Rebuild Over\n");
		Print(H);
	}

	return 0;
}