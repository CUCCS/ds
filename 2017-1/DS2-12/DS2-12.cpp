#include<stdio.h>
#include<stdlib.h>
#define ListLength 2
typedef int ElemType; //Ԫ������
typedef struct LNode{ 
	ElemType data;
    struct LNode *next;
}LNode;
LNode *createList()//����������
{
	LNode *p1, *p2;
	LNode *head = NULL;//ͷ���
	int n = 0;
	int l = ListLength;//l���������ȣ����ڿ�����������ݸ���
	p2 = p1 = (LNode *)malloc(sizeof(LNode));//Ϊp1p2�����ڴ�
	scanf("%d", &p1->data);//����p1���������Ԫ��
	while(l){
	    n = n + 1;
		if( n == 1)
			head = p1;//ͷ���ָ��p1
		else
			p2->next = p1;//p2β���ָ��p1
		p2 = p1;//?
		p1 = (LNode *) malloc(sizeof(LNode));//�ٴη����ڴ�
		if( l != 1)
			scanf("%d", &p1->data);//���������ݸ���С�������ȣ����������
		l--;
	}//end of while
	p2->next = NULL;
	return head;
}//end of createList
void printList(LNode *head)
{
	LNode *p;
	p = head;//ָ��ָ������ͷ���
	if( head != NULL ){
		do{
			printf("%d\n", p->data);
			p = p->next;
		}while( p != NULL );
	}
}//end of printList
LNode *mergeList(LNode *l1, LNode *l2)
{
	LNode *head, *p1, *p2, *pos;
	head = p1 = l1;
	p2 = l2;
	pos = head;
	while(p2 != NULL){
		p1 = p1->next;//���ν��в���
		pos->next = p2;
		pos = p2;
		p2 = p2->next;
		pos->next = p1;
		pos = p1;
	}
	return head;
}//end of mergeList

int main()
{
	LNode *A = NULL;
	LNode *B = NULL;
	A = createList();
	B = createList();
	A = mergeList(A, B);
	printList(A);
	return 0;
}