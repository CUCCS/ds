#include "Tree.h"

int main()  
{  
    int a[12] = { 8, 10, 14, 3, 1, 6, 4, 7, 5, 19, 22, 30 };  
	int b[5] = { 13, 8, 5, 20, 6 } ;
    int n = 10;
	int i = 0;//loop counter


	//BSTtree
    BSTTree T;  
    printf("BSTtree:\n");
    if(createBST(T, a, n)){
		printf("Tree creating succeeded:)\n");
		preOrderTraverse(T);  
		printf("\n");
	}
	else{
		printf("Tree creating faild:(");
	}

	for( i = 0; i < 5; i++ )
	{
		if(searchBST(T,b[i])){
			printf("FOUND %d in the BSTtree! Now delete it from the tree.\n", b[i]);
			printf("After delete: ");
			DeleteBST(&T,b[i]);
			preOrderTraverse(T); 
			printf("\n\n");
		}
		else{
			printf("%d NOT FOUND:( Now insert it into the tree.\n", b[i]);
			if(BSTInsert(T,b[i])){
				printf("After insert: ");
			    preOrderTraverse(T); 
			    printf("\n\n");
			}
			else{
				printf("Insert failed:(");
			}
		}
	}
    return 0;  
}  