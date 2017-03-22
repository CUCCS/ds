#include<stdlib.h>
#include "2.12.h"
void MergeList_L(LinkList La, LinkList Lb, LinkList *Lc) {
	LNode *pa = La->next, *pb = Lb->next;
	LNode *pc = La = *Lc;//La头节点作为Lc头节点
	while (pa&&pb) {
		if (pa->data <= pb->data) {
			pc->next = pa;
			pc = pa;
		}//pa所指结点链接至pc所指节点之后
		else {
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}//pb所指结点连接至pc所指节点之后
	}//pa，pb其中一个为假（空值）时，停止循环
	pc->next = pa ? pa : pb;//插入剩余段
	free(Lb);//释放Lb头节点
}//Mergel_L