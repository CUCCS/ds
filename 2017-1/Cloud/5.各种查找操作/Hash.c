#include "Hash.h"

/* ��ʼ����ϣ�� */
void InitHashTable(HashTable *H) {
	int i;
	H->count = 0;
	H->sizeindex = SizeIndex;
	H->elem = (ElemType*)malloc(H->sizeindex * sizeof(ElemType));
	for (i = 0; i < H->sizeindex; i++) {
		H->elem[i].key = NULLKEY;
		H->elem[i].val = NULLKEY;
	}
}

/* ��������ɵ��������������Hash�� */
void CreateHashTable(HashTable * H) {
	int i;
	ElemType e;
	for (i = 0; i < H->sizeindex; i++) {
		e.val = rand() % 1024;
		e.key = e.val % SizeIndex;
		InsertHash(H, e);
	}
	return;
}

/* ����for���� */
void _Search(HashTable T) {
	int i, k, p = 0, c = 0;
	for (i = 0; i < 5; i++)
	{
		k = (T.elem[i].key + 1 + rand()) % T.sizeindex;
		if (SearchHash(T, k, &p, &c)) {
			printf("�ؼ���%d���ҳɹ�! ��ͻ����%d\n", k, c);
		}
		else {
			printf("�ؼ���%d����ʧ��!\n", k);
		}
	}

}

/* ���ع�ϣ��ַ */
int Hash(KeyType k) {
	return k%SizeIndex;
}

/* �����ϣ��ͻ */
void collision(int *p, int *c) {
	*p = (*p + 1) % SizeIndex;
	*c++;
}

/* ��ϣ��Ĳ��� */
Status SearchHash(HashTable H, KeyType K, int *p, int *c) {
	// �ڿ��Ŷ�ַ��ϣ��H�в��ҹؼ���ΪK�ļ�¼
	// c���ڼ�¼��ͻ��������ֵ��0
	*p = Hash(K); // ��ù�ϣ��ַ
	while (H.elem[*p].key != NULLKEY && K != H.elem[*p].key) {
		collision(p, c);       // �����һ̽���ַ p
	}
	if (K == H.elem[*p].key) { // ���ҳɹ���p���ش�������Ԫ��λ��
		return SUCCESS;
	}
	else {
		return FAILED;   // ���Ҳ��ɹ�
	}
}

/* ���ϣ���в������� */
Status InsertHash(HashTable *H, ElemType e) {
	// ���Ҳ��ɹ�ʱ��������Ԫ��e�����ŵ�ַ��ϣ��H�У�������OK
	// ����ͻ�����������ؽ���ϣ��
	int p, c;
	c = 0;//��¼��ͻ����
	if (SearchHash(*H, e.key, &p, &c) == SUCCESS) {
		collision(&p, &c);       // ���������� e ����ͬ�ؼ��ֵ�Ԫ��
		while ((*H).elem[p].key != NULLKEY && e.key != (*H).elem[p].key) {
			collision(&p, &c);       // �����һ̽���ַ p
		}
		H->elem[p].val = e.val;
		H->elem[p].key = e.key;
		++H->count;
		return DUPLICATE;
	}
	else if (c < H->sizeindex / 2) {
		// ��ͻ���� c δ�ﵽ���ޣ�����ֵ�ɵ����˴���Ϊʾ����
		H->elem[p].val = e.val;
		H->elem[p].key = e.key;
		//++H->count;
		return SUCCESS;
	}
	else {
		// �ؽ���ϣ����������¿��ܹ�ϣ����������
		// ����ͨ�����ؽ����̶����������¹�ϣ�������
		RecreateHashTable(H);
	}
	return SUCCESS;
}

/* �ؽ���ϣ�� */
void RecreateHashTable(HashTable *H) // �ؽ���ϣ�����ο���csdn�������ķ��� -�����ݽṹ����ϣ��
{
	int i, count = (*H).count;
	ElemType *p, *elem = (ElemType*)malloc(count * sizeof(ElemType));
	p = elem;
	printf("�ؽ���ϣ��\n");
	for (i = 0; i < (*H).sizeindex; i++) // ����ԭ�е����ݵ�elem��   
		if (((*H).elem + i)->key != NULLKEY) // �õ�Ԫ������   
			*(p++) = *((*H).elem + i);
	(*H).count = 0;
	(*H).sizeindex++; // ����洢����   
	p = (ElemType*)realloc((*H).elem, (*H).sizeindex * sizeof(ElemType));
	if (!p)
		exit(0); // �洢����ʧ��   
	(*H).elem = p;
	for (i = 0; i < (*H).sizeindex; i++)
		(*H).elem[i].key = NULLKEY; // δ���¼�ı�־(��ʼ��)   
	for (p = elem; p < elem + count; p++) // ��ԭ�е����ݰ����µı����뵽�ؽ��Ĺ�ϣ����   
		InsertHash(H, *p);
}

/* ��ӡ��ϣ�� */
void PrintHashTable(HashTable H) {
	int i = 0;
	for (; i < H.sizeindex; i++) {
		// {[Ԫ������Hash���е�����λ��] : �ؼ���->ֵ}
		printf("{[%d] : %d->%d}\n", i, H.elem[i].key, H.elem[i].val);
	}
	printf("\n");
}
