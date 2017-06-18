#include"Sort.h"
int main()
{
	RecordType r[11];
	RecordType temp[11];
	srand(time(0));
	temp[0] = 0;
	for (int i = 1; i < 11; i++)
	{
		temp[i] = rand() % 100;
	}
	int a, b;
	int *CpNumber, *MovNumber;
	CpNumber = &a; MovNumber = &b;
	printf("序列：\n");
	Print(temp, 10);
	Copy(r, temp,10);
	printf("\n插入排序：\n");
	InsSort(r, 10,CpNumber,MovNumber);
	printf("比较次数：%d，移动次数：%d\n\n", (*CpNumber), (*MovNumber));
	Copy(r, temp, 10);
	printf("希尔排序：\n");
	ShellSort(r, 10, CpNumber, MovNumber);
	printf("比较次数：%d，移动次数：%d\n\n", (*CpNumber), (*MovNumber));
	Copy(r, temp, 10);
	printf("冒泡排序：\n");
	BubbleSort(r, 10, CpNumber, MovNumber);
	printf("比较次数：%d，移动次数：%d\n\n", (*CpNumber), (*MovNumber));
	Copy(r, temp, 10);
	*CpNumber = 0; *MovNumber = 0;
	printf("快速排序：\n");
	QKSort(r, 1, 10, CpNumber, MovNumber);
	Print(r, 10);
	printf("比较次数：%d，移动次数：%d\n\n", (*CpNumber), (*MovNumber));
	Copy(r, temp, 10);
	printf("简单选择排序：\n");
	SelectSort(r, 10, CpNumber, MovNumber);
	printf("比较次数：%d，移动次数：%d\n\n", (*CpNumber), (*MovNumber));



	
	
	


}