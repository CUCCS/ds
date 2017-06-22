#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#define init_num 9
#define search_num 6
#define SUCCESS 1
#define UNSUCCESS 0
#define DUPLICATE  -1
typedef int status;
typedef int KeyType;
typedef int ValueType;
typedef struct _ElemType 
{
	KeyType key;      // �ؼ���
	ValueType val;    // ֵ
    #ifdef CHAINED_HASH
	struct _ElemType *next;
    #endif
} ElemType;
typedef struct
{
	ElemType *elem;
	int count;//��ǰԪ�ظ���
	int sizeindex;//��ϣ���
}HashTable;
static int m;//�ڲ����Ӿ�̬������mΪ��ϣ���  
static int hashsize[] = { 11,19,29,37,49 };//�ڲ����Ӿ�̬��������ϣ����������m��������һ�����ʵ��������С�
int hashsize_count = 0;
int  hash(KeyType e, int l);//����Ѱַ
void collision(int *p, int c, KeyType k, int l);//��һ����Ѱ��λ��ȷ��
status RecreateHashTable(HashTable *H);//�ؽ���ϣ��
status InsertHash(HashTable *H, KeyType e, ValueType v);//���в������
status SearchHash(HashTable  H, KeyType e, ValueType v, int* p, int *c);//���в��Ҳ���
void TraverHash(HashTable  H);
status  InitHashTable(HashTable  *H);
void travel(int *q, int l);