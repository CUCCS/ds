#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG 1
#define COUNT 6
#define SIZEINDEX 11

typedef enum
{
	false,
	true
} bool;

typedef int KeyType;
typedef int ValueType;

typedef struct _ElemType
{
	KeyType key;      // �ؼ���
	ValueType val;    // ֵ
} ElemType;

typedef struct
{
	ElemType  *elem;
	int  count;     // ��ǰ����Ԫ�ظ���
	int  sizeindex; // hashsize[sizeindex]Ϊ��ǰ����
} HashTable;

ElemType InitElemType(KeyType key, ValueType value); //��ʼ���ؼ��ֺ�ֵ

HashTable InitHash(int size);   //��ʼ��һ����ϣ�� 

bool isPrime(int num);    //�ж�һ�����Ƿ�Ϊ���� 

int getPrimenumber(HashTable H);   //�ҵ����ʵ�С�ڱ�������n 

void InsertHashTable(HashTable H, ElemType elem); //��HashTable�в���Ԫ��

int Find(HashTable H, KeyType key); //���ҹؼ���

void Print(HashTable H);  //���Hash��������Ԫ��

void RecreateHashTable(HashTable *H);  // �ؽ���ϣ��
