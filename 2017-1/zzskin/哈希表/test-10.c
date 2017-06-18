#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SUCCESS 1 
#define UNSUCCESS 0 
#define DUPLICATE -1 

typedef int KeyType; 
typedef int ValueType; 

typedef struct _ElemType { 
	KeyType key;      // �ؼ��� 
	ValueType val;    // ֵ 
#ifdef CHAINED_HASH 
	struct _ElemType *next; 
#endif 
} ElemType; 

typedef struct 
{ 
	ElemType *elem;//����Ԫ�ش洢��ַ ��̬�������� 
	int count;//��ǰ����Ԫ�ظ��� 
	int size_index;//hashsize[size_index]Ϊ��ǰ���� 
}HashTable; 


typedef enum { // ��������ֵ 
	OK, 
	ERROR 
}Status; 

typedef enum { // ��������ֵ 
	FALSE, 
	TRUE 
}Bool; 

int InsertHash(HashTable *H, ElemType e)
{
	int c,p;
	if(SearchHash(*H,e.key,&p,&c) == SUCCESS)
	{
		return DUPLICATE;
	}
	else
	{
		if(p == (*H).size_index || c > (*H).size_index / 2)
		{
			RecreateHashTable(H);
		}
		(*H).elem[p] = e;
		++(*H).count;
		printf("��ͻ����: %d\n",c);
		printf("Insert:%d->%d\n",H->elem[p].key, H->elem[p].val);
		printf("\n");
		return 0;
	}
}

Status CreateHash(HashTable *H,int size)
{
	ElemType temp;
	int i;

	(*H).size_index = size;
	(*H).count = 0;
	(*H).elem = (ElemType *)malloc(sizeof(ElemType) * size);

	if(!((*H).elem))
	{
		return ERROR;
	}
	for(i = 0; i < size; i++)
	{
		(*H).elem[i].key = -1;
		(*H).elem[i].val = 0;
	}
	printf("---------------Hash����----------------\n");
	printf("HashTable ��С : %d\n",(*H).size_index);
	for(i = 0; H->count < size / 2; i++)
	{
		temp.key = rand() % 501;    //�����������
		temp.val = rand() % 501;
		InsertHash(H, temp);
	}
	printf("������ɣ�\n\n");
	return OK;
}

Bool Empty(HashTable H)    //�жϹ�ϣ���Ƿ�Ϊ��
{
	if(H.count == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

Bool Prime(int n)          //�ж��Ƿ�Ϊ����
{
	int i;

	if(n == 2)
	{
		return TRUE;
	}
	for(i = 2; i <= (int)sqrt((double)n); i++)
	{
		if(n % i == 0)
		{
			return FALSE;
		}
	}
	return TRUE;
}

Bool hash(KeyType a,KeyType b)
{
	if(a == b)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int SearchHash(HashTable H, KeyType K, int *p, int *w)
{
	*p = K % H.size_index;
	*w = 0;
	while(H.elem[*p].key != -1 && !hash(K,H.elem[*p].key))
	{
		if((*p) < H.size_index)
		{
			printf("��ͻ�� %d->%d\n",H.elem[*p].key,H.elem[*p].val);
			(*p)++;
			(*w)++;
		}
		else
		{
			break;
		}
	}
	if(hash(K,H.elem[*p].key))
	{
		return SUCCESS;
	}
	else
	{
		return UNSUCCESS;
	}
}

Status RecreateHashTable(HashTable *H)
{
	int i,n;
	HashTable temp;
	ElemType e;
	if(Empty(*H))
	{
		return ERROR;
	}
	e.key = -1;
	e.val = 0;
	n = 2 * (*H).size_index;
	while (!Prime(n))
	{
		n++;
	};
	temp.size_index = n;
	temp.count = (*H).count;
	temp.elem = (ElemType *)malloc(sizeof(ElemType)*n); 
	for(i = 0; i < n; i++)
	{
		temp.elem[i].key = -1;
		temp.elem[i].val = 0;
	}
	for(i = 0; i < (*H).size_index; i++)
	{
		(*H).elem[i].key = temp.elem[i].key;
		(*H).elem[i].val = temp.elem[i].val; 
	}
	(*H).size_index = temp.size_index;
	(*H).count = temp.count;
	(*H).elem = (ElemType *)malloc(sizeof(ElemType)*n);
	for(i = 0; i < n; i++)
	{
		(*H).elem[i].key = temp.elem[i].key;
		(*H).elem[i].val = temp.elem[i].val;
	}
	free(temp.elem);
	return OK;
}

Status Print(HashTable H)
{
	int i;
	if(Empty(H))
	{
		return ERROR;
	}

	printf("---------------��ӡ��ϣ��---------------\n");
	for(i = 0; i < H.size_index; i++)
	{
		printf("[%d] : %d->%d\n", i, H.elem[i].key, H.elem[i].val); 
	}
		printf("��ӡ��ɣ�\n");
		printf("\n");
		return OK;
}

int main()
{
	int size = 0,i;
	int p,c;
	HashTable H;
	ElemType e;
	srand(time(NULL));
	while(Prime(size))
	{
		size = rand() % 11 + 20;
	}
	CreateHash(&H,size);
	Print(H);

	p = c = 0;
	printf("-------------����---------------\n");
	for(i = 0; i < H.size_index; i++)
	{
		e.key = rand() % 501;
		printf("���ң�%d\n",e.key);
		if(SearchHash(H,e.key,&p,&c) == SUCCESS)
		{
			printf("���ҵ���%d\n",e.key);
			printf("The Element Is : %d->%d\n", H.elem[p].key, H.elem[p].val); 
			printf("----------------------------------\n");
		}
		else
		{
			printf("���Ҳ����ڣ�%d\n",e.key);
			printf("----------------------------------\n");
		}
	}
	printf("���ҽ�����\n");

	printf("-----------------------���½�����ϣ��--------------------\n");
	if(!RecreateHashTable(&H))
	{
		printf("\n");
		Print(H);
		printf("���½���������\n");
		
	}
	return 0;
}