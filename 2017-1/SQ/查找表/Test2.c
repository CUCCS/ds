#include "AVLTree.h"

int main() {
	ElemType test1[] = { 8,10,14,3,1,6,4,7,5,19,22,30 }; // 原始数据
	KeyType Key[] = { 13,8,5,20,6 }; // 待查找数据
	int elem_number, search_number;
	int i; // 计数用
	bool taller = false;

	elem_number = sizeof(test1) / sizeof(ElemType); // 计算平衡树中将会有的元素个数
	search_number = sizeof(Key) / sizeof(KeyType); // 计算待查找元素的个数

	AVLTree Tree = NULL;
	AVLTree temp = NULL;
	FILE *p;

	p = fopen("D:\\BaiduYunDownload\\AVLOutput.txt", "w+");

	CreateAVLT(&Tree, test1, elem_number); // 构建一棵平衡树
	PrintTree(Tree, p); // 打印

	for (i = 0; i < search_number; i++) {
		// 依次查找，若找到值为key[i]的结点，删除并打印
		// 若没找到，则将该元素插入平衡树
		if (!SearchAVLT(&Tree, Key[i], NULL, &temp)) {
			DeleteNode(&Tree, Key[i]);
			PrintTree(Tree, p);
		}
		else {
			InsertAVLT(&Tree, Key[i], &taller);
			PrintTree(Tree, p);
		}
	}
	return 0;
}
