#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK    1
#define ERROR 0
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode;
//��ʼ������
LNode *InitList(LNode *L);
//�������
int SplitList(LNode *L, LNode **L1, LNode **L2);
//���������
int PrintList(LNode *L);
//���ѭ������
int PrinttCircle_List(LNode *L);
//��������
int Destroy(LNode **L);

//�ռ临�Ӷ�ΪO(1)
//ʱ�临�Ӷ�ΪO(n),��������Ϊ2ʱֻ��Ҫ������ѭ��һ��