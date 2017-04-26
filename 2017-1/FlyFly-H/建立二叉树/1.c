#include<stdio.h>
#include<stdlib.h>

typedef enum status
{
	OK,
	ERROR,
	OVERFLOW
}Status;

typedef char TElemType;

typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

 int i = 0;
Status CreateBiTree(BiTree *T,TElemType * p)
{
	
	 TElemType ch;
	 ch = p[i];
	 i++;

	 if(ch == '*')
	 {
		 *T = NULL;
	 }
	 else
	 {
		 if(!(*T = (BiTree)malloc(sizeof(BiTNode))))
		 {
			 return OVERFLOW;
		 }
		 (*T)->data = ch;
		 CreateBiTree(&(*T)->lchild,p);
		 CreateBiTree(&(*T)->rchild,p);
	 }
	 return OK;
}

void PostOrderTraverseTree(BiTree T)
{
	if(T)
	{
		PostOrderTraverseTree(T->lchild);
		PostOrderTraverseTree(T->rchild);
		printf("%c",T->data);
	}
}


int main()
{
	BiTree T = NULL;
	BiTree B = NULL;

	TElemType str1[30] = "ABDG***EH**I*K**C*F**"; 
	TElemType str2[30] = "ABD*F***CE***"; 

	printf("������ķ�ʽ����������:ABDG***EH**I*K**C*F**\n");
	CreateBiTree(&T,str1);
	printf("�����������ɹ�\n");
	printf("�Ժ���ķ�ʽ���������:\n");
	PostOrderTraverseTree(T);

    printf("\n\n");

	i=0;
	printf("������ķ�ʽ����������:ABD*F***CE***\n");
	CreateBiTree(&T,str2);
	printf("�����������ɹ�\n");
	printf("�Ժ���ķ�ʽ���������:\n");
	PostOrderTraverseTree(T);
	printf("\n");
	return 0;
}
