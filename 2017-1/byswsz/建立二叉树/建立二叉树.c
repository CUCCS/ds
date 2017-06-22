#include<stdio.h>
#include<stdlib.h>
typedef char TElemType;
typedef int Status;

int  count = 0;


//�������Ķ�������Ĵ洢��ʾ��
typedef struct BiTnode {
	TElemType data;
	struct BiTNode *lchild, *rchild;//���Һ���ָ�룻

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
		(*T)->data = ch;//���ɸ���� 
		CreateBiTree(&(*T)->lchild, c);//���������� 
		CreateBiTree(&(*T)->rchild, c);//���������� 
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
	printf("����������˳��Ϊ\n");
	postorderTraversal(t);
    return 0;
}
