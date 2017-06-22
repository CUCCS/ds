#include "Sort.h"

int main() {
	SqList a, test;
	int i;
	int comparetimes = 0, movetimes = 0;
	int dk;

	srand((unsigned)time(NULL));
	a.length = test.length = 0;
	for (i = 0; i < MAXSIZE; ++i) {
		a.r[i] = test.r[i] = rand() % 100 + 1;
		a.length++;
		test.length++;
	}

	printf("初始化的数组为:\n");
	Traverse(a);
	printf("待排序的数组为:\n");
	Traverse(test);

	InsertSort(&test, &comparetimes, &movetimes);
	printf("\n经过直接插入排序后的数组:\n");
	Traverse(test);
	printf("总比较次数为:%d\n总移动记录次数:%d\n两者次数之和:%d\n", comparetimes, movetimes, comparetimes + movetimes);

	InitTestArrary(&a, &test, &comparetimes, &movetimes);

	dk = 4;
	ShellInsert(&test, dk, &comparetimes, &movetimes);
	dk = 6;
	ShellInsert(&test, dk, &comparetimes, &movetimes);
	InsertSort(&test, &comparetimes, &movetimes);
	printf("经过希尔排序后的数组:\n");
	Traverse(test);
	printf("总比较次数为:%d\n总移动记录次数:%d\n两者次数之和:%d\n", comparetimes, movetimes, comparetimes + movetimes);

	InitTestArrary(&a, &test, &comparetimes, &movetimes);

	BubbleSort(&test, &comparetimes, &movetimes);
	printf("经过气泡排序后的数组:\n");
	Traverse(test);
	printf("总比较次数为:%d\n总移动记录次数:%d\n两者次数之和:%d\n", comparetimes, movetimes, comparetimes + movetimes);

	InitTestArrary(&a, &test, &comparetimes, &movetimes);

	QKSort(&test, 0, 19, &comparetimes, &movetimes);
	printf("经过快速排序后的数组:\n");
	Traverse(test);
	printf("总比较次数为:%d\n总移动记录次数:%d\n两者次数之和:%d\n", comparetimes, movetimes, comparetimes + movetimes);

	InitTestArrary(&a, &test, &comparetimes, &movetimes);

	SelectSort(&test, &comparetimes, &movetimes);
	printf("经过简单选择排序后的数组:\n");
	Traverse(test);
	printf("总比较次数为:%d\n总移动记录次数:%d\n两者次数之和:%d\n", comparetimes, movetimes, comparetimes + movetimes);
	return 0;
}