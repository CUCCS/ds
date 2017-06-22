#include"hash.h"

int main()
{
	srand(time(0));
	ElemType* r = Inputs(SIZE);
	HashTable h;
	int i, j, p;
	KeyType k=0;

	InitHashTable(&h);
	for (i = 0; i<SIZE ; i++)
	{
		j = InsertHash(&h, r[i]);
		if (j == DUPLICATE)
			printf("�������йؼ���Ϊ%d�ļ�¼���޷��ٲ����¼(%d,%d)\n",
			r[i].key, r[i].key, r[i].val);
	}
	printf("����ϣ��ַ��˳�������ϣ��:\n");
	TraverseHash(h, print);

	//����Ԫ��(���Ѵ洢�Ĺؼ�������� һ�����ҵ�)
	for (int i = 0; i < SIZE/2; i++)
	{

		k = r[rand() % SIZE].key;
		printf("���ҹؼ���Ϊ[%d]��Ԫ��\n", k);
		j = Find(h, k, &p);
		if (j == SUCCESS)
			print(p, h.elem[p]);
		else
			printf("�޸�Ԫ��\n");
	}
	//����Ԫ��(�ڹؼ��ַ�Χ����� ��һ�����ҵ�)
	for (int i = 0; i < SIZE / 2; i++)
	{

		k = rand() % 100;
		printf("���ҹؼ���Ϊ[%d]��Ԫ��\n", k);
		j = Find(h, k, &p);
		if (j == SUCCESS)
			print(p, h.elem[p]);
		else
			printf("�޸�Ԫ��\n");
	}


	return 0;
}
