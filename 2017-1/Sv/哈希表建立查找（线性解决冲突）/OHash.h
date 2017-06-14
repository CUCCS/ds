#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define  NULLKEY -1
//-----------------------------------
typedef int KeyType;
typedef int ValueType;
typedef struct _ElemType {
	KeyType key;      // 关键字
	ValueType val;    // 值
#ifdef CHAINED_HASH
	struct _ElemType *next;
#endif
} ElemType;
typedef struct _bool{ true,false }bool;
typedef struct {
	ElemType  *elem;//地址
	int  count;     // 当前数据元素个数
	int  sizeindex; // hashsize[sizeindex]为当前容量
} HashTable;
typedef enum _status
{
	SUCCESS, FAILED, DUPLICATE,OK
}Status;
//-----------------------------------
bool EQ(int, int);
bool isSushu(int a);//判断是否为素数
int hashsize(int size);
void RecreateHashTable(HashTable *H);
Status SearchHash(HashTable H, KeyType K, int *p, int *c);//哈希表中查找关键值为K的记录，c记录次数，p返回地址
int Hash(KeyType,int size);
Status InsertHash(HashTable &H, ElemType e);
HashTable NewHashTable(int size);






