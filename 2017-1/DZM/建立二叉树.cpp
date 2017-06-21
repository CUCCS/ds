//其中扩充结点用'0'号表示。即‘0’表示空树节点
#include<iostream>
#include<stdio.h>
#include <iomanip>
#include<stdlib.h>

using namespace std;
#define OVERFLOW 0
#define OK 1

typedef int Status;
typedef char ElemType;

//二叉树结点的定义
typedef struct BiTree
{
    ElemType data;
    struct BiTree *Lchild;
    struct BiTree *Rchild;
}BiTree,*Binary_Tree;

//创建一个二叉树
Status CreateBiTree(Binary_Tree &T)
{
    char ch;
    T=(Binary_Tree)malloc(sizeof(BiTree));
    if(!T)
        exit(OVERFLOW);
    cin>>ch;
    if(ch=='0')
        T=NULL;
    else
    {
        T->data=ch;
        CreateBiTree(T->Lchild);
        CreateBiTree(T->Rchild);
   }
   return OK;
}

//先遍历二叉树
Status PreShowBiTree(Binary_Tree T)
{
    if(T!=NULL)
    {
       cout<<T->data<<setw(3);
       PreShowBiTree(T->Lchild);
       PreShowBiTree(T->Rchild);
    }
    return OK;
}

//中遍历二叉树
Status MidShowBiTree(Binary_Tree T)
{
    if(T!=NULL)
    {
       MidShowBiTree(T->Lchild);
       cout<<T->data<<setw(3);
       MidShowBiTree(T->Rchild);
    }
    return OK;
}

//后遍历二叉树
Status BehShowBiTree(Binary_Tree T)
{
    if(T!=NULL)
    {
       BehShowBiTree(T->Lchild);
       BehShowBiTree(T->Rchild);
       cout<<T->data<<setw(3);
    }
    return OK;
}

int main()
{
    BiTree *T;
    cout<<"请创建一个二叉树: "<<endl;
    CreateBiTree(T);

    cout<<"先序遍历: ";
    PreShowBiTree(T);
    cout<<endl;
    cout<<"中序遍历: ";
    MidShowBiTree(T);
    cout<<endl;
    cout<<"后序遍历: ";
    BehShowBiTree(T);
    cout<<endl;
}