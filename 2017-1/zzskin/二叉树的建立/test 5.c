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

int main()
{
	BiTree T = NULL;
	Status pop;

	TElemType str1[40] = "ABDG###EH##I#K##C#F##"; 
    TElemType str2[40] = "ABD#F###CE###"; 

    printf("�����һ�������� :  ABDG###EH##I#K##C#F## \n"); 
	pop = CreateBiTree(&T,str1);
	printf("����������Ϊ   :  "); 
	PostOrderTraverseTree(T);

	printf("\n");

	count = 0;     //����ڶ���������
	
    printf("����ڶ��������� :  ABD#F###CE### \n"); 
	pop = CreateBiTree(&T,str1);
	printf("����������Ϊ   :  "); 
	PostOrderTraverseTree(T);
	printf("\n");

	return 0;
}