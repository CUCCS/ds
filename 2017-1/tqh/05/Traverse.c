#include<stdio.h>
#include<stdlib.h>
typedef char TElemType;
typedef struct BiTNode {
	TElemType data;
	BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
typedef enum {
	ERROR,
	OK,
	OVERFLOW
}Status;

Status CreateBitree (BiTree *T,int i);
Status PostOrderTraverse(BiTree T);
Status InOrderTraverse(BiTree T);
Status PostOrderTraverse(BiTree T);

char*s[]={"ABDG###EH##I#K##C#F##","ABD#F##CE###"};int si[]={0,0};

Status CreateBitree (BiTree *T,int i)
{
	char ch;
	//scanf("%c",&ch);
	ch=s[i][si[i]++];
	if(ch == '#')
		*T =NULL;
	else{
		if(! (*T = (BiTNode *)malloc(sizeof(BiTNode)) ))
			exit(OVERFLOW);
		(*T)->data = ch;
		CreateBitree(&(*T)->lchild,i);
		CreateBitree(&(*T) ->rchild,i);
	}
	return OK;
}
Status PreOrderTraverse(BiTree T)
{
	if(T){
		printf("%c",T->data);
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
	}
	return OK;
}
Status InOrderTraverse(BiTree T)
{
	if(T){
		PostOrderTraverse(T->lchild);
		printf("%c",T->data);
		PostOrderTraverse(T->rchild);
	}
	return OK;
}
Status PostOrderTraverse(BiTree T)
{
	if(T){
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%c",T->data);
	}
	return OK;
}
int main()
{
	BiTree tree[]={NULL,NULL};
	int i;
	for(i=0;i!=2;++i)
	{
		printf("%s\n",s[i]);

		CreateBitree(&tree[i],i);

		printf("%-6s","pre:");
		PreOrderTraverse(tree[i]);
		printf("\n");

		printf("%-6s","in:");
		InOrderTraverse(tree[i]);
		printf("\n");

		printf("%-6s","post:");
		PostOrderTraverse(tree[i]);
		printf("\n");

		printf("\n");
	}

	return 0;
}
