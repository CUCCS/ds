//������������'0'�ű�ʾ������0����ʾ�����ڵ�
#include<iostream>
#include<stdio.h>
#include <iomanip>
#include<stdlib.h>

using namespace std;
#define OVERFLOW 0
#define OK 1

typedef int Status;
typedef char ElemType;

//���������Ķ���
typedef struct BiTree
{
    ElemType data;
    struct BiTree *Lchild;
    struct BiTree *Rchild;
}BiTree,*Binary_Tree;

//����һ��������
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

//�ȱ���������
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

//�б���������
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

//�����������
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
    cout<<"�봴��һ��������: "<<endl;
    CreateBiTree(T);

    cout<<"�������: ";
    PreShowBiTree(T);
    cout<<endl;
    cout<<"�������: ";
    MidShowBiTree(T);
    cout<<endl;
    cout<<"�������: ";
    BehShowBiTree(T);
    cout<<endl;
}