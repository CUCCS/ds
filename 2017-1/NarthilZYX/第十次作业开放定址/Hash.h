#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef enum{
	ERROR,
    OK
}Status;
typedef enum{
	False,
	True
}Bool;
#define NULLKEY -1       //����չؼ���ֵ
#define DELKEY -2        //���屻ɾ�ؼ���ֵ
#define DELVAL -2
#define EMPTYKEY 0
#define EMPTYVALUE 0
typedef int KeyType;
typedef int ValueType;
typedef struct _ElemType {
    KeyType key;      // �ؼ���
    ValueType val;    // ֵ
#ifdef CHAINED_HASH
    struct _ElemType *next;
#endif
} ElemType;

#define MaxSize 100      //��������ϣ����
int hashsize[10] = {13, 19, 29, 41, 59, 79, 107, 149, 197, 263 };
typedef struct {
	ElemType *elem;//����Ԫ�ش洢��ַ����̬�����ڴ�
	int count;//�ѱ�ʹ�õ����ݵĸ���
	int sizeindex;//�����ܸ���
}HashTable;

//�����жϺ�������д
Bool isPrime( int num );
//������ȡ����
int getPrime( HashTable h );

//��ϣ���Ƿ�Ϊ�ռ��Ƿ��������жϺ�������д
Bool isEmpty( HashTable h );
Bool isFull ( HashTable h );

//�½���ϣ�����ݣ���д
HashTable newHashTable( int sizeindex );
ElemType newElemType( KeyType key, ValueType value );
//�ؽ���ϣ��
HashTable rebuildHashTable( HashTable h );

Status SearchHashTable( HashTable ha,KeyType k );

//ɾ����ϣ���йؼ���k
int DeleteHT(HashTable ha, ElemType elem);

//���ؼ���k���뵽��ϣ����
void InsertHT(HashTable ha, ElemType elem);

//�����ϣ��
void printHashTable(HashTable ha);