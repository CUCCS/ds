#include "Sort.h"
int  main() {

	SqList s;

	printf("\n---------------------------------");
	printf("\n1.�򵥲�������\n");
	CreatArray(&s);
	InsertSort(&s);

	printf("---------------------------------");
	printf("\n2.��������\n");
	CreatArray(&s);
	QuickSort(&s);

	printf("---------------------------------");
	printf("\n3.��ѡ������\n");
	CreatArray(&s);
	SelectSort(&s);

	printf("---------------------------------");
	printf("\n4.ð������\n");
	CreatArray(&s);
	BubbleSort(&s);

	printf("---------------------------------");
	printf("\n5.ϣ������\n");
	CreatArray(&s);
	ShellSort(&s);

	return 0;
}