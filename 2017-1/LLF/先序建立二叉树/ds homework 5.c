//�������ҵ ʵ�����ַ����������������������������
#include<stdio.h>  
#include<stdlib.h>

//���������
typedef struct BiTNode
{
	char data;
	struct BiTNode *lchild, *rchild; //���Һ���ָ��
}BiTNode,*BiTree;

typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;

//��ȡ�ַ�
int i = 0;
char getChar(char *s)
{

	char c;
	c = s[i];
	i++;
	return c;
}

//������������
Status CreatBiTree(BiTree *root,char *a)
{
	char s;
	s = getChar(a);
	if (s == ' ')
	{
		*root = NULL;
	}
	else
	{
		*root = (BiTNode*)malloc(sizeof(BiTNode));
		if (!root)
		{
			return OVERFLOW;
		}
		(*root)->data = s;
		CreatBiTree(&(*root)->lchild,a);
		CreatBiTree(&(*root)->rchild,a);
	}
	return OK;
}

//�������������
Status PostOrderTraverse(BiTree root)
{
	if (root)
	{
		PostOrderTraverse(root->lchild);
		PostOrderTraverse(root->rchild);
		printf("%c", root->data);
	}
	return OK;
}

//���ٶ�����
Status destoryBiTree(BiTree root)
{
	if (!root)
	{
		return ERROR;
	}
	else
   {
		destoryBiTree(root->lchild);
		destoryBiTree(root->rchild);
		free(root);
	}
	
}

int main()
{
	BiTree p1 = NULL;
	char *ch1= "ABDG   EH  I K  C F  ";
	printf("ch1 preorder: ");
	puts(ch1);
	printf("ch1 postorder: ");
	CreatBiTree(&p1,ch1);
	PostOrderTraverse(p1);
	destoryBiTree(p1);
	printf("\n");
	i = 0;
	BiTree p2 = NULL;
	char *ch2 = "BCE G   DF    ";
	printf("ch2 preorder: ");
	puts(ch2);
	printf("ch2 postorder: ");
	CreatBiTree(&p2, ch2);
	PostOrderTraverse(p2);
	destoryBiTree(p2);

	return 0;

}


