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
 Status CreateBiTree(BiTree *T,TElemType * p) //����������
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

void PostOrderTraverseTree(BiTree T) //���������
{
	if(T)
	{
		PostOrderTraverseTree(T->lchild);
		PostOrderTraverseTree(T->rchild);
		printf("%c",T->data);
	}
}

int Depth(BiTree T)// ���ض����������
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

int count[50];//��Ÿ���������
int max = 0; //����ȣ�
int j=0;//

int Width(BiTree T)//�õݹ��������
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

int CountLeaf(BiTree T) // ����ָ��T��ָ������������Ҷ�ӽ�����
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

int Count (BiTree T) //����ָ��T��ָ�����������н�����
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

	TElemType str1[30] = "ABDG***EH**I*K**C*F**"; 
	TElemType str2[30] = "ABD*F***CE***"; 

	printf("��������1:ABDG***EH**I*K**C*F**\n");
	CreateBiTree(&T,str1);
	printf("�˶������߶�Ϊ%d,�����Ϊ%d\n",Depth(T), Width(T));
	printf("�˶�����Ҷ�ӽ�����Ϊ%d,��Ҷ�ӽ�����Ϊ%d",CountLeaf(T),Count(T)-CountLeaf(T));

    printf("\n\n");

	i=0;
	j=0;
	max = 0;
	printf("��������2:ABD*F***CE***\n");
	CreateBiTree(&T,str2);
	printf("�˶������߶�Ϊ%d,�����Ϊ%d\n",Depth(T), Width(T));
	printf("�˶�����Ҷ�ӽ�����Ϊ%d,��Ҷ�ӽ�����Ϊ%d",CountLeaf(T),Count(T)-CountLeaf(T));
	printf("\n");
	return 0;
}
