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
	KeyType key;      // �ؼ���
	ValueType val;    // ֵ
} ElemType;

typedef struct _OpenHash {
	int size; //���ݸ���
	int used; //�Ѿ�ʹ���˵����ݸ���
	ElemType* elements; //������ݵĵ�ַ
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
/*�ڱ�openHash�в���Ԫ��elem*/
/*���ҵ��򷵻�elem��λ��,���򷵻�-1*/
int Find(OpenHash openHash, KeyType key);
OpenHash Rebuild(OpenHash openHash);