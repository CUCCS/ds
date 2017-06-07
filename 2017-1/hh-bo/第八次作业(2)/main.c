//
//  main.c
//  hw8
//
//  Created by Huhongbo on 2017/6/7.
//  Copyright © 2017年 Huhongbo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

//树的结构定义
typedef struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
    
}treeNode;

//最小元素查找
treeNode* FindMin(treeNode *node)
{
    if (node == NULL)
    {
        return NULL;
    }
    if (node->left)
        return FindMin(node->left);
    else
        return node;
}

//最大元素查找
treeNode* FindMax(treeNode *node)
{
    if (node == NULL)
    {
        return NULL;
    }
    if (node->right)
        return FindMax(node->right);
    else
        return node;
}

//插入数据
treeNode * Insert(treeNode *node, int data)
{
    if (node == NULL)
    {
        treeNode *temp;
        temp = (treeNode *)malloc(sizeof(treeNode));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (data >(node->data))
    {
        node->right = Insert(node->right, data);
    }
    else if (data < (node->data))
    {
        node->left = Insert(node->left, data);
    }
    return node;
}

//删除数据
treeNode * Delete(treeNode *node, int data)
{
    treeNode *temp;
    if (node == NULL)
    {
        printf("Element Not Found");
    }
    else if (data < node->data)
    {
        node->left = Delete(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = Delete(node->right, data);
    }
    else
    {
        if (node->right && node->left)
        {
            temp = FindMin(node->right);
            node->data = temp->data;
            node->right = Delete(node->right, temp->data);
        }
        else
        {
            temp = node;
            if (node->left == NULL)
                node = node->right;
            else if (node->right == NULL)
                node = node->left;
            free(temp);
        }
    }
    return node;
    
}

//查找数据
treeNode * Find(treeNode *node, int data)
{
    if (node == NULL)
    {
        return NULL;
    }
    if (data > node->data)
    {
        return Find(node->right, data);
    }
    else if (data < node->data)
    {
        return Find(node->left, data);
    }
    else
    {
        return node;
    }
    
}



//先序遍历
void PrintPreorder(treeNode *node)
{
    if (node == NULL)
    {
        return;
    }
    printf("%d ，", node->data);
    PrintPreorder(node->left);
    PrintPreorder(node->right);
}

//建立二叉树
treeNode*  createTree(treeNode *node, int *a,int n)
{
    for (int i = 0; i < n;i++)
        node=Insert(node, a[i]);
    return node;
}

int main()
{
    //建立二叉树并插入测试数据
    treeNode *root = NULL;
    int s[] = { 8,10,14,3,1,6,4,7,5,19,22,30 };
    int n = 12;
    root=createTree(root, &s,n);
    PrintPreorder(root);
    printf("\n");
    //待查找关键字
    int a[] = { 13,8,5,20,6 };
    treeNode * temp;
    for (int i = 0; i < 5; i++)
    {
        temp = Find(root, a[i]);
        printf("查找节点：");
        printf("%d\n", a[i]);
        if (temp == NULL)
        {
            printf("该元素不存在，插入该节点，重新打印树\n");
            Insert(root, a[i]);
            PrintPreorder(root);
            printf("\n");
        }
        else
        {
            printf("该元素存在，删除该节点，重新打印树\n");
            Delete(root, a[i]);
            PrintPreorder(root);
            printf("\n");
        }
    }
    
}
