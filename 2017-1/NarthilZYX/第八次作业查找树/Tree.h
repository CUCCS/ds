#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef int ElemType;
typedef enum{
	ERROR,
    OK
}Status;
typedef enum{
	False,
	True
}Bool;
typedef struct BiTNode {
	ElemType data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BSTTree, *AVLTree, *B3Tree;

//------BSTTree------//
// 在给定的BST中插入结点，其数据域为element, 使之称为新的BST  
Bool BSTInsert(BiTNode * &p, int element)  
{  
    if(NULL == p) // 空树  
    {  
        p =  (BSTTree)malloc(sizeof(BiTNode));  
        p->data = element;  
        p->lchild = p->rchild = NULL;  
        return True;  
    }  
  
    if(element == p->data) // BST中不能有相等的值 
	{
        return False;  
	}
    if(element < p->data)  // 递归  
	{
        return BSTInsert(p->lchild, element);  
	}
    return BSTInsert(p->rchild, element); // 递归  
}  
  
// 建立BST  
Status createBST(BiTNode * &T, int a[], int n)  
{  
    T = NULL;   
    int i;  
    for(i = 0; i < n; i++)  
    {  
        BSTInsert(T, a[i]);  
    }  
	return OK;
}

void preOrderTraverse(BSTTree T)  
	//先序遍历二叉排列树
{  
    if(T)  
    {  
		printf("%d ",T->data);  
        preOrderTraverse(T->lchild);  
        preOrderTraverse(T->rchild);  
    }  
}
Status Delete(BSTTree &p)//从二叉排序树中删除结点p，并重接它的左或右子树
{
	BiTNode *q, *s;
    if(!p->rchild)//右子树空则只需重接它的左子树
    {
        q=p;
        p=p->lchild;
        free(q);
     }
    else if(!p->lchild)//左子树空只需重接它的右子树
    {
        q=p;
        p=p->rchild;
        free(q);
    }
    else//左右子树均不空
    {
            q=p;
            s=p->lchild;
        while(s->rchild)//转左，然后向右到尽头
        {
           q=s;
            s=s->rchild;
        }
            p->data=s->data;//s指向被删结点的“前驱”
        if(q!=p)//以上循环至少执行了一次
           q->rchild=s->lchild;
        else
            q->lchild=s->lchild;//重接*q的左子树
        delete(s);
     }
    return OK;
}
Status searchBST(BSTTree T,ElemType key)
	//若二叉排序树T中存在关键字等于key的数据元素时，则删除该数据元素，并返回TRUE；否则返回FALSE
{
    if(!T)
	{
        return ERROR;
	}
    else
    {
        if(key==T->data)//找到关键字等于key的数据元素      
		{
            return OK;
		}
        else if(key<T->data){
            return searchBST(T->lchild,key);
		}
        else{
            return searchBST(T->rchild,key);
		}
    }
    return OK;
}
      
Status Delete(BSTTree *p)  
{  
        /* 从二叉排序树中删除节点p， 并重接它的左或右子树 */  
        BSTTree q, s;  
        if(  !(*p)->lchild && !(*p)->rchild ) /* p为叶子节点 */  
		{
            *p = NULL;  
		}
        else if( !(*p)->lchild ) /* 左子树为空，重接右子树 */  
        {  
            q = *p;   
            *p = (*p)->rchild;  
            free(q);  
        }  
        else if( !(*p)->rchild ) /* 右子树为空，重接左子树 */  
        {  
            q = *p;  
            *p = (*p)->lchild;         
            free(q);  
        }  
        else                        /* 左右子树均不为空 */  
        {  
            q = *p;  
            s = (*p)->lchild;  
            while(s->rchild)     /* 转左，然后向右走到尽头*/  
            {  
                q = s;  
                s = s->rchild;  
            }  
            (*p)->data = s->data;  
            if( q != *p )               /* 判断是否执行上述while循环 */  
			{
                q->rchild = s->lchild;    /* 执行上述while循环，重接右子树 */   
			}
            else  {
                q->lchild = s->lchild;    /* 未执行上述while循环，重接左子树 */  
			}
            free(s);  
        }  
        return OK;  
}  

Status DeleteBST(BSTTree *T, int key)  
{  
        /* 若二叉排序树T中存在关键字等于key的数据元素时，则删除该数据元素节点 */  
        /* 并返回TRUE；否则返回FALSE */  
	if( !(*T))  {
		return ERROR;   /* 不存在关键字等于key的数据元素 */  
	}
    else  
    {  
        if( key == (*T)->data ){
            Delete(T);  
		}
        else if( key < (*T)->data){
            return DeleteBST(&(*T)->lchild, key);  
		}
        else {
            return DeleteBST(&(*T)->rchild, key);  
		}
        }  
    }  

//------AVLTree------//

//------B3Tree------//