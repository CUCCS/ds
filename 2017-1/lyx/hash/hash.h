//Hash���ұ�Ľ������ؼ��ֲ��Һ��ؽ���ϣ������ԭHash������������ʵ��
//ʹ�á����Ŷ�ַ��֮����̽����ɢ�С����Hash��ͻ (������ݲ���)
#include <stdio.h>
#include <malloc.h>
#include<stdlib.h>
#include<time.h>
#define NULLKEY 0 // 0Ϊ�޼�¼��־
#define N 10  // ����Ԫ�ظ���
#define SIZE 6 
#define SUCCESS 1
#define UNSUCCESS 0
#define DUPLICATE -1
typedef int KeyType;// ��ؼ�����Ϊ����
// ���Ŷ�ַ��ϣ��Ĵ洢�ṹ
typedef struct
{
	KeyType key;//�ؼ���
	int val;//ֵ
}ElemType; // ����Ԫ������

int hashsize[] = { 11,19,29,37 }; // ��ϣ������������һ�����ʵ���������
int m = 0; // ��ϣ�����ȫ�ֱ���

//�����ϣ��
typedef struct
{
	ElemType *elem; // ����Ԫ�ش洢��ַ����̬��������
	int count; // ��ǰ����Ԫ�ظ���
	int sizeindex; // hashsize[sizeindex]Ϊ��ǰ����
}HashTable;
int InitHashTable(HashTable);// ����һ���յĹ�ϣ��
void DestroyHashTable(HashTable);//  ���ٹ�ϣ��H
unsigned Hash(KeyType);// һ���򵥵Ĺ�ϣ����(mΪ����ȫ�ֱ���)
void collision(int *, int);// ���Ŷ�ַ�������ͻ
int SearchHash(HashTable , KeyType , int *, int *);
void RecreateHashTable(HashTable *);
int InsertHash(HashTable *, ElemType );
void RecreateHashTable(HashTable *);
void TraverseHash(HashTable H, void(*)(int, ElemType));
int Find(HashTable , KeyType , int *);
void print(int , ElemType );
ElemType newElemType(KeyType , int );
ElemType* Inputs(int );



