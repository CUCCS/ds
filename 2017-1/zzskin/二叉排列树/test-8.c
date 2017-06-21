#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef char KeyTypem;      //关键字类型

typedef struct BiTNode
{
	ElemType data;
	struct BiTNode *lchild, *rchild;   //左右孩子的指针
}BiTNode, *BiTree;

typedef enum
{
	ERROR,
	OK
}Status;         //枚举定义（返回状态）

typedef enum
{
	True,
	False
}Bool;          //定义布尔类型

Status SearchBST(BiTree T,ElemType key)
{
	/* 递归查找二叉排序树T中是否存在key */
	/* 指针f指向T的双亲，其初始调用值为NULL */
	/* 若查找成功，则指针p指向该数据元素节点，并返回TRUE */
	/* 否则指针p指向查找路径上访问的最后一个节点并返回FALSE */
	if( !T )
	{
		return ERROR;
	}
	else
	{
		if(key == T->data)       //找到关键字等于key的数据元素
		{
			return OK;
		}
		else if(key < T->data)
		{
			return SearchBST( T->lchild, key);/* 在右子树继续查找*/
		}
		else
		{
			return SearchBST( T->rchild, key);/* 在左子树继续查找*/
		}
	}
	return OK;
}

int InsertBST(BiTree *T, int key)
{
	/* 当二叉排序树T中不存在关键字等于key的数据元素时 */
	/* 插入key并返回TRUE，否则返回FALSE */
	/* 调用查找函数SearchBST，非递归 */
	if( !(*T) )
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = key;
		(*T)->lchild = (*T)->rchild = NULL;
		return 1;
	}
	if( key == (*T)->data )
		{
			return 0;    
		}
	if( key > (*T)->data)
		{
			return  InsertBST(&((*T)->rchild),key);/* 插入右孩子 */
		}
		else
		{
			return  InsertBST(&((*T)->lchild),key);/* 插入左孩子 */
		}
}

Status createBST(BiTree *T, int a[], int n)   
{   
	int i;
	*T = NULL;    
	   
	for(i = 0; i < n; i++)   
	{   
		InsertBST(T, a[i]);   
	}   
	return OK; 
} 

void preOrderTraverse(BiTree T)
{
	if(T)
	{
		printf("%d ",T->data);
		preOrderTraverse(T->lchild);
		preOrderTraverse(T->rchild);
	}
}

Status Delete(BiTree *p)
{
	/* 从二叉排序树中删除节点p， 并重接它的左或右子树*/
	BiTree q, s;
	if( !(*p)->lchild && !(*p)->rchild)   /* p为叶子节点*/
	{
		*p = NULL;
	}
	else if( !(*p)->lchild )    /* 左子树为空，重接右子树 */
	{
		q = *p;
		*p = (*p)->rchild;
		free(q);
	}
	else if( !(*p)->rchild )      /* 右子树为空，重接左子树*/
	{
		q = *p;
		*p = (*p)->lchild;
		free(q);
	}
	else             /* 左右子树均不为空 */
	{
		q = *p;
		s = (*p)->lchild;
		while( s->rchild )     /* 转左，然后向右走到尽头*/
		{
			q = s;
			s = s->rchild;
		}
		(*p)->data = s->data;
		if( q != *p )    /* 判断是否执行上述while循环 */
		{
			q->rchild = s->lchild;    /* 执行上述while循环，重接右子树 */
		}
		else
		{
			q->lchild = s->rchild;     /* 未执行上述while循环，重接左子树*/
		}
		free(s);
	}
	return OK;
}

Status  DeleteBST(BiTree *T, int key)
{
/* 若二叉排序树T中存在关键字等于key的数据元素时，则删除该数据元素节点 */
/* 并返回TRUE；否则返回FALSE */
	if( !(*T) )
	{
		return ERROR;    /* 不存在关键字等于key的数据元素*/
	}
	else
	{
		if( key == (*T)->data )
		{
			Delete(T);
		}
		else if(key < (*T)->data )
		{
			return DeleteBST(&(*T)->lchild,key);
		}
		else
		{
			return DeleteBST(&(*T)->rchild,key);
		}
	}
}

int main()
{
	int a[12] = {8,10,14,3,1,6,4,7,5,19,22,30};
	int b[5] = {13,8,5,20,6};
	int n = 10; 
	int i = 0;//loop counter 

	//BSTtree 
	BiTree T;   
	printf("二叉树:\n"); 
	if(createBST(&T, a, n))
	{ 
		printf("成功建立二叉树！\n"); 
		preOrderTraverse(T);   
		printf("\n"); 
	} 
	else
	{ 
		printf("失败！"); 
	} 
	for( i = 0; i < 5; i++ ) 
	{ 
		if(SearchBST(T,b[i]))
		{ 
			printf("在树中删除  %d  \n", b[i]); 
			printf("删除后: "); 
			DeleteBST(&T,b[i]); 
			preOrderTraverse(T);  
			printf("\n\n"); 
		} 
		else
		{ 
			printf("新插入  %d .\n", b[i]); 
			if(InsertBST(&T,b[i]))
			{ 
				printf("插入后： "); 
				preOrderTraverse(T);  
				printf("\n\n"); 
			} 
			else
			{ 
				printf("插入失败 \n"); 
			} 
		} 
	} 
	return 0;   
} 