#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;
typedef int KeyType;
typedef enum {
    OK,
    ERROR,
    OVERFLOW
} Status;

typedef struct BiTNode {
    
    ElementType data;//数据元素
    struct BiTNode *lchild;//左孩子指针
    struct BiTNode *rchild; //右孩子指针
} BiTNode, *BiTree;//二叉树节点类型

Status CreatBST(BiTree &Tree, ElementType element[], int n);//初始化二叉排序树
bool SearchBST(BiTree Tree, BiTree f, BiTree &p, KeyType key);//二叉排序树的查找
Status InsertBST(BiTree &Root, KeyType key);     //二叉排序树未找到关键字的插入,Tree为传引用指针
void PreOrderTraverse(BiTree Tree);//先序遍历
void InOrderTraverse(BiTree Tree);//中序遍历
void VisitBiTree(BiTree Tree);//输出根节点
int Delete(BiTree &Tree);//删除节点
int DeleteBST(BiTree &Tree, KeyType key);//二叉排序树找到关键字的删除
void PrintTree(BiTree Tree);//打印二叉排序树
