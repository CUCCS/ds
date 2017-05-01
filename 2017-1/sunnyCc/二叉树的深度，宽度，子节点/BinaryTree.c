#include"BinaryTree.h"
int count = 0;
Status CreateBiTree(BiTree *T, TElemType *p)
{
	TElemType ch;
	ch = p[count];
	count++;
	if (ch == '#')        //if the tree has no child
	{
		*T = NULL;
	}
	else
	{
		if (!(*T = (BiTree)malloc(sizeof(BiTNode))))
		{
			return OVERFLOW;
		}
		(*T)->data = ch;              // creat root node
		CreateBiTree(&(*T)->lchild, p);   // creat left node,"&(*T)->lchild" is equal to "&((*T)->lchild)"
		CreateBiTree(&(*T)->rchild, p);   //creat right node
	}
	return OK;
}
void PostOrderTraverse(BiTree T)
{
	if (T == NULL)
	{
		return;
	}
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%c", T->data);
}
int Depth(BiTree T)
{
	int dep1, dep2;
	if (T == NULL) return(0);
	else
	{
		dep1 = Depth(T->lchild);
		dep2 = Depth(T->rchild);
		if (dep1 > dep2) return(dep1 + 1);
		else return(dep2 + 1);
	}
}
int Width(BiTree T)//�������T�������
{
	if (T == NULL)
		return (0); //�ն��������Ϊ0
	else {
		BiTree Q[100], p; //Q�Ƕ��У�Ԫ��Ϊ���������ָ�룬�����㹻��
		int front = 1, rear = 1, last = 1;//front��ͷָ��,rear��βָ��,lastͬ�����ҽ���ڶ����е�λ��
		int temp = 0, maxw = 0; //temp�Ǿֲ����, maxw�������
		Q[rear] = T; //���������� 
		while (front <= last)
		{
			p = Q[front++];
			temp++; //ͬ��Ԫ������1
			if (p->lchild != NULL)
				Q[++rear] = p->lchild; //����Ů���
			if (p->rchild != NULL)
				Q[++rear] = p->rchild;//����Ů���
			if (front > last) //һ�����
			{
				last = rear;
				if (temp > maxw)
					maxw = temp; //lastָ���²�����Ԫ��, ���µ�ǰ�����
				temp = 0;
			}//if 
		}//while
		return maxw;
	}
}//����width
int Count(BiTree  T)
{
	if (T == NULL) {
		return 0;
	}
	else if ((T->lchild == NULL) && (T->rchild == NULL)) {
		return 1;
	}
	else {
		return Count(T->lchild) + Count(T->rchild);
	}
}
int NoLeafCount(BiTree  T)/*��������з�Ҷ�ӽ�����Ŀ*/
{
	if (!T)
		return 0; /*����û��Ҷ��*/
	else if (!T->lchild && !T->rchild)
		return 0; /*Ҷ�ӽ��*/
	else
		return (1 + NoLeafCount(T->lchild) + NoLeafCount(T->rchild));/*��ǰ���+�������ķ�Ҷ����+�������ķ�Ҷ����*/
}