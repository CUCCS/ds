#include<stdio.h>
#include<stdlib.h>
#include "2.12.h"
//�㷨2.12����������ϲ�
void MergeList_L(LinkList La, LinkList Lb, LinkList Lc) {
	LinkList pa = La->next, pb = Lb->next;
	LinkList pc = La = Lc;//Laͷ�ڵ���ΪLcͷ�ڵ�
	while (pa&&pb) {
		if (pa->data <= pb->data) {
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}//pa��ָ���������pc��ָ�ڵ�֮��
		else {
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}//pb��ָ���������pc��ָ�ڵ�֮��
	}//pa��pb����һ��Ϊ�٣���ֵ��ʱ��ֹͣѭ��
	pc->next = pa ? pa : pb;//����ʣ���
	free(Lb);//�ͷ�Lbͷ�ڵ�
}//Mergel_L
//�½�������
void CreateList_L(LinkList L, int n) {
	//L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	int i; LinkList p;
	printf("�����б�Ԫ��:\n");
	for (i = n; i > 0; --i) {
		p = (LinkList)malloc(sizeof(LNode));//�����½��
		scanf_s("%d", &p->data);//����Ԫ��ֵ
		p->next = L->next; L->next = p;//���뵽��ͷ
	}
}//CreatList_L
//���������
void PRINT(LinkList L)
{
	LinkList p = L->next;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}


