#include<stdlib.h>
#include "2.12.h"
void MergeList_L(LinkList La, LinkList Lb, LinkList *Lc) {
	LNode *pa = La->next, *pb = Lb->next;
	LNode *pc = La = *Lc;//Laͷ�ڵ���ΪLcͷ�ڵ�
	while (pa&&pb) {
		if (pa->data <= pb->data) {
			pc->next = pa;
			pc = pa;
		}//pa��ָ���������pc��ָ�ڵ�֮��
		else {
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}//pb��ָ���������pc��ָ�ڵ�֮��
	}//pa��pb����һ��Ϊ�٣���ֵ��ʱ��ֹͣѭ��
	pc->next = pa ? pa : pb;//����ʣ���
	free(Lb);//�ͷ�Lbͷ�ڵ�
}//Mergel_L