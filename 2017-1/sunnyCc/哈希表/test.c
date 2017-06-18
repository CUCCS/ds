#include "Hash.h"
int main()
{
	int i;
	srand((int)time(NULL));
	HashTable  hash = newtable(MAXLEN);//��ʼ����ϣ��

	ElemType* testInputs = (ElemType*)malloc(SIZE * sizeof(ElemType));//������ɲ�������
	for (i = 0; i < SIZE; ++i) {
		testInputs[i] = newElemType(rand() % 100, rand() % 100);
	}

	for (i = 0; i < SIZE; ++i)//�����ɵĲ������ݲ����ϣ��
	{
		Insert(hash, testInputs[i]);
	}
	printf("ShowHashTable\n\n");
	ShowHashTable(hash);
	printf("\n");
	for (i = 0; i < SIZE / 2; ++i)//�������Hash���еĲ���Ԫ�عؼ���
	{
		Find(hash, testInputs[rand() % SIZE].key);
	}
	for (int i = 0; i < SIZE / 2; ++i) //����������ɹؼ���
	{
		int num = rand() % 100;
		Find(hash, num);
	}
	hash = Rebuild(hash);
	printf("ShowHashTable\n\n");
	ShowHashTable(hash);
	printf("\n");
	return 0;
}
