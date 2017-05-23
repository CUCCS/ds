#pragma once

#define Node struct _Node
/*����ص��жϺ�*/
#define isLeaf(node) (!(node)->left && !(node)->right)
#define hasParent(node) (!!(node)->parent)
#define hasLeft(node) (!!(node)->left)
#define hasRight(node) (!!(node)->right)
#define isLeft(child,parent) ((child) == (parent)->left)
#define isRight(child,parent) ((child) == (parent)->right)
#define isLeftChild(node) (hasParent(node) && isLeft((node),(node)->parent))
#define isRightChild(node) (hasParent(node) && isRight((node),(node)->parent))
/*����*/
#define Swap(a,b) if((a)!=(b))(a)^=(b),(b)^=(a),(a)^=(b)
/*��������غ�*/
#define DEBUG 0
#define debug_print(...) if(DEBUG)printf(__VA_ARGS__)
#include <stdlib.h>
typedef enum _bool {false,true} bool;
typedef int elemType;
typedef struct _Node{
	elemType data;
	Node * parent;
	Node * left;
	Node * right;
}*BST;

Node* newNode() {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = 0;
	temp->parent = temp->left = temp->right = NULL;
	return temp;
}
/*����������*/
void Show(Node* tree) {
	printf("%d",tree->data);
	if (tree->left) {
		printf(", ");
		Show(tree->left);
	}
	if (tree->right) {
		printf(", ");
		Show(tree->right);
	}
}
bool BSTfind(BST bst, elemType data) {
	if (data == bst->data)return true;
	if (data < bst->data) return bst->left ? BSTfind(bst->left, data) : false;
	if (data > bst->data)return bst->right ? BSTfind(bst->right, data) : false;
	debug_print("%d", __LINE__); exit(-1);
}
BST BSTinsert(BST bst, elemType data) {
	if (data < bst->data) {
		if (hasLeft(bst)) {
			BSTinsert(bst->left, data);
		}
		else {
			bst->left = newNode();
			bst->left->data = data;
			bst->left->parent = bst;
		}
		return bst;
	}
	if (data > bst->data) {
		if (hasRight(bst)) {
			BSTinsert(bst->right, data);
		}
		else {
			bst->right = newNode();
			bst->right->data = data;
			bst->right->parent = bst;
		}
		return bst;
	}
	printf("%d", __LINE__); exit(-1);
}
BST getMaxNode(BST bst) {
	while (hasRight(bst))bst = bst->right;
	return bst;
}
BST getMinNode(BST bst) {
	while (hasLeft(bst))bst = bst->left;
	return bst;
}
BST BSTremove(BST bst, elemType data) {
	debug_print("BSTremove((%d),%d);\n",bst->data,data);
	BST temp;
	if (data < bst->data) BSTremove(bst->left, data);
	else if (data > bst->data) BSTremove(bst->right, data);
	else {
		debug_print("Node to remove found.\n");
		/*����Ҷ�ڵ㣬�Ͽ���parent�Ĺ�ϵ��ɾ������*/
		if (isLeaf(bst)) {
			debug_print("It's a leaf node\n");
			if (isLeftChild(bst))bst->parent->left = NULL;
			else if (isRightChild(bst))bst->parent->right = NULL;
			free(bst);
		}
		/*����ֻ����/�Һ��ӵ����������/�Һ���������parent��ɾ������*/
		else if (hasLeft(bst) && !hasRight(bst)) {
			debug_print("It's a leaf with left child\n");
			if (isLeftChild(bst))bst->parent->left = bst->left;
			else if (isRightChild(bst))bst->parent->right = bst->left;
			free(bst);
		}
		else if (hasRight(bst) && !hasLeft(bst)) {
			debug_print("It's a leaf with right child\n");
			if (isLeftChild(bst))bst->parent->left = bst->right;
			else if (isRightChild(bst))bst->parent->right = bst->right;
			free(bst);
		}
		/*���ڴ�ɾ���ڵ����������ӵ��������������������ֵ���Ľڵ㽻����Ȼ��ɾ��*/
		else {
			debug_print("It's a leaf with double child\n");
			temp = getMaxNode(bst->left);
			debug_print("Swap(%d,%d)\n",temp->data,bst->data);
			Swap(temp->data, bst->data);
			BSTremove(bst->left,temp->data);
		}
	}//end if data==bst->data

	return bst;
}
BST newBST(int data) {
	BST bst = newNode();
	bst->data = data;
	return bst;
}