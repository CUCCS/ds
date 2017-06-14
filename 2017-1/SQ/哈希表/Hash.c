#include "Hash.h"

Status CreateHash(HashTable *H, int size) {
	// ����Hash��
	ElemType temp;
	int i;

	(*H).sizeindex = size;
	(*H).count = 0;
	(*H).elem = (ElemType *)malloc(sizeof(ElemType) * size);

	if (!((*H).elem)) {
		return ERROR;
	}

	for (i = 0; i < size; i++) {
		(*H).elem[i].key = NULLKEY;
		(*H).elem[i].val = NONEVALUE;
	}

	printf("==========Creating HashTable==========\n");
	printf("HashTable size:%d\n", (*H).sizeindex);
	for (i = 0; H->count < size / 2; i++) {
		temp.key = (int)rand() % 501;
		temp.val = (int)rand() % 501;
		InsertHash(H, temp);
	}
	printf("Crating Over\n\n");

	return OK;
}

bool Empty(HashTable H) {
	// �ж�Hash���Ƿ�Ϊ�գ���û��Ԫ��
	if (H.count == 0) {
		return TRUE;
	}

	return FALSE;
}

bool Prime(int n) {
	// �ж�һ�����Ƿ�Ϊ����
	if (n == 2) {
		return TRUE;
	}

	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return FALSE;
		}
	}

	return TRUE;
}

int SearchHash(HashTable H, KeyType K, int *p, int *c) {
	// �ڿ��Ŷ�ַ��ϣ��H�в��ҹؼ�ֵΪK�ļ�¼
	*p = K % H.sizeindex; // ��ù�ϣ��ַ
	*c = 0; // c���ڼ�¼��ͻ��������ֵ��0
	while (H.elem[*p].key != NULLKEY && !EQ(K, H.elem[*p].key)) {
		if ((*p) < H.sizeindex) {
			printf("Collide  with %d->%d\n", H.elem[*p].key, H.elem[*p].val);
			(*p)++;
			(*c)++;
		}
		else
			break;
	}
	if (EQ(K, H.elem[*p].key)) { // ���ҳɹ���p���ش�������Ԫ��λ��
		return SUCCESS;
	}
	else {
		return FAILED;   // ���Ҳ��ɹ�
	}
}

Status InsertHash(HashTable *H, ElemType e) {
	// ���Ҳ��ɹ�ʱ��������Ԫ��e�����ŵ�ַ��ϣ��H�У�������OK
	// ����ͻ����������ҵ�ĩβ�����ؽ���ϣ��
	int c, p;
	if (SearchHash(*H, e.key, &p, &c) == SUCCESS) { // ���������� e ����ͬ�ؼ��ֵ�Ԫ��
		return DUPLICATE;
	}
	else{
		if (p == (*H).sizeindex || c > (*H).sizeindex / 2) {
			RecreateHashTable(H);
		}
		(*H).elem[p] = e;
		++(*H).count;
		printf("Collision times:%d\n", c);
		printf("Insert:%d->%d\n", H->elem[p].key, H->elem[p].val);
		printf("--------------------------\n");
		return OK;
	}
}

bool EQ(KeyType a, KeyType b) {
	// �жϹؼ�ֵa�Ƿ����b
	if (a == b) {
		return TRUE;
	}

	return FALSE;
}

Status RecreateHashTable(HashTable *H) {
	// �ؽ�Hash�������䣨һ���鷳��������
	int i, n;
	HashTable temp; // ��ʱHash��
	ElemType e;

	if (Empty(*H)) {
		return ERROR;
	}

	e.key = NULLKEY;
	e.val = NONEVALUE;
	n = 2 * (*H).sizeindex;

	while (!Prime(n)) {
		n++;
	};

	temp.sizeindex = n;
	temp.count = (*H).count;
	temp.elem = (ElemType *)malloc(sizeof(ElemType)*n);
	for (i = 0; i < n; i++) {
		temp.elem[i].key = NULLKEY;
		temp.elem[i].val = NONEVALUE;
	}
	for (i = 0; i < (*H).sizeindex; i++) {
		temp.elem[i].key = (*H).elem[i].key;
		temp.elem[i].val = (*H).elem[i].val;
	}

	(*H).sizeindex = temp.sizeindex;
	(*H).count = temp.count;
	(*H).elem = (ElemType *)malloc(sizeof(ElemType)*n);
	for (i = 0; i < n; i++) {
		(*H).elem[i].key = temp.elem[i].key;
		(*H).elem[i].val = temp.elem[i].val;
	}

	free(temp.elem);

	return OK;
}

Status Print(HashTable H) {
	// �������Hash��
	if (Empty(H)) {
		return ERROR;
	}

	printf("==========Print HashTable==========\n");
	for (int i = 0; i < H.sizeindex; i++)
		printf("[%d] : %d->%d\n", i, H.elem[i].key, H.elem[i].val);
	printf("Print Over\n");
	printf("\n");

	return OK;
}