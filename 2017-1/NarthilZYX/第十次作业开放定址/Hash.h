#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef enum{
	ERROR,
    OK
}Status;
typedef enum{
	False,
	True
}Bool;
#define NULLKEY -1       //定义空关键字值
#define DELKEY -2        //定义被删关键字值
#define DELVAL -2
#define EMPTYKEY 0
#define EMPTYVALUE 0
typedef int KeyType;
typedef int ValueType;
typedef struct _ElemType {
    KeyType key;      // 关键字
    ValueType val;    // 值
#ifdef CHAINED_HASH
    struct _ElemType *next;
#endif
} ElemType;

#define MaxSize 100      //定义最大哈希表长度
int hashsize[10] = {13, 19, 29, 41, 59, 79, 107, 149, 197, 263 };
typedef struct {
	ElemType *elem;//数据元素存储基址，动态分配内存
	int count;//已被使用的数据的个数
	int sizeindex;//数据总个数
}HashTable;

//质数判断函数，待写
Bool isPrime( int num );
//质数获取函数
int getPrime( HashTable h );

//哈希表是否为空及是否已满的判断函数，待写
Bool isEmpty( HashTable h );
Bool isFull ( HashTable h );

//新建哈希表及数据，待写
HashTable newHashTable( int sizeindex );
ElemType newElemType( KeyType key, ValueType value );
//重建哈希表
HashTable rebuildHashTable( HashTable h );

Status SearchHashTable( HashTable ha,KeyType k );

//删除哈希表中关键字k
int DeleteHT(HashTable ha, ElemType elem);

//将关键字k插入到哈希表中
void InsertHT(HashTable ha, ElemType elem);

//输出哈希表
void printHashTable(HashTable ha);