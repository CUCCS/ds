#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SUCCESS 1
#define UNSUCCESS 0
#define DUPLICATE -1

#define NULLKEY -1//无记录标志
#define N 10//数据元素个数

#define EQ(a,b) ((a)==(b))

int collisiontime;

typedef int KeyType;//设关键字域为整型
typedef int ValueType;
typedef struct _ElemType {
	KeyType key;      // 关键字
	ValueType val;    // 值
#ifdef CHAINED_HASH
	struct _ElemType *next;
#endif
} ElemType;//数据元素类型

typedef struct
{
	ElemType *elem;//数据元素存储基址 动态分配数组
	int count;//当前数据元素个数
	int size_index;//hashsize[size_index]为当前容量
}HashTable;

ElemType newElemType(KeyType key, ValueType value);
int initHashTable(HashTable *H);
void destroyHashTable(HashTable *H);
unsigned Hash(KeyType K);
int searchHash(HashTable H, KeyType K, int *p, int *c);
int insertHash(HashTable *H, ElemType e);//对函数的声明
void recreateHashTable(HashTable *H);//重建哈希表
void traverseHash(HashTable H, void(*Vi)(int, ElemType));
int find(HashTable H, KeyType K, int *p);
void printHash(int p, ElemType r);