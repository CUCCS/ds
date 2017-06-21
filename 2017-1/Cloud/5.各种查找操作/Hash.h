#pragma once
#ifndef Hash_h
#define Hash_h
#include <stdio.h>
#include <stdlib.h>
#
#include <time.h>
#define  SUCCESS    1
#define  FAILED     0
#define  DUPLICATE -1
#define  NULLKEY -1
#define  SizeIndex 7   // hash表的表长

typedef int KeyType;
typedef int ValueType;
typedef int Status;

typedef struct _ElemType {
	KeyType key;      // 关键字
	ValueType val;    // 值
#ifdef CHAINED_HASH
	struct _ElemType *next;
#endif
} ElemType;

typedef struct {
	ElemType  *elem;
	int  count;     // 当前数据元素个数
	int  sizeindex; // hashsize[sizeindex]为当前容量
} HashTable;

/* 初始化哈希表 */
void InitHashTable(HashTable *H);

/* 用随机生成的正整数序列填充Hash表(for本题) */
void CreateHashTable(HashTable * H);

/* 查找函数(for本题) */
void _Search(HashTable T);

/* 解决哈希冲突 */
void collision(HashTable H, int *p, int *c);

/* 返回哈希地址 */
int Hash(HashTable H, ValueType k);

/* 哈希表的查找 */
Status SearchHash(HashTable H, ElemType e, int *p, int *c);

/* 向哈希表中插入数据 */
Status InsertHash(HashTable *H, ElemType e);

/* 重建哈希表 */
void RecreateHashTable(HashTable *H);

/* 打印哈希表 */
void PrintHashTable(HashTable H);
#endif // !1