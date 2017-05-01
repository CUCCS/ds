#include "BinaryTrees.h"

int main()
{
	//����һ
	BiTree T1 = NULL;
	int level = 0;
	int j;
	int *counts=(int*)malloc(sizeof(int));
	int count = 0;
	int ncounts = 0;
	char*s1 = "ABDG   EH  I K  C F  ";

	printf("��������1Ϊ��\n");
	puts(s1);
	printf("����ʽ���ʽΪ��\n");
	CreateBiTree(&T1, s1);
	PostOrderTraverse(T1);
	printf("\n");
	printf("�������ĸ߶�Ϊ:%d\n", getHigh(T1));
	printf("�������Ŀ��Ϊ:%d\n", getWide(T1, level));
	CountLeaf(T1, &count, &ncounts);
	printf("Ҷ�ӽ�����Ϊ:%d\n", count);
	printf("��Ҷ�ӽ�����Ϊ:%d\n", ncounts-count);
	destoryBiTree(T1);




	//������
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

	printf("\n\n\n��������2Ϊ:\n");
	puts(s2);
	printf("����ʽ���ʽΪ��\n");
	CreateBiTree(&T2, s2);
	PostOrderTraverse(T2);
	printf("\n");
	printf("�������ĸ߶�Ϊ:%d\n", getHigh(T2));
	printf("�������Ŀ��Ϊ:%d\n", getWide(T2, level));
	CountLeaf(T2, &count,&ncounts);
	printf("Ҷ�ӽ�����Ϊ:%d\n", count);
	printf("��Ҷ�ӽ�����Ϊ:%d\n", ncounts-count);
	destoryBiTree(T2);
}




