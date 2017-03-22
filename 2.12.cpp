#include<stdio.h>
#include<malloc.h>
#define NULL 0
#define LEN sizeof(struct LNode)

//���嵥�����Ա�
typedef struct LNode
{
	int data;
   struct LNode *next;
}LNode,*LinkList;

//�����������Ա�
void CreateList_L(LinkList &L, int n)//��λ������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��
{
	struct LNode *p;
	L = (LinkList)malloc(LEN);
	L->next = NULL;//�Ƚ���һ����ͷ���ĵ�����
	for (int i = n; i > 0; --i)
	{
		p= (LinkList)malloc(LEN);//�����½��;
		scanf_s("%d", p->data);//����Ԫ��ֵ
		p->next = L->next;
		L->next = p;//���뵽��ͷ
	}

}//CreateList_L

//��֪�������Ա�la��lb��Ԫ�ذ�ֵ�ǵݼ����С�
//�鲢la��lb�õ��µĵ������Ա�lc��lc��Ԫ��Ҳ��ֵ�ǵݼ����С�
void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc)
{
	struct LNode *pa, *pb, *pc;
	pa = La->next;
	pb = Lb->next;
	pc = La; Lc = pc;//��la��ͷ�����Ϊlc��ͷ���
	while (pa&&pb)
	{
		if (pa->data <= pb->data) //��pa��ָ������ӵ�pc��ָ���֮��
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else       //��pb��ָ������ӵ�pc��ָ���֮��
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb; //����ʣ���
	free(Lb);               //�ͷ�lb��ͷ���
}//MergeList_L

//������
void Print_L(struct LNode *head)
{
	struct LNode *p;
	p = head;
	if (head != NULL)        //������ǿ�������������������нڵ�  
	{
		
		do
		{
			printf("%d ",p->data);//�������
			p = p->next;     //�Ƶ���һ���ڵ�  
		} while (p != NULL);
	}
}//Print_L

int main()
{
	LinkList La, Lb, Lc;
	CreateList_L(La, 3);
	CreateList_L(Lb, 3);
	MergeList_L(La, Lb, Lc);
	Print_L(La);

	return 0;
}