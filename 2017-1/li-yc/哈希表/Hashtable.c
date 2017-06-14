#include "Hashtable.h"

Hashtable CreatHash(int size) {//������ϣ��
	int i;
	Hashtable temp;
	temp.size = size;
	temp.used = 0;
	temp.elements = (ElemType*)malloc(size * sizeof(ElemType));
	for (i = 0; i < HashLength; ++i) {
		temp.elements[i].key = -1;
		temp.elements[i].val = 0;
	}
	return temp;
}

Status CreatArray(int arr[][2]) {//���������Ҫ���������
	int i;
	srand(time(0));
	for (i = 0; i < ArrayLenth; ++i) {
		arr[i][0] = rand() % 100 + 1;
		arr[i][1] = rand() % 100 + 1;
	}
	return OK;
}

bool isFull(Hashtable H) {//�жϹ�ϣ���Ƿ��Ѿ���ȫʹ��
	return H.size == H.used;
}

Status Insert(Hashtable H, KeyType keyvalue, ValueType value) {//����ϣ���ڲ���Ԫ��
	int d = 0;
	int pos = (keyvalue + d) % H.size;
	if (isFull(H)) {
		printf("��ϣ������\n");
		RebulidHash(&H);
		return ERROR;
	}
	while (H.elements[pos].key != -1 && keyvalue != -1) {
		d++;
		pos = (pos + d) % H.size;
	}
	if (keyvalue != -1) {
		H.elements[pos].key = keyvalue;
		H.elements[pos].val = value;
	}
	if (d != 0) {
		printf("\n----[����%dԪ��ʱ�����˳�ͻ%d��]----\n", keyvalue, d);
	}
	return OK;
}

Status Find(Hashtable H, KeyType keyval) {//�ڹ�ϣ���в���Ԫ��
	int d = 0;
	int pos = (keyval + d) % H.size;
	printf("\n�ڱ��в��ҹؼ���%d\n", keyval);
	while (H.elements[pos].key != keyval) {
		if (H.elements[pos].key == -1) {
			printf("�����ҵĹؼ��ֲ��ڱ���\n");
			return ERROR;
		}
		d++;
		pos = (pos + d) % H.size;
	}
	printf("�ڹ�ϣ����λ��%d�ҵ��ؼ���%d\n\n", pos, keyval);
	return OK;
}

Status RebulidHash(Hashtable *H) {//�ؽ���ϣ��
	int newsize = (*H).size;
	int i;
	Hashtable temp = CreatHash((*H).size);
	printf("\n�ؽ���ϣ��\n");
	for (i = 0; i < (*H).size; ++i) {
		temp.elements[i].key = (*H).elements[i].key;
		temp.elements[i].val = (*H).elements[i].val;
	}
	(*H).size *= 2;
	(*H).elements = (ElemType*)malloc((*H).size * sizeof(ElemType));
	for (i = 0; i < (*H).size; ++i) {
		(*H).elements[i].key = -1;
		(*H).elements[i].val = 0;
	}
	for (i = 0; i < newsize; ++i) {
		Insert(*H, temp.elements[i].key, temp.elements[i].val);
	}
	return OK;
}

Status TraverseHash(Hashtable H) {//������ϣ��
	int i;
	int flag=0;
	for (i = 0; i < H.size; ++i) {
		printf("{ [%d] : %d->%d } \n", i, H.elements[i].key, H.elements[i].val);
	}
	printf("\n");
	return OK;
}
