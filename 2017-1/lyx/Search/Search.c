#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int flag;
typedef enum{
	OK,
	ERROR,
}Status;
typedef struct BiTNode
{
	int value;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

bool LT(int a,int b)//LessThan小于
{
	if(a<b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
在根指针root所指向的二叉排序树中递归地查找其关键字等于data的数据元素，若查找成功，则指针p指向该数据元素结点，并返回true， 
否则指针p指向查找路径上访问的最后一个结点并返回false指针，指针f指向root的双亲，其初始调用值NULL 
*/
bool SearchBST(BiTree root,int data)
{
	if(!root)
	{
		printf("未找到该数据,请重新输入!\n");
		return false;
	}
	else if(data == root->value)//查找成功
	{
		return true;
	}
	else if(data < root->value) //在左子树继续查找
	{
		return SearchBST(root->lchild,data);
	}
	else if(data > root->value) //在右子树继续查找  
	{
		return SearchBST(root->rchild,data);
	}
	return true;
}

//当二叉排序树root中不存在关键字等于data的数据元素时，插入data
bool InsertBST(BiTNode * &p, int element) 
{  
	if(NULL == p) // 空树  
	{  
		p =  (BiTree)malloc(sizeof(BiTNode));  
		p->value = element;  
		p->lchild = p->rchild = NULL;  
		return true;  
	}  
	if(element == p->value) // BST中不能有相等的值 
	{
		return false;  
	}
	if(element < p->value)  // 递归  
	{
		return InsertBST(p->lchild, element);  
	}
	return InsertBST(p->rchild, element); // 递归  
}  

// 建立BST  
Status CreateBST(BiTNode * &T, int a[], int n)  
{  
	T = NULL;   
	int i;  
	for(i = 0; i < n; i++)  
	{  
		InsertBST(T, a[i]);  
	}  
	return OK;
}
void PreOrderTraverse(BiTree root) //先序遍历
{
	if(root)
	{
		printf("%d ",root->value);
		PreOrderTraverse(root->lchild);
		PreOrderTraverse(root->rchild);
	}
}
void InOrderTraverse(BiTree root) //中序遍历
{
	if(root)
	{
		InOrderTraverse(root->lchild);
		printf("%d ,",root->value);
		InOrderTraverse(root->rchild);
	}
}
Status print(int data, FILE*pfile)
{
	char *d = ", ";
	if (NULL == pfile)
	{
		return ERROR;
	}
	if (NULL != pfile)
	{
		if (flag == 1)
		{
			fwrite(d, sizeof(d), 1, pfile);
		}
		fprintf(pfile, "%d", data);
		flag = 1;
	}
}
void PreOrderTraverse(BiTree T, FILE*pfile)
{
	if (T)
	{
		print(T->value, pfile);
		PreOrderTraverse(T->lchild, pfile);
		PreOrderTraverse(T->rchild, pfile);
	}
};
int Delete(BiTree *p)
{ 
	BiTree q,s;
	if(!(*p)->rchild)
	{//右子树空的话只需重接它的左
		q = *p;
		*p = (*p)->lchild;
		free(q);
	}
	else if(!(*p)->lchild)
	{//左子树为空的话，只需重接它的右子树
		q = *p;
		*p = (*p)->lchild;
		free(q);
	}
	else
	{//左右子树均不为空
		q = *p;
		s = (*p)->lchild;
		while(s->rchild)
		{//转左。然后向右走到尽头
			q = s;
			s = s->rchild;
		}
		(*p)->value = s->value;//s指向被删除结点的前驱
		if(q != *p)
		{//重接*q的右子树
			q->rchild = s->lchild;
		}
		else
		{//重接*q的左子树
			q->lchild = s->lchild;
		}
		delete s;
	}
	return true;
}
int DeleteBST(BiTree *T,int key)
{
	if(!T)
	{
		return false; 
	}
	else
	{
		if(key == (*T)->value)
		{//找到关键字为key的数据元素
			return Delete(T);
		}
		else if(key < (*T)->value)
		{//关键字小于结点的话，即在左子树
			return DeleteBST(&(*T)->lchild,key);
		}
		else if(key > (*T)->value)
		{//关键字大于结点的话，即在右子树
			return DeleteBST(&(*T)->rchild,key);
		}
	}
}
int main()
{
	int a[12] = { 8, 10, 14, 3, 1, 6, 4, 7, 5, 19, 22, 30 };
	int b[5] = { 13, 8, 5, 20, 6 };
	int n = 12;
	int i = 0;
	BiTree T;
	FILE*pfile = fopen("BSTOutput.txt", "a"); 
	if(CreateBST(T,a,n))
	{
		PreOrderTraverse(T);
		printf("\n");
	}//end if
	for(i = 0;i < 5;i++)
	{
		if(SearchBST(T,b[i]))
		{
			DeleteBST(&T,b[i]);
		}//end if
		else
		{
			InsertBST(T,b[i]);		
		}//end else
		flag=0;
		PreOrderTraverse(T);
		printf("\n");
		//end if
	}//end for
}//end main
