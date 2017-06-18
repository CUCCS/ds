#include "Hash.h"



Status Init(HashTable hashTable, int hashsize)//初始化散列表
{
    int i;
    Hash_size = hashsize;
    hashTable->elem = (ElemType *) malloc(Hash_size * sizeof(ElemType));
    hashTable->count = Hash_size;
    for (i = 0; i < Hash_size; i++) {
        hashTable->elem[i].key = nullval;
        hashTable->elem[i].val = nullval;
    }
    return OK;
}


Status Hash(int data)//获得哈希函数
{
    return data % Hash_size;
}


void Insert(HashTable hashTable, int hkey, int value)//插入关键字和相应的值
{
    int hashaddress = Hash(value); //求哈希地址
    int count = 0;//记录冲突次数
    while (hashTable->elem[hashaddress].key != nullval)//发生冲突
    {
        
        hashaddress = (++hashaddress) % Hash_size;//利用开放定址的线性探测法解决冲突
        count++;
    }
    
    
    hashTable->elem[hashaddress].key = hkey;
    hashTable->elem[hashaddress].val = value;
}

void Display(HashTable hashTable)//打印结果
{
    int i;
    printf("--Hashtable--\n");
    for (i = 0; i < hashTable->count; i++) {
        if (hashTable->elem[i].val == nullval) {
            printf("{[%d]:%d->%d}\n", i, -1, 0);
        }
        printf("{[%d]:%d->%d}\n", i, hashTable->elem[i].key, hashTable->elem[i].val);
    }
    
    printf("-------------\n");
}

Status Search(HashTable hashTable, int data)//查找
{
    int hashaddress = Hash(data);
    
    
    while (hashTable->elem[hashaddress].key != data) {
        
        hashaddress = (++hashaddress) % Hash_size;
        
        if (hashTable->elem[hashaddress].key == nullval || hashaddress == Hash(data))
            return -1;
    }
    
    
    return hashaddress;//查找成功
}

