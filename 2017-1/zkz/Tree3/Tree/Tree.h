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
#define Value(p) ((p) ? (p)->data : 0)

#include <stdlib.h>

typedef enum _bool {false,true} bool;
typedef int elemType;
typedef struct _Node{
	elemType data;
	Node * parent;
	Node * left;
	Node * right;
}*BST,*AVL;

Node* newNode();
/*����������*/
void Show(Node* tree);
int getDepth(Node* tree);

BST newBST(int data);
bool BSTfind(BST bst, elemType data);
BST BSTinsert(BST bst, elemType data);
BST getMaxNode(BST bst);
BST getMinNode(BST bst);
BST BSTremove(BST bst, elemType data);

AVL newAVL(int data);
int getBalanceFactor(AVL avl);
bool isAVL(AVL avl);
bool AVLfind(AVL avl, elemType data);
/*ʹ��ƽ����ƽ��ĵ�������*/
void rightRotate(AVL root);
void leftRotate(AVL root);
AVL AVLfix(AVL avl);

AVL AVLinsert(AVL avl, elemType data);
AVL AVLremove(AVL avl, elemType data);