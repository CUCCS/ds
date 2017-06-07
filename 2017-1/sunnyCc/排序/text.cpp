#include "Sort.cpp"
int  main() {
	int i, k, num;
	srand((unsigned)time(NULL));
	SqList s;
	printf("随机生成10个序列中的元素：\n");
	for (i = 1; i <= LENGTH; i++)
	{
		s.r[i].key = rand() % 101;  //产生0-100的随机数	
	}
	s.length = i - 1;
	for (i = 1; i <= LENGTH; i++)
	{
		printf("%d ", s.r[i].key);
	}
	printf("\n---------------------------------");
	printf("\n1.简单插入排序\n");
	InsertSort(&s);
	printf("---------------------------------");
	printf("\n2.快速排序\n");
	QuickSort(&s);
	printf("---------------------------------");
	printf("\n3.简单选择排序\n");
	SelectSort(&s);
	printf("---------------------------------");
	printf("\n4.冒泡排序\n");
	BubbleSort(&s);
	printf("---------------------------------");
	printf("\n5.希尔排序\n");
	ShellSort(&s);
	return 0;
}


