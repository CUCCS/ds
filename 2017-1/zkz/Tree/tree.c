#include "tree.h"

#define EMPTY '#'

/*===字符串相关===*/
/*手动获取子串*/
char* substr(char* source, int begin, int end) {
	__try {
		int size = end - begin + 1;
		if (size <= 0) {
			return "";
		}
		char* result = (char*)malloc((size + 1) * sizeof(char));
		result[size] = '\0';
		--size;
		for (; size >= 0; --size) {
			result[size] = source[begin + size - 1];
		}
		return result;
	}
	__except (solveException) {};
}
/*手动分割字符串*/
void divideString(char* source, char delim, char** pDes1, char** pDes2) {
	__try {
		char* p = source;
		int size1, sizeS = strlen(source);
		while (*(p++) != delim);
		size1 = p - source - 1;
		*pDes1 = substr(source, 1, size1);
		*pDes2 = substr(source, size1 + 2, sizeS);
		//printf("divide %s with %c : %s and %s\n",source,delim,*pDes1 == "" ? "(empty)" : *pDes1, *pDes2 == "" ? "(empty)" : *pDes2);
	}
	__except (solveException) {};
}

inline Node* newNode() {
	__try {
		Node* p = (Node*)malloc(sizeof(Node));
		p->parent = p->left = p->right = NULL;
		p->data = 0;
		return p;
	}
	__except (solveException) {};
}
void InitializeTree(Tree* pT) {
	__try {
		*pT = newNode();
	}
	__except (solveException) {};
}
void _TraverseTree(const Tree root, Order order) {
	__try {
		/*如果root不为空 , 则根据order按顺序遍历root*/
		if (root) {
			if (order == pre)printf("%c ", root->data);
			_TraverseTree(root->left, order);
			if (order == in)printf("%c ", root->data);
			_TraverseTree(root->right, order);
			if (order == post)printf("%c ", root->data);
		}
	}
	__except (solveException) {};
}
/*遍历二叉树*/
/*root : 待遍历的二叉树*/
/*order : 遍历顺序(pre , in , post , all 分别为前序、中序、后序及所有顺序)*/
void TraverseTree(const Tree root, Order order) {
	if (order == all) {
		TraverseTree(root, pre);
		TraverseTree(root, in);
		TraverseTree(root, post);
		return;
	}
	debug_print("%s序遍历树0x%p : ", order == pre ? "前" : order == in ? "中" : "后", root);
	_TraverseTree(root, order);
	debug_print("\n");
}
inline int getDepth(const Tree t) {
	__try {
		int depth = 1;
		Node* p = t;
		while (p->parent) {
			++depth;
			p = p->parent;
		}
		return depth;
	}
	__except (solveException) {};
}
/*新建一个完全二叉树*/
void NewCBTree(Tree* pRoot, int depth) {
	__try {
		int i;
		for (i = getDepth(*pRoot) - 1; i > 0; --i) { debug_print("    "); }
		debug_print("以%p为根建立深度为%d的完全二叉树\n", *pRoot, depth);
		/*如果深度为1 , 说明就是个叶节点。只需left与right置空即可。*/
		if (depth == 1) {
			(*pRoot)->left = (*pRoot)->right = NULL;
			return;
		}
		/*构建左节点 , 最后以左节点为根建立深度为depth-1的树*/
		(*pRoot)->left = newNode();
		(*pRoot)->left->data = (*pRoot)->data * 2;
		(*pRoot)->left->parent = *pRoot;
		NewCBTree(&(*pRoot)->left, depth - 1);
		/*同理构建右节点*/
		(*pRoot)->right = newNode();
		(*pRoot)->right->data = (*pRoot)->data * 2 + 1;
		(*pRoot)->right->parent = *pRoot;
		NewCBTree(&(*pRoot)->right, depth - 1);

		for (i = getDepth(*pRoot) - 1; i > 0; --i) { debug_print("    "); }
		debug_print("树%p构建完毕 , 左子树为%p , 右子树为%p\n", (*pRoot), (*pRoot)->left, (*pRoot)->right);
	}
	__except (solveException) {};
}
/*删除树中数据为c的节点*/
void DeleteSpecialNode(Tree *pRoot, Elemtype c) {
	__try {
		if ((*pRoot)->left) {
			if ((*pRoot)->left->data == c) {
				free((*pRoot)->left);
				(*pRoot)->left = NULL;
			}
			else {
				DeleteSpecialNode(&(*pRoot)->left, c);
			}
		}
		if ((*pRoot)->right) {
			if ((*pRoot)->right->data == c) {
				free((*pRoot)->right);
				(*pRoot)->right = NULL;
			}
			else {
				DeleteSpecialNode(&(*pRoot)->right, c);
			}
		}
	}
	__except (solveException) {};
}
/*根据一个完整先序序列建立二叉树*/
Tree newBinaryTree(char* str) {
	__try {
		Node* current;
		Tree tree;
		InitializeTree(&tree);
		/*如果是空字符串则什么都不做*/
		if (strlen(str) == 0) {
			return tree;
		}
		debug_print("以【%s】为完整前序序列", str);
		debug_print("在0x%p处建立二叉树\n", tree);
		tree->data = str[0];
		current = tree;
		while (*++str != '\0') {
			if (current->left == NULL) {
				current->left = newNode();
				current->left->parent = current;
				current->left->data = *str;
				if (*str != EMPTY) {
					current = current->left;
				}
			}/*end if current->left == NULL*/
			else if (current->right == NULL) {
				current->right = newNode();
				current->right->parent = current;
				current->right->data = *str;
				if (*str != EMPTY) {
					current = current->right;
				}
			}/*end if current->left == NULL*/
			else {
				current = current->parent;
				--str;
			}
		}/*end while*/
		 /*去掉数据为空格的叶节点*/
		DeleteSpecialNode(&tree, EMPTY);
		return tree;
	}
	__except (solveException) {};
}
/*根据一个不完整的先序序列与一个不完整的中序序列建立二叉树*/
Tree _newBinaryTree2(char* pre, char* in) {
	__try {
		Tree tree = newNode();
		int len = strlen(pre);
		char * p = in;
		char* leftPre, *leftIn, *rightPre, *rightIn;
		if (strlen(pre) == 1 && strlen(in) == 1) {
			tree->data = *pre;
			return tree;
		}
		tree->data = pre[0];
		divideString(in, pre[0], &leftIn, &rightIn);
		/*有左子树*/
		if (strlen(leftIn)) {
			leftPre = substr(pre, 2, strlen(leftIn) + 1);
			tree->left = _newBinaryTree2(leftPre, leftIn);
		}
		/*有右子树*/
		if (strlen(rightIn)) {
			rightPre = substr(pre, strlen(pre) - strlen(rightIn) + 1, strlen(pre));
			tree->right = _newBinaryTree2(rightPre, rightIn);
		}

		return tree;
	}
	__except (solveException) {};
}
Tree newBinaryTree2(char*pre, char* in) {
	Tree tree = _newBinaryTree2(pre, in);
	debug_print("以【%s】与【%s】在0x%p处建立二叉树\n", pre, in, tree);
	return tree;
}