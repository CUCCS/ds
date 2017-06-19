#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

LinkList Initial(){
	LinkList L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	return L;
}

void Create(LinkList L, int n){
	LNode *p;
	for (int i = n; i > 0; --i){
		p = (LNode *)malloc(sizeof(LNode));
		//scanf("%d", &p->data);
		p->next = L->next;
		L->next = p;
	}
}

void Merge(LinkList La, LinkList Lb){
	LNode *pa, *pb, *pc;
	pa = La->next;
	pb = Lb->next;
	pc = La;
	while (pa && pb){
		if (pa->data <= pb->data){
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;
	free(Lb);
}

int main(){
	LinkList a = Initial(), b = Initial(),p,pa=a,pb=b;
	int m, n;
	//scanf("%d%d", &m, &n);//输入两个表的长度
	m = 10; n = 10;
	Create(a, m);
	Create(b, n);
	printf("La:\n");
	for (int i = 0; i < m; i++){
		pa = pa->next;
		pa->data = 2*(2*i+1);//随意写的函数赋值
		printf("%d ", pa->data);
	}
	printf("\nLb:\n");
	for (int i = 0; i < n; i++){
		pb = pb->next;
		pb->data = 3 * (i+1);//随意写的函数赋值
		printf("%d ", pb->data);
	}
	printf("\nMerge:\n");
	Merge(a, b);
	p = a;
	while (p->next){
		p = p->next;
		printf("%d ", p->data);
	}
	return 0;
}