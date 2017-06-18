#include "Hash.h"



int main() {
    int i, j, result;
    Hash_Table hashTable;
    int number1 = 0, number2 = 0, number3 = 0;
    srand(time(NULL));
    int HASHSIZE = rand() % 5 + 13; // 定义散列表长为数组的长度
    ValueType value[HASHSIZE];
    KeyType key[HASHSIZE];
    int seed = rand() % 3 + 6;
    int test[seed];//测试查找用例
    for (j = 0; j < HASHSIZE; j++) {
        value[j] = rand() % 3 + 7 + number1;
        number1++;
    }
    for (j = 0; j < HASHSIZE; j++) {
        key[j] = rand() % 6 + 23 + number2;
        number2 = number2 + 3;
        
    }
    for (j = 0; j < seed; j++) {
        test[j] = rand() % 5 + 28 + number3;
        number3++;
    }
    Init(&hashTable, HASHSIZE);//初始化哈希表
    for (i = 0; i < HASHSIZE; i++) {
        Insert(&hashTable, key[i], value[i]);//插入数据
    }
    Display(&hashTable);
    printf("\n------------测试查找用例-----------\n");
    for (j = 0; j < seed; j++) {
        printf("[%d] ", test[j]);
    }
    printf("\n------------测试查找用例-----------\n");
    for (j = 0; j < seed; j++) {
        result = Search(&hashTable, test[j]);//查找数据
        if (result == -1)
            printf("没有找到！\n");
        else printf("关键字为[%d]的值在哈希表中的位置是:[%d]\n", test[j], result);
    }
    
    return 0;
}
