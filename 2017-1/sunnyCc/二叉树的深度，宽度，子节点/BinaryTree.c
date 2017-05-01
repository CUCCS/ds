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
int Width(BiTree T)//求二叉树T的最大宽度
{
	if (T == NULL)
		return (0); //空二叉树宽度为0
	else {
		BiTree Q[100], p; //Q是队列，元素为二叉树结点指针，容量足够大
		int front = 1, rear = 1, last = 1;//front队头指针,rear队尾指针,last同层最右结点在队列中的位置
		int temp = 0, maxw = 0; //temp记局部宽度, maxw记最大宽度
		Q[rear] = T; //根结点入队列 
		while (front <= last)
		{
			p = Q[front++];
			temp++; //同层元素数加1
			if (p->lchild != NULL)
				Q[++rear] = p->lchild; //左子女入队
			if (p->rchild != NULL)
				Q[++rear] = p->rchild;//右子女入队
			if (front > last) //一层结束
			{
				last = rear;
				if (temp > maxw)
					maxw = temp; //last指向下层最右元素, 更新当前最大宽度
				temp = 0;
			}//if 
		}//while
		return maxw;
	}
}//结束width
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
int NoLeafCount(BiTree  T)/*求二叉树中非叶子结点的数目*/
{
	if (!T)
		return 0; /*空树没有叶子*/
	else if (!T->lchild && !T->rchild)
		return 0; /*叶子结点*/
	else
		return (1 + NoLeafCount(T->lchild) + NoLeafCount(T->rchild));/*当前结点+左子树的非叶子数+右子树的非叶子数*/
}