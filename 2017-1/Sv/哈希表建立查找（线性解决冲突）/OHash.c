#include"OHash.h"
bool isSushu(int a)
{
	for (int i = 2; i < sqrt(a)+2; i++)

	{
		if (a%i == 0)return false;
	}
	return true;
}
int hashsize(int size)
{
	int p = size;
	if (p == 1)return 1;
	while (!isSushu(p--));//��size��ʼ���µ������ĵ�һ���������˴��������
	return p + 1;
}
int Hash(KeyType K, int size)
{
	int p = hashsize(size);
	return K%p;
}
bool EQ(int a, int b) { return(a == b); }
void collision(int *p, int *c){ (*p)++ ; (*c)++; }

HashTable NewHashTable(int size)
{
	HashTable temp;
	temp.count = 0;
	temp.sizeindex = size;
	temp.elem = (ElemType*)malloc(size * sizeof(ElemType));
	for (int i = 0; i < size; i++)
	{
		temp.elem[i].key = -1;
		temp.elem[i].val = 0;
	}
	return temp;
}
void RecreateHashTable(HashTable *H)
{
	HashTable temp = NewHashTable(H->sizeindex * 2);
	int a = H->sizeindex;
	for (int i = 0; i <a; i++)
	{
		temp.elem[i] = H->elem[i];
	}
	H->sizeindex *= 2;
	H->elem= (ElemType*)malloc(H->sizeindex * sizeof(ElemType));
	for (int i = 0; i < H->sizeindex; i++)
	{
		H->elem[i].key = -1; H->elem[i].val = 0;
	}
	for (int i = 0; i < a; i++)
	{
		int p = Hash(temp.elem[i].key, H->sizeindex);
		H->elem[p] = temp.elem[i];
	}
}
Status SearchHash(HashTable H, KeyType K, int *p, int *c)
{
	*p = Hash(K,H.sizeindex); // ��ù�ϣ��ַ
	while (H.elem[*p].key != NULLKEY && !EQ(K, H.elem[*p].key)) {
		collision(p, c);       //��ͻ�������һ̽���ַ p
		//printf("***");
	}

	if (EQ(K, H.elem[*p].key)) { // ���ҳɹ���p���ش�������Ԫ��λ��
		return SUCCESS;
	}
	else {
		return FAILED;   // ���Ҳ��ɹ�
	}
}
Status InsertHash(HashTable &H, ElemType e)
{
	// ���Ҳ��ɹ�ʱ��������Ԫ��e�����ŵ�ַ��ϣ��H�У�������OK
	// ����ͻ�����������ؽ���ϣ��
	int a = 0,b=0;
	int *c ;//���ڼ�¼��ͻ����
	c = &a;
	int *p ;
	p = &b;
	if (SearchHash(H, e.key, p, c) == SUCCESS) { // ���������� e ����ͬ�ؼ��ֵ�Ԫ��
		if ((*c) != 0)
		{
			printf("\n��ϣ��ͻ��������%d���ؼ���ֵ��%d->%d\n", *c, e.key, e.val);
		}
		return DUPLICATE;
	}

	else if (*c < hashsize(H.sizeindex) / 2) {
		// ��ͻ���� c δ�ﵽ���ޣ�����ֵ�ɵ����˴���Ϊʾ����
		H.elem[*p] = e;
		++H.count;
		return OK;
	}
	else {
		// �ؽ���ϣ����������¿��ܹ�ϣ����������
		// ����ͨ�����ؽ����̶����������¹�ϣ�������
		RecreateHashTable(&H);
	}
}