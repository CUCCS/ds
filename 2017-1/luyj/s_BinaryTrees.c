#include "BinaryTrees.h"

int main()
{
	int level = 0;
	int j;
	int count = 0;
	int ncounts = 0;


	/*=========����һ=========*/
	BiTree T1 = NULL;
	char*s1 = "ABDG   EH  I K  C F  ";
	printf("��������1Ϊ��\n");
	puts(s1);
	CreateBiTree(&T1, s1);
	printBiTree(T1);
	printf("�������ĸ߶�Ϊ:%d\n", getHigh(T1));
	printf("�������Ŀ��Ϊ:%d\n", getWide(T1, level));
	CountLeaf(T1, &count, &ncounts);
	printLeafNumber(T1, count, ncounts);
	printIsComplete(T1);
	destoryBiTree(T1);




	/*=========������=========*/
	valInit(&level, wide, &count, &ncounts);
	BiTree T2 = NULL;
	char*s2 = "ABD F   CE   ";
	printf("\n\n\n��������2Ϊ:\n");
	puts(s2);

	CreateBiTree(&T2, s2);
	printBiTree(T2);
	printf("�������ĸ߶�Ϊ:%d\n", getHigh(T2));
	printf("�������Ŀ��Ϊ:%d\n", getWide(T2, level));
	CountLeaf(T2, &count, &ncounts);
	printLeafNumber(T2, count, ncounts);
	printIsComplete(T2);
	destoryBiTree(T2);


	/*=========����������=========*/
	valInit(&level, wide, &count, &ncounts);
	BiTree T3 = NULL;
	char*s3 = "ABC  D  E  ";
	printf("\n\n\n��������3Ϊ:\n");
	puts(s3);

	CreateBiTree(&T3, s3);
	printBiTree(T3);
	printf("�������ĸ߶�Ϊ:%d\n", getHigh(T3));
	printf("�������Ŀ��Ϊ:%d\n", getWide(T3, level));
	CountLeaf(T3, &count, &ncounts);
	printLeafNumber(T3, count, ncounts);
	printIsComplete(T3);
	destoryBiTree(T3);

	/*=========����������=========*/
	valInit(&level, wide, &count, &ncounts);
	BiTree T4 = NULL;
	char*s4 = "ABCH   D  EFK   G  ";
	printf("\n\n\n��������4Ϊ:\n");
	puts(s4);
	CreateBiTree(&T4, s4);
	printBiTree(T4);
	printf("�������ĸ߶�Ϊ:%d\n", getHigh(T4));
	printf("�������Ŀ��Ϊ:%d\n", getWide(T4, level));
	CountLeaf(T4, &count, &ncounts);
	printLeafNumber(T4, count, ncounts);
	printIsComplete(T4);
	destoryBiTree(T4);
}






