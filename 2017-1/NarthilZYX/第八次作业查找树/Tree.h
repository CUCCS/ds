#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef int ElemType;
typedef enum{
	ERROR,
    OK
}Status;
typedef enum{
	False,
	True
}Bool;
typedef struct BiTNode {
	ElemType data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BSTTree, *AVLTree, *B3Tree;

//------BSTTree------//
// �ڸ�����BST�в����㣬��������Ϊelement, ʹ֮��Ϊ�µ�BST  
Bool BSTInsert(BiTNode * &p, int element)  
{  
    if(NULL == p) // ����  
    {  
        p =  (BSTTree)malloc(sizeof(BiTNode));  
        p->data = element;  
        p->lchild = p->rchild = NULL;  
        return True;  
    }  
  
    if(element == p->data) // BST�в�������ȵ�ֵ 
	{
        return False;  
	}
    if(element < p->data)  // �ݹ�  
	{
        return BSTInsert(p->lchild, element);  
	}
    return BSTInsert(p->rchild, element); // �ݹ�  
}  
  
// ����BST  
Status createBST(BiTNode * &T, int a[], int n)  
{  
    T = NULL;   
    int i;  
    for(i = 0; i < n; i++)  
    {  
        BSTInsert(T, a[i]);  
    }  
	return OK;
}

void preOrderTraverse(BSTTree T)  
	//�����������������
{  
    if(T)  
    {  
		printf("%d ",T->data);  
        preOrderTraverse(T->lchild);  
        preOrderTraverse(T->rchild);  
    }  
}
Status Delete(BSTTree &p)//�Ӷ�����������ɾ�����p�����ؽ��������������
{
	BiTNode *q, *s;
    if(!p->rchild)//����������ֻ���ؽ�����������
    {
        q=p;
        p=p->lchild;
        free(q);
     }
    else if(!p->lchild)//��������ֻ���ؽ�����������
    {
        q=p;
        p=p->rchild;
        free(q);
    }
    else//��������������
    {
            q=p;
            s=p->lchild;
        while(s->rchild)//ת��Ȼ�����ҵ���ͷ
        {
           q=s;
            s=s->rchild;
        }
            p->data=s->data;//sָ��ɾ���ġ�ǰ����
        if(q!=p)//����ѭ������ִ����һ��
           q->rchild=s->lchild;
        else
            q->lchild=s->lchild;//�ؽ�*q��������
        delete(s);
     }
    return OK;
}
Status searchBST(BSTTree T,ElemType key)
	//������������T�д��ڹؼ��ֵ���key������Ԫ��ʱ����ɾ��������Ԫ�أ�������TRUE�����򷵻�FALSE
{
    if(!T)
	{
        return ERROR;
	}
    else
    {
        if(key==T->data)//�ҵ��ؼ��ֵ���key������Ԫ��      
		{
            return OK;
		}
        else if(key<T->data){
            return searchBST(T->lchild,key);
		}
        else{
            return searchBST(T->rchild,key);
		}
    }
    return OK;
}
      
Status Delete(BSTTree *p)  
{  
        /* �Ӷ�����������ɾ���ڵ�p�� ���ؽ�������������� */  
        BSTTree q, s;  
        if(  !(*p)->lchild && !(*p)->rchild ) /* pΪҶ�ӽڵ� */  
		{
            *p = NULL;  
		}
        else if( !(*p)->lchild ) /* ������Ϊ�գ��ؽ������� */  
        {  
            q = *p;   
            *p = (*p)->rchild;  
            free(q);  
        }  
        else if( !(*p)->rchild ) /* ������Ϊ�գ��ؽ������� */  
        {  
            q = *p;  
            *p = (*p)->lchild;         
            free(q);  
        }  
        else                        /* ������������Ϊ�� */  
        {  
            q = *p;  
            s = (*p)->lchild;  
            while(s->rchild)     /* ת��Ȼ�������ߵ���ͷ*/  
            {  
                q = s;  
                s = s->rchild;  
            }  
            (*p)->data = s->data;  
            if( q != *p )               /* �ж��Ƿ�ִ������whileѭ�� */  
			{
                q->rchild = s->lchild;    /* ִ������whileѭ�����ؽ������� */   
			}
            else  {
                q->lchild = s->lchild;    /* δִ������whileѭ�����ؽ������� */  
			}
            free(s);  
        }  
        return OK;  
}  

Status DeleteBST(BSTTree *T, int key)  
{  
        /* ������������T�д��ڹؼ��ֵ���key������Ԫ��ʱ����ɾ��������Ԫ�ؽڵ� */  
        /* ������TRUE�����򷵻�FALSE */  
	if( !(*T))  {
		return ERROR;   /* �����ڹؼ��ֵ���key������Ԫ�� */  
	}
    else  
    {  
        if( key == (*T)->data ){
            Delete(T);  
		}
        else if( key < (*T)->data){
            return DeleteBST(&(*T)->lchild, key);  
		}
        else {
            return DeleteBST(&(*T)->rchild, key);  
		}
        }  
    }  

//------AVLTree------//

//------B3Tree------//