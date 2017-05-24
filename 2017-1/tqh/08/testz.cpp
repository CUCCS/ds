#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int num[] = {8,10,14,3,1,6,4,7,5,19,22,30};
int searchnum[] = {13,8,5,20,6};
int flag;
enum
{
	FALSE,
	TRUE
};
typedef struct BiTNode { // 结点结构
	int      data;
	struct BiTNode  *lchild, *rchild; // 左右孩子指针
} BiTNode,*BiTree;
typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;

Status PreOrderTraverse(BiTree T);
int SearchBST( BiTree T, int key, BiTree f, BiTree *p ) ;
int InsertBST( BiTree *T, int key );
Status Delete(BiTree *p);
int DeleteBST(BiTree *T,  int kval);

Status PreOrderTraverse(BiTree T)
{
	if(T){
		printf("%d ",T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
	return OK;
}

int SearchBST( BiTree T, int key, BiTree f, BiTree *p )  
{  
	BiTree s;  
	if( !T )  
	{   
		*p = f;
		return FALSE;
	}  
	else  
	{  
		while( T )  
		{  
			if( key == T->data )  
			{   
				*p = T;     
				return TRUE; 
			}  
			if( key > T->data )  
			{   
				s = T; 
				T = T->rchild;
			}  
			else  
			{  
				s = T;  
				T = T->lchild;  
			}  
		}  
		*p = s;  
		return FALSE;  
	}  
}
int InsertBST( BiTree *T, int key )  
{  
	/* 当二叉排序树T中不存在关键字等于key的数据元素时 */  
	/* 插入key并返回TRUE，否则返回FALSE */  
	/* 调用查找函数SearchBST，非递归 */  
	BiTree p, s;  
	if( !SearchBST( *T, key, NULL, &p ) )  
	{  
		s = (BiTree)malloc(sizeof(BiTNode));  
		s->data = key;  
		s->lchild = s->rchild = NULL;  
		if( !p )  
			*T = s;             /* 插入s为根节点，此前树为空树 */  
		else if( key > p->data )  
			p->rchild = s;       /* 插入s为右孩子 */  
		else  
			p->lchild = s;       /* 插入s为左孩子 */  
		return TRUE;  
	}  
	return FALSE;  
}
Status Delete(BiTree *p) {
	// 从二叉排序树中删除结点 p，
	// 并重接它的左子树或右子树
	BiTree q,s ;
	if(!&(*p)->rchild && !&(*p)->lchild)
	{
		p = NULL;
	}
	else if (!(*p)->rchild)  { // 右子树为空树则只需重接它的左子树
		q = *p;
		*p = (*p)->lchild;
		free(q);
	} 
	else if (!(*p)->lchild) { // 左子树为空树则只需重接它的右子树
		q = *p;
		*p = (*p)->rchild;
		free(q);
	} 
	else {  // 左右子树均不空
		q = *p;
		s = (*p)->lchild;
		while(s->rchild) { // s 指向被删结点的前驱
			q = s;
			s = s->rchild; 
		}
		(*p)->data = s->data;
		if(q != *p) { 
			q->rchild = s->lchild; // 重接*q的右子树
		} else {
			q->lchild = s->lchild; // 重接*q的左子树
		}
		free(s);
	}
	return OK;
} 
int DeleteBST(BiTree *T,  int kval) {
	// 若二叉排序树 T 中存在其关键字等于 kval 的
	// 数据元素，则删除该数据元素结点，并返回
	// 函数值 TRUE，否则返回函数值 FALSE
	if(!(*T)) { // 不存在关键字等于kval的数据元素
		return FALSE;
	} 
	else {  
		if(EQ(kval, (*T)->data)) { // 找到关键字等于key的数据元素
			Delete (T);
			return TRUE;
		} 
		else if(LT(kval, (*T)->data)) { // 继续在左子树中进行查找
			return DeleteBST(&(*T)->lchild, kval);
		}
		else { // 继续在右子树中进行查找
			return DeleteBST(&(*T)->rchild, kval);
		}
	}
}

int main()
{
	int j;
	BiTree T=NULL;
	for(j = 0;j < 12;j++)
	{
		InsertBST(&T, num[j]);
	}
	PreOrderTraverse(T);
	for(j = 0;j <5;j++)
	{
		if(!InsertBST(&T, searchnum[j])){
			DeleteBST(&T,searchnum[j]);
		}
		printf("\n");
		PreOrderTraverse(T);
	}
	return 0;
}
