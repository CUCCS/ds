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
typedef struct BiTNode {
	int      data;
	struct BiTNode  *lchild, *rchild;
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
	BiTree p, s;  
	if( !SearchBST( *T, key, NULL, &p ) )  
	{  
		s = (BiTree)malloc(sizeof(BiTNode));  
		s->data = key;  
		s->lchild = s->rchild = NULL;  
		if( !p )  
			*T = s;
		else if( key > p->data )  
			p->rchild = s;
		else  
			p->lchild = s;
		return TRUE;  
	}  
	return FALSE;  
}
Status Delete(BiTree *p) {
	
	BiTree q,s ;
	if(!&(*p)->rchild && !&(*p)->lchild)
	{
		p = NULL;
	}
	else if (!(*p)->rchild)  {
		q = *p;
		*p = (*p)->lchild;
		free(q);
	} 
	else if (!(*p)->lchild) { 		q = *p;
		*p = (*p)->rchild;
		free(q);
	} 
	else {
		q = *p;
		s = (*p)->lchild;
		while(s->rchild) {
			q = s;
			s = s->rchild; 
		}
		(*p)->data = s->data;
		if(q != *p) { 
			q->rchild = s->lchild;
		} else {
			q->lchild = s->lchild;
		}
		free(s);
	}
	return OK;
} 
int DeleteBST(BiTree *T,  int kval) {
	
	if(!(*T)) {
		return FALSE;
	} 
	else {  
		if(EQ(kval, (*T)->data)) {
			Delete (T);
			return TRUE;
		} 
		else if(LT(kval, (*T)->data)) {
			return DeleteBST(&(*T)->lchild, kval);
		}
		else {
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
