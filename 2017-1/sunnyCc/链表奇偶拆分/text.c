//1.线性链表分解为两个带有头结点的循环链表,
//2.将两个循环链表的长度分别存放在各自头结点的数据域中。
//3.线性表中序号为奇数的元素分解到第一个循环链表中, 序号为偶数的元素分解到第二个循环链表中
//4.要求用最少的时间和最少的空间

//使用循环链表来表示list1，list2使得找寻链表的头尾项可以直接插入，降低了时间复杂度到O(1)
//而且分解过程只涉及一次循环，降低了空间复杂度到O(n)
#include "split.h"
int main()
{
	LinkList list, list1, list2;
	int n;
	srand((unsigned int)time(NULL));
	n = rand() % 10 + 10;//随机产生list链表长度
	printf("被拆分链表:\n元素个数为%d\n", n);
	CreateList(&list, n);//创建并打印链表list，随机生成测试数据进入链表
	list1 = (LNode *)malloc(sizeof(LNode));
	list2 = (LNode *)malloc(sizeof(LNode));
	Split(list, list1, list2);//对链表进行拆分

	printf("\n序列数为奇数（序列数从0开始计算）链表1:\n元素个数为%d\n", list1->data);
	Traverse(list1);
	printf("\n序列数为偶数（序列数从0开始计算）链表2:\n元素个数为%d\n", list2->data);
	Traverse(list2);
	return 0;
}