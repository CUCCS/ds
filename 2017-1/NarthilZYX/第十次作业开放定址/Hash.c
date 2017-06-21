#include "Hash.h"

//�����жϺ���
Bool isPrime( int num )
{
	for (int i = 2; i < num; ++i) {
		if (num % i == 0) 
			return False;
	}
	return True;
}
//������ȡ����
int getPrime( HashTable h )
{
	int p = h.sizeindex;
	if(p==1)
		return 1;
	while(!isPrime(p--));
	return p+1;
}

//��ϣ���Ƿ�Ϊ�ռ��Ƿ��������жϺ���
Bool isEmpty( HashTable h )
{
	if(h.count == 0)
		return True;
	return False;
}
Bool isFull ( HashTable h )
{
	if(h.count == h.sizeindex)
		return True;
	return False;
}

//�½���ϣ������
HashTable createHashTable( int sizeindex )
{
	HashTable temp;
	temp.count = 0;
	temp.sizeindex = sizeindex;
	temp.elem = (ElemType *)malloc(sizeindex * sizeof(ElemType));
	for( int i = 0; i < sizeindex; i++)
	{
		temp.elem[i].key = EMPTYKEY;
		temp.elem[i].val = EMPTYVALUE;
	}
	return temp;
}
ElemType newElemType( KeyType key, ValueType value )
{
	ElemType temp;
	temp.key = key;
	temp.val = value;
	return temp;
}
//�ؽ���ϣ��
HashTable rebuildHashTable( HashTable h )
{
	int sizeindex = 2 * h.sizeindex;
	HashTable temp = createHashTable( sizeindex );
    for( int i = 0; i < sizeindex; i++)
	{
		if(h.elem[i].key != EMPTYKEY && h.elem[i].key != NULLKEY)
			InsertHT(temp, h.elem[i]);
	}
	free(h.elem);
	return temp;
}

Status SearchHashTable( HashTable h,KeyType k ){
	//�ڿ��Ŷ�ַ��ϣ��ha�в��ҹؼ���Ϊk��Ԫ�أ������ҳɹ���
	//��pָʾ��������Ԫ���ڱ���λ�ã�������OK��������p
	//ָʾ�����λ�ã�������ERROR��collision���ԼƳ�ͻ���������ֵ���㣬���������ʱ�ο�
    int i = 0;
	int p = getPrime(h);
	int pos = k % p;
	int collision = 0;
	while (h.elem[i].key!=NULLKEY && h.elem[pos].key!=k)
		//��λ�������м�¼�ҹؼ��ֲ����
    {
        i++; //��������̽�鷨����һ����ַ
        collision++;
		++pos;
		pos = pos % h.sizeindex;
    }
    if(collision)
		printf("�ڳ�ͻ %d ��֮��", collision);
	printf("�� %d ���ҵ��ؼ��� %d \n", pos, k);
	return OK;
}

//ɾ����ϣ���йؼ���k
int DeleteHT(HashTable ha, ElemType elem){
	int p = getPrime(ha);
	int pos = elem.key %p;
	int collision = 0;
	while(ha.elem[pos].key != elem.key)
	{
		collision++;
		++pos;
		pos = pos % ha.sizeindex;
	}
	ha.elem[pos] = newElemType(DELKEY, DELVAL);
	ha.count -= 1;
	if(collision)
		printf("�ڳ�ͻ %d ��֮��", collision);
	printf("�� %d ���ҵ�Ԫ��{ %d ->%d }��ɾ�� %d \n", pos, elem.key, elem.val);
    return OK;
}

//���ؼ���k���뵽��ϣ����
void InsertHT(HashTable ha, ElemType k ){
    int i;
	int p = getPrime(ha);
    int pos = k.key % p;
	int collision = 0;
    if (ha.elem[pos].key==NULLKEY || ha.elem[pos].key==DELKEY)  //x[j]����ֱ�ӷ��ڹ�ϣ����
    {
        ha.elem[pos] = k;
        ha.count+=1;
    } 
    else      //������ͻʱ,��������̽�鷨�����ͻ
    {
        i=1;  //i��¼x[j]������ͻ�Ĵ���
        do 
        {
            pos = (pos+1)%p;
            i++;
        } while (ha.elem[pos].key!=NULLKEY && ha.elem[pos].key!=DELKEY);
        ha.elem[pos]=k;
        ha.count+=1;
		collision++;
    }
    if (collision) {
		printf("��ͻ %d �κ�,", collision);
	}
	printf("�� %d λ�ò�����Ԫ��{ %d -> %d} \n", pos, k.key, k.val );
}

//�����ϣ��
void printHashTable(HashTable ha){
	for (int i = 0; i < ha.sizeindex; ++i) {
		printf("{ [%d] : %d->%d }\n", i, ha.elem[i].key, ha.elem[i].val);
	}
}


int main()
{
	srand(time(NULL));
	HashTable ha = createHashTable(10);

	ElemType* testInputs;
	testInputs = (ElemType *)malloc(6 * sizeof(ElemType));
	for(int i = 0; i < 6; i++)
	{
		testInputs[i] = newElemType(rand() % 100, rand() % 100);
	}
	
	for (int i = 0; i < 6; ++i) {
		InsertHT(ha,testInputs[i]);
	}
	printHashTable(ha);
	
	printf("���ң�\n");
	for (int i = 0; i < 6/2; ++i) {
		SearchHashTable(ha, testInputs[rand()%6].key);
	}
	for (int i = 0; i < 6/2; ++i) {
		SearchHashTable(ha,rand()%100);
	}

	ha = rebuildHashTable(ha);
    printHashTable(ha);
}