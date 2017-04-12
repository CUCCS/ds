#include "LinkList.h"

//Á´±í²ð·Öº¯Êý
Status LinkDepart(LinkList L)
{
	LinkList La, Lb;
	La=(LNode *)malloc(sizeof(L));
    Lb=(LNode *)malloc(sizeof(L));
	int i = 0;
	LinkList p,pa,pb;
	LinkList ra,rb;
	p = L;
	pa = La;
	pb = Lb;
	La->next = Lb->next = NULL;
	while(p)
	{
		if(i%2==0){
			ra = (LNode *)malloc(sizeof(L));
			ra->data = p->data;
			pa->next = ra;
			pa = ra;
		}
		else{
			rb = (LNode *)malloc(sizeof(L));
			rb->data = p->data;
			pb->next = rb;
			pb = rb;
		}
		i++;
		p = p->next;
	}
	pa->next = pb->next = NULL;
	La = La->next;
	Lb = Lb->next;
	printf("LinkListA:\n");
	TraverseList(La);
	printf("LinkListB:\n");
	TraverseList(Lb);
	return OK;
}

int main()
{
	LNode *list = NULL;
	list = createList();
	LinkDepart(list);
	return 0;
}