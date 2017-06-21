#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define  SUCCESS    1
#define  FAILED     0
#define  DUPLICATE -1 // 重复
#define  NULLKEY   -1 // 空关键字
#define  NONEVALUE  0 // 空值

typedef int KeyType;
typedef int ValueType;

typedef enum { // 函数返回值
	OK,
	ERROR
}Status;

typedef enum { // 布尔返回值
	FALSE,
	TRUE
}bool;

typedef struct _ElemType {
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