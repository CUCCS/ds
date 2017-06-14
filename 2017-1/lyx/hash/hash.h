//Hash查找表的建立、关键字查找和重建哈希表（扩充原Hash表容量）操作实现
//使用“开放定址法之线性探测再散列”解决Hash冲突 (随机数据插入)
#include <stdio.h>
#include <malloc.h>
#include<stdlib.h>
#include<time.h>
#define NULLKEY 0 // 0为无记录标志
#define N 10  // 数据元素个数
#define SIZE 6 
#define SUCCESS 1
#define UNSUCCESS 0
#define DUPLICATE -1
typedef int KeyType;// 设关键字域为整型
// 开放定址哈希表的存储结构
typedef struct
{
	KeyType key;//关键字
	int val;//值
}ElemType; // 数据元素类型

int hashsize[] = { 11,19,29,37 }; // 哈希表容量递增表，一个合适的素数序列
int m = 0; // 哈希表表长，全局变量

//定义哈希表
typedef struct
{
	ElemType *elem; // 数据元素存储基址，动态分配数组
	int count; // 当前数据元素个数
	int sizeindex; // hashsize[sizeindex]为当前容量
}HashTable;
int InitHashTable(HashTable);// 构造一个空的哈希表
void DestroyHashTable(HashTable);//  销毁哈希表H
unsigned Hash(KeyType);// 一个简单的哈希函数(m为表长，全局变量)
void collision(int *, int);// 开放定址法处理冲突
int SearchHash(HashTable , KeyType , int *, int *);
void RecreateHashTable(HashTable *);
int InsertHash(HashTable *, ElemType );
void RecreateHashTable(HashTable *);
void TraverseHash(HashTable H, void(*)(int, ElemType));
int Find(HashTable , KeyType , int *);
void print(int , ElemType );
ElemType newElemType(KeyType , int );
ElemType* Inputs(int );



