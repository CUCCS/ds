#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define  SUCCESS    1
#define  FAILED     0
#define  DUPLICATE -1 // �ظ�
#define  NULLKEY   -1 // �չؼ���
#define  NONEVALUE  0 // ��ֵ

typedef int KeyType;
typedef int ValueType;

typedef enum { // ��������ֵ
	OK,
	ERROR
}Status;

typedef enum { // ��������ֵ
	FALSE,
	TRUE
}bool;

typedef struct _ElemType {
	KeyType key;      // �ؼ���
	ValueType val;    // ֵ
#ifdef CHAINED_HASH
	struct _ElemType *next;
#endif
} ElemType;

typedef struct {
	ElemType  *elem; // �����ϣ��Ԫ��
	int  count;     // Ԫ�ظ���
	int  sizeindex; // ����
} HashTable;

Status CreateHash(HashTable *H, int size); // ����Hash��
bool Empty(HashTable H); // �ж�Hash���Ƿ�Ϊ��
bool Prime(int n); // �ж��Ƿ�Ϊ����
int SearchHash(HashTable H, KeyType K, int *p, int *c); // ��Hash���в��ҹؼ���ΪK��Ԫ��
Status InsertHash(HashTable *H, ElemType e); // ��Hash���в����µ�Ԫ��
bool EQ(KeyType a, KeyType b); // �жϹؼ����Ƿ����
Status RecreateHashTable(HashTable *H); // �ؽ�Hash��
Status Print(HashTable H); // ���Hash��