//Hash���ұ�Ľ������ؼ��ֲ��Һ��ؽ���ϣ������ԭHash������������ʵ��
//ʹ�á����Ŷ�ַ��֮����̽����ɢ�С����Hash��ͻ (������ݲ���)
#include <stdio.h>
#include <malloc.h>
#include<stdlib.h>
#include<time.h>
#define NULLKEY 0 // 0Ϊ�޼�¼��־
#define N 10  // ����Ԫ�ظ���
#define SIZE 6 
#define SUCCESS 1
#define UNSUCCESS 0
#define DUPLICATE -1
typedef int KeyType;// ��ؼ�����Ϊ����

					// ���Ŷ�ַ��ϣ��Ĵ洢�ṹ
typedef struct
{
	KeyType key;//�ؼ���
	int val;//ֵ
}ElemType; // ����Ԫ������

int hashsize[] = { 11,19,29,37 }; // ��ϣ������������һ�����ʵ���������
int m = 0; // ��ϣ�����ȫ�ֱ���

		   //�����ϣ��
typedef struct
{
	ElemType *elem; // ����Ԫ�ش洢��ַ����̬��������
	int count; // ��ǰ����Ԫ�ظ���
	int sizeindex; // hashsize[sizeindex]Ϊ��ǰ����
}HashTable;

// ����һ���յĹ�ϣ��
int InitHashTable(HashTable *H)
{
	int i;
	(*H).count = 0; // ��ǰԪ�ظ���Ϊ0
	(*H).sizeindex = 0; // ��ʼ�洢����Ϊhashsize[0]
	m = hashsize[0];
	(*H).elem = (ElemType*)malloc(m * sizeof(ElemType));
	if (!(*H).elem)
		exit(0); // �洢����ʧ��
	for (i = 0; i < m; i++)
	{
		(*H).elem[i].key = NULLKEY; // δ���¼�ı�־
	}
	return 1;
}

//  ���ٹ�ϣ��H
void DestroyHashTable(HashTable *H)
{
	free((*H).elem);
	(*H).elem = NULL;
	(*H).count = 0;
	(*H).sizeindex = 0;
}

// һ���򵥵Ĺ�ϣ����(mΪ����ȫ�ֱ���)
unsigned Hash(KeyType K)
{
	return K%m;
}

// ���Ŷ�ַ�������ͻ
void collision(int *p, int d) // ����̽����ɢ��
{
	*p = (*p + d) % m;
}

// �ڿ��Ŷ�ַ��ϣ��H�в��ҹؼ���ΪK��Ԫ��,�����ҳɹ�,��pָʾ��������
// Ԫ���ڱ���λ��,������SUCCESS;����,��pָʾ����λ��,������UNSUCCESS
// c���ԼƳ�ͻ���������ֵ���㣬���������ʱ�ο���
int SearchHash(HashTable H, KeyType K, int *p, int *c)
{
	*p = Hash(K); // ��ù�ϣ��ַ
	while (H.elem[*p].key != NULLKEY && !(K == H.elem[*p].key))
	{
		// ��λ�������м�¼�����ҹؼ��ֲ����
		(*c)++;
		if (*c<m)
			collision(p, *c); // �����һ̽���ַp
		else
			break;
	}
	if (K == H.elem[*p].key)
		return SUCCESS; // ���ҳɹ���p���ش�������Ԫ��λ��
	else
		return UNSUCCESS; // ���Ҳ��ɹ�(H.elem[p].key==NULLKEY)��p���ص��ǲ���λ��
}

void RecreateHashTable(HashTable *H);

// ���Ҳ��ɹ�ʱ��������Ԫ��e�����Ŷ�ַ��ϣ��H�У�������1��
// ����ͻ�����������ؽ���ϣ��
int InsertHash(HashTable *H, ElemType e)
{
	int c, p;
	c = 0;  
	if (SearchHash(*H, e.key, &p, &c)) // ����������e����ͬ�ؼ��ֵ�Ԫ��
	{
		return DUPLICATE;
	}
	else if (c<hashsize[(*H).sizeindex] / 2) // ��ͻ����cδ�ﵽ����,(c�ķ�ֵ�ɵ�)
	{
		// ����e
		(*H).elem[p] = e;
		++(*H).count;
		return 1;
	}
	else
		RecreateHashTable(H); // �ؽ���ϣ��

	return 0;
}

