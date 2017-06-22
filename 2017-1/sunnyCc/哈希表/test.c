#include "Hash.h"
int main()
{
	int i;
	srand((int)time(NULL));
	HashTable  hash = newtable(MAXLEN);//初始化哈希表

	ElemType* testInputs = (ElemType*)malloc(SIZE * sizeof(ElemType));//随机生成测试数据
	for (i = 0; i < SIZE; ++i) {
		testInputs[i] = newElemType(rand() % 100, rand() % 100);
	}

	for (i = 0; i < SIZE; ++i)//将生成的测试数据插入哈希表
	{
		Insert(hash, testInputs[i]);
	}
	printf("ShowHashTable\n\n");
	ShowHashTable(hash);
	printf("\n");
	for (i = 0; i < SIZE / 2; ++i)//随机查找Hash表中的部分元素关键字
	{
		Find(hash, testInputs[rand() % SIZE].key);
	}
	for (int i = 0; i < SIZE / 2; ++i) //查找随机生成关键字
	{
		int num = rand() % 100;
		Find(hash, num);
	}
	hash = Rebuild(hash);
	printf("ShowHashTable\n\n");
	ShowHashTable(hash);
	printf("\n");
	return 0;
}
