#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ArrayLenth 10 //输入的数组长度
#define HashLength 12 //哈希表初始化长度

typedef int KeyType;
typedef int ValueType;
typedef struct _ElemType {
	KeyType key;      // 关键字
	ValueType val;    // 值
} ElemType;
typedef struct {
	int size;
	int used;
	ElemType* elements;
}Hashtable;
typedef enum {
	false,
	true,
}bool;
typedef enum {
	OK,
	OVERFLOW,
	ERROR,
} Status;

Hashtable CreatHash(int size);
Status CreatArray(int arr[][2]);
bool isFull(Hashtable H);
Status Insert(Hashtable H, KeyType keyvalue, ValueType value);
Status Find(Hashtable H, KeyType keyval);
Status RebulidHash(Hashtable *H);
Status TraverseHash(Hashtable H);