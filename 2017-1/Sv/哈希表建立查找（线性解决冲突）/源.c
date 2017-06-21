#include"OHash.h"

int main()
{
	int SIZE = 30;
	HashTable HA = NewHashTable(SIZE);
	srand(time(0));
	printf("插入20个元素：\n");
	ElemType array[20];
	for (int i = 0; i < 20; i++)
	{
		ElemType e;
		e.key = rand() % 1000 + 1;
		e.val = rand() % 1000 + 1;
		array[i] = e;
		InsertHash(HA, e);
	}

	for (int i = 0; i < HA.sizeindex; i++)
	{
		printf("{ [%d] : %d -> %d }\t", i, HA.elem[i].key, HA.elem[i].val);
	}
	for (int i = 0; i < 3; i++)
	{
		ElemType temp = array[rand() % 20];
		int p,c;
		if (SearchHash(HA, temp.key, &p, &c) == SUCCESS)
		{
			printf("查找关键字为%d，地址：%d\n", temp.key, p);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		ElemType temp;
		temp.key = rand() % 1000 + 1;
		temp.val = rand() % 1000 + 1;
		int p, c;
		if (SearchHash(HA, temp.key, &p, &c) == SUCCESS)
		{
			printf("查找关键字为%d，地址：%d\n", temp.key, p);
		}
		else
		{
			printf("查找关键字为%d，查找失败！\n", temp.key);
		}
	}
	printf("\n重建哈希表：\n");
	RecreateHashTable(&HA);
	for (int i = 0; i < HA.sizeindex; i++)
	{
		printf("{ [%d] : %d -> %d }\t", i, HA.elem[i].key, HA.elem[i].val);
	}

}