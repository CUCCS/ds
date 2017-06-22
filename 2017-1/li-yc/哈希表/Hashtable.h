#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ArrayLenth 10 //��������鳤��
#define HashLength 12 //��ϣ���ʼ������

typedef int KeyType;
typedef int ValueType;
typedef struct _ElemType {
	KeyType key;      // �ؼ���
	ValueType val;    // ֵ
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