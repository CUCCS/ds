#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int key;
	struct node *lchild, *rchild;
}BSTNode, *BSTree;

//����
int InsertBST(BSTree *bst, int k)
{
	BSTree r, s, pre;
	r = (BSTree)malloc(sizeof(BSTNode));
	r->key = k;
	r->lchild = NULL;
	r->rchild = NULL;
	if(*bst == NULL)
	{
		*bst = r;
		return 1;
	}
	pre = NULL;
	s = *bst;
	while(s)
	{
		if(k == s->key)
			return 0;
		else if(k < s->key)
		{
			pre = s;
			s = s->lchild;
		}
		else
		{
			pre = s;
			s = s->rchild;
		}
	}
	if(k < pre->key)
		pre->lchild = r;
	else
		pre->rchild = r;
	return 1;
}   
BSTree DeleteBST(BSTree T, int k)
{
	BSTree p, q, s, f;
	p = T;
	f = NULL;
	while (p)
	{
		if(p->key == k)
			break;
		f = p;
		if(p->key > k)
			p =p->lchild;
		else  if(p->key< k)
			p =p->rchild;

	}

	q = p;

	if ((p->lchild)&& (p->rchild))
	{
		s =p->lchild;
		while(s->rchild)
		{
			q =s;
			s =s->rchild;
		}
		p->key =s->key;
		if (p != q)

			q->rchild= s->lchild;

		else  if (p == q)
			q->lchild= s->lchild;
		free(s);
		return T;
	}
	else if (!p->lchild)

		p =p->rchild;

	else if (!p->rchild)
		p =p->lchild;
	if (!f)

		T = p;

	else if (q == f->lchild)
		f->lchild= p;
	else
		f->rchild= p;

	free(q);
	return T;

}

void CreateBST(BSTree *bst)
{
	int key;
	*bst = NULL;
	scanf("%d", &key);
	while(key != -1)
	{
		InsertBST(bst, key);
		scanf("%d", &key);
	}
}
/*��ӡ���������������*/
void InOrder(BSTree root)
{
	if(root != NULL)
	{
		InOrder(root->lchild);
		printf( "%d ", root->key);
		InOrder(root->rchild);
	}
}

/*����*/
BSTree SearchBST(BSTree bst, int key)
{
	BSTree q;
	q = bst;
	//�ݹ�
	while(q)
	{
		if(q->key == key)
			return q;
		if(q->key > key)
			q=q->lchild;
		else
			q=q->rchild;
	}
	return NULL;                        //����ʧ��
}

int main()
{
	BSTree T;
	int tag = 1;
	int m, n;
	printf("����������������������������-1������");
	CreateBST(&T);
	printf("�������������������Ϊ��");
	InOrder(T);
	while(tag != 0)
	{
		printf("��������Ҫ���ҵ�Ԫ��:");
		scanf("%d", &n);
		if(SearchBST(T, n) == NULL)
		{
			printf("��Ǹ����ʧ��!");
			InsertBST(&T, n);
		}
		else
		{
			printf("���ҳɹ������ҵ�����Ϊ%d\n", SearchBST(T,n)->key);
			DeleteBST(SearchBST(T,n),n);
		}
		InOrder(T);
		printf("\n�Ƿ�������� �� ���밴 1 ���� 0:");
		scanf("%d", &tag);
	}
	return 0;
}