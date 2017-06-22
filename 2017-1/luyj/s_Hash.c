#include "Hash.h"

int main()
{
	HashTable h;
	ElemType e;
	int num = 0;//������ɱ�;
	int numble = 0;//������ɳ�ʼ����������;
	int i;
	srand(time(0));
	num = rand() % 5 + 10;
	numble = rand() % 5 + 5;
	InitHashTable(&h, num);
	printf("������ɹ�ϣ����� %d\n", num);
	printf("�������������ݸ�����%d\n", numble);
	for (i = 0; i < numble; i++)
	{
		e.key = rand() % 20 + 1;
		e.val = rand() % 20 + 1;
		printf("key:%d     val:%d\n", e.key, e.val);
		InsertHash(&h, e);
	}
	for (i = 0; i < num; i++)
	{
		printf("{[%d]:%d->%d} ", i, h.elem[i]);
	}
	int p = getP(num);

	for (i = 0; i < 10; i++)
	{
		int c = 0;
		e.key = rand() % 20 + 1;
		e.val = rand() % 20 + 1;
		int q = Hash(e.key, p);
		printf("\n���ң� key:%d     val:%d\n", e.key, e.val);
		if (1 == SearchHash(h, e.key, &q, &c, p))
		{
			printf("���ҳɹ�  ");
		}
		else
		{
			printf("����ʧ��  ");
		}
		printf("��ͻ������%d\n", c);
	}
}