#include "Sort.h"

int main()
{
	int compare, move, length;
	RecordType *test; // �����ٵ�����

	srand(time(NULL)); // �������

	if (!(length = CreateTest(&test))) {
		return 1; // ���ٿռ�ʧ��
	}

	compare = move = 0; // ��ʼ���Ƚϴ������ƶ�����
	Sort(&test, length, &compare, &move); // ���ø������򷽷�

	return 0;
}