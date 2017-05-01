#include "BinaryTrees.h"

int main()
{
	//用例一
	BiTree T1 = NULL;
	int level = 0;
	int j;
	int *counts=(int*)malloc(sizeof(int));
	int count = 0;
	int ncounts = 0;
	char*s1 = "ABDG   EH  I K  C F  ";

	printf("测试用例1为：\n");
	puts(s1);
	printf("后序式表达式为：\n");
	CreateBiTree(&T1, s1);
	PostOrderTraverse(T1);
	printf("\n");
	printf("二叉树的高度为:%d\n", getHigh(T1));
	printf("二叉树的宽度为:%d\n", getWide(T1, level));
	CountLeaf(T1, &count, &ncounts);
	printf("叶子结点个数为:%d\n", count);
	printf("非叶子结点个数为:%d\n", ncounts-count);
	destoryBiTree(T1);




	//用例二
	level = 0;
	i = 0;
	count = 0;
	ncounts = 0;
	for (j = 0; j < 50; j++)
	{
		wide[j] = 0;
	}
	BiTree T2 = NULL;
	char*s2 = "ABD F   CE   ";

	printf("\n\n\n测试用例2为:\n");
	puts(s2);
	printf("后序式表达式为：\n");
	CreateBiTree(&T2, s2);
	PostOrderTraverse(T2);
	printf("\n");
	printf("二叉树的高度为:%d\n", getHigh(T2));
	printf("二叉树的宽度为:%d\n", getWide(T2, level));
	CountLeaf(T2, &count,&ncounts);
	printf("叶子结点个数为:%d\n", count);
	printf("非叶子结点个数为:%d\n", ncounts-count);
	destoryBiTree(T2);
}




