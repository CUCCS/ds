#include<stdio.h>
#include<stdlib.h>
#include<math.h>//�����ж��Ƿ�Ϊ��ȫ�������е��ݴμ���

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
//����һ��������
int count =0;//�����ܽ����
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

int x[100];   //��Ÿ�������
int max = 0;    //�����

int TreeWidth(Binary_Tree T)  //�ݹ��������
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


	printf("�봴����һ��������,0����� :\n");
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
		printf("�ö�����Ϊ��ȫ������\n");
	else
		printf("�ö�����������ȫ������\n");


	printf("��һ�������������Ϊ%d\n",depth);
	printf("��һ���������Ŀ��Ϊ%d\n",width);
	printf("��һ����������Ҷ�ӽڵ���Ϊ%d\n",count1);
	printf("��һ���������ķ�Ҷ�ӽڵ���Ϊ%d\n\n\n\n",notleaf1);





	return 0;
}