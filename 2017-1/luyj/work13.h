//˵����
//ʱ�临�Ӷȣ�
//ParitySequence�����ڽ�list��������ֽ������ѭ������ʱ��ֻ����һ��ѭ������һ�����Ա���ʱ�临�Ӷ�ԼΪO(n)(nΪlist����ĳ���)����ʱ��ʱ�临�Ӷ�ӦΪ��С��
//�ռ临�Ӷȣ�
//�ڴ�������ѭ������(list1,list2)ʱ��ֻ�ֱ����¶�̬������һ��ͷ��㡣��������ѭ������Ĺ��̣����ֽ�list�Ĺ��̣�list1,list2��ͷ�����������㣬û�����·���ռ䣬����ֱ�ӽ�nextָ��ָ��list��Ӧ��㡣

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;

//���������
Status output(LinkList L);

//���ѭ���������һ�����ڣ�
Status output1(LinkList L);

//����һ����������������һ�������Ϊָ��list������
void CreateList_L(LinkList L, int n);

//�����Ե�����ֽ⵽��ż����ѭ������
void ParitySequence(LinkList list, LinkList list1, LinkList list2);
