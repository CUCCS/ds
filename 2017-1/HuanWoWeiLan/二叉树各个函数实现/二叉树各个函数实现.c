#include<stdio.h>
#include<stdlib.h>
#include<math.h>//用于判断是否为完全二叉树中的幂次计算

#define OVERFLOW 0
#define OK 1



typedef int Status;
typedef char ElemType;
typedef struct BiTree
{
	ElemType data;
	struct BiTree *Lchild;
	struct BiTree *Rchild;
}BiTree,*Binary_Tree;
//创建一个二叉树
int count =0;//计算总结点数
Status CreateBiTree(Binary_Tree *T)
{
	char ch;
	*T=(Binary_Tree)malloc(sizeof(BiTree));
	if(!(*T))
		exit(OVERFLOW);
	scanf("%c",&ch);
	if(ch=='0')
		*T=NULL;
	else
	{
		(*T)->data=ch;
		count++;
		CreateBiTree(&((*T)->Lchild));
		CreateBiTree(&((*T)->Rchild));
	}
	return OK;
}


int TreeDepth(Binary_Tree T) {  
	if (T == NULL)  
		return 0;  
	int nLeft = TreeDepth(T->Lchild);  
	int nRight = TreeDepth(T->Rchild);  
	return (nLeft>nRight) ? (nLeft+1):(nRight+1);  
} 

int x[100];   //存放各层结点数
int max = 0;    //最大宽度

int TreeWidth(Binary_Tree T)  //递归求最大宽度
{

	if(T == NULL)
	{
		return 0;
	}
	count++;
	x[count]++;
	if(max < x[count])
	{
		max = x[count];
	}
	TreeWidth(T->Lchild);
	TreeWidth(T->Rchild);
	count--;
	return max;
}
int LeafCount(Binary_Tree T){
	if(T == NULL){
		return 0;
	}
	else if ((T->Lchild==NULL) && (T->Rchild==NULL)){
		return 1;
	}
	else{
		return  LeafCount(T->Lchild)+ LeafCount(T->Rchild);
	}
}




int main()
{
	BiTree *T=NULL;


	printf("请创建第一个二叉树,0代表空 :\n");
	CreateBiTree(&T);
	int depth= TreeDepth(T);
	int width=TreeWidth(T);
	int count1=LeafCount(T);
	int notleaf1=count-count1;
	int n=1;
	for(int i=0;i<depth-1;i++)
	{
		n=n*2;
	}
	if(n==count)
		printf("该二叉树为完全二叉树\n");
	else
		printf("该二叉树不是完全二叉树\n");


	printf("第一个二叉树的深度为%d\n",depth);
	printf("第一个二叉树的宽度为%d\n",width);
	printf("第一个二叉树的叶子节点数为%d\n",count1);
	printf("第一个二叉树的非叶子节点数为%d\n\n\n\n",notleaf1);





	return 0;
}