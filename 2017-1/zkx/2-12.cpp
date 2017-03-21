#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 
typedef int ElemType;    //������������

typedef struct  LNode
{
	ElemType data;
	struct LNode *next;
}LNode , *LinkList;     //�ṹ��Ľ���

#define OK 0
#define ERROR 1
#define OVERFLOW 2     //Ԥ���峣��

void CreateList(LinkList L, int n)
{
 	int i;
 	LNode* p;
 	L->next = NULL;  //��ͷ���ĵ�����
 
 	for (i = 0; i < n; ++i)
	{
 		p = (LinkList)malloc(sizeof(LNode));
 		scanf("%d",&p->data);   //����Ԫ��
 		p->next = L->next;    //���뵽��ͷ
 		L->next = p;
 	}
}; 
void MergeList_L(LinkList La, LinkList Lb, LinkList *Lc)
{
 	LNode *pa = La->next, *pb = Lb->next, *pc;
 	(*Lc) = pc = La;//��La��ͷ�ڵ���ΪLc��ͷ�ڵ�
 
 	while (pa&&pb)
	{
 		if (pa->data <= pb->data)
		{
 			pc->next = pa; pc = pa; pa = pa->next;
 		}
 		else
		{
 		pc->next = pb; pc = pb; pb = pb->next;
 		}
    }
 	pc->next = pa ? pa : pb;
 	free(Lb);
 }
void TraverseList_L(LinkList L)
{
 	LNode *p = L->next;
 	while (p)
	{
		printf("%d ",p->data);
 		p = p->next;
 	}
 }
 int main()
 {
	 int n1,n2;

	 printf("��������La�����ݸ�����\n");
	 scanf("%d",&n1);

	  printf("��������Lb�����ݸ�����\n");
	  scanf("%d",&n2);

	 LinkList La,Lb,Lc;
	 La = (LinkList)malloc(sizeof(LNode));
	 Lb = (LinkList)malloc(sizeof(LNode));
//srand(time(NULL));

	 printf("���ǵ�������La���ݣ�\n");
	 CreateList(La,n1);  //����La
 	 printf("La:");         //���La
 	 TraverseList_L(La);
 	 printf("\n");

	 printf("���ǵ�������Lb���ݣ�\n");
	 CreateList(Lb,n2);     //����Lb
 	 printf("Lb:");            //���Lb
 	 TraverseList_L(Lb);
 	 printf("\n");

	 MergeList_L(La, Lb, &Lc);  //�ϲ�La��Lb
	 printf("�ϲ�La��Lb������������Lc��\n");
 	 printf("Lc:");                        //����ϲ���Lc
 	 TraverseList_L(Lc);
 	 printf("\n");
 	return 0;
 }