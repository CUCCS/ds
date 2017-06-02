#include "BSTree.h"

int main(){
	ElemType test1[] = { 8,10,14,3,1,6,4,7,5,19,22,30 };
	KeyType Key[] = { 13,8,5,20,6 };
	int elem_number, search_number;
	int i;

	elem_number = sizeof(test1) / sizeof(ElemType);
	search_number = sizeof(Key) / sizeof(KeyType);

	BSTree Tree = NULL;
	BSTree temp = NULL;
	FILE *p;

	p = fopen("D:\\BaiduYunDownload\\BSTOutput.txt", "w+");

	CreateBST(&Tree, test1, elem_number);
	PrintTree(Tree,p);

	for (i = 0; i < search_number; i++) {
		if (!SearchBST(&Tree, Key[i], NULL, &temp)) {
			DeleteBST(&Tree, Key[i]);
			PrintTree(Tree,p);
		}
		else {
			InsertBST(&Tree, Key[i]);
			PrintTree(Tree,p);
		}
	}

	return 0;
}