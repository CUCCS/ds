#include<stdio.h>  
#include<stdlib.h>  

//����������������  
typedef int KeyType;
typedef int ElemType;
int flag;
typedef struct Node
{
	ElemType data;          //�ؼ���  
	struct Node * left;   //����ָ��  
	struct Node * right;  //�Һ���ָ��  
	struct Node * parent; //ָ�򸸽ڵ�ָ��  
}Node, *PNode;

//������������в�����  
//����Ļ�������Ҫ�ı�����ĵ�ַ�����Դ����Ƕ���ָ��  
void inseart(PNode * T, KeyType key)
{
	//��ʼ��������  
	PNode p = (PNode)malloc(sizeof(Node));
	p->data = key;
	p->left = p->right = p->parent = NULL;
	//����ʱ��ֱ����Ϊ�����  
	if ((*T) == NULL) {
		*T = p;
		return;
	}
	//���뵽��ǰ��㣨*root��������  
	if ((*T)->left == NULL && (*T)->data > key) {
		p->parent = (*T);
		(*T)->left = p;
		return;
	}
	//���뵽��ǰ��㣨*root�����Һ���  
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

//����Ԫ��,�ҵ����عؼ��ֵĽ��ָ�룬û�ҵ�����NULL  
PNode search(PNode T, KeyType key)
{
	if (T == NULL)
		return NULL;
	if (key > T->data) //����������  
		return search(T->right, key);
	else if (key < T->data) //����������  
		return search(T->left, key);
	else
		return T;
}

//������С�ؼ���,����ʱ����NULL  
PNode searchMin(PNode T)
{
	if (T == NULL)
		return NULL;
	if (T->left == NULL)
		return T;
	else  //һֱ�������ң�ֱ��û�����ӵĽ��  
		return searchMin(T->left);
}

//�������ؼ���,����ʱ����NULL  
PNode searchMax(PNode T)
{
	if (T == NULL)
		return NULL;
	if (T->right == NULL)
		return T;
	else  //һֱ���Һ����ң�ֱ��û���Һ��ӵĽ��  
		return searchMax(T->right);
}

//����ĳ������ǰ��  
PNode searchPredecessor(PNode p)
{
	//����  
	if (p == NULL)
		return p;
	//�����������������������Ǹ�  
	if (p->left)
		return searchMax(p->left);
	//��������,����ĳ��������������������  
	else {
		if (p->parent == NULL)
			return NULL;
		//����Ѱ��ǰ��  
		while (p) {
			if (p->parent->right == p)
				break;
			p = p->parent;
		}
		return p->parent;
	}
}

//����ĳ�����ĺ��  
PNode searchSuccessor(PNode p)
{
	//����  
	if (p == NULL)
		return p;
	//��������������������С���Ǹ�  
	if (p->right)
		return searchMin(p->right);
	//��������,����ĳ��������������������  
	else {
		if (p->parent == NULL)
			return NULL;
		//����Ѱ�Һ��  
		while (p) {
			if (p->parent->left == p)
				break;
			p = p->parent;
		}
		return p->parent;
	}
}

//���ݹؼ���ɾ��ĳ�����,ɾ���ɹ�����1,���򷵻�0  
//����Ѹ����ɾ������ôҪ�ı�����ĵ�ַ�����Դ�����ָ��  
int deleteNode(PNode* T, KeyType key)
{
	PNode q;
	//���ҵ�Ҫɾ���Ľ��  
	PNode p = search(*T, key);
	KeyType temp;    //�ݴ��̽���ֵ  
					 //û�鵽�˹ؼ���  
	if (!p)
		return 0;
	//1.��ɾ�����Ҷ�ӽ�㣬ֱ��ɾ��  
	if (p->left == NULL && p->right == NULL) {
		//ֻ��һ��Ԫ�أ�ɾ��֮����һ�ſ���  
		if (p->parent == NULL) {
			free(p);
			(*T) = NULL;
		}
		else {
			//ɾ���Ľ���Ǹ��ڵ������  
			if (p->parent->left == p)
				p->parent->left = NULL;
			else  //ɾ���Ľ���Ǹ��ڵ���Һ���  
				p->parent->right = NULL;
			free(p);
		}
	}

	//2.��ɾ���ֻ��������  
	else if (p->left && !(p->right)) {
		p->left->parent = p->parent;
		//���ɾ���Ǹ���㣬Ҫ�ı丸�ڵ�ָ��  
		if (p->parent == NULL)
			*T = p->left;
		//ɾ���Ľ���Ǹ��ڵ������  
		else if (p->parent->left == p)
			p->parent->left = p->left;
		else //ɾ���Ľ���Ǹ��ڵ���Һ���  
			p->parent->right = p->left;
		free(p);
	}
	//3.��ɾ���ֻ���Һ���  
	else if (p->right && !(p->left)) {
		p->right->parent = p->parent;
		//���ɾ���Ǹ���㣬Ҫ�ı丸�ڵ�ָ��  
		if (p->parent == NULL)
			*T = p->right;
		//ɾ���Ľ���Ǹ��ڵ������  
		else if (p->parent->left == p)
			p->parent->left = p->right;
		else //ɾ���Ľ���Ǹ��ڵ���Һ���  
			p->parent->right = p->right;
		free(p);
	}
	//4.��ɾ���Ľ��������ӣ������Һ���  
	//�ý��ĺ�̽��϶���������(�ο�������Һ�̽�㺯��)  
	//ɾ����̽��,��̽���ֵ����ý��  
	else {
		//�ҵ�Ҫɾ�����ĺ��  
		q = searchSuccessor(p);
		temp = q->data;
		//ɾ����̽��  
		deleteNode(T, q->data);
		p->data= temp;
	}
	return 1;
}

//����һ�ö��������  
void create(PNode* T, KeyType *keyArray, int length)
{
	int i;
	//����������������  
	for (i = 0; i<length; i++)
		inseart(T, keyArray[i]);
}
int print(ElemType key, FILE*pfile)
{
	char *d = ", ";
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
void pre(PNode T,FILE*pfile)
{
	if (T)
	{
		print( T->data,pfile);
		pre(T->left,pfile);
		pre(T->right,pfile);
	}
	//printf("\n");
}


int main(void)
{
	int i;
	char c = '\n';
	FILE*pfile;
	pfile = fopen(" BSTOutput.txt","a");
	PNode T = NULL;
	KeyType nodeArray[12] = { 8, 10, 14, 3, 1, 6, 4, 7, 5, 19, 22, 30 };
	create(&T, nodeArray, 12);
	pre(T,pfile);
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

