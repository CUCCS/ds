#include<stdio.h>
//ͷ�ļ�����׼�������
#include<stdlib.h>
//�ڴ���亯��malloc��ͷ�ļ�
typedef struct LNode
{
	int data;//����
	struct LNode *next;//ָ����һ���ڵ��ָ��

}LNode, *Linklist;
void CreatList(Linklist &L, int n);//�����µ����Ա�ĺ���
void MergeList(Linklist &l1, Linklist &L2, Linklist &l3);//ʵ���������������γɵ���������
void output(Linklist ll, int n);//���γɵ����Ա�����
