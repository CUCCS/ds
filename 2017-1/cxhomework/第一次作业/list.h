#include<stdio.h>
//ͷ�ļ�����׼�������
#include<stdlib.h>
//�ڴ���亯��malloc��ͷ�ļ�
//#include<time.h>//�����������Ҫ��ͷ�ļ�
#include<time.h>srand(time(NULL));

typedef struct LNode
{
	int data;//����
	struct LNode *next;//ָ����һ���ڵ��ָ��

}LNode, *Linklist;
Linklist CreatList(LNode *L, int n);//�����µ����Ա�ĺ���
Linklist MergeList(LNode *l1, LNode  *L2, LNode *l3);//ʵ���������������γɵ���������
void output(LNode *ll, int n);
