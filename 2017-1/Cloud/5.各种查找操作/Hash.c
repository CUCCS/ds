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
		e.key = e.val % H->sizeindex;
		InsertHash(H, e);
	}
	return;
}

/* ����for���� */
void _Search(HashTable T) {
	int i, p = 0, c = 0;
	ElemType e;
	printf("\n");
	for (i = 0; i < 5; i++)
	{
		e.val = (T.elem[i].key + 1 + rand())%1024;
		e.key = e.val % T.sizeindex;
		if (SearchHash(T, e, &p, &c)) {
			printf("�ؼ���%d���ҳɹ�! ��ͻ����%d\n", e.key, c);
		}
		else {
			printf("�ؼ���%d����ʧ��!\n", e.key);
		}
	}

}

/* ���ع�ϣ��ַ */
int Hash(HashTable H,ValueType k) {
	int p;
	p = k%H.sizeindex;
	return p;
}

/* �����ϣ��ͻ */
void collision(HashTable H,int *p, int *c) {
	*c++;
	*p = (*p + 1) % H.sizeindex;
}

/* ��ϣ��Ĳ��� */
Status SearchHash(HashTable H, ElemType e, int *p, int *c) {
	// �ڿ��Ŷ�ַ��ϣ��H�в��ҹؼ���ΪK�ļ�¼
	// c���ڼ�¼��ͻ��������ֵ��0
	*p = e.key; // ��ù�ϣ��ַ
	while (H.elem[*p].key != NULLKEY && e.key != H.elem[*p].key) {
		if(*p == H.sizeindex -1 )
			return  FAILED;
		collision(H,p, c);       // �����һ̽���ַ p
	}
	if (e.key == H.elem[*p].key) { // ���ҳɹ���p���ش�������Ԫ��λ��
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
	if (SearchHash(*H, e, &p, &c) == SUCCESS) {
		collision(*H,&p, &c);       // ���������� e ��	��ͬ�ؼ��ֵ�Ԫ��
		while ((*H).elem[p].key != NULLKEY /*&& e.key != (*H).elem[p].key*/) {
			collision(*H,&p, &c);       // �����һ̽���ַ p
		}
		H->elem[p].val = e.val;
		H->elem[p].key = e.key;
		++H->count;
		return DUPLICATE;
	}
	else if (c < H->sizeindex / 2) {
		// ��ͻ���� c δ�ﵽ���ޣ�����ֵ�ɵ����˴���Ϊʾ����
		H->elem[e.key].val = e.val;
		H->elem[e.key].key = e.key;
		++H->count;
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
	printf("\n�ؽ���ϣ��:\n");
	int i, count = (*H).count,n = (*H).sizeindex;
	ElemType *p , *elem = (ElemType*)malloc(count * sizeof(ElemType));
	p = elem;
	
	(*H).count = 0;
	for (i = 0; i < n; i++) { // ����ԭ�е����ݵ�elem��   
		if (((*H).elem + i)->key != NULLKEY) { // �õ�Ԫ������   
			*p++ = *((*H).elem + i);
			/*p->val = ((*H).elem + i)->val;
			p->key = Hash(*H, ((*H).elem + i)->val);
			p++;*/
		}
	}

	(*H).sizeindex += SizeIndex;
	for (i = 0; i < n; i++) { 
		if (((*H).elem + i)->key != NULLKEY) {
			p->val = ((*H).elem + i)->val;
			p->key = Hash(*H, ((*H).elem + i)->val);
			p++;
		}
	}
	 // ����洢����   
	p = (ElemType*)malloc((*H).sizeindex * sizeof(ElemType));
	if (!p)
		exit(1); // �洢����ʧ��   
   (*H).elem = p;
	for (i = 0; i < (*H).sizeindex; i++) {
		(*H).elem[i].key = -1; // ��ʼ��   
	    (*H).elem[i].val = -1;
	}
	for (p = elem; p < elem + count ; p++) // ��ԭ�е����ݰ����µı����뵽�ؽ��Ĺ�ϣ����   
		InsertHash(H, *p);
}

/* ��ӡ��ϣ�� */
void PrintHashTable(HashTable H){
	int i = 0,j = 0;
	for (; i < H.sizeindex; i++) {
		// {[Ԫ������Hash���е�����λ��] : �ؼ���->ֵ}
		printf("{[%d] : %d->%d}   ", i, H.elem[i].key, H.elem[i].val);
		j++;
		if(j%3 == 0)
			printf("\n");
	}
	printf("\n");
}
