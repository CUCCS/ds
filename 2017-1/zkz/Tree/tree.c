#include "tree.h"

#define EMPTY '#'

/*===�ַ������===*/
/*�ֶ���ȡ�Ӵ�*/
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
/*�ֶ��ָ��ַ���*/
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
		/*���root��Ϊ�� , �����order��˳�����root*/
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
/*����������*/
/*root : �������Ķ�����*/
/*order : ����˳��(pre , in , post , all �ֱ�Ϊǰ�����򡢺�������˳��)*/
void TraverseTree(const Tree root, Order order) {
	if (order == all) {
		TraverseTree(root, pre);
		TraverseTree(root, in);
		TraverseTree(root, post);
		return;
	}
	debug_print("%s�������0x%p : ", order == pre ? "ǰ" : order == in ? "��" : "��", root);
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
/*�½�һ����ȫ������*/
void NewCBTree(Tree* pRoot, int depth) {
	__try {
		int i;
		for (i = getDepth(*pRoot) - 1; i > 0; --i) { debug_print("    "); }
		debug_print("��%pΪ���������Ϊ%d����ȫ������\n", *pRoot, depth);
		/*������Ϊ1 , ˵�����Ǹ�Ҷ�ڵ㡣ֻ��left��right�ÿռ��ɡ�*/
		if (depth == 1) {
			(*pRoot)->left = (*pRoot)->right = NULL;
			return;
		}
		/*������ڵ� , �������ڵ�Ϊ���������Ϊdepth-1����*/
		(*pRoot)->left = newNode();
		(*pRoot)->left->data = (*pRoot)->data * 2;
		(*pRoot)->left->parent = *pRoot;
		NewCBTree(&(*pRoot)->left, depth - 1);
		/*ͬ�����ҽڵ�*/
		(*pRoot)->right = newNode();
		(*pRoot)->right->data = (*pRoot)->data * 2 + 1;
		(*pRoot)->right->parent = *pRoot;
		NewCBTree(&(*pRoot)->right, depth - 1);

		for (i = getDepth(*pRoot) - 1; i > 0; --i) { debug_print("    "); }
		debug_print("��%p������� , ������Ϊ%p , ������Ϊ%p\n", (*pRoot), (*pRoot)->left, (*pRoot)->right);
	}
	__except (solveException) {};
}
/*ɾ����������Ϊc�Ľڵ�*/
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
/*����һ�������������н���������*/
Tree newBinaryTree(char* str) {
	__try {
		Node* current;
		Tree tree;
		InitializeTree(&tree);
		/*����ǿ��ַ�����ʲô������*/
		if (strlen(str) == 0) {
			return tree;
		}
		debug_print("�ԡ�%s��Ϊ����ǰ������", str);
		debug_print("��0x%p������������\n", tree);
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
		 /*ȥ������Ϊ�ո��Ҷ�ڵ�*/
		DeleteSpecialNode(&tree, EMPTY);
		return tree;
	}
	__except (solveException) {};
}
/*����һ��������������������һ�����������������н���������*/
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
		/*��������*/
		if (strlen(leftIn)) {
			leftPre = substr(pre, 2, strlen(leftIn) + 1);
			tree->left = _newBinaryTree2(leftPre, leftIn);
		}
		/*��������*/
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
	debug_print("�ԡ�%s���롾%s����0x%p������������\n", pre, in, tree);
	return tree;
}