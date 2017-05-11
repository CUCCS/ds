#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"
#define Visit(x) {visited[(x)-1]=true;}
#define isVisited(x) (bool)visited[(x)-1]
/*用邻接矩阵进行存储*/
typedef struct _Graph {
	/*0和1的二维数组*/
	bool** matrix;
	/*节点个数*/
	int size;
	/*函数指针：在结点a与b之间建立连接*/
	void(*connect)(struct _Graph*, int a, int b);
	/*函数指针：判断结点a与b之间是否有连接*/
	bool(*connected)(struct _Graph*,int a,int b);
	/*函数指针：打印二维数组*/
	void(*show)(struct _Graph*);
	/*函数指针：找到从节点start到节点end的最短路径*/
	void(*directory)(struct _Graph*, int start, int end);
}Graph;
/*初始化一个图*/
Graph newGraph(int size);