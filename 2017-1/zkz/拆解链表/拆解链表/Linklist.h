#pragma once

#include <stdlib.h>
#include "Status.h"

#define NEWNODE (Node*)malloc(sizeof(Node))
#define MAXNUM 99
#define MINNUM 10
/*rd : ����һ����С��Min�Ҳ�����Max�������*/
#define rd(Min,Max) (rand()%((Max)-(Min)+1)+(Min))
#define DEBUG 1
#define debug_print(...) if(DEBUG){printf(__VA_ARGS__);}

typedef int Elemtype;
typedef struct _Node {
	Elemtype data;
	struct _Node* prev;
	struct _Node* next;
}Node,*Linklist;

/*��ʼ������*/
/*pL : ����ʼ������ĵ�ַ*/
/*length : ������*/
Status InitList(Linklist* pL, const int length);
/*������ӡ����*/
/*L : ����������*/
Status TraverseList(const Linklist L);
/*�ڱ�β����Ԫ��*/
/*pL : ����������ĵ�ַ*/
/*data : ����������*/
Status Insert(Linklist* pL, Elemtype data);

/*�������*/
/*��һ�������е���ż��ֱ��ֵ������µ�������*/
/*list : ���ֽ�����*/
/*pL1 : ���������������ͷ�ڵ��ַ*/
/*pL2 : ���ż����������ͷ�ڵ��ַ*/
Status DivideList(Linklist list, Linklist* pL1, Linklist* pL2);