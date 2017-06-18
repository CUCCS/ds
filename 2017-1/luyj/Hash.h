#include <stdio.h>
#include <malloc.h>
#include <time.h>

#define NULL -1
#define  SUCCESS    1
#define  FAILED     0
#define  DUPLICATE -1

typedef int KeyType;
typedef int ValueType;
typedef struct _ElemType
{
	KeyType key;
	ValueType val;
#ifdef CHAINED_HASH
	struct _ElemType *next;
#endif // CHAINED_HASH

}ElemType;

typedef struct
{
	ElemType  *elem;
	int  count;     // 当前数据元素个数
	int  sizeindex; // hashsize[sizeindex]为当前容量
} HashTable;

typedef enum
{
	FALSE,
	TRUE
}Bool;

typedef enum
{
	OK,
	ERROR
}Status;

int InsertHash(HashTable *h, ElemType e);
int Hash(int k, int p);
Bool EQ(KeyType k, KeyType key);
Status collision(int *q, int p);
Status RecreateHashTable(HashTable *h);
int SearchHash(HashTable h, KeyType k, int *q, int *c, int p);
Status InitHashTable(HashTable *h, int num);
