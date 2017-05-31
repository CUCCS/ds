#include "OpenHash.h"
bool DEBUG = 1;
bool isPrime(int n) {
	for (int i = 2; i < n; ++i) {
		if (n%i == 0) return false;
	}
	return true;
}
bool isFull(OpenHash openHash) {
	return openHash.used == openHash.size;
}
bool isEmpty(OpenHash openHash) {
	return openHash.used == 0;
}
ElemType newElemType(KeyType key, ValueType value) {
	ElemType temp = { key,value };
	return temp;
}
OpenHash newOpenHash(int size) {
	OpenHash temp;
	temp.size = size;
	temp.used = 0;
	temp.elements = (ElemType*)malloc(size * sizeof(ElemType));
	for (int i = 0; i < size; ++i) {
		temp.elements[i].key = EMPTYKEY;
		temp.elements[i].val = EMPTYVALUE;
	}
	return temp;
}
int getP(OpenHash openHash) {
	int p = openHash.size;
	if (p == 1)return 1;
	while (!isPrime(p--));
	return p + 1;
}
void ShowOpenHash(OpenHash openHash) {
	for (int i = 0; i < openHash.size; ++i) {
		printf("{ [%d] : %d->%d }\n", i, openHash.elements[i].key, openHash.elements[i].val);
	}
}
void Insert(OpenHash openHash, ElemType elem) {
	debug_print("׼������Ԫ��{ %d -> %d }\n", elem.key, elem.val);
	if (isFull(openHash)) {
		debug_print("Error : full hash table to insert\n");
		debug_print("======================\n");
		return;
	}
	int p = getP(openHash);
	int pos = elem.key % p;
	int collisionTimes = 0;
	while (openHash.elements[pos].key != EMPTYKEY) {
		collisionTimes += 1;
		++pos; pos %= openHash.size;
	}
	if (collisionTimes) {
		debug_print("��ͻ %d �κ� \n", collisionTimes);
	}
	openHash.elements[pos] = elem;
	openHash.used += 1;
	debug_print("��λ�� %d ����Ԫ��{ %d ->%d }\n", pos, elem.key, elem.val);

	debug_print("======================\n");
}
void Delete(OpenHash openHash, ElemType elem) {
	debug_print("׼��ɾ��Ԫ��{ %d -> %d }\n", elem.key, elem.val);
	if (isEmpty(openHash)) {
		debug_print("Error : empty hash table to delete\n");
		debug_print("======================\n");
		return;
	}
	int p = getP(openHash);
	int pos = elem.key % p;
	int collisionTimes = 0;
	while (openHash.elements[pos].key != elem.key) {
		collisionTimes += 1;
		++pos; pos %= openHash.size;
	}
	if (collisionTimes) {
		debug_print("��ͻ %d �κ� \n", collisionTimes);
	}
	openHash.elements[pos] = newElemType(DELETEDKEY, DELETEDVALUE);
	openHash.used -= 1;
	debug_print("��λ�� %d ɾ��Ԫ��{ %d ->%d }\n", pos, elem.key, elem.val);

	debug_print("======================\n");
}
/*�ڱ�openHash�в���Ԫ��elem*/
/*���ҵ��򷵻�elem��λ��,���򷵻�-1*/
int Find(OpenHash openHash, KeyType key) {
	debug_print("׼�����ҹؼ��� %d \n", key);
	int p = getP(openHash);
	int pos = key % p;
	int collisionTimes = 0;
	while (openHash.elements[pos].key != key) {
		if (openHash.elements[pos].key == EMPTYKEY) {
			debug_print("�ؼ��� %d ���ڱ���\n", key);
			debug_print("======================\n");
			return -1;
		}
		collisionTimes += 1;
		++pos; pos %= openHash.size;
	}
	if (collisionTimes) {
		debug_print("��ͻ %d �κ� \n", collisionTimes);
	}
	debug_print("��λ�� %d �ҵ��ؼ��� %d \n", pos, key);

	debug_print("======================\n");
	return pos;
}
OpenHash Rebuild(OpenHash openHash) {
	debug_print("������\n");
	int size = 2 * openHash.size;
	int debugStatu = DEBUG;
	DEBUG = 0;
	OpenHash temp = newOpenHash(size);
	for (int i = 0; i < openHash.size; ++i) {
		if (openHash.elements[i].key != EMPTYKEY && openHash.elements[i].key != DELETEDKEY) {
			Insert(temp, openHash.elements[i]);
		}
	}
	free(openHash.elements);
	DEBUG = debugStatu;
	return temp;
}