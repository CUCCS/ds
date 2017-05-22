#include "BinaryTree.h"
#include <stdbool.h>
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
	printf("%c ", T->data);
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
int Width(BiTree T)//The most width of a binary tree
{
	if (T == NULL)
		return (0); //The width of a empty binary tree is 0
	else {
		BiTree Q[100], p; //Constructing a queue to store the node of a binary tree and assuming that the queue has an enough capacity
		int front = 1, rear = 1, last = 1;//front队头指针,rear队尾指针,last同层最右结点在队列中的位置
		int temp = 0, maxw = 0; //temp width and max width
		Q[rear] = T; //Enqueueing the rear root
		while (front <= last)
		{
			p = Q[front++];
			temp++; 
			if (p->lchild != NULL)
				Q[++rear] = p->lchild; //Enqueueing the left child
			if (p->rchild != NULL)
				Q[++rear] = p->rchild;//Enqueueing the right child
			if (front > last) //end that floor
			{
				last = rear;
				if (temp > maxw)
					maxw = temp; // Pointing last to next floor's right-most element while updating the most width
				temp = 0;
			}//if 
		}//while
		return maxw;
	}
}//enwidth
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
int NoLeafCount(BiTree  T)//No leaf count 
{
	if (!T)//If the Binary tree is empty ,it has no leaf count
		return 0; 
	else if (!T->lchild && !T->rchild)
		return 0;//This T has leaf count
	else
		return (1 + NoLeafCount(T->lchild) + NoLeafCount(T->rchild));//The sum of no leaf count =current node+no-leaf count of right+no-leaf count of left

}

