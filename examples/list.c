 /*******************************************************************************
  文件名: 
  项目:   
  模块:   
  作者:   huangwei
  版本:   0.1
  创建于:  
  描述:

  修改历史:
  日期:     修改人:    修改描述:

 *********************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "myds.h"
#include "list.h"

Status ListInsert_L(LinkList L, int i, ElemType e) {
    // L 为带头结点的单链表的头指针，本算法在链表中第i 个结点之前插入新的元素 e
    LinkList p = L;    
    int j = 0;
    while (p && j < i-1) { 
        p = p->next;  
        ++j; 
    }   // 寻找第 i-1 个结点
    if (!p || j > i-1) {
        return ERROR;   // i 大于表长或者小于1 
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));      // 生成新结点
    if (s == NULL)  {
        return ERROR;
    }
    s->data = e; 
    s->next = p->next;
    p->next = s;       // 插入
    return OK;
} // LinstInsert_L


Status CreateList_L(LinkList L, int n) {
	// 逆序输入 n 个数据元素，建立带头结点的单链表
    int i;
	L->next = NULL; 
	// 先建立一个带头结点的单链表
	for (i = n; i > 0; --i) {
		LNode *p = (LNode *)malloc(sizeof(LNode));
		//scanf("%d", &p->data);    // 输入元素值
        p->data = i;
		p->next = L->next;
		L->next = p;  // 插入
	}

    return OK;
}

// ElemType 是一个 输出参数
Status GetElem_L(LinkList L, int i, ElemType *e) {
    int j = 1;       // j为计数器
    // L是带头结点的链表的头指针，以 e 返回第 i 个元素
    LinkList p = L->next; // p指向第一个结点
    while (p && j < i)  { // 顺指针向后查找，直到 p 指向第 i 个元素 或 p 为空
        p = p->next;  
        ++j; // 元素位置计数器执行+1操作
    }
    if ( !p || j > i ) {
        return ERROR;      //  第 i 个元素不存在
    }
    *e = p->data;           //  取得第 i 个元素
    return OK;
} // GetElem_L

Status ListDelete_L(LinkList L, int i) {
    // 删除以 L 为头指针(带头结点)的单链表中第 i 个结点
    LinkList p = L;
    int j = 0;
    while (p->next && j < i-1) {  // 寻找第 i 个结点，并令 p 指向其前驱
        p = p->next;
        ++j; 
    } 
    if(!(p->next) || j > i-1) { 
        return ERROR;  // 删除位置不合理
    }
    LNode *q = p->next;
    p->next = q->next;  // 删除并释放结点
	if(q) {
		free(q);
	} else {
		return ERROR;
	}
    return OK;
} // ListDelete_L


Status ClearList(LinkList L) {
   // 将单链表重新置为一个空表
    while(L->next) {
        LNode *p = L->next;
        L->next = p->next;
		if(p) {
			free(p); // 对于通过动态内存分配方式创建的结点p一定要注意手工释放内存
		} else {
			return ERROR;
		}
	}
    return OK;
} // ClearList

