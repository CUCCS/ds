#include "Hash.h"

int main()
{
	int size, i;
	int p, c;
	HashTable H;
	ElemType e;

	srand(time(NULL)); // �������

	do {
		size = (int)rand() % 11 + 20; // ������ϣ����С��20~30֮��
	} while (!Prime(size));

	CreateHash(&H, size);
	Print(H);

	p = c = 0;
	printf("==========Searching==========\n");
	for (i = 0; i < H.sizeindex; i++) {
		e.key = (int)rand() % 501;
		printf("Search : %d\n", e.key);
		if (SearchHash(H, e.key, &p, &c) == SUCCESS) {
			printf("Find %d\n", e.key);
			printf("The Element Is : %d->%d\n", H.elem[p].key, H.elem[p].val);
			printf("--------------------------\n");
		}
		else {
			printf("Didn't Find %d\n", e.key);
			printf("--------------------------\n");
		}
	}
	printf("Search Over\n\n");

	printf("==========Rebuild HashTable==========\n");
	if (!RecreateHashTable(&H)) {
		printf("Rebuild Over\n");
		Print(H);
	}

	return 0;
}