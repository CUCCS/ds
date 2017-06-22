#include "Hash.h"
HashTable newtable(int size)//��ʼ����ϣ�����йؼ���ȡֵΪ-1����Ϊ������λ��δ�洢Ԫ�ء� 
{
	HashTable temp;
	temp.size = size;
	temp.used = 0;
	temp.elements = (ElemType*)malloc(size * sizeof(ElemType));
	for (int i = 0; i < size; ++i) {
		temp.elements[i].key = INVALID_KEY;
		temp.elements[i].val = INVALID_VALUE;
	}
	return temp;
}
ElemType newElemType(KeyType key, ValueType value) {
	ElemType temp = { key,value };
	return temp;
}
bool isFull(HashTable table)//�жϹ�ϣ���Ƿ���
{
	return table.used == table.size;
}

void ShowHashTable(HashTable table)//��ӡ��ϣ��
{
	for (int i = 0; i < table.size; ++i) {
		printf("{ [%d] : %d->%d }\n", i, table.elements[i].key, table.elements[i].val);
	}
}
bool isPrime(int n)//�ж�һ�����Ƿ�������
{
	for (int i = 2; i < n; ++i) {
		if (n%i == 0) return false;
	}
	return true;
}
int FindPrime(HashTable table)//�ҵ�����Ҫ�������
{
	int p = table.size;
	if (p == 1) {
		return 1;
	}
	else {
		for (p = table.size; !isPrime(p); p--);
	}
	return p + 1;
}


void Insert(HashTable table, ElemType n)//��n�����ϣ��
{
	printf("Inserting: { %d -> %d }\n", n.key, n.val);
	if (isFull(table))//�жϹ�ϣ���Ƿ����� 
	{
		printf("Error : full hash table to insert\n");
		printf("--------------------------\n");
		return;
	}
	int p = FindPrime(table);//�ҵ�һ������
	int pos = n.key % p;//��ֵ/pȷ��Ԫ�ط����ϣ���ʼλ��
	int count = 0;//��ͻ����
	while (table.elements[pos].key != INVALID_KEY) //�����λ�ò�Ϊ�գ��������ǰѰ��λ�ã���ͻ������������
	{
		count += 1;
		++pos;
		pos %= table.size;
	}
	if (count) {
		printf("collisionTime(s):  %d  \n", count);
	}
	table.elements[pos] = n;
	table.used += 1;
	printf("Position: %d  { %d ->%d }\n", pos, n.key, n.val);

	printf("--------------------------\n");
}
int Find(HashTable table, KeyType n)//����n�Ƿ���Hash���� 
{
	printf("Finding: %d \n", n);
	int p = FindPrime(table);
	int pos = n % p;//������ؼ�������ڱ��еĳ�ʼλ��
	int count = 0;

	while (table.elements[pos].key != n)//���������Ĺؼ�λ��û�����Ԫ��
	{

		if (table.elements[pos].key == INVALID_KEY)// �����λ����ֵΪ��-1��
		{
			printf(" %d is not in the table\n", n);//��˵���ؼ��ֲ��ڱ���
			printf("--------------------------\n");
			return -1;
		}
		count += 1;//��ͻ������һ
		++pos;
		pos %= table.size;
	}
	if (count) {
		printf("collisionTime(s):  %d  \n", count);
	}
	printf("Finding the %d at position: %d  \n", n, pos);

	printf("--------------------------\n");
	return pos;
}
HashTable Rebuild(HashTable openHash) {
	printf("Rebuilding HashTabe\n");
	int size = 2 * openHash.size;
	HashTable temp = newtable(size);
	for (int i = 0; i < openHash.size; ++i) {
		if (openHash.elements[i].key != INVALID_KEY) {
			Insert(temp, openHash.elements[i]);
		}
	}
	free(openHash.elements);
	return temp;
}