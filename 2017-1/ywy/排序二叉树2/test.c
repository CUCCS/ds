#include<stdio.h>  

#include<stdlib.h>  



//二叉查找树结点描述  

typedef int KeyType;

typedef int ElemType;

int flag;

typedef struct Node

{

	ElemType data;          //关键字  

	struct Node * left;   //左孩子指针  

	struct Node * right;  //右孩子指针  

	struct Node * parent; //指向父节点指针  

}Node, *PNode;



//往二叉查找树中插入结点  

//插入的话，可能要改变根结点的地址，所以传的是二级指针  

void inseart(PNode * T, KeyType key)

{

	//初始化插入结点  

	PNode p = (PNode)malloc(sizeof(Node));

	p->data = key;

	p->left = p->right = p->parent = NULL;

	//空树时，直接作为根结点  

	if ((*T) == NULL) {

		*T = p;

		return;

	}

	//插入到当前结点（*root）的左孩子  

	if ((*T)->left == NULL && (*T)->data > key) {

		p->parent = (*T);

		(*T)->left = p;

		return;

	}

	//插入到当前结点（*root）的右孩子  

	if ((*T)->right == NULL && (*T)->data < key) {

		p->parent = (*T);

		(*T)->right = p;

		return;

	}

	if ((*T)->data > key)

		inseart(&(*T)->left, key);

	else if ((*T)->data < key)

		inseart(&(*T)->right, key);

	else

		return;

}



//查找元素,找到返回关键字的结点指针，没找到返回NULL  

PNode search(PNode T, KeyType key)

{

	if (T == NULL)

		return NULL;

	if (key > T->data) //查找右子树  

		return search(T->right, key);

	else if (key < T->data) //查找左子树  

		return search(T->left, key);

	else

		return T;

}



//查找最小关键字,空树时返回NULL  

PNode searchMin(PNode T)

{

	if (T == NULL)

		return NULL;

	if (T->left == NULL)

		return T;

	else  //一直往左孩子找，直到没有左孩子的结点  

		return searchMin(T->left);

}



//查找最大关键字,空树时返回NULL  

PNode searchMax(PNode T)

{

	if (T == NULL)

		return NULL;

	if (T->right == NULL)

		return T;

	else  //一直往右孩子找，直到没有右孩子的结点  

		return searchMax(T->right);

}



//查找某个结点的前驱  

PNode searchPredecessor(PNode p)

{

	//空树  

	if (p == NULL)

		return p;

	//有左子树、左子树中最大的那个  

	if (p->left)

		return searchMax(p->left);

	//无左子树,查找某个结点的右子树遍历完了  

	else {

		if (p->parent == NULL)

			return NULL;

		//向上寻找前驱  

		while (p) {

			if (p->parent->right == p)

				break;

			p = p->parent;

		}

		return p->parent;

	}

}



//查找某个结点的后继  

PNode searchSuccessor(PNode p)

{

	//空树  

	if (p == NULL)

		return p;

	//有右子树、右子树中最小的那个  

	if (p->right)

		return searchMin(p->right);

	//无右子树,查找某个结点的左子树遍历完了  

	else {

		if (p->parent == NULL)

			return NULL;

		//向上寻找后继  

		while (p) {

			if (p->parent->left == p)

				break;

			p = p->parent;

		}

		return p->parent;

	}

}



//根据关键字删除某个结点,删除成功返回1,否则返回0  

//如果把根结点删掉，那么要改变根结点的地址，所以传二级指针  

int deleteNode(PNode* T, KeyType key)

{

	PNode q;

	//查找到要删除的结点  

	PNode p = search(*T, key);

	KeyType temp;    //暂存后继结点的值  

					 //没查到此关键字  

	if (!p)

		return 0;

	//1.被删结点是叶子结点，直接删除  

	if (p->left == NULL && p->right == NULL) {

		//只有一个元素，删完之后变成一颗空树  

		if (p->parent == NULL) {

			free(p);

			(*T) = NULL;

		}

		else {

			//删除的结点是父节点的左孩子  

			if (p->parent->left == p)

				p->parent->left = NULL;

			else  //删除的结点是父节点的右孩子  

				p->parent->right = NULL;

			free(p);

		}

	}



	//2.被删结点只有左子树  

	else if (p->left && !(p->right)) {

		p->left->parent = p->parent;

		//如果删除是父结点，要改变父节点指针  

		if (p->parent == NULL)

			*T = p->left;

		//删除的结点是父节点的左孩子  

		else if (p->parent->left == p)

			p->parent->left = p->left;

		else //删除的结点是父节点的右孩子  

			p->parent->right = p->left;

		free(p);

	}

	//3.被删结点只有右孩子  

	else if (p->right && !(p->left)) {

		p->right->parent = p->parent;

		//如果删除是父结点，要改变父节点指针  

		if (p->parent == NULL)

			*T = p->right;

		//删除的结点是父节点的左孩子  

		else if (p->parent->left == p)

			p->parent->left = p->right;

		else //删除的结点是父节点的右孩子  

			p->parent->right = p->right;

		free(p);

	}

	//4.被删除的结点既有左孩子，又有右孩子  

	//该结点的后继结点肯定无左子树(参考上面查找后继结点函数)  

	//删掉后继结点,后继结点的值代替该结点  

	else {

		//找到要删除结点的后继  

		q = searchSuccessor(p);

		temp = q->data;

		//删除后继结点  

		deleteNode(T, q->data);

		p->data = temp;

	}

	return 1;

}



//创建一棵二叉查找树  

void create(PNode* T, KeyType *keyArray, int length)

{

	int i;

	//逐个结点插入二叉树中  

	for (i = 0; i<length; i++)

		inseart(T, keyArray[i]);

}

int print(ElemType key, FILE*pfile)

{

	char d[] = ", ";

	if (NULL == pfile)

	{

		return 0;

	}

	if (NULL != pfile)

	{

		if (flag == 1)

		{

			fwrite(d, sizeof(d), 1, pfile);

		}

		fprintf(pfile, "%d", key);

		flag = 1;

	}

}

void pre(PNode T, FILE*pfile)

{

	if (T)

	{

		print(T->data, pfile);

		pre(T->left, pfile);

		pre(T->right, pfile);

	}

	//printf("\n");

}





int main(void)

{

	int i;

	char c = '\n';

	FILE*pfile;

	pfile = fopen(" BSTOutput.txt", "a");

	PNode T = NULL;

	KeyType nodeArray[12] = { 8, 10, 14, 3, 1, 6, 4, 7, 5, 19, 22, 30 };

	create(&T, nodeArray, 12);

	pre(T, pfile);

	fwrite(&c, sizeof(c), 1, pfile);

	KeyType searArray[5] = { 13, 8, 5, 20, 6 };

	for (i = 0; i < 5; i++)

	{

		if (deleteNode(&T, searArray[i]) == 0)

		{

			inseart(&T, searArray[i]);

		}

		flag = 0;

		//pre(T,pfile);

		fwrite(&c, sizeof(c), 1, pfile);

	}

	pre(T, pfile);

	fclose(pfile);

	pfile = NULL;

	return 0;

}