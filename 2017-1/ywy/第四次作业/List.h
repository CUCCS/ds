#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef enum {
	ok,
	error,
	overflow
}Status;
typedef int Elemtype;
typedef struct Node
{
	Elemtype data;
	struct Node*next;
}Node,*Linklist;
Status CreatList(Linklist L,int n);
Status TravelList(Linklist L);
Status chaifenList(Linklist L,Linklist L1,Linklist L2);
