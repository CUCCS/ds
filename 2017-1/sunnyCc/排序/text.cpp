#include "Sort.cpp"
int  main() {
	int i, k, num;
	srand((unsigned)time(NULL));
	SqList s;
	printf("�������10�������е�Ԫ�أ�\n");
	for (i = 1; i <= LENGTH; i++)
	{
		s.r[i].key = rand() % 101;  //����0-100�������	
	}
	s.length = i - 1;
	for (i = 1; i <= LENGTH; i++)
	{
		printf("%d ", s.r[i].key);
	}
	printf("\n---------------------------------");
	printf("\n1.�򵥲�������\n");
	InsertSort(&s);
	printf("---------------------------------");
	printf("\n2.��������\n");
	QuickSort(&s);
	printf("---------------------------------");
	printf("\n3.��ѡ������\n");
	SelectSort(&s);
	printf("---------------------------------");
	printf("\n4.ð������\n");
	BubbleSort(&s);
	printf("---------------------------------");
	printf("\n5.ϣ������\n");
	ShellSort(&s);
	return 0;
}


