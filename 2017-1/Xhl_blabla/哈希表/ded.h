#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#define init_num 9;
#define SUCCESS 1
#define UNSUCCESS 0
#define DUPLICATE  -1
#define init_num 9
#define search_num 6
typedef int status;
typedef int KeyType;
typedef int ValueType;
typedef struct _ElemType {
	KeyType key;      // 关键字
	ValueType val;    // 值
#ifdef CHAINED_HASH
	struct _ElemType *next;
#endif
} ElemType;
//难道我要用单链表存储吗
typedef struct
{
	ElemType *elem;
	int count;//当前元素个数
	int sizeindex;//哈希表表长
}HashTable;
static int m;//内部链接静态变量，m为哈希表表长  
static int hashsize[] = { 11,19,29,37,49 };//内部链接静态变量，哈希表容量（表长m）递增表，一个合适的素数序列。
int hashsize_count = 0;
int  hash_(KeyType e, int l);//进行寻址
void collision(int *p, int c, KeyType k, int l);//下一个搜寻的位置确定
status RecreateHashTable(HashTable *H);//重建哈希表
status InsertHash(HashTable *H, KeyType e, ValueType v);//进行插入操作
status SearchHash(HashTable  H, KeyType e, ValueType v, int* p, int *c);//进行查找操作
void TraverHash(HashTable  H);
status  InitHashTable(HashTable  *H);
void travel_(int *q, int l);