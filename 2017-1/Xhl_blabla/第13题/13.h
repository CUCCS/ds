#include <stdio.h>//ͷ�巨 û��ָ����ƶ�
typedef struct Lnode
{
	int data;
	struct Lnode* next;
}Lnode;
//��ʼ��һ������ β�巨
Lnode * ListCreat();
int ApartList(Lnode *p, Lnode **px, Lnode **py);
int print_list(Lnode *p);
int print_circle_list(p1);
int destory(Lnode **p);