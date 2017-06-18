#include <stdio.h>
#include "Hash.h"
int main() {
	srand(time(NULL));
	HashTable H;
	InitHashTable(&H);
	CreateHashTable(&H);
	PrintHashTable(H);
	_Search(H);
	RecreateHashTable(&H);
	PrintHashTable(H);
	return 0;
}