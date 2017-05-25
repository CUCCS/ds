#include<stdio.h>
//头文件，标准输入输出
#include<stdlib.h>
//内存分配函数malloc的头文件
//#include<time.h>//生成随机数需要的头文件
#include<time.h>srand(time(NULL));

typedef struct LNode
{
	int data;//数据
	struct LNode *next;//指向下一个节点的指针

}LNode, *Linklist;
Linklist CreatList(LNode *L, int n);//创建新的线性表的函数
Linklist MergeList(LNode *l1, LNode  *L2, LNode *l3);//实现两个链表相结合形成第三个链表
void output(LNode *ll, int n);
