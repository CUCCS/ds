#include <stdio.h>
#include "BST.h"
int main() {
	BiTree T = NULL;
	TElemType c[] = { 8, 10, 14, 3, 1, 6, 4, 7, 5, 19, 22, 30 ,-1 },
		s[] = { 13, 8, 5, 20, 6 ,-1 };
	_CreateBST(&T, c);
	_print(T);
	_Search(T, s);
	return 0;
}