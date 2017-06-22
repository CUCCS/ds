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

	printf("��ʼ��������Ϊ:\n");
	Traverse(a);
	printf("�����������Ϊ:\n");
	Traverse(test);

	InsertSort(&test, &comparetimes, &movetimes);
	printf("\n����ֱ�Ӳ�������������:\n");
	Traverse(test);
	printf("�ܱȽϴ���Ϊ:%d\n���ƶ���¼����:%d\n���ߴ���֮��:%d\n", comparetimes, movetimes, comparetimes + movetimes);

	InitTestArrary(&a, &test, &comparetimes, &movetimes);

	dk = 4;
	ShellInsert(&test, dk, &comparetimes, &movetimes);
	dk = 6;
	ShellInsert(&test, dk, &comparetimes, &movetimes);
	InsertSort(&test, &comparetimes, &movetimes);
	printf("����ϣ������������:\n");
	Traverse(test);
	printf("�ܱȽϴ���Ϊ:%d\n���ƶ���¼����:%d\n���ߴ���֮��:%d\n", comparetimes, movetimes, comparetimes + movetimes);

	InitTestArrary(&a, &test, &comparetimes, &movetimes);

	BubbleSort(&test, &comparetimes, &movetimes);
	printf("������������������:\n");
	Traverse(test);
	printf("�ܱȽϴ���Ϊ:%d\n���ƶ���¼����:%d\n���ߴ���֮��:%d\n", comparetimes, movetimes, comparetimes + movetimes);

	InitTestArrary(&a, &test, &comparetimes, &movetimes);

	QKSort(&test, 0, 19, &comparetimes, &movetimes);
	printf("������������������:\n");
	Traverse(test);
	printf("�ܱȽϴ���Ϊ:%d\n���ƶ���¼����:%d\n���ߴ���֮��:%d\n", comparetimes, movetimes, comparetimes + movetimes);

	InitTestArrary(&a, &test, &comparetimes, &movetimes);

	SelectSort(&test, &comparetimes, &movetimes);
	printf("������ѡ������������:\n");
	Traverse(test);
	printf("�ܱȽϴ���Ϊ:%d\n���ƶ���¼����:%d\n���ߴ���֮��:%d\n", comparetimes, movetimes, comparetimes + movetimes);
	return 0;
}