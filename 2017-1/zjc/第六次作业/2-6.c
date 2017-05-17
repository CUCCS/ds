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
ElemType CountLeaf(BiTree T)   //���������Ҷ�ӽ����� 
{ 
	ElemType m, n;      
	if(T == NULL)  
		return 0; 
    if(T->lchild == NULL && T->rchild == NULL)  
	{  
        return 1; 
    }  
	else  
	{ 
        m = CountLeaf(T->lchild);   
        n = CountLeaf(T->rchild);  
        return m+n;    
    }  
} 
ElemType Count(BiTree T)    //���������н����� 
{ 
	ElemType m, n; 
	if (T == NULL) 
		return 0; 
    if (T->lchild == NULL && T->rchild == NULL)  
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

int main(){
	BiTree T = NULL;
	char*s1 = "ABDG###EH##I#K##C#F##";
	char*s2 = "ABD#F###CE###";
	printf("��������1:");
	puts(s1);
	CreateBiTree(&T,s1); 
	printf("Ҷ�ӽڵ���Ϊ�� %d",CountLeaf(T)); 
	printf("\n��Ҷ�ӽڵ���Ϊ�� %d\n",Count(T)-CountLeaf(T) ); 
    j=0;
    CreateBiTree(&T,s2); 
    printf("��������2:");
	puts(s2);
	printf("Ҷ�ӽڵ���Ϊ�� %d",CountLeaf(T));
	printf("\n��Ҷ�ӽڵ���Ϊ�� %d", Count(T)-CountLeaf(T)); 
}

 
