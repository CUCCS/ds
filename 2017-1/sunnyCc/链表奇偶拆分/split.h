#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
	int data;
	struct Node *next;
}LNode, *LinkList;
void CreateList(LinkList *L, int n);
void Split(LinkList list, LinkList list1, LinkList list2);
void Traverse(LinkList head);
