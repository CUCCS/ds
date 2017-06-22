#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef enum {
    FALSE,
    TRUE
}bool;

typedef enum {
	ERROR,
	OK
}Status;

typedef struct BiTNode {
	int value;
	struct BiTNode *lchild, *rchild;
}*BiTree,BiTNode;

bool LT(int a, int b)//LessThan小于  
{
	if (a<b)
		return TRUE;
	else
		return FALSE;
}

//当二叉排序树root中不存在关键字等于data的数据元素时，插入data  
bool InsertBST(BiTNode *p, int data) //root为传引用指针  
{
	if (NULL ==p) // 空树  
		{
		p = (BiTree)malloc(sizeof(BiTNode));
		p->value =data;
		p->lchild = p->rchild = NULL;
		return TRUE;
		}
		if (data==p->value) // BST中不能有相等的值  
        {
		return FALSE;
         }if (data< p->value)  // 递归   
		{
		return InsertBST(p->lchild,data);
		}
         return InsertBST(p->rchild,data); // 递归
		 return TRUE;
}

Status createBST(BiTree *T, int a[], int n)
	  {
	  T = NULL;
	  int i;
	  for (i = 0; i < n; i  )
		  {
       InsertBST(T, a[i]);
		  }
	  return OK;
	  }
void  PreOrderTraverse(BiTree root)//先序遍历 
{
	if (root)
	{
		printf("%d ", root->value);
		PreOrderTraverse(root->lchild);
		PreOrderTraverse(root->rchild);
	}
}
void InOrderTraverse(BiTree root)//中序遍历 
{
	if (root)
	{
		InOrderTraverse(root->lchild);
		printf("%d ", root->value);
		InOrderTraverse(root->rchild);
	}
}
void PostOrderTraverse(BiTree root)//后序遍历 
{
	if (root)
	{
		PostOrderTraverse(root->lchild);
		PostOrderTraverse(root->rchild);
		printf("%d ", root->value);
	}
}
bool SearchBST(BiTree root, int data)

{
	if (!root)
	{
		return FALSE;
	}
	else if(data== root->value)//查找成功 
	{
		return TRUE;
	}
	else if(data< root->value) //在左子树继续查找 
		return SearchBST(root->lchild, data);
	else if(data> root->value) //在右子树继续查找 
		return SearchBST(root->rchild, data);
	return TRUE;
}

 Status Delete(BiTree *p)
 {

	         /* 从二叉排序树中删除节点p， 并重接它的左或右子树 */
		 BiTree q, s;
	 if (!(*p)->lchild && !(*p)->rchild) /* p为叶子节点 */
		 {
		 *p = NULL;
		 }
	 else if (!(*p)->lchild) /* 左子树为空，重接右子树 */
		 {
		 q = *p;
		 *p = (*p)->rchild;
		 free(q);
		 }
	 else if (!(*p)->rchild) /* 右子树为空，重接左子树 */
	 {
		 q = *p;
		 *p = (*p)->lchild;
		 free(q);
		 }
	 else                        /* 左右子树均不为空 */
		 {
		 q = *p;
		 s = (*p)->lchild;
		 while (s->rchild)     /* 转左，然后向右走到尽头*/
		 {
			 q = s;
			 s = s->rchild;
		 }
		 (*p)->value= s->value;
		 if (q != *p)               /* 判断是否执行上述while循环 */
			 {
			 q->rchild = s->lchild;    /* 执行上述while循环，重接右子树 */
			 }
		 else {
			 q->lchild = s->lchild;    /* 未执行上述while循环，重接左子树 */	 
		}
		 free(s);
		 }
	 return OK;
	 }

 Status DeleteBST(BiTree *T, int key)
 {
	         /* 若二叉排序树T中存在关键字等于key的数据元素时，则删除该数据元素节点 */
		         /* 并返回TRUE；否则返回FALSE */
		 if (!(*T)) {
		 return ERROR;   /* 不存在关键字等于key的数据元素 */	 
	}
	 else
		 {
		 if (key == (*T)->value) {
			 Delete(T);	 
		}
		 else if (key < (*T)->value) {
			 return DeleteBST(&(*T)->lchild, key); 
		}
		 else {
            return DeleteBST(&(*T)->rchild, key);	 
		}
		 }
	 }
int main() {
	int a[12] = { 8, 10, 14, 3, 1, 6, 4, 7, 5, 19, 22, 30 };
	 int b[5] = { 13, 8, 5, 20, 6 };
	 int n = 10;
	 int i = 0;//loop counter 
		 	//BSTtree 
		 BiTree T;
	 printf("BiTtree:\n");
	 if (createBST(T, a, n)) {
		 printf("创建了一棵树\n");
		 PreOrderTraverse(T);
		 printf("\n"); 
	}
	 else {
		 printf("创建树失败");	 
	}
		 for (i = 0; i < 5; i ++ )
		 {
		 if (SearchBST(T, b[i])) {
			 printf("在数中找到 %d ! 现在把这个数从树中删除。\n", b[i]);
			 printf("删除以后: ");
			 DeleteBST(&T, b[i]);
			 PreOrderTraverse(T);
			 printf("\n\n");		 
		}
		 else {

			 printf("%d 没有找到:( 现在把这个数加入树中。\n", b[i]);
			 if (InsertBST(T, b[i])) {
				 printf("插入后: ");
				 PreOrderTraverse(T);
				 printf("\n\n");	 
			}
			 else {
				 printf("插入失败");	 
			}	 
		}
		 }
	 return 0;
}