#include <stdio.h>
#include <malloc.h>

#define TElemType char
#define ElemType BiTNode *   // 树的结点

typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode;

BiTNode *CreatBiTree(char z[])
{
	static int i=-1;
	BiTNode *root;
	i++;
	if(z[i]=='*') return NULL;
	root=(BiTNode *)malloc(sizeof(BiTNode));
	root->data=z[i];
	root->lchild=CreatBiTree(z); //构造左子树
	root->rchild=CreatBiTree(z); //构造右子树
	return(root);
}

void Postorder(struct BiTNode* BT)  //后序遍历
{  
	if (BT != NULL)  
	{  
		Postorder(BT->lchild);  
		Postorder(BT->rchild);  
		printf("%c,", BT->data);
	}  
}  

void main()
{   
	char z[]="ABDG***EH**I*K**C*F**";  //测试用例
	BiTNode *T;
	T=(BiTNode *)malloc(sizeof(BiTNode));
	T=CreatBiTree(z);
	printf("测试用例：ABDG***EH**I*K**C*F** 后序遍历的顺序为：\n");
	Postorder(T);

}