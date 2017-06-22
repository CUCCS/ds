//
//  main.c
//  hw10
//
//  Created by Huhongbo on 2017/6/14.
//  Copyright © 2017年 Huhongbo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int Status;
typedef int KeyType;
typedef int ValueType;
typedef struct _ElemType {
    KeyType key;      // 关键字
    ValueType val;    // 值
#ifdef CHAINED_HASH
    struct _ElemType *next;
#endif
} ElemType;
typedef struct
{
    ElemType *elem;
    int count;//当前元素个数
    int sizeindex;//哈希表表长
}HashTable;

static int m;
static int hashsize[] = { 11,19,29,37,49 };
int hashsize_count = 0;
int  hash_(KeyType e, int l);
Status RecreateHashTable(HashTable *H);
Status InsertHash(HashTable *H, KeyType e, ValueType v);
Status SearchHash(HashTable  H, KeyType e, ValueType v, int* p, int *c);
Status  InitHashTable(HashTable  *H);
void travel_(int *q, int l);
void TraverHash(HashTable  H);
void collision(int *p, int c, KeyType k, int l);

//制造数组
Status  make(int *q,int l)
{
    int temp;
    int length;
    int i;
    length = l;
    for (i = 0; i <length; i++)
    {
        do
        {
            temp = rand() % 100 + 1;
        } while (temp <= 0);
        q[i] = temp;
    }
    return length;
}
//打印出随机产生的数组
void travel_(int *q, int l)
{
    for (int i = 0; i < l; i++)
    {
        printf("%d   ", q[i]);
    }
    printf("\n");
}
//构造一个未存入数据的空哈希表
Status InitHashTable(HashTable *H)
{
    int i;
    (*H).count = 0; // 当前元素个数为0
    (*H).sizeindex = hashsize[hashsize_count]; // 初始存储容量为hashsize[0]
    m = (*H).sizeindex;
    H->elem = (ElemType*)malloc(m * sizeof(ElemType));
    if (!(*H).elem)
        exit(0);//return 0; // 存储分配失败
    for (i = 0; i < (*H).sizeindex; i++)
    {
        (*H).elem[i].key =-1; // 未填记录的标志
        (*H).elem[i].val = 0;
    }
    hashsize_count++;
    return 1;
}
//进行插入操作
Status InsertHash(HashTable *h, KeyType e, ValueType v)
{
    int c = 0;//用于计数冲突次数
    int   p;//用于返回插入的位置
    if (SearchHash(*h, e, v, &p, &c))
    {
        return -1;//如果已有该元素  返回
    }
    else if (c < h->sizeindex / 2)//冲突次数达到则进行扩表 c的值可调
    {
        (*h).elem[p].val = v;
        (*h).elem[p].key = e;
        ++(*h).count;
        return 1;//插入成功
    }
    else
    {//如果哈希表过于小
        printf("哈希表分配过小  重建表\n");
        RecreateHashTable(h);
        return 0;
    }
}
Status SearchHash(HashTable  h, KeyType e, ValueType v, int* p, int *c)
{//如果查找成功 p为所在的下标  否则p为待插入的位置
    *p = hash_(e, h.sizeindex);//返回下标
    while (h.elem[*p].key != -1 && v != h.elem[*p].val)
    {
        (*c)++;
        if ((*c) < h.sizeindex)
        {//如果冲突次数还能继续处理
            collision(p, *c,e,h.sizeindex);
        }
        else
        {
            break;
        }
    }
    if (v == h.elem[*p].val)
        return 1;
    else
        return 0;
}
int  hash_(KeyType e,int l)
{//除留余数法构造简单的哈希表
    int i = e%l;
    return i;
}
void collision(int *p,int c, KeyType k,int l)
{
    *p = (k + c) % l;//线性探索再散列：di = 1,2,3,...,m-1
}
//打印哈希表
void TraverHash(HashTable  h)
{
    for (int i = 0; i < h.sizeindex; i++)
    {
        printf("{[%d] : ",i);
        printf("%d->%d}  ",h.elem[i].key, h.elem[i].val);
    }
    printf("\n");
}
//重建哈希表
Status RecreateHashTable(HashTable *H)
{
    int i, count = (*H).sizeindex;//H中原有记录个数
    ElemType *p, *elem = (ElemType *)malloc(count * sizeof(ElemType));//动态生成存放哈希表H原有数据的空间
    p = elem;
    for (i = 0; i < (*H).sizeindex; ++i)
    {//将原有的所有记录，保存到elem中
        //*p++ = (*H).elem[i];//将记录依次存入elem
        p[i].key = (*H).elem[i].key;
        p[i].val = (*H).elem[i].val;
    }
    (*H).count = 0;//将原有记录数置为0，为下面调用InserHash做准备
    (*H).sizeindex = hashsize[hashsize_count];
    (*H).elem = (ElemType *)realloc((*H).elem, (*H).sizeindex * sizeof(ElemType));//以新的存储容量重新生成空哈希表H
    for (i = 0; i <(*H).sizeindex; ++i)
    {//初始化新的哈希表
        (*H).elem[i].key = -1;//未填记录
        (*H).elem[i].val = 0;
    }
    for (i=0;i<count;i++)
    {//将原表中的记录重新存储到新的哈希表中
        if (p[i].key != -1)
        {
            InsertHash(H, p[i].key, p[i].val);
        }
    }
    p = NULL;
    free(elem);//释放elem的存储空间
    hashsize_count++;//增加表长下标 为下一次重建做准备
    return 1;
}
int main()
{
    srand(time(0));
    int  list[9];
    int list_val[9];
    int search_list[6];
    int search_list_val[6] ;
    int search_list_length= 6;
    int i;
    make(list, hashsize[0]-2);//制造需要打印的数组 并返回长
    make(list_val, hashsize[0] - 2);//制造需要打印的数组 并返回长度
    make(search_list, search_list_length/2);
    make(search_list_val, search_list_length / 2);
    for (i = search_list_length / 2; i < search_list_length; i++)
    {
        search_list[i] = list[i];
        search_list_val[i] = list_val[i];
    }
    HashTable H;
    if (InitHashTable(&H)==0)
    {
        printf("初始化失败");
        exit(0);
    }
    for (i=0; i < hashsize[0] - 2; i++)
    {
        printf("插入 %d  关键字为%d\n", list_val[i], list[i]);
        InsertHash(&H, list[i], list_val[i]);
        if (0 == InsertHash(&H, list[i], list_val[i]))
        {//插入不成功
            InsertHash(&H, list[i], list_val[i]);
        }
    }
    printf("首次填充完的哈希表\n");
    TraverHash(H);
    for (i = 0; i < search_list_length; i++)
    {
        int p;
        int c=0;
        printf("查找 %d    关键字%d ", search_list_val[i], search_list[i]);
        if (SearchHash(H, search_list[i], search_list_val[i], &p, &c))
        {
            if (c != 0)
            {
                printf("        发生冲突的关键字是 %d", search_list[i]);
                printf("      发生冲突的次数是%d", c);
            }
            printf("    查找成功,位于%d       \n",p);
        }
        else
        {
            if (c != 0)
            {
                printf("        发生冲突的关键字是 %d", search_list[i]);
                printf("     发生冲突的次数是%d", c);
            }
            printf("    查找失败\n");
        }
    }
    printf("重建哈希表\n");
    RecreateHashTable(&H);
    TraverHash(H);
    free(H.elem);
    return 0;
}
