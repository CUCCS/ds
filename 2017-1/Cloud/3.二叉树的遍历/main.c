#include<stdio.h>
#include<stdlib.h>
#include "BiTree.h"
TElemType tr_A[MAX_TREE_SIZE] = {'A','B','D','G',' ',' ',' ','E','H',' ',' ', 'I',' ','K',' ',' ', 'C', ' ', 'F' ,' ', ' ' };
TElemType tr_B[MAX_TREE_SIZE] = {'A','B','D',' ','F',' ',' ',' ','C','E',' ', ' ',' '};
int main(){
	BiTree treeA , treeB;
	printf("%s","Creating  binary treeA...");
	CreateBiTree(&treeA,tr_A);
	printf("\nTreeA in preorder: ABDG---EH--I-K--C-F--");
	printf("\nTreeA's depth : %d",Depth(treeA));
	printf("\nTreeA's width : %d",Width(treeA));
	printf("\nThe number of TreeA's leaf node : %d",CountLeafNode(treeA));
	printf("\nThe number of TreeA's non-leaf node : %d\n",CountNonLeafNode(treeA));
	printf("%s","\nCreating  binary treeB...");
	count = 0 ;
	CreateBiTree(&treeB,tr_B);
	printf("\nTreeB in preorder:  ABD-F---CE---");
	printf("\nTreeB's depth : %d",Depth(treeB));
	printf("\nTreeB's width : %d",Width(treeB));
	printf("\nThe number of TreeB's leaf node : %d",CountLeafNode(treeB));
	printf("\nThe number of TreeB's non-leaf node : %d\n",CountNonLeafNode(treeB));
	return 0;

}