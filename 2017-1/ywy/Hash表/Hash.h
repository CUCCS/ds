#pragma once
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#define SUCCESS 1
#define UNSUCCESS 0
#define DUPLICATE -1
#define UNKEY -1
#define UNVAL 0
//#define HASHSIZE 30
typedef int KeyType;
typedef int ValueType;
typedef struct _ElemType
{
	KeyType key;//¹Ø¼ü×Ö
	ValueType val;//Öµ
#ifdef CHAINED_HASH
	struct _ElemType*next;
#endif
}ElemType;
typedef struct
{
	 ElemType*elem;//´æ´¢¹þÏ£±íÔªËØ
	int count;
	int maxsize;
}HashTable;
typedef enum
{
	ok,
	error
}Status;

typedef enum
{ 
	FALSE,
	TRUE
}bool;
Status PrintHash(HashTable H);
Status InitHashTable(HashTable*H,int size);
Status InsertHashTable(HashTable*H, ElemType e);
bool Empty(HashTable H);
bool Equal(KeyType a, KeyType b);
bool SuS(int n);
int SearchHashTable(HashTable H, KeyType key, int*add, int*count);
Status ReHash(HashTable *H);