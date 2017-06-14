#include "Sort.h"
int  main() {

	SqList s;

	printf("\n---------------------------------");
	printf("\n1.InsertSort\n");
	CreatArray(&s);
	InsertSort(&s);

	printf("---------------------------------");
	printf("\n2.QuickSort\n");
	CreatArray(&s);
	QuickSort(&s);

	printf("---------------------------------");
	printf("\n3.SelectSort\n");
	CreatArray(&s);
	SelectSort(&s);

	printf("---------------------------------");
	printf("\n4.BubbleSort\n");
	CreatArray(&s);
	BubbleSort(&s);

	printf("---------------------------------");
	printf("\n5.ShellSort\n");
	CreatArray(&s);
	ShellSort(&s);

	return 0;
}