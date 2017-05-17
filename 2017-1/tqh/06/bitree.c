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
char*s[2]={"ABDG###EH##I#K##C#F##","ABD#F##CE###"};
int index2[2]={0};

Status CreateBitree (BiTree *T,int index)
{
	//char ch;
	//scanf("%c",&ch);
	if(s[index][index2[index]] == '#')
	{
		*T =NULL;
		++index2[index];
	}
	else
	{
		if((*T = (BiTNode*)malloc(sizeof(BiTNode)))==NULL)
		{
			exit(OVERFLOW);
		}
		(*T)->data = s[index][index2[index]];
		++index2[index];
		CreateBitree(&(*T)->lchild,index);
		CreateBitree(&(*T) ->rchild,index);
	}
	return OK;
}
Status PostOrderTraverse(BiTree T,int*leaf_count,int*nonleaf_count)
{
	if(T!=NULL)
	{
		if(T->lchild==NULL&&T->rchild==NULL)
		{
			++*leaf_count;
		}
		else
		{
			++*nonleaf_count;
		}
		PostOrderTraverse(T->lchild,leaf_count,nonleaf_count);
		PostOrderTraverse(T->rchild,leaf_count,nonleaf_count);
		printf("%c",T->data);
	}
	return OK;
}
void FindDepthest(BiTree T,int layer,int*depth)
{
	if(layer>*depth)
	{
		*depth=layer;
	}
	if(T->lchild!=NULL)
	{
		FindDepthest(T->lchild,layer+1,depth);
	}
	if(T->rchild!=NULL)
	{
		FindDepthest(T->rchild,layer+1,depth);
	}
}
void FindBitreeWidth(BiTree T,int layer,int*width[])
{
	if(T->lchild!=NULL)
	{
		++(*width)[layer-1];
		FindBitreeWidth(T->lchild,layer+1,width);
	}
	if(T->rchild!=NULL)
	{
		++(*width)[layer-1];
		FindBitreeWidth(T->rchild,layer+1,width);
	}
}
int main()
{
	int i;
	for(i=0;i!=2;++i)
	{
		BiTree tree=NULL;
		int tDepth = 1; 
		CreateBitree(&tree,i);

		int temp1=0,temp2=0;
		PostOrderTraverse(tree,&temp1,&temp2);
		printf("\n");
		printf("叶子节点的个数：%d\n非叶子节点个数:%d\n",temp1,temp2);

		temp1=0;
		FindDepthest(tree,1,&temp1);
		printf("输出树的高度：%d",temp1);
		printf("\n");

		int*temp3=(int*)calloc(temp1,sizeof(int));
		FindBitreeWidth(tree,1,&temp3);
		int j,max=0;
		for(j=0;j!=temp1;++j)
		{
			if(temp3[j]>max)
			{
				max=temp3[j];
			}
		}
		printf("输出最大宽度：%d\n",max);
	}
	return 0;
}