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
 Status CreateBiTree(BiTree *T,TElemType * p) //构建二叉树
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

void PostOrderTraverseTree(BiTree T) //输出二叉树
{
	if(T)
	{
		PostOrderTraverseTree(T->lchild);
		PostOrderTraverseTree(T->rchild);
		printf("%c",T->data);
	}
}

int Depth(BiTree T)// 返回二叉树的深度
{
	int depthval,depthLeft,depthRight;
    if(!T) 
	{
        depthval = 0;
    } 
	else 
	{
        depthLeft = Depth(T->lchild);
        depthRight= Depth(T->rchild);
        depthval = 1 + (depthLeft > depthRight ? depthLeft : depthRight);
    } 
    return depthval;
}

int count[50];//存放各层结点数；
int max = 0; //最大宽度；
int j=0;//

int Width(BiTree T)//用递归求最大宽度
{
	if(T == NULL)
	   return 0;
	i++;
	count[i]++;
	if(max < count[i])
		max =  count[i];
	Width(T -> lchild);
	Width(T -> rchild);
	i--;
	return max;
}

int CountLeaf(BiTree T) // 返回指针T所指二叉树中所有叶子结点个数
{
	int m=0,n=0;
    if(!T) return 0;
    if(!T->lchild && !T->rchild) { 
        return 1;
    } else {
        m = CountLeaf(T->lchild);  
        n = CountLeaf(T->rchild); 
        return m+n;   
    } 
}

int Count (BiTree T) //返回指针T所指二叉树中所有结点个数
{
	int m,n;
    if (!T) return 0;
    if (!T->lchild && !T->rchild) {
        return 1;
    } else {
        m = Count(T->lchild);  
        n = Count(T->rchild); 
        return m + n + 1;   
    }
} 
int main()
{
	BiTree T = NULL;
	BiTree B = NULL;

	TElemType str1[30] = "ABDG***EH**I*K**C*F**"; 
	TElemType str2[30] = "ABD*F***CE***"; 

	printf("测试用例1:ABDG***EH**I*K**C*F**\n");
	CreateBiTree(&T,str1);
	printf("此二叉树高度为%d,最大宽度为%d\n",Depth(T),Width(T));
	printf("此二叉树结点为%d,叶子结点为%d",Count(T),CountLeaf(T));

    printf("\n\n");

	i=0;
	j=0;
	printf("测试用例2:ABD*F***CE***\n");
	CreateBiTree(&T,str2);
	printf("此二叉树高度为%d,最大宽度为%d\n",Depth(T),Width(T));
	printf("此二叉树结点为%d,叶子结点为%d",Count(T),CountLeaf(T));
	printf("\n");
	return 0;
}
