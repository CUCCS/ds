#include "work13.h"

int main()
{
	srand(time(0));
	int n;
	LinkList list = (LinkList)malloc(sizeof(LNode));
	LinkList list1 = (LinkList)malloc(sizeof(LNode));//���������ͷ��㣻
	LinkList list2 = (LinkList)malloc(sizeof(LNode));//ż�������ͷ��㣻
	n = rand() % 9 + 3;//ȷ������list��С���ڵ���2��
	printf("���������������:\n");
	CreateList_L(list, n);
	output(list);
	ParitySequence(list, list1, list2);
	printf("\n�����е�ѭ������(ѭ��һ�ε����)��\n");
	output1(list1);
	printf("\nż���е�ѭ������ѭ��һ�ε��������\n");
	output1(list2);

}