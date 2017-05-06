#include "BinaryTrees.h"

int main()
{
	int level = 0;
	int j;
	int count = 0;
	int ncounts = 0;


	/*=========用例一=========*/
	BiTree T1 = NULL;
	char*s1 = "ABDG   EH  I K  C F  ";
	printf("测试用例1为：\n");
	puts(s1);
	CreateBiTree(&T1, s1);
	printBiTree(T1);
	printf("二叉树的高度为:%d\n", getHigh(T1));
	printf("二叉树的宽度为:%d\n", getWide(T1, level));
	CountLeaf(T1, &count, &ncounts);
	printLeafNumber(T1, count, ncounts);
	printIsComplete(T1);
	destoryBiTree(T1);




	/*=========用例二=========*/
	valInit(&level, wide, &count, &ncounts);
	BiTree T2 = NULL;
	char*s2 = "ABD F   CE   ";
	printf("\n\n\n测试用例2为:\n");
	puts(s2);

	CreateBiTree(&T2, s2);
	printBiTree(T2);
	printf("二叉树的高度为:%d\n", getHigh(T2));
	printf("二叉树的宽度为:%d\n", getWide(T2, level));
	CountLeaf(T2, &count, &ncounts);
	printLeafNumber(T2, count, ncounts);
	printIsComplete(T2);
	destoryBiTree(T2);


	/*=========新增用例三=========*/
	valInit(&level, wide, &count, &ncounts);
	BiTree T3 = NULL;
	char*s3 = "ABC  D  E  ";
	printf("\n\n\n测试用例3为:\n");
	puts(s3);

	CreateBiTree(&T3, s3);
	printBiTree(T3);
	printf("二叉树的高度为:%d\n", getHigh(T3));
	printf("二叉树的宽度为:%d\n", getWide(T3, level));
	CountLeaf(T3, &count, &ncounts);
	printLeafNumber(T3, count, ncounts);
	printIsComplete(T3);
	destoryBiTree(T3);

	/*=========新增用例四=========*/
	valInit(&level, wide, &count, &ncounts);
	BiTree T4 = NULL;
	char*s4 = "ABCH   D  EFK   G  ";
	printf("\n\n\n测试用例4为:\n");
	puts(s4);
	CreateBiTree(&T4, s4);
	printBiTree(T4);
	printf("二叉树的高度为:%d\n", getHigh(T4));
	printf("二叉树的宽度为:%d\n", getWide(T4, level));
	CountLeaf(T4, &count, &ncounts);
	printLeafNumber(T4, count, ncounts);
	printIsComplete(T4);
	destoryBiTree(T4);
}






