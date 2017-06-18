#include "Hash.h"

int main()
{
	HashTable h;
	ElemType e;
	int num = 0;//随机生成表长;
	int numble = 0;//随机生成初始填充表数个数;
	int i;
	srand(time(0));
	num = rand() % 5 + 10;
	numble = rand() % 5 + 5;
	InitHashTable(&h, num);
	printf("随机生成哈希表表长： %d\n", num);
	printf("随机生成填充数据个数：%d\n", numble);
	for (i = 0; i < numble; i++)
	{
		e.key = rand() % 20 + 1;
		e.val = rand() % 20 + 1;
		printf("key:%d     val:%d\n", e.key, e.val);
		InsertHash(&h, e);
	}
	for (i = 0; i < num; i++)
	{
		printf("{[%d]:%d->%d} ", i, h.elem[i]);
	}
	int p = getP(num);

	for (i = 0; i < 10; i++)
	{
		int c = 0;
		e.key = rand() % 20 + 1;
		e.val = rand() % 20 + 1;
		int q = Hash(e.key, p);
		printf("\n查找： key:%d     val:%d\n", e.key, e.val);
		if (1 == SearchHash(h, e.key, &q, &c, p))
		{
			printf("查找成功  ");
		}
		else
		{
			printf("查找失败  ");
		}
		printf("冲突次数：%d\n", c);
	}
}