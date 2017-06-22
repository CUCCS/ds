#include"hash.h"

int main()
{
	srand(time(0));
	ElemType* r = Inputs(SIZE);
	HashTable h;
	int i, j, p;
	KeyType k=0;

	InitHashTable(&h);
	for (i = 0; i<SIZE ; i++)
	{
		j = InsertHash(&h, r[i]);
		if (j == DUPLICATE)
			printf("表中已有关键字为%d的记录，无法再插入记录(%d,%d)\n",
			r[i].key, r[i].key, r[i].val);
	}
	printf("按哈希地址的顺序遍历哈希表:\n");
	TraverseHash(h, print);

	//查找元素(在已存储的关键字中随机 一定能找到)
	for (int i = 0; i < SIZE/2; i++)
	{

		k = r[rand() % SIZE].key;
		printf("查找关键字为[%d]的元素\n", k);
		j = Find(h, k, &p);
		if (j == SUCCESS)
			print(p, h.elem[p]);
		else
			printf("无该元素\n");
	}
	//查找元素(在关键字范围内随机 不一定能找到)
	for (int i = 0; i < SIZE / 2; i++)
	{

		k = rand() % 100;
		printf("查找关键字为[%d]的元素\n", k);
		j = Find(h, k, &p);
		if (j == SUCCESS)
			print(p, h.elem[p]);
		else
			printf("无该元素\n");
	}


	return 0;
}
