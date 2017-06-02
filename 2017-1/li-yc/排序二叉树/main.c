#include "BiTree.h"

int main(){
	char c[30] = {8, 10, 14, 3, 1, 6, 4, 7, 5, 19, 22, 30};
	char c1[10] = {13, 8, 5, 20, 6};
	int i;
	bool flag = 0;
	BiTree T = NULL;
	BiTree p = NULL;

	for(i=0; i<12; i++){
		InsertBST(&T, c[i], p);
	}

	preOrderTraverse(T);
	printf("\n\n");

	for(i=0; i<5; i++){
		flag = SearchBST(T, c1[i], NULL, &p);
		if(flag == true){
			DeleteBST(&T, c1[i]);
		}
		else{
			InsertBST(&T, c1[i], p);
		}
		preOrderTraverse(T);
		printf("\n\n");
	}
	return 0;
}