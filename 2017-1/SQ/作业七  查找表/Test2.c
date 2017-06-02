#include "AVLTree.h"

int main() {
	ElemType test1[] = { 8,10,14,3,1,6,4,7,5,19,22,30 }; // ԭʼ����
	KeyType Key[] = { 13,8,5,20,6 }; // ����������
	int elem_number, search_number;
	int i; // ������
	bool taller = false;

	elem_number = sizeof(test1) / sizeof(ElemType); // ����ƽ�����н����е�Ԫ�ظ���
	search_number = sizeof(Key) / sizeof(KeyType); // ���������Ԫ�صĸ���

	AVLTree Tree = NULL;
	AVLTree temp = NULL;
	FILE *p;

	p = fopen("D:\\BaiduYunDownload\\AVLOutput.txt", "w+");

	CreateAVLT(&Tree, test1, elem_number); // ����һ��ƽ����
	PrintTree(Tree, p); // ��ӡ

	for (i = 0; i < search_number; i++) {
		// ���β��ң����ҵ�ֵΪkey[i]�Ľ�㣬ɾ������ӡ
		// ��û�ҵ����򽫸�Ԫ�ز���ƽ����
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
