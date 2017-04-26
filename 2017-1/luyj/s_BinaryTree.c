#include "BinaryTree.h"

int main()
{
	BiTree T1 = NULL;
	char*s1 = "ABDG   EH  I K  C F  ";
	printf("测试用例1为：\n");
	puts(s1);
	printf("后序式表达式为：\n");
	CreateBiTree(&T1, s1);
	PostOrderTraverse(T1);
	destoryBiTree(T1);
	i = 0;
	BiTree T2 = NULL;
	char*s2 = "ABD F   CE    ";
	printf("测试用例2为:\n");
	puts(s2);
	printf("后序式表达式为：\n");
	CreateBiTree(&T2, s2);
	PostOrderTraverse(T2);
	destoryBiTree(T2);
}
