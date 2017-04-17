#include <stdio.h>//头插法 没有指针的移动
typedef struct Lnode
{
	int data;
	struct Lnode* next;
}Lnode;
//初始化一个链表 尾插法
Lnode * ListCreat();
int ApartList(Lnode *p, Lnode **px, Lnode **py);
int print_list(Lnode *p);
int print_circle_list(p1);
int destory(Lnode **p);