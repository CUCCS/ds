
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

typedef int ElemType;

typedef char TElemType;

typedef struct BiTNode

{
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;
int i= 0;
int  count[50];  
 int max=0; 
 int j=0;   
Status CreateBiTree(BiTree *T, char*s)
{
	char ch = s[j];
	j++;
	if (ch == '#')
	{
		*T = NULL;
	}
	else
	{
		if (!(*T = (BiTNode*)malloc(sizeof(BiTNode))))
		{
			return OVERFLOW;
		}
		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild, s);
		CreateBiTree(&(*T)->rchild, s);
	}
	return OK;
}
ElemType Depth(BiTree T)     //计算二叉树的深度 
{ 
	if(T == NULL) 
	{ 
		return OVERFLOW; 
	} 
	return Depth(T->lchild) > Depth(T->rchild) 
		? (Depth(T->lchild) + 1) : (Depth(T->rchild) + 1); 
} 
int Count(BiTree T)
{
	ElemType m, n; 
	if (T == NULL) 
		return 0; 
    if (T->lchild == NULL && T->rchild == NULL)   //左右孩子都为空，说明该节点为叶子结点 
	{ 
        return 1; 
   }  
	else  
	{ 
      m = Count(T->lchild);   
      n = Count(T->rchild);  
       return m + n + 1;  
}
}
int Width(BiTree T)
{
   if(T == NULL)   
		return 0;   
	i++; 
    count[i]++;   
    if(max < count[i])  
		max = count[i];   
    Width(T->lchild);   
    Width(T->rchild);  
	i--;    //返回根结点 
	return max; 
 
} 
int main(){
    int w1,w2;
	BiTree T = NULL;
	char*s1 = "ABDG###EH##I#K##C#F##";
	char*s2 = "ABD#F###CE###";
	printf("测试用例1:");
	puts(s1);
	CreateBiTree(&T,s1); 
	printf("高度为： %d",Depth(T)-1); 
	w1 = Width(T); 
	printf("\n最大宽度为： %d", w1); 
    j=0;
    CreateBiTree(&T,s2); 
    printf("测试用例2:");
	puts(s2);
	printf("高度为： %d",Depth(T)-1); 
	w2 = Width(T); 
	printf("\n最大宽度为： %d", w2); 
}

 
