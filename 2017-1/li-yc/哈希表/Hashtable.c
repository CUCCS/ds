#include "Hashtable.h"

Hashtable CreatHash(int size) {//创建哈希表
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

Status CreatArray(int arr[][2]) {//随机生成需要输入的数组
	int i;
	srand(time(0));
	for (i = 0; i < ArrayLenth; ++i) {
		arr[i][0] = rand() % 100 + 1;
		arr[i][1] = rand() % 100 + 1;
	}
	return OK;
}

bool isFull(Hashtable H) {//判断哈希表是否已经完全使用
	return H.size == H.used;
}

Status Insert(Hashtable H, KeyType keyvalue, ValueType value) {//往哈希表内插入元素
	int d = 0;
	int pos = (keyvalue + d) % H.size;
	if (isFull(H)) {
		printf("哈希表已满\n");
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
		printf("\n----[插入%d元素时发生了冲突%d次]----\n", keyvalue, d);
	}
	return OK;
}

Status Find(Hashtable H, KeyType keyval) {//在哈希表中查找元素
	int d = 0;
	int pos = (keyval + d) % H.size;
	printf("\n在表中查找关键字%d\n", keyval);
	while (H.elements[pos].key != keyval) {
		if (H.elements[pos].key == -1) {
			printf("所查找的关键字不在表中\n");
			return ERROR;
		}
		d++;
		pos = (pos + d) % H.size;
	}
	printf("在哈希表中位置%d找到关键字%d\n\n", pos, keyval);
	return OK;
}

Status RebulidHash(Hashtable *H) {//重建哈希表
	int newsize = (*H).size;
	int i;
	Hashtable temp = CreatHash((*H).size);
	printf("\n重建哈希表\n");
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

Status TraverseHash(Hashtable H) {//遍历哈希表
	int i;
	int flag=0;
	for (i = 0; i < H.size; ++i) {
		printf("{ [%d] : %d->%d } \n", i, H.elements[i].key, H.elements[i].val);
	}
	printf("\n");
	return OK;
}
