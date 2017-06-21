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
#define  SizeIndex 7   // hash��ı�

typedef int KeyType;
typedef int ValueType;
typedef int Status;

typedef struct _ElemType {
	KeyType key;      // �ؼ���
	ValueType val;    // ֵ
#ifdef CHAINED_HASH
	struct _ElemType *next;
#endif
} ElemType;

typedef struct {
	ElemType  *elem;
	int  count;     // ��ǰ����Ԫ�ظ���
	int  sizeindex; // hashsize[sizeindex]Ϊ��ǰ����
} HashTable;

/* ��ʼ����ϣ�� */
void InitHashTable(HashTable *H);

/* ��������ɵ��������������Hash��(for����) */
void CreateHashTable(HashTable * H);

/* ���Һ���(for����) */
void _Search(HashTable T);

/* �����ϣ��ͻ */
void collision(HashTable H, int *p, int *c);

/* ���ع�ϣ��ַ */
int Hash(HashTable H, ValueType k);

/* ��ϣ��Ĳ��� */
Status SearchHash(HashTable H, ElemType e, int *p, int *c);

/* ���ϣ���в������� */
Status InsertHash(HashTable *H, ElemType e);

/* �ؽ���ϣ�� */
void RecreateHashTable(HashTable *H);

/* ��ӡ��ϣ�� */
void PrintHashTable(HashTable H);
#endif // !1