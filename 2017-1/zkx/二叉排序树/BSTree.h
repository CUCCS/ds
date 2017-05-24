#include <stdio.h>
#include <stdlib.h>
 
#define EQ(a,b) (a==b)
#define LT(a,b) (a<b)
#define LQ(a,b) (a<=b)

int visit[25];
int u = 0;         //用来计数，以便使用.txt格式进行输出

typedef int ElemType;

typedef struct BiTNode
{
	ElemType data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;

}BiTNode, *BiTree;

typedef enum
{   
	OK,
	ERROR,
	OVERFLOW
}Status;

typedef enum
{
	TRUE,
	FALSE
}Status;

Status SearchBST(BiTree T, ElemType key, BiTree f, BiTree *p);

Status InsertBST(BiTree *T, ElemType e);

Status PreOrderTraverse(BiTree T);

Status Delete(BiTree *p);

Status DeleteBST(BiTree *T, ElemType key);

Status  print(BiTree T, FILE *fp);

