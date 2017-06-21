#include<stdio.h>
#include<stdlib.h>
#define ElemType int

typedef struct NODE
{
	ElemType elem; /*����Ԫ���ֶ�*/
	struct NODE *lc, *rc; /*����ָ���ֶ�*/
}NodeType; /*�������������*/

int SearchBST(NodeType *t, NodeType **p, NodeType **q, ElemType kx)
 /*�ڶ���������t �ϲ�������Ԫ�ص��� kx ��Ԫ�أ����ҵ�������1����q ָ��ý�㣬p ָ���丸��㣻*/
	/*���򣬷���0����p ָ�����ʧ�ܵ����һ�����*/
{
	int flag = 0; 
	*q = t;
	while (*q!=NULL) /*�Ӹ���㿪ʼ����*/ 
	{
		if (kx>(*q)->elem) /*kx ���ڵ�ǰ���*q */
		{
			*p = *q; 
			*q = (*q)->rc;
		} /*����ǰ���*q ���Һ�����Ϊ�¸�*/
		else
		{
			if (kx<(*q)->elem) /*kx С�ڵ�ǰ���*q */
			{
				*p = *q; 
				*q = (*q)->lc;
			} /*����ǰ���*q ������Ů��Ϊ�¸�*/
			else 
			{ 
				flag = 1;
				break; 
			} /*���ҳɹ�������*/
		}
	}/*while*/
	return flag;
}

int InsertBST(NodeType **t, ElemType kx)/*�ڶ���������*t �ϲ�������Ϊkx �Ľ��*/
{ 
	NodeType *p=*t, *q, *s;
	int flag = 0;
	if (!SearchBST(*t, &p, &q, kx)); /*��*t Ϊ���������ϲ���*/
	{ 
		s = (NodeType*)malloc(sizeof(NodeType)); /*�����㣬����ֵ*/
		s->elem = kx;
		s->lc = NULL;
		s->rc = NULL;
		flag = 1; /*���ò���ɹ���־*/
	if (!p) 
		*t = s; /*������в���ʱ*/
	else
	{
		if (kx>p->elem)
			p->rc = s; /*������Ϊp ������Ů*/
		else 
			p->lc = s; /*������Ϊp ������Ů*/
	}
	}
	return flag;
}

int DeleteBST(NodeType **t, ElemType kx)
{
	NodeType *p = *t, *q, *s, **f;
	int flag = 0;
	if (SearchBST(*t, &p, &q, kx))
	{ 
		flag = 1; /*���ҳɹ�����ɾ���ɹ���־*/
		if (p == q) 
		f = &(*t); /*��ɾ���Ϊ�����ʱ*/
	else /*��ɾ���Ǹ����ʱ*/
	{
		f = &(p->lc); if (kx>p->elem) f = &(p->rc);
	} /*f ָ���ɾ���ĸ�������Ӧָ����*/
	if (!q->rc) 
		*f = q->lc; /*����ɾ����������������������滻��ɾ���*/
	else
	{
		if (!q->lc) 
			*f = q->rc; /*����ɾ����������������������滻��ɾ���*/
		else /*��������������������*/
		{
			p = q->rc;s = p;
			while (p->lc) 
			{
				s = p;
				p = p->lc; 
			}/*����������������ɾ����ǰ��p*/
			*f = p;
			p->lc = q->lc; /*�滻��ɾ���q���ؽ�������*/
			if (s != p)
			{
				s->lc = p->rc; /*��ɾ��������Ů��������ʱ����Ҫ�ؽ�������*/
				p->rc = q->rc;
			}
		}
	}
	free(q);
	}
	return flag;
}
void PreOrder(NodeType *t)//����������
{
	if (t != NULL)
	{
		printf("%d ", t->elem);
		PreOrder(t->lc);
		PreOrder(t->rc);
		
	}
}

int main()
{
	int a[12] = { 8, 10, 14, 3, 1, 6, 4, 7, 5, 19, 22, 30 };
	int b[5] = { 13, 8, 5, 20, 6 };
	NodeType *t=NULL;
	int i;
	for (i = 0;i < 12;i++)//��������������
	{
		InsertBST(&t, a[i]);
	}
	PreOrder(t);//�������
	printf("\n");
	for (i = 0;i < 5;i++)//����ɾ��
	{
		if (!DeleteBST(&t, b[i]))
			InsertBST(&t, b[i]);
		PreOrder(t);
		printf("\n");
	}
}