#include<stdio.h>
#include<stdlib.h>
#include "BiTree.h"
TElemType da[MAX_TREE_SIZE] = {'A','B','D','G',' ',' ',' ','E','H',' ',' ', 'I',' ','K',' ',' ', 'C', ' ', 'F' ,' ', ' ' };
TElemType db[MAX_TREE_SIZE] = {'A','B','D',' ','F',' ',' ',' ','C','E',' ', ' ',' '};
int main(){
	BiTree tree1 , tree2;
	CreateBiTree(&tree1,da);
	printf("%s","Tree 1 in preorder: ABDG---EH--I-K--C-F--");
	printf("%s","\nTree 1 in postorder: ");
	Postorder(tree1);
	count = 0;
	CreateBiTree(&tree2,db);
	printf("%s","\nTree 2 in preorder:  ABD-F---CE---");
	printf("%s","\nTree 2 in postorder: ");
	Postorder(tree2);
	return 0;

}