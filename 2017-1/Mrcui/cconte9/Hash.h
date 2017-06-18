#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define OK 1
#define nullval -33333

typedef int Status;
typedef int KeyType;
typedef int ValueType;
typedef struct _ElemType {
    KeyType key;      // 关键字
    ValueType val;    // 值
#ifdef CHAINED_HASH
    struct _ElemType *next;
#endif
} ElemType;
typedef struct {
    ElemType *elem; // 数据元素存储地址
    int count; //数据元素个数
} Hash_Table, *HashTable;

int Hash_size = 0; //散列表表长
Status Init(HashTable hashTable, int hashsize);//初始化散列表
Status Hash(int data);//获得哈希函数
void Insert(HashTable hashTable, int hkey, int value);//插入关键字和相应的值
void Display(HashTable hashTable);//打印结果
Status Search(HashTable hashTable, int data);//查找
