//��ҵ �� 2017-4-27 ������ 3�� 
//���������ö�������洢��
//���������������߶ȵ��㷨���������ĸ߶�Ҳ�ж���������ȣ���
//�������������ȵ��㷨�����������������ָ���������в��н����������ֵ����
//
//---------------------------------------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>
#include "BiTree.h"
TElemType da[MAX_TREE_SIZE] = {'A','B','D','G',' ',' ',' ','E','H',' ',' ', 'I',' ','K',' ',' ', 'C', ' ', 'F' ,' ', ' ' };
TElemType db[MAX_TREE_SIZE] = {'A','B','D',' ','F',' ',' ',' ','C','E',' ', ' ',' '};
int main(){
	BiTree treeA , treeB;
	printf("%s","Creating  binary treeA...\n");
	CreateBiTree(&treeA,da);
	printf("TreeA in preorder: ABDG---EH--I-K--C-F--");
	printf("\nTreeA's depth : %d",Depth(treeA) );
	printf("\nTreeA's width : %d\n",Width(treeA) );

	count = 0;//��ʼ�Ա����´���������
	printf("%s","\nCreating  binary treeB...");
	CreateBiTree(&treeB,db);
	printf("\nTreeB in preorder:  ABD-F---CE---");
	printf("\nTreeB's depth : %d",Depth(treeB) );
	printf("\nTreeB's width : %d\n",Width(treeB) );
	return 0;

}