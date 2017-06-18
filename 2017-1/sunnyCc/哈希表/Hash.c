#include "Hash.h"
HashTable newtable(int size)//初始化哈希表，其中关键字取值为-1定义为该索引位置未存储元素。 
{
	HashTable temp;
	temp.size = size;
	temp.used = 0;
	temp.elements = (ElemType*)malloc(size * sizeof(ElemType));
	for (int i = 0; i < size; ++i) {
		temp.elements[i].key = INVALID_KEY;
		temp.elements[i].val = INVALID_VALUE;
	}
	return temp;
}
ElemType newElemType(KeyType key, ValueType value) {
	ElemType temp = { key,value };
	return temp;
}
bool isFull(HashTable table)//判断哈希表是否满
{
	return table.used == table.size;
}

void ShowHashTable(HashTable table)//打印哈希表
{
	for (int i = 0; i < table.size; ++i) {
		printf("{ [%d] : %d->%d }\n", i, table.elements[i].key, table.elements[i].val);
	}
}
bool isPrime(int n)//判断一个数是否是素数
{
	for (int i = 2; i < n; ++i) {
		if (n%i == 0) return false;
	}
	return true;
}
int FindPrime(HashTable table)//找到符合要求的素数
{
	int p = table.size;
	if (p == 1) {
		return 1;
	}
	else {
		for (p = table.size; !isPrime(p); p--);
	}
	return p + 1;
}


void Insert(HashTable table, ElemType n)//将n插入哈希表
{
	printf("Inserting: { %d -> %d }\n", n.key, n.val);
	if (isFull(table))//判断哈希表是否已满 
	{
		printf("Error : full hash table to insert\n");
		printf("--------------------------\n");
		return;
	}
	int p = FindPrime(table);//找到一个素数
	int pos = n.key % p;//用值/p确定元素放入哈希表初始位置
	int count = 0;//冲突次数
	while (table.elements[pos].key != INVALID_KEY) //如果此位置不为空，则继续向前寻找位置，冲突次数依次增加
	{
		count += 1;
		++pos;
		pos %= table.size;
	}
	if (count) {
		printf("collisionTime(s):  %d  \n", count);
	}
	table.elements[pos] = n;
	table.used += 1;
	printf("Position: %d  { %d ->%d }\n", pos, n.key, n.val);

	printf("--------------------------\n");
}
int Find(HashTable table, KeyType n)//查找n是否在Hash表中 
{
	printf("Finding: %d \n", n);
	int p = FindPrime(table);
	int pos = n % p;//计算出关键字如果在表中的初始位置
	int count = 0;

	while (table.elements[pos].key != n)//如果计算出的关键位置没有这个元素
	{

		if (table.elements[pos].key == INVALID_KEY)// 且这个位置上值为“-1”
		{
			printf(" %d is not in the table\n", n);//就说明关键字不在表中
			printf("--------------------------\n");
			return -1;
		}
		count += 1;//冲突次数加一
		++pos;
		pos %= table.size;
	}
	if (count) {
		printf("collisionTime(s):  %d  \n", count);
	}
	printf("Finding the %d at position: %d  \n", n, pos);

	printf("--------------------------\n");
	return pos;
}
HashTable Rebuild(HashTable openHash) {
	printf("Rebuilding HashTabe\n");
	int size = 2 * openHash.size;
	HashTable temp = newtable(size);
	for (int i = 0; i < openHash.size; ++i) {
		if (openHash.elements[i].key != INVALID_KEY) {
			Insert(temp, openHash.elements[i]);
		}
	}
	free(openHash.elements);
	return temp;
}