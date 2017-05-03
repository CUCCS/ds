#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef char TElemType ;

typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild, *rchild;   //���Һ��ӵ�ָ��
}BiTNode, *BiTree;

typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;         //ö�ٶ��壨����״̬��


Status CreateBiTree(BiTree *T,TElemType *p);
void PostOrderTraverseTree(BiTree T);
int BiTreeDepth(BiTree T);
int BiTreeWidth(BiTree T);
int BiTreeCount(BiTree T);
int BiTreeCountLeaf(BiTree T);


int count = 0;  //����ȫ�ֱ���  ���ڶԶ��������м���

Status CreateBiTree(BiTree *T,TElemType *p) // ����������
{
	TElemType ch;
	ch = p[count];
	count++;                          //��������洢�ַ���

	if(ch == ' ')
	{
		return OK;

	}
	else if(ch == '#')
	{
		*T = NULL;
	}
	else
	{
		if(!(*T = (BiTNode *)malloc(sizeof(BiTNode))))
		{
			return OVERFLOW;
		}
		(*T)->data = ch;     //���ڵ�
		CreateBiTree(&(*T)->lchild,p);  //��������
		CreateBiTree(&(*T)->rchild,p);   //�����Һ���
	}
	return OK;
}

void PostOrderTraverseTree(BiTree T)
{
	if(T != NULL) 
	{ 
		PostOrderTraverseTree(T->lchild); 
		PostOrderTraverseTree(T->rchild); 
		printf("%c",T->data); 
	}
}

int BiTreeDepth(BiTree T)
{
	int depthleft,depthright;
	if(T == NULL)
	{
		return 0;
	}
	else
	{
		depthleft = BiTreeDepth(T->lchild);
		depthright = BiTreeDepth(T->rchild);
		if(depthleft > depthright)
		{
			return (depthleft + 1);
		}
		else
		{
			return (depthright + 1);
		}
	}
}

int pot[100];   //��Ÿ�������
int max = 0;    //�����

int BiTreeWidth(BiTree T)  //�ݹ��������
{

	if(T == NULL)
	{
		return 0;
	}
		count++;
		pot[count]++;
		if(max < pot[count])
		{
			max = pot[count];
		}
		BiTreeWidth(T->lchild);
		BiTreeWidth(T->rchild);
		count--;
		return max;
}

int BiTreeCount(BiTree T)//����ָ��T��ָ�����������н����� 
{
	if(T == NULL)
	{
		return 0;
	}
	else if((T->lchild == NULL) && (T->rchild == NULL))
	{
		return 1;
	}
	else
	{
		return BiTreeCount(T->lchild) + BiTreeCount(T->rchild) + 1;
	}
}

int BiTreeCountLeaf(BiTree T)// ����ָ��T��ָ������������Ҷ�ӽ����� 
{
	if(T == NULL)
	{
		return 0;
	}
	else if((T->lchild == NULL) && (T->rchild == NULL))
	{
		return 1;
	}
	else
	{
		return BiTreeCountLeaf(T->lchild) + BiTreeCountLeaf(T->rchild);
	}
}


int main()
{
	BiTree T = NULL;

	TElemType str1[40] = "ABDG###EH##I#K##C#F##"; 
    TElemType str2[40] = "ABD#F###CE###"; 

    printf("�����һ�������� :  ABDG###EH##I#K##C#F## \n"); 
	CreateBiTree(&T,str1); 
	printf("�˶������߶�Ϊ%d\n�����Ϊ%d\n",BiTreeDepth(T),BiTreeWidth(T)); 
    printf("�˶��������Ϊ%d\nҶ�ӽ��Ϊ%d",BiTreeCount(T),BiTreeCountLeaf(T)); 
	printf("\n");

	count = 0;     //����ڶ���������
	
    printf("����ڶ��������� :  ABD#F###CE### \n"); 
    CreateBiTree(&T,str2);
	printf("�˶������߶�Ϊ%d\n�����Ϊ%d\n",BiTreeDepth(T),BiTreeWidth(T)); 
    printf("�˶��������Ϊ%d\nҶ�ӽ��Ϊ%d",BiTreeCount(T),BiTreeCountLeaf(T)); 
	printf("\n");

	return 0;
}