//作业 ： 2017-4-27 第六章 3题 
//二叉树采用二叉链表存储：
//计算整个二叉树高度的算法（二叉树的高度也叫二叉树的深度）。
//计算二叉树最大宽度的算法（二叉树的最大宽度是指二叉树所有层中结点个数的最大值）。
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

	count = 0;//初始以便重新创建二叉树
	printf("%s","\nCreating  binary treeB...");
	CreateBiTree(&treeB,db);
	printf("\nTreeB in preorder:  ABD-F---CE---");
	printf("\nTreeB's depth : %d",Depth(treeB) );
	printf("\nTreeB's width : %d\n",Width(treeB) );
	return 0;

}