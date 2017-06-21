#include "2.h"
//将随即生成的线性链表，按奇偶分成两个循环链表
//主函数和算法分析参照同学的，函数均为自己实现

int main()
{
	srand(time(0));
	int n;
	LinkList list = (LinkList)malloc(sizeof(LNode));
	LinkList list1 = (LinkList)malloc(sizeof(LNode));//奇序号链表头结点；
	LinkList list2 = (LinkList)malloc(sizeof(LNode));//偶序号链表头结点；
	n = rand() % 9 + 3;//确保链表list大小大于等于2；
	printf("随机生成线性链表:\n");
	CreateList_L(list, n);
	output(list);
	ParitySequence(list, list1, list2);
	printf("\n奇序列的循环链表(循环一次的输出)：\n");
	output1(list1);
	printf("\n偶序列的循环链表（循环一次的输出）：\n");
	output1(list2);

}