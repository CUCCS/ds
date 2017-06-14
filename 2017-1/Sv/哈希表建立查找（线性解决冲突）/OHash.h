#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define  NULLKEY -1
//-----------------------------------
typedef int KeyType;
typedef int ValueType;
typedef struct _ElemType {
	KeyType key;      // �ؼ���
	ValueType val;    // ֵ
#ifdef CHAINED_HASH
	struct _ElemType *next;
#endif
} ElemType;
typedef struct _bool{ true,false }bool;
typedef struct {
	ElemType  *elem;//��ַ
	int  count;     // ��ǰ����Ԫ�ظ���
	int  sizeindex; // hashsize[sizeindex]Ϊ��ǰ����
} HashTable;
typedef enum _status
{
	SUCCESS, FAILED, DUPLICATE,OK
}Status;
//-----------------------------------
bool EQ(int, int);
bool isSushu(int a);//�ж��Ƿ�Ϊ����
int hashsize(int size);
void RecreateHashTable(HashTable *H);
Status SearchHash(HashTable H, KeyType K, int *p, int *c);//��ϣ���в��ҹؼ�ֵΪK�ļ�¼��c��¼������p���ص�ַ
int Hash(KeyType,int size);
Status InsertHash(HashTable &H, ElemType e);
HashTable NewHashTable(int size);






