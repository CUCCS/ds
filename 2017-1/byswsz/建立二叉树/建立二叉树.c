#include<stdio.h>
#include<stdlib.h>
typedef char TElemType;
typedef int Status;

int  count = 0;


//二叉树的二插链表的存储表示；
typedef struct BiTnode {
	TElemType data;
	struct BiTNode *lchild, *rchild;//左右孩子指针；

}BiTnode, *BiTree;
//



Status CreateBiTree(BiTree *T, char *c)
{
		TElemType ch;
	ch = c[count];
	count++;
	if (ch == '*')
		{
		*T = NULL;
	}
	else
	{
		if (!(*T = (BiTree)malloc(sizeof(BiTnode))))
		{
			exit(-1);
		}
		(*T)->data = ch;//生成根结点 
		CreateBiTree(&(*T)->lchild, c);//构造左子树 
		CreateBiTree(&(*T)->rchild, c);//构造右子树 
	}
	return 1;
	}
void postorderTraversal(BiTree T)
{
	if (T == NULL)
		{ 
		printf("*");
		return;
		}
		postorderTraversal(T->lchild);
	postorderTraversal(T->rchild);
	printf("%c ", T->data);
	}



int main()
{
	BiTree t;
	TElemType c[20];
	scanf("%s", c);
	CreateBiTree(&t, c);
	printf("后续遍历的顺序为\n");
	postorderTraversal(t);
    return 0;
}
