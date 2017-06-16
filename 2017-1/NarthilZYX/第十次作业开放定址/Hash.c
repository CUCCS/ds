#include "Hash.h"

//质数判断函数
Bool isPrime( int num )
{
	for (int i = 2; i < num; ++i) {
		if (num % i == 0) 
			return False;
	}
	return True;
}
//除数获取函数
int getPrime( HashTable h )
{
	int p = h.sizeindex;
	if(p==1)
		return 1;
	while(!isPrime(p--));
	return p+1;
}

//哈希表是否为空及是否已满的判断函数
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

//新建哈希表及数据
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
//重建哈希表
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
	//在开放定址哈希表ha中查找关键码为k的元素，若查找成功，
	//以p指示待查数据元素在表中位置，并返回OK，否则，以p
	//指示其插入位置，并返回ERROR，collision用以计冲突次数，其初值置零，供建表插入时参考
    int i = 0;
	int p = getPrime(h);
	int pos = k % p;
	int collision = 0;
	while (h.elem[i].key!=NULLKEY && h.elem[pos].key!=k)
		//该位置中填有记录且关键字不相等
    {
        i++; //采用线性探查法找下一个地址
        collision++;
		++pos;
		pos = pos % h.sizeindex;
    }
    if(collision)
		printf("在冲突 %d 次之后，", collision);
	printf("于 %d 处找到关键字 %d \n", pos, k);
	return OK;
}

//删除哈希表中关键字k
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
		printf("在冲突 %d 次之后，", collision);
	printf("于 %d 处找到元素{ %d ->%d }并删除 %d \n", pos, elem.key, elem.val);
    return OK;
}

//将关键字k插入到哈希表中
void InsertHT(HashTable ha, ElemType k ){
    int i;
	int p = getPrime(ha);
    int pos = k.key % p;
	int collision = 0;
    if (ha.elem[pos].key==NULLKEY || ha.elem[pos].key==DELKEY)  //x[j]可以直接放在哈希表中
    {
        ha.elem[pos] = k;
        ha.count+=1;
    } 
    else      //发生冲突时,采用线性探查法解决冲突
    {
        i=1;  //i记录x[j]发生冲突的次数
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
		printf("冲突 %d 次后,", collision);
	}
	printf("在 %d 位置插入了元素{ %d -> %d} \n", pos, k.key, k.val );
}

//输出哈希表
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
	
	printf("查找：\n");
	for (int i = 0; i < 6/2; ++i) {
		SearchHashTable(ha, testInputs[rand()%6].key);
	}
	for (int i = 0; i < 6/2; ++i) {
		SearchHashTable(ha,rand()%100);
	}

	ha = rebuildHashTable(ha);
    printHashTable(ha);
}