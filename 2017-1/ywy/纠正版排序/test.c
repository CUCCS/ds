#include"Sort.h"

//#include"Sort.c"

int main()

{

	SqList L, L1, L2, L3, L4;

	L.length = len;

	int i = 0;

	srand((unsigned)time(NULL));

	for (i = 1; i <= len; i++)

	{

		L.r[i].key =rand()%15;

	}

	printf("\n原序：");

	for (i = 1; i<L.length; i++)

	{

		printf("%d ", L.r[i].key);

	}

	printf("\n\n");

	L1 = L2 = L3 = L4 = L;

	BubbleSort(&L);

	InsertSort(&L1);

	QuickSort(&L2);

	SelectSort(&L3);

	ShellSort(&L4);

	return 0;

}