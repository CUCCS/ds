#include <stdio.h>
#include "Tree.h"
Node* newNode() {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = 0;
	temp->parent = temp->left = temp->right = NULL;
	return temp;
}
void Show(Node* tree) {
	printf("%d", tree->data);
	if (tree->left) {
		printf(", ");
		Show(tree->left);
	}
	if (tree->right) {
		printf(", ");
		Show(tree->right);
	}
}
int getDepth(Node* tree) {
	int leftDepth, rightDepth;
	if (!tree)return 0;
	leftDepth = 1 + getDepth(tree->left);
	rightDepth = 1 + getDepth(tree->right);
	return leftDepth > rightDepth ? leftDepth : rightDepth;
}
BST newBST(int data) {
	BST bst = newNode();
	bst->data = data;
	return bst;
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
	debug_print("BSTremove((%d),%d);\n", bst->data, data);
	BST temp;
	if (data < bst->data) BSTremove(bst->left, data);
	else if (data > bst->data) BSTremove(bst->right, data);
	else {
		debug_print("Node to remove found.\n");
		/*对于叶节点，断开与parent的关系后删除即可*/
		if (isLeaf(bst)) {
			debug_print("It's a leaf node\n");
			if (isLeftChild(bst))bst->parent->left = NULL;
			else if (isRightChild(bst))bst->parent->right = NULL;
			free(bst);
		}
		/*对于只有左/右孩子的情况，将左/右孩子连接至parent后删除即可*/
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
		/*对于待删除节点有两个孩子的情况，将其与左子树中值最大的节点交换，然后删除*/
		else {
			debug_print("It's a leaf with double child\n");
			temp = getMaxNode(bst->left);
			debug_print("Swap(%d,%d)\n", temp->data, bst->data);
			Swap(temp->data, bst->data);
			BSTremove(bst->left, temp->data);
		}
	}//end if data==bst->data

	return bst;
}
AVL newAVL(int data) {
	AVL avl = newNode();
	avl->data = data;
	return avl;
}
int getBalanceFactor(AVL avl) {
	if (!avl) { printf(__FUNCTION__"NULL avl to get BF\n"); exit(-1); }
	return getDepth(avl->left) - getDepth(avl->right);
}
bool isAVL(AVL avl) {
	return avl ? abs(getBalanceFactor(avl)) <= 1 && isAVL(avl->left) && isAVL(avl->right) : true;
}
bool AVLfind(AVL avl, elemType data) {
	return BSTfind(avl, data);
}
/*使非平衡树平衡的调整操作*/
void rightRotate(AVL root) {
	debug_print(__FUNCTION__" at node (%d)\n", root->data);
	debug_print("Before : node(%d) is {%d,%d,%d}\n", root->data, Value(root->parent), Value(root->left), Value(root->right));

	AVL temp = root->left;
	if (isLeftChild(root))root->parent->left = temp;
	else if (isRightChild(root)) root->parent->right = temp;
	temp->parent = root->parent;

	root->left = temp->right;
	if (temp->right)temp->right->parent = root;
	temp->right = root;
	root->parent = temp;
	debug_print("After : node(%d) is {%d,%d,%d}\n", root->data, Value(root->parent), Value(root->left), Value(root->right));
	root = root->parent;
	debug_print("After : node(%d) is {%d,%d,%d}\n", root->data, Value(root->parent), Value(root->left), Value(root->right));
}
void leftRotate(AVL root) {
	debug_print(__FUNCTION__" at node (%d)\n", root->data);
	debug_print("Before : node(%d) is {%d,%d,%d}\n", root->data, Value(root->parent), Value(root->left), Value(root->right));

	AVL temp = root->right;
	if (isLeftChild(root))root->parent->left = temp;
	else if (isRightChild(root)) root->parent->right = temp;
	temp->parent = root->parent;

	root->right = temp->left;
	if (temp->left)temp->left->parent = root;
	temp->left = root;
	root->parent = temp;
	debug_print("After : node(%d) is {%d,%d,%d}\n", root->data, Value(root->parent), Value(root->left), Value(root->right));
	root = root->parent;
	debug_print("After : node(%d) is {%d,%d,%d}\n", root->data, Value(root->parent), Value(root->left), Value(root->right));
}
AVL AVLfix(AVL avl) {
	AVL temp = avl;
	bool leftIsAVL, rightIsAVL;
	int BF, leftBF, rightBF;
	if (isAVL(avl))return avl;
	debug_print("node (%d) need to fix\n", avl->data);
	leftIsAVL = isAVL(temp->left);
	rightIsAVL = isAVL(temp->right);
	/*如果自己不平衡但左右子树平衡，则自己就是最小非平衡二叉树*/
	while (!leftIsAVL || !rightIsAVL) {
		/*否则如果左/右子树不平衡，那就让自己成为左/右子树*/
		temp = leftIsAVL ? temp->right : temp->left;

		leftIsAVL = isAVL(temp->left);
		rightIsAVL = isAVL(temp->right);
	}
	debug_print("The minimum unbalanced tree is at node (%d)\n", temp->data);
	/*此时，temp应该就是最小非平衡二叉树了*/
	BF = getBalanceFactor(temp);
	if (BF == 2) {
		leftBF = getBalanceFactor(temp->left);
		if (leftBF == 1) {
			debug_print("It needs a LL\n");
			rightRotate(temp);
		}
		else if (leftBF == -1) {
			debug_print("It needs a LR\n");
			leftRotate(temp->left);
			rightRotate(temp);
		}
		else {
			printf("%d Boom!\n", __LINE__);
			exit(-1);
		}
	}//end if BF==2
	else if (BF == -2) {
		rightBF = getBalanceFactor(temp->right);
		if (rightBF == 1) {
			debug_print("It needs a RL\n");
			rightRotate(temp->right);
			leftRotate(temp);
		}
		else if (rightBF == -1) {
			debug_print("It needs a RR\n");
			leftRotate(temp);
		}
		else {
			printf("%d Boom!\n", __LINE__);
			exit(-1);
		}
	}//end if BF==-2
	else {
		printf("%d BOOMSHAKALAKA!\n", __LINE__);
		exit(-1);
	}
	while (avl->parent)avl = avl->parent;
	return avl;
}
AVL AVLinsert(AVL avl, elemType data) {
	debug_print(__FUNCTION__"((%d),%d)\n", avl->data, data);
	BSTinsert(avl, data);
	return AVLfix(avl);
}
AVL AVLremove(AVL avl, elemType data) {
	debug_print(__FUNCTION__"((%d),%d)\n", avl->data, data);
	BSTremove(avl, data);
	return AVLfix(avl);
}