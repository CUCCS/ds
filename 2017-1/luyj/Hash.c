#include "Hash.h"


int getP(int length)  
{
	//�ҵ������ڱ����������
	int p = 0;
	int flag = 0;
	int i,j;
	for (i = length; i > 0; i--)
	{
		flag = 0;
		for (j = 2; j <i; j++)
		{
			if (i%j == 0)
			{
				flag = 1;
				break;
			}
		}
		if (0 == flag)
		{
			p = i;
			break;
		}
	}
	return p;
}

int Hash(int k, int p) 
{
	//�ؼ��ֱ������ڱ���������������Ľ��,����ȡ�ؼ�������λ��

	return k%p;
}

Bool EQ(KeyType k, KeyType key)
{
	if (k == key)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

Status collision(int *q,int p)
{
	(*q)++;
	(*q) = (*q) % p;
	return OK;
}

Status RecreateHashTable(HashTable *h)
{
	int i;
	int count = h->count;
	ElemType *x;
	ElemType *elem = (ElemType*)malloc(count*(sizeof(ElemType)));
	x = elem;
	for (i = 0; i < count; i++)//���Ʊ����ݵ�elem��
	{
		*x = h->elem[i];
		x++;
	}
	h->count = 0;
	h->sizeindex = h->sizeindex * 2;
	x = (ElemType*)realloc(h->elem, h->sizeindex * sizeof(ElemType));
	if (!x)
	{
		return ERROR;
	}
	h->elem = x;
	for (i = 0; i < h->sizeindex; i++)
	{
		h->elem->key = NULL;
	}
	x = elem;
	for (i = 0; i < count; i++)
	{
		InsertHash(h, *x);
	}
	

}
int SearchHash(HashTable h, KeyType k, int *q, int *c, int p) 
{
	// �ڿ��Ŷ�ַ��ϣ��H�в��ҹؼ���ΪK�ļ�¼
	// c���ڼ�¼��ͻ��������ֵ��0

	*q = Hash(k,p); // ��ù�ϣ��ַ
	while (-1 != h.elem[*q].key && !EQ(k, h.elem[*q].key))
	{
		(*c)++;
		collision(q, p);
		if ((*c) > h.sizeindex)
		{
			break;
		}
	}// �����һ̽���ַ p
	if (EQ(k, h.elem[*q].key))
	{ // ���ҳɹ���p���ش�������Ԫ��λ��
		return SUCCESS;
	}
	else if (-1 == h.elem[*q].key)
	{
		return FAILED;   // ���Ҳ��ɹ�
	}
}

int InsertHash(HashTable *h, ElemType e) 
{
	// ���Ҳ��ɹ�ʱ��������Ԫ��e�����ŵ�ַ��ϣ��H�У�������OK
	// ����ͻ�����������ؽ���ϣ��
	int c = 0;//��¼��ͻ����
	int q;
	int p;
	p = getP(h->sizeindex);
	if (SUCCESS == SearchHash(*h, e.key, &q, &c, p))
	{ 
		// ���������� e ����ͬ�ؼ��ֵ�Ԫ��
		return DUPLICATE;
	}
	else if (c < p) 
	{
		// ��ͻ���� c δ�ﵽ����
		h->elem[q] = e;
		++h->count;
		return OK;
	}
	else 
	{
		// �ؽ���ϣ����������¿��ܹ�ϣ����������
		// ����ͨ�����ؽ����̶����������¹�ϣ�������
		RecreateHashTable(h);
	}
}

Status InitHashTable(HashTable *h,int num)
{

	int i;
	h->count = 0;
	h->sizeindex = num;
	h->elem = (ElemType*)malloc(h->sizeindex * sizeof(ElemType));
	if (!(h->elem))
		return ERROR;
	ElemType*p = h->elem;
	for (i = 0; i < h->sizeindex; i++)
	{
		p->key = NULL;
		p->val = 0;
		p++;
	}
}
