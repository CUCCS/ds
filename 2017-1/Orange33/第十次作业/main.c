#include "hash.h"

int main()
{
	ElemType r[N];
	for (int i = 0; i < N; i++)
	{
		r[i] = newElemType(rand() % 100, rand() % 100);
	}
	HashTable h;
	int i, p;
	int j;
	KeyType k;
	initHashTable(&h);
	for (i = 0; i < N - 1; i++)//插入前N-1个记录
	{
		j = insertHash(&h, r[i]);
		printf("已插入元素：{%d，%d}\t", r[i].key, r[i].val);
		printf("冲突次数：%d\n", collisiontime);
		if (j == DUPLICATE)
			printf("表中已有关键字尾%d的记录 无法再插入记录(%d %d)\n", r[i].key, r[i].key, r[i].val);
	}
	printf("\n按哈希地址的顺序遍历哈希表\n");
	traverseHash(h, printHash);
	printf("\n\n");

	int count = 5;
	while (count > 0)
	{
		printf("输入关键字:");
		k = rand() % 100;
		j = find(h, k, &p);
		printf("%d\n", k);
		if (j == SUCCESS)
		{
			printf("在位置%d找到该元素", p);
			printHash(p, h.elem[p]);
		}
		else
			printf("没找到\n");
		k = 0;
		count--;
	}
	j = insertHash(&h, r[i]);//插入第N个记录
	if (j == 0)//j==ERROR 重建哈希表
	{
		j = insertHash(&h, r[i]);//重建哈希表后重新插入第N个记录
	}

	printf("按哈希地址的顺序遍历重建后的哈希表\n");
	traverseHash(h, printHash);
	printf("\n\n");

	destroyHashTable(&h);
	printf("哈希表销毁成功!");
	printf("\n\n");

	return 0;
}