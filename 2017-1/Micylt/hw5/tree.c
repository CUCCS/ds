//建立二叉树
#include <stdio.h>
#include <stdlib.h>

typedef enum 
{
	false,
	true,
}bool;
typedef enum 
{
	OK,
	OVERFLOW,
	ERROR,
} Status;

typedef struct BiTNode 
{
	char data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

typedef struct 
{
	BiTree base;
	BiTree top;
	int stacksize;
}SqStack;


int i = 0;

Status CreateBiTree(BiTree *T, char *c) 
{
	char ch;
	ch = c[i];
	i++;
	if (ch == '*') 
	{
		*T = NULL;
	}
	else 
	{
		if (!(*T = (BiTNode *)malloc(sizeof(BiTNode)))) 
		{
			exit(OVERFLOW);
		}
		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild, c);
		CreateBiTree(&(*T)->rchild, c);
	}
	return OK;
}

Status PostOrderTraverse(BiTree T)
{
	if (T) 
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%c", T->data);
	}
	return OK;
}

void print(char t[])
{
	int i = 0;
	do
	{
		
		printf("%c", t[i++]);
	} while (t[i]!='\0');
}

int main() 
{
    
	
	char t2[30];
	BiTree T = NULL;
	printf("请输入测试字符串：");
	gets(t2);
	printf("开始建立第一个二叉树：\n");
	print(t2);
	printf("\n");
	CreateBiTree(&T, t2);
	printf("创建完毕第一个二叉树\n");
	printf("后序遍历第一个二叉树:\n");
	PostOrderTraverse(T);
	printf("\n遍历结束\n\n");
	fflush(stdin);
	return 0;
}