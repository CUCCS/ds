#include "hash.h"

int main()
{
	ElemType r[N];
	for (int i = 0; i < N; i++)
	{
		r[i] = newElemType(rand() % 100, rand() % 100);
	}
	HashTable h;
	int i, p;
	int j;
	KeyType k;
	initHashTable(&h);
	for (i = 0; i < N - 1; i++)//����ǰN-1����¼
	{
		j = insertHash(&h, r[i]);
		printf("�Ѳ���Ԫ�أ�{%d��%d}\t", r[i].key, r[i].val);
		printf("��ͻ������%d\n", collisiontime);
		if (j == DUPLICATE)
			printf("�������йؼ���β%d�ļ�¼ �޷��ٲ����¼(%d %d)\n", r[i].key, r[i].key, r[i].val);
	}
	printf("\n����ϣ��ַ��˳�������ϣ��\n");
	traverseHash(h, printHash);
	printf("\n\n");

	int count = 5;
	while (count > 0)
	{
		printf("����ؼ���:");
		k = rand() % 100;
		j = find(h, k, &p);
		printf("%d\n", k);
		if (j == SUCCESS)
		{
			printf("��λ��%d�ҵ���Ԫ��", p);
			printHash(p, h.elem[p]);
		}
		else
			printf("û�ҵ�\n");
		k = 0;
		count--;
	}
	j = insertHash(&h, r[i]);//�����N����¼
	if (j == 0)//j==ERROR �ؽ���ϣ��
	{
		j = insertHash(&h, r[i]);//�ؽ���ϣ������²����N����¼
	}

	printf("����ϣ��ַ��˳������ؽ���Ĺ�ϣ��\n");
	traverseHash(h, printHash);
	printf("\n\n");

	destroyHashTable(&h);
	printf("��ϣ�����ٳɹ�!");
	printf("\n\n");

	return 0;
}