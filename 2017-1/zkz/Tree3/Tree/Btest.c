
#include <stdio.h>
#include "BTree.h"

void Traverse(Node* tree) {
	for (int i = 0; i < M; ++i) {
		//childs
		if (tree->childs[i])Traverse(tree->childs[i]);
		if (i == M - 1)break;
		//keys
		if(tree->keys[i])printf("%d ",tree->keys[i]);
	}
}
int main() {
	BTree tree = newBTree();
	int inputs[] = { 8, 10, 14, 3, 1, 6, 4, 7, 5, 19, 22, 30 };
	int size1 = 10;
	for (int i = 0; i < size1; ++i) {
		tree = Insert(tree, inputs[i]);
	}
	BFSprint(tree);
	printf("\n");
	for (int i = 1; i <= 20; ++i) {
		printf("%d\t%d\n",i,Find(tree,i));
	}
}