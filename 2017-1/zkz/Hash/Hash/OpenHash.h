#pragma once
#include <stdio.h>
#include <stdlib.h>

#define EMPTYKEY -1
#define EMPTYVALUE 0
#define DELETEDKEY -2
#define DELETEDVALUE 0
#define debug_print(...) if(DEBUG)printf(__VA_ARGS__)

typedef enum _bool { false, true } bool;
typedef int KeyType;
typedef int ValueType;
typedef struct _ElemType {
	KeyType key;      // 关键字
	ValueType val;    // 值
} ElemType;

typedef struct _OpenHash {
	int size; //数据个数
	int used; //已经使用了的数据个数
	ElemType* elements; //存放数据的地址
}OpenHash;

bool isPrime(int n);
bool isFull(OpenHash openHash);
bool isEmpty(OpenHash openHash);
ElemType newElemType(KeyType key, ValueType value);
OpenHash newOpenHash(int size);
int getP(OpenHash openHash);
void ShowOpenHash(OpenHash openHash);

void Insert(OpenHash openHash, ElemType elem);
void Delete(OpenHash openHash, ElemType elem);
/*在表openHash中查找元素elem*/
/*若找到则返回elem的位置,否则返回-1*/
int Find(OpenHash openHash, KeyType key);
OpenHash Rebuild(OpenHash openHash);