#include"bt.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
	//����һ 
	BiTree T1 = NULL;
	int l = 0;
	int j;
	int *counts = (int*)malloc(sizeof(int));
	int count1 = 0;
 	int count2 = 0;
	char*s1 = "ABDG   EH  I K  C F  ";
	
 	printf("��������1Ϊ��\n");
	puts(s1);
	printf("����ʽ���ʽΪ��\n");
 	CreateBiTree(&T1, s1);
 	PostOrderTraverseTree(T1);
 	printf("\n");
	printf("�������ĸ߶�Ϊ:%d\n", getHeight(T1));
	printf("�������Ŀ��Ϊ:%d\n", getWidth(T1, l));
 	CountLeaf(T1, &count1, &count2);
 	printf("Ҷ�ӽ�����Ϊ:%d\n", count1);
 	printf("��Ҷ�ӽ�����Ϊ:%d\n", count2);
 	destoryBiTree(T1);
	
 	//������ 
 	l = 0;
	i = 0;
 	count1 = 0;
 	count2 = 0;
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
 	PostOrderTraverseTree(T2);
 	printf("\n");
 	printf("�������ĸ߶�Ϊ:%d\n", getHeight(T2));
 	printf("�������Ŀ��Ϊ:%d\n", getWidth(T2, l));
 	CountLeaf(T2, &count1, &count2);
 	printf("Ҷ�ӽ�����Ϊ:%d\n", count1);
 	printf("��Ҷ�ӽ�����Ϊ:%d\n", count2);
 	destoryBiTree(T2);
 }
