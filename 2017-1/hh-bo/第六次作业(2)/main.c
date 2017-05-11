//
//  main.c
//  6
//
//  Created by Huhongbo on 2017/5/10.
//  Copyright © 2017年 Huhongbo. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#define TelemType char
int count = 0;
int count1 = 0;
typedef struct BitNode
{
    TelemType data;
    struct BitNode *lchild, *rchild;
}BitNode;
typedef enum
{
    error, ok
}Status;
BitNode* CreateBiTree(BitNode* T, TelemType *c)
{
    
    if (c[count++] == ' ')
        T = NULL;
    else
    {
        T = (BitNode*)malloc(sizeof(BitNode));
        T->data = c[count - 1];
        T->lchild = CreateBiTree(T->lchild, c);
        T->rchild = CreateBiTree(T->rchild, c);
    }
    return T;
}
void PostOrder(BitNode* T)//计算所有节点个数
{
    if (T != NULL)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        printf("%c ", T->data);
    }
}
void Point(BitNode* T)
{
    if (T != NULL)
    {
        count1++;
        Point(T->lchild);
        Point(T->rchild);
    }
}
int LeafPoint(BitNode* T)//返回叶子节点个数
{
    int m, n;
    if (T == NULL)
    {
        return 0;
    }
    if (T->lchild == NULL&&T->rchild == NULL)
    {
        return 1;
    }
    else
    {
        m = LeafPoint(T->lchild);
        n = LeafPoint(T->rchild);
    }
    return m + n;
}
int Depth(BitNode* T)
{
    int depthL, depthR, depth;
    if (!T)
    {
        depth = 0;
    }
    else
    {
        depthL = Depth(T->lchild);
        depthR = Depth(T->rchild);
        depth = 1 + (depthL > depthR ? depthL : depthR);
    }
    return depth;
}
int a[10] = { 0 };
int i = 0;
void Width(BitNode *T)
{
    if (T != NULL)
    {
        if (i == 0)
        {
            a[0] = 1;
            i++;
            if (T->lchild != NULL) a[i]++;
            if (T->rchild != NULL) a[i]++;
        }
        else {
            i++;
            if (T->lchild != NULL) a[i]++;
            if (T->rchild != NULL) a[i]++;
        }
        Width(T->lchild);
        i--;
        Width(T->rchild);
    }
}
int MaxWidth()
{
    int max = 0,i;
    for (i = 0;i < 10;i++)
        if (max < a[i])
            max = a[i];
    return max;
}


int main()
{
    BitNode* T = NULL;
    int count2, count3;
    char str[25] = "ABDG   EH  I K  C F  ";
    TelemType *c = str;
    printf("创建二叉树:");
    T = CreateBiTree(T, c);
    printf("%s\n", str);
    printf("后序遍历:");
    PostOrder(T);
    Point(T);
    printf("\n结点数:%d", count1);
    count2=LeafPoint(T);
    printf("\n叶子结点数:%d", count2);
    count3 = count1 - count2;
    printf("\n非叶子节结点数:%d", count3);
    printf("\n二叉树的深度:");
    printf("%d", Depth(T));
    printf("\n二叉树的宽度:");
    Width(T);
    printf("%d\n", MaxWidth());
}
