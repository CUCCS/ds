#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"
#define Visit(x) {visited[(x)-1]=true;}
#define isVisited(x) (bool)visited[(x)-1]
/*���ڽӾ�����д洢*/
typedef struct _Graph {
	/*0��1�Ķ�ά����*/
	bool** matrix;
	/*�ڵ����*/
	int size;
	/*����ָ�룺�ڽ��a��b֮�佨������*/
	void(*connect)(struct _Graph*, int a, int b);
	/*����ָ�룺�жϽ��a��b֮���Ƿ�������*/
	bool(*connected)(struct _Graph*,int a,int b);
	/*����ָ�룺��ӡ��ά����*/
	void(*show)(struct _Graph*);
	/*����ָ�룺�ҵ��ӽڵ�start���ڵ�end�����·��*/
	void(*directory)(struct _Graph*, int start, int end);
}Graph;
/*��ʼ��һ��ͼ*/
Graph newGraph(int size);