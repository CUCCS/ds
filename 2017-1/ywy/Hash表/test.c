#include"Hash.h"
int main()

{
	int size;
	int i;
	KeyType key;
	HashTable H;
	size = 11;//
	srand((unsigned)time(NULL));
	
	InitHashTable(&H, size);
	PrintHash(H);
	int add = 0;
	int count = 0;
	for (i = 0; i < H.count; i++)
	{
		key = rand() % size;
		if(SearchHashTable(H,key,&add,&count)==SUCCESS)
		{
			printf("find %d  ", key);
			printf("address %d: \n", add);
		}
		else
		{
			printf("not find %d:  \n", key);
		}
	}
	return 0;
}