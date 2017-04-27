//
//  main.c
//  binary tree
//
//  Created by Huhongbo on 2017/4/25.
//  Copyright © 2017年 Huhongbo. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>

#define TelemType char

typedef struct BitNode//结构定义
{
    TelemType data;
    struct BitNode *lchild, *rchild;
}BitNode;

typedef enum
{
    error,ok
}Status;

BitNode* CreateBiTree(BitNode* T)//建立二叉树
{
    TelemType c;
    scanf("%c", &c);
    if (c == ' ')
        T = NULL;
    else
    {
        T = (BitNode*)malloc(sizeof(BitNode));
        T->data = c;
        T->lchild=CreateBiTree(T->lchild);
        T->rchild=CreateBiTree(T->rchild);
    }
    return T;
}

void PostOrder(BitNode* T)
{
    if (T!=NULL)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        printf("%c ", T->data);
    }
}

int main()//主函数
{
    BitNode* T=NULL;
    printf("Create a BitTree:\n");
    T=CreateBiTree(T);
    printf("Postorder Traverse:\n");
    PostOrder(T);
}
