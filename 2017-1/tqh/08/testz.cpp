#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int num[] = {8,10,14,3,1,6,4,7,5,19,22,30};
int searchnum[] = {13,8,5,20,6};
int flag;
enum
{
	FALSE,
	TRUE
};
typedef struct BiTNode { // ���ṹ
	int      data;
	struct BiTNode  *lchild, *rchild; // ���Һ���ָ��
} BiTNode,*BiTree;
typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;

Status PreOrderTraverse(BiTree T);
int SearchBST( BiTree T, int key, BiTree f, BiTree *p ) ;
int InsertBST( BiTree *T, int key );
Status Delete(BiTree *p);
int DeleteBST(BiTree *T,  int kval);

Status PreOrderTraverse(BiTree T)
{
	if(T){
		printf("%d ",T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
	return OK;
}

int SearchBST( BiTree T, int key, BiTree f, BiTree *p )  
{  
	BiTree s;  
	if( !T )  
	{   
		*p = f;
		return FALSE;
	}  
	else  
	{  
		while( T )  
		{  
			if( key == T->data )  
			{   
				*p = T;     
				return TRUE; 
			}  
			if( key > T->data )  
			{   
				s = T; 
				T = T->rchild;
			}  
			else  
			{  
				s = T;  
				T = T->lchild;  
			}  
		}  
		*p = s;  
		return FALSE;  
	}  
}
int InsertBST( BiTree *T, int key )  
{  
	/* ������������T�в����ڹؼ��ֵ���key������Ԫ��ʱ */  
	/* ����key������TRUE�����򷵻�FALSE */  
	/* ���ò��Һ���SearchBST���ǵݹ� */  
	BiTree p, s;  
	if( !SearchBST( *T, key, NULL, &p ) )  
	{  
		s = (BiTree)malloc(sizeof(BiTNode));  
		s->data = key;  
		s->lchild = s->rchild = NULL;  
		if( !p )  
			*T = s;             /* ����sΪ���ڵ㣬��ǰ��Ϊ���� */  
		else if( key > p->data )  
			p->rchild = s;       /* ����sΪ�Һ��� */  
		else  
			p->lchild = s;       /* ����sΪ���� */  
		return TRUE;  
	}  
	return FALSE;  
}
Status Delete(BiTree *p) {
	// �Ӷ�����������ɾ����� p��
	// ���ؽ�������������������
	BiTree q,s ;
	if(!&(*p)->rchild && !&(*p)->lchild)
	{
		p = NULL;
	}
	else if (!(*p)->rchild)  { // ������Ϊ������ֻ���ؽ�����������
		q = *p;
		*p = (*p)->lchild;
		free(q);
	} 
	else if (!(*p)->lchild) { // ������Ϊ������ֻ���ؽ�����������
		q = *p;
		*p = (*p)->rchild;
		free(q);
	} 
	else {  // ��������������
		q = *p;
		s = (*p)->lchild;
		while(s->rchild) { // s ָ��ɾ����ǰ��
			q = s;
			s = s->rchild; 
		}
		(*p)->data = s->data;
		if(q != *p) { 
			q->rchild = s->lchild; // �ؽ�*q��������
		} else {
			q->lchild = s->lchild; // �ؽ�*q��������
		}
		free(s);
	}
	return OK;
} 
int DeleteBST(BiTree *T,  int kval) {
	// ������������ T �д�����ؼ��ֵ��� kval ��
	// ����Ԫ�أ���ɾ��������Ԫ�ؽ�㣬������
	// ����ֵ TRUE�����򷵻غ���ֵ FALSE
	if(!(*T)) { // �����ڹؼ��ֵ���kval������Ԫ��
		return FALSE;
	} 
	else {  
		if(EQ(kval, (*T)->data)) { // �ҵ��ؼ��ֵ���key������Ԫ��
			Delete (T);
			return TRUE;
		} 
		else if(LT(kval, (*T)->data)) { // �������������н��в���
			return DeleteBST(&(*T)->lchild, kval);
		}
		else { // �������������н��в���
			return DeleteBST(&(*T)->rchild, kval);
		}
	}
}

int main()
{
	int j;
	BiTree T=NULL;
	for(j = 0;j < 12;j++)
	{
		InsertBST(&T, num[j]);
	}
	PreOrderTraverse(T);
	for(j = 0;j <5;j++)
	{
		if(!InsertBST(&T, searchnum[j])){
			DeleteBST(&T,searchnum[j]);
		}
		printf("\n");
		PreOrderTraverse(T);
	}
	return 0;
}
