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
	printf("���У�\n");
	Print(temp, 10);
	Copy(r, temp,10);
	printf("\n��������\n");
	InsSort(r, 10,CpNumber,MovNumber);
	printf("�Ƚϴ�����%d���ƶ�������%d\n\n", (*CpNumber), (*MovNumber));
	Copy(r, temp, 10);
	printf("ϣ������\n");
	ShellSort(r, 10, CpNumber, MovNumber);
	printf("�Ƚϴ�����%d���ƶ�������%d\n\n", (*CpNumber), (*MovNumber));
	Copy(r, temp, 10);
	printf("ð������\n");
	BubbleSort(r, 10, CpNumber, MovNumber);
	printf("�Ƚϴ�����%d���ƶ�������%d\n\n", (*CpNumber), (*MovNumber));
	Copy(r, temp, 10);
	*CpNumber = 0; *MovNumber = 0;
	printf("��������\n");
	QKSort(r, 1, 10, CpNumber, MovNumber);
	Print(r, 10);
	printf("�Ƚϴ�����%d���ƶ�������%d\n\n", (*CpNumber), (*MovNumber));
	Copy(r, temp, 10);
	printf("��ѡ������\n");
	SelectSort(r, 10, CpNumber, MovNumber);
	printf("�Ƚϴ�����%d���ƶ�������%d\n\n", (*CpNumber), (*MovNumber));



	
	
	


}