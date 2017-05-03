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
char*s[2]={"ABDG###EH##I#K##C#F##","ABD#F###C#E#G##"};
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

//#include<stdio.h>
//#include<stdlib.h>
//#define MAXLEVEL 10
//int i = 0,j = 0 ;
//int dep = 0;
//int max = 1;
//typedef char TElemType;
//typedef struct BiTNode {
//	TElemType data;
//	BiTNode *lchild,*rchild;
//	int IsLeaf;
//}BiTNode,*BiTree;
//typedef enum {
//	ERROR,
//	OK,
//	OVERFLOW
//}Status;
//
//Status CreateBitree (BiTree *T,int index);
//Status PostOrderTraverse(BiTree T);
//
////int FindBitreeDepth(BiTree T,int depth);
//char*s[2]={"ABDG###EH##I#K##C#F##","ABD#F###C#E#G##"};
//int index2[2]={0};
//Status CreateBitree (BiTree *T,int index)
//{
//	//char ch;
//	//scanf("%c",&ch);
//	if(s[index][index2[index]] == '#')
//	{
//		*T =NULL;
//		++index2[index];
//	}
//	else
//	{
//		if(! (*T = (BiTNode *)malloc(sizeof(BiTNode)) ))
//			exit(OVERFLOW);
//		(*T)->data = s[index][index2[index]];
//		++index2[index];
//		CreateBitree(&(*T)->lchild,index);
//		CreateBitree(&(*T) ->rchild,index);
//	}
//	return OK;
//}
//BiTree FindBitreeDepth(BiTree *T,int depth)
//{
//	 if(*T == NULL)  
//        return *T;
//	 else if((*T)->IsLeaf == i) //如果子树的根节点的值等于要寻找的值，  
//    {  
//		dep = depth;
//    } 
//    //继续在根节点的左子树和右子树中寻找目标值  
//	 FindBitreeDepth(&(*T)->lchild, depth+1);  
//	 FindBitreeDepth(&(*T)->rchild, depth+1);
//}
//int FindDepthest(BiTree T,int depth)
//{
//	for(;i>0;i--)
//	{
//		FindBitreeDepth(&T,depth);
//		if(max < dep)
//			max = dep;
//	}
//	return max;
//}
//
//int FindBitreeWidth(BiTree T)
//{
//	static int level[MAXLEVEL];
//	static int n = 0;
//	static int wmax = 0;
//	if(T){
//		if(n == 0){
//			level[n]++;
//			n++;
//			if(T->lchild)
//				level[n]++;
//			if(T->rchild)
//				level[n]++;
//		}
//		else{
//			n++;
//			if(T->lchild)
//				level[n]++;
//			if(T->rchild)
//				level[n]++;
//		}
//		if(wmax < level[n])
//			wmax = level[n];
//		FindBitreeWidth
//			
//			(T->lchild);
//		if(T->lchild && T->rchild)
//			n++;
//		n--;
//		FindBitreeWidth(T->rchild);
//	}
//	return wmax;
//}
//Status PostOrderTraverse(BiTree T)
//{
//	if(T){
//		++j;
//		if(!(T->lchild)&& !(T->rchild) )
//			T->IsLeaf = (++i);
//		else
//			T->IsLeaf = 0;
//		PostOrderTraverse(T->lchild);
//		PostOrderTraverse(T->rchild);
//		printf("%c",T->data);
//		/*printf("%d",T->IsLeaf);*/
//	}
//	return OK;
//}
//
//int main()
//{
//	int k;
//	for(k=0;k!=2;++k)
//	{
//		BiTree tree=NULL;
//		int tDepth = 1; 
//		CreateBitree(&tree,k);
//
//		PostOrderTraverse(tree);
//		printf("\n");
//		printf("叶子节点的个数：%d\n非叶子节点个数:%d\n",i,j-i);
//
//		FindDepthest(tree,tDepth);
//		printf("输出树的高度：%d",FindDepthest(tree,tDepth));
//		printf("\n");
//
//		printf("输出最大宽度：%d\n",FindBitreeWidth(tree));
//	}
//
//	
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#define MAXLEVEL 10
//int i = 0,flag = 0,j = 0 ;
//int dep = 0;
//int max = 1;
//typedef char TElemType;
//typedef struct BiTNode {
//	TElemType data;
//	BiTNode *lchild,*rchild;
//	int IsLeaf;
//}BiTNode,*BiTree;
//typedef enum {
//	ERROR,
//	OK,
//	OVERFLOW
//}Status;
//
//Status CreateBitree (BiTree *T);
//Status PostOrderTraverse(BiTree T);
//
////int FindBitreeDepth(BiTree T,int depth);
//
//Status CreateBitree (BiTree *T)
//{
//	char ch;
//	scanf("%c",&ch);
//	if(ch == '#')
//		*T =NULL;
//	else{
//		if(! (*T = (BiTNode *)malloc(sizeof(BiTNode)) ))
//			exit(OVERFLOW);
//		(*T)->data = ch;
//		CreateBitree(&(*T)->lchild);
//		CreateBitree(&(*T) ->rchild);
//	}
//	return OK;
//}
//BiTree FindBitreeDepth(BiTree *T,int depth)
//{
//	 if(*T == NULL)  
//        return *T;
//	 else if((*T)->IsLeaf == i) //如果子树的根节点的值等于要寻找的值，  
//    {  
//		dep = depth;
//    } 
//    //继续在根节点的左子树和右子树中寻找目标值  
//	 FindBitreeDepth(&(*T)->lchild, depth+1);  
//	 FindBitreeDepth(&(*T)->rchild, depth+1);
//}
//int FindDepthest(BiTree T,int depth)
//{
//	for(;i>0;i--)
//	{
//		FindBitreeDepth(&T,depth);
//		if(max < dep)
//			max = dep;
//	}
//	return max;
//}
//
//int FindBitreeWidth(BiTree T)
//{
//	static int level[MAXLEVEL];
//	static int n = 0;
//	static int wmax = 0;
//	if(T){
//		if(n == 0){
//			level[n]++;
//			n++;
//			if(T->lchild)
//				level[n]++;
//			if(T->rchild)
//				level[n]++;
//		}
//		else{
//			n++;
//			if(T->lchild)
//				level[n]++;
//			if(T->rchild)
//				level[n]++;
//		}
//		if(wmax < level[n])
//			wmax = level[n];
//		FindBitreeWidth
//			
//			(T->lchild);
//		if(T->lchild && T->rchild)
//			n++;
//		n--;
//		FindBitreeWidth(T->rchild);
//	}
//	return wmax;
//}
//Status PostOrderTraverse(BiTree T)
//{
//	if(T){
//		++j;
//		if(!(T->lchild)&& !(T->rchild) )
//			T->IsLeaf = (++i);
//		else
//			T->IsLeaf = 0;
//		PostOrderTraverse(T->lchild);
//		PostOrderTraverse(T->rchild);
//		printf("%c",T->data);
//		/*printf("%d",T->IsLeaf);*/
//	}
//	return OK;
//}
//
//int main()
//{
//	BiTree tree=NULL;
//	int tDepth = 1; 
//	CreateBitree(&tree);
//
//	PostOrderTraverse(tree);
//	printf("\n");
//	printf("叶子节点的个数：%d\n非叶子节点个数:%d\n",i,j-i);
//
//	FindDepthest(tree,tDepth);
//	printf("输出树的高度：%d",FindDepthest(tree,tDepth));
//	printf("\n");
//
//	printf("输出最大宽度：%d\n",FindBitreeWidth(tree));
//	
//	return 0;
//}
