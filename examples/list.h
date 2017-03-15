#ifndef _LIST_H_
#define _LIST_H_

#include "myds.h"

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

Status ListInsert_L(LinkList L, int i, ElemType e);

Status CreateList_L(LinkList L, int n);

Status GetElem_L(LinkList L, int i, ElemType *e);

Status ListDelete_L(LinkList L, int i);

Status ClearList(LinkList L);

#endif
