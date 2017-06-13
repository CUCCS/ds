#include "Sort.h"
int  main() {

	SqList s;

	printf("\n---------------------------------");
	printf("\n1.ºÚµ•≤Â»Î≈≈–Ú\n");
	CreatArray(&s);
	InsertSort(&s);

	printf("---------------------------------");
	printf("\n2.øÏÀŸ≈≈–Ú\n");
	CreatArray(&s);
	QuickSort(&s);

	printf("---------------------------------");
	printf("\n3.ºÚµ•—°‘Ò≈≈–Ú\n");
	CreatArray(&s);
	SelectSort(&s);

	printf("---------------------------------");
	printf("\n4.√∞≈›≈≈–Ú\n");
	CreatArray(&s);
	BubbleSort(&s);

	printf("---------------------------------");
	printf("\n5.œ£∂˚≈≈–Ú\n");
	CreatArray(&s);
	ShellSort(&s);

	return 0;
}