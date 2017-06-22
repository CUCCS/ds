#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SUCCESS 1
#define UNSUCCESS 0
#define DUPLICATE -1

#define NULLKEY -1//�޼�¼��־
#define N 10//����Ԫ�ظ���

#define EQ(a,b) ((a)==(b))

int collisiontime;

typedef int KeyType;//��ؼ�����Ϊ����
typedef int ValueType;
typedef struct _ElemType {
	KeyType key;      // �ؼ���
	ValueType val;    // ֵ
#ifdef CHAINED_HASH
	struct _ElemType *next;
#endif
} ElemType;//����Ԫ������

typedef struct
{
	ElemType *elem;//����Ԫ�ش洢��ַ ��̬��������
	int count;//��ǰ����Ԫ�ظ���
	int size_index;//hashsize[size_index]Ϊ��ǰ����
}HashTable;

ElemType newElemType(KeyType key, ValueType value);
int initHashTable(HashTable *H);
void destroyHashTable(HashTable *H);
unsigned Hash(KeyType K);
int searchHash(HashTable H, KeyType K, int *p, int *c);
int insertHash(HashTable *H, ElemType e);//�Ժ���������
void recreateHashTable(HashTable *H);//�ؽ���ϣ��
void traverseHash(HashTable H, void(*Vi)(int, ElemType));
int find(HashTable H, KeyType K, int *p);
void printHash(int p, ElemType r);