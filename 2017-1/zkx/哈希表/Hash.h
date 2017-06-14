#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG 1
#define COUNT 6
#define SIZEINDEX 11

typedef enum
{
	false,
	true
} bool;

typedef int KeyType;
typedef int ValueType;

typedef struct _ElemType
{
	KeyType key;      // 关键字
	ValueType val;    // 值
} ElemType;

typedef struct
{
	ElemType  *elem;
	int  count;     // 当前数据元素个数
	int  sizeindex; // hashsize[sizeindex]为当前容量
} HashTable;

ElemType InitElemType(KeyType key, ValueType value); //初始化关键字和值

HashTable InitHash(int size);   //初始化一个哈希表 

bool isPrime(int num);    //判断一个数是否为素数 

int getPrimenumber(HashTable H);   //找到合适的小于表长的素数n 

void InsertHashTable(HashTable H, ElemType elem); //在HashTable中插入元素

int Find(HashTable H, KeyType key); //查找关键字

void Print(HashTable H);  //输出Hash表中所有元素

void RecreateHashTable(HashTable *H);  // 重建哈希表
