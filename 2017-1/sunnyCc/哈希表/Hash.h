#include <stdio.h>  
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define  MAXLEN 11 
#define SIZE 6
#define INVALID_KEY -1
#define INVALID_VALUE 0 
#define DELETEDKEY -2
#define DELETEDVALUE 0

typedef int KeyType;
typedef int ValueType;
typedef struct ElemType {
	KeyType key;      // �ؼ���
	ValueType val;    // ֵ
} ElemType;
typedef struct OpenHash {
	int size; //���ݸ���
	int used; //�Ѿ�ʹ���˵����ݸ���
	ElemType* elements; //������ݵĵ�ַ
}HashTable;

ElemType newElemType(KeyType key, ValueType value);
HashTable newtable(int size);
int Find(HashTable openHash, KeyType key);
void Insert(HashTable table, ElemType n);
HashTable Rebuild(HashTable openHash);
int FindPrime(HashTable table);