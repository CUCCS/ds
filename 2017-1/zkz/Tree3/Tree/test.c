#include <stdio.h>
#include "Tree.h"

void SuperShow(Node* tree) {
	if (!tree)return;
	if(!isLeaf(tree))printf("(");
	SuperShow(tree->left);
	if (tree->left)printf("��");
	printf(" %d ",tree->data);
	if (tree->right)printf("��");
	SuperShow(tree->right);
	if(!isLeaf(tree))printf(")");
}

int main() {
	/*�������뼰�����*/
	int inputs[] = { 8, 10, 14, 3, 1, 6, 4, 7, 5, 19, 22, 30 };
	int size1 = 12;
	int toFind[] = { 13, 8, 5, 20, 6 };
	int size2 = 5;

	/*��ʼ�����ұ�*/
	BST bst = newBST(inputs[0]);
	AVL avl = newAVL(inputs[0]);
	for (int i = 1; i < size1; ++i) {
		bst = BSTinsert(bst, inputs[i]);
		avl = AVLinsert(avl, inputs[i]);
		if (DEBUG)SuperShow(avl),printf("\n");
	}
	printf("BST:\n");
	Show(bst);
	printf("\n");
	/*��ʼ���Ҳ���*/
	for (int j = 0; j < size2; ++j) {
		/*����ҵ���ɾ����û�ҵ��Ͳ���*/
		BSTfind(bst, toFind[j]) ? BSTremove(bst, toFind[j]) : BSTinsert(bst, toFind[j]);
		Show(bst);
		printf("\n");
	}

	printf("AVL:\n");
	Show(avl);
	printf("\n");
	/*��ʼ���Ҳ���*/
	for (int j = 0; j < size2; ++j) {
		/*����ҵ���ɾ����û�ҵ��Ͳ���*/
		AVLfind(avl, toFind[j]) ? AVLremove(avl, toFind[j]) : AVLinsert(avl, toFind[j]);
		Show(avl);
		printf("\n");
	}
}