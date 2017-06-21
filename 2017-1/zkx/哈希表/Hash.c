#include "Hash.h"

ElemType InitElemType(KeyType key, ValueType value)
{
	ElemType e = { key,value };
	return e;
}

HashTable InitHash(int size)   //��ʼ��һ����ϣ�� 
{
	HashTable H;
	H.sizeindex = size;
	H.count = 0;
	H.elem = (ElemType*)malloc(size * sizeof(ElemType));
	for (int i = 0; i < size; i++)
	{
		H.elem[i].key = -1;
		H.elem[i].val = 0;
	}
	return H;
}

bool isPrime(int num)    //�ж�һ�����Ƿ�Ϊ���� 
{
	for (int i = 2; i < num; i++)
	{
		if (num%i == 0)
		{
			return false;
		}
		return true;
	}
}

int getPrimenumber(HashTable H)   //�ҵ����ʵ�С�ڱ�������n 
{
	int n;
	n = H.sizeindex;
	while (!isPrime(n))
	{
		n--;
	}
	return n;
}

void InsertHashTable(HashTable H, ElemType elem)
{
	DEBUG && printf("����Ԫ��{ %d -> %d }��", elem.key, elem.val);
	int n = getPrimenumber(H);
	int pos = elem.key % n;
	int collisionTimes = 0;
	while (H.elem[pos].key != -1)
	{
		collisionTimes+=1;
		pos++;
		pos %= H.sizeindex;
	}
	H.elem[pos] = elem;
	H.count++;
	DEBUG && printf("λ�� %d \n", pos, elem.key, elem.val);
}

int Find(HashTable H, KeyType key)
{
	DEBUG && printf("���ҹؼ��� %d ��", key);
	int n = getPrimenumber(H);
	int pos = key % n;
	int collisionTimes = 0;
	while (H.elem[pos].key != key)
	{
		if (H.elem[pos].key == -1)
		{
			DEBUG && printf("�ؼ��� %d ���ڱ���\n", key);
			return -1;
		}
		collisionTimes+=1;
		pos++;
		pos %= H.sizeindex;
	}
	DEBUG && printf("λ�� %d \n", pos);

	return pos;
}

void Print(HashTable H)
{
	printf("\n");
	for (int i = 0; i < H.sizeindex; ++i)
	{
		printf("{ [%d] : %d->%d } \t", i, H.elem[i].key, H.elem[i].val);
	}
	printf("\n\n");
}

void RecreateHashTable(HashTable *H)
{
	HashTable temp = InitHash(H->sizeindex * 2);
	int a = H->sizeindex;
	for (int i = 0; i <a; i++)
	{
		temp.elem[i] = H->elem[i];
	}
	H->sizeindex *= 2;
	H->elem = (ElemType*)malloc(H->sizeindex * sizeof(ElemType));
	for (int i = 0; i < H->sizeindex; i++)
	{
		H->elem[i].key = -1; H->elem[i].val = 0;
	}
	for (int i = 0; i < a; i++)
	{
		int p = temp.elem[i].key%getPrimenumber(*H);
		H->elem[p] = temp.elem[i];
	}
}

int main()
{
	srand(time(0));
	ElemType* inputs = (ElemType*)malloc(COUNT * sizeof(ElemType));
	for (int i = 0; i < COUNT; i++)
	{
		inputs[i] = InitElemType(rand() % 1024, rand() % 1024);
	}

	HashTable H = InitHash(SIZEINDEX);
	for (int i = 0; i < COUNT; ++i)
	{
		InsertHashTable(H, inputs[i]);
	}
	Print(H);
	for (int i = 0; i < COUNT / 2; ++i)
	{
		Find(H, inputs[rand() % COUNT].key);
	}

	printf("\n�ؽ���ϣ��\n");
	RecreateHashTable(&H);
	Print(H);
	return 0;

}