// �ؽ���ϣ��
void RecreateHashTable(HashTable *H) 
{
	int i, count = (*H).count;
	ElemType *p, *elem = (ElemType*)malloc(count * sizeof(ElemType));
	p = elem;
	printf("�ؽ���ϣ��\n");
	for (i = 0; i<m; i++) // ����ԭ�е����ݵ�elem��
		if (((*H).elem + i)->key != NULLKEY) // �õ�Ԫ������
			*p++ = *((*H).elem + i);
	(*H).count = 0;
	(*H).sizeindex++; // ����洢����
	m = hashsize[(*H).sizeindex];
	p = (ElemType*)realloc((*H).elem, m * sizeof(ElemType));
	if (!p)
		exit(0); // �洢����ʧ��
	(*H).elem = p;
	for (i = 0; i<m; i++)
		(*H).elem[i].key = NULLKEY; // δ���¼�ı�־(��ʼ��)
	for (p = elem; p<elem + count; p++) // ��ԭ�е����ݰ����µı����뵽�ؽ��Ĺ�ϣ����
		InsertHash(H, *p);
}

// ����ϣ��ַ��˳�������ϣ��
void TraverseHash(HashTable H, void(*Vi)(int, ElemType))
{
	int i;
	printf("��ϣ��ַ0��%d\n", m - 1);
	for (i = 0; i < m; i++)
	{
		if (H.elem[i].key != NULLKEY) // ������
			Vi(i, H.elem[i]);
		else 
			printf("{ [%d] : -1->0 }\n", i);
	}
}

// �ڿ��Ŷ�ַ��ϣ��H�в��ҹؼ���ΪK��Ԫ��,�����ҳɹ�,��pָʾ��������
// Ԫ���ڱ���λ��,������SUCCESS;����,����UNSUCCESS
int Find(HashTable H, KeyType K, int *p)
{
	int c = 0;
	*p = Hash(K); // ��ù�ϣ��ַ
	while (H.elem[*p].key != NULLKEY && !(K == H.elem[*p].key))
	{ // ��λ�������м�¼�����ҹؼ��ֲ����
		c++;
		if (c<m)
			collision(p, c); // �����һ̽���ַp
		else
			return UNSUCCESS; // ���Ҳ��ɹ�(H.elem[p].key==NULLKEY)
	}
	if (K == H.elem[*p].key)
		return SUCCESS; // ���ҳɹ���p���ش�������Ԫ��λ��
	else
		return UNSUCCESS; // ���Ҳ��ɹ�(H.elem[p].key==NULLKEY)
}

//��ӡԪ��
void print(int p, ElemType r)
{
	printf("{ [%d] : %d->%d }\n", p, r.key, r.val);
}

ElemType newElemType(KeyType key, int val)
{
	ElemType temp = { key,val };
	return temp;
}

ElemType* Inputs(int size)
{
	ElemType* a = (ElemType*)malloc(size * sizeof(ElemType));
	for (int i = 0; i < size; ++i)
	{
		a[i] = newElemType(rand() % 100, rand() % 100);
	}
	return a;
}

int main()
{
	srand(time(0));
	ElemType* r = Inputs(SIZE);
	HashTable h;
	int i, j, p;
	KeyType k=0;

	InitHashTable(&h);
	for (i = 0; i<SIZE ; i++)
	{
		j = InsertHash(&h, r[i]);
		if (j == DUPLICATE)
			printf("�������йؼ���Ϊ%d�ļ�¼���޷��ٲ����¼(%d,%d)\n",
				r[i].key, r[i].key, r[i].val);
	}
	printf("����ϣ��ַ��˳�������ϣ��:\n");
	TraverseHash(h, print);

	//����Ԫ��(���Ѵ洢�Ĺؼ�������� һ�����ҵ�)
	for (int i = 0; i < SIZE/2; i++)
	{
		
		k = r[rand() % SIZE].key;
		printf("���ҹؼ���Ϊ[%d]��Ԫ��\n", k);
		j = Find(h, k, &p);
		if (j == SUCCESS)
			print(p, h.elem[p]);
		else
			printf("û�ҵ�\n");
	}
	//����Ԫ��(�ڹؼ��ַ�Χ����� ��һ�����ҵ�)
	for (int i = 0; i < SIZE / 2; i++)
	{

		k = rand() % 100;
		printf("���ҹؼ���Ϊ[%d]��Ԫ��\n", k);
		j = Find(h, k, &p);
		if (j == SUCCESS)
			print(p, h.elem[p]);
		else
			printf("û�ҵ�\n");
	}


	return 0;
}


