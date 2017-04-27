#include <stdio.h>
#include <stdlib.h>

extern int i;
typedef char TElemType;

typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;


//将字符从字符串中取出;
char AbstractWord(char*s);

//建立二叉树;
Status CreateBiTree(BiTree *T, char *s);

//以后序式输出;
Status PostOrderTraverse(BiTree T);

//摧毁二叉树;
Status destoryBiTree(BiTree T);



