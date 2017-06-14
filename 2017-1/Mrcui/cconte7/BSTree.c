#include "BSTree.h"

Status CreatBST(BiTree &Tree, ElementType element[], int n) //初始化二叉排序树
{
    int i = 0;
    for (i = 0; i < n; i++) {
        InsertBST(Tree, element[i]);
    }
    if (Tree) {
        return ERROR;
    }
    return OK;
}

bool SearchBST(BiTree Tree, BiTree f, BiTree &p, KeyType key) //二叉排序树的查找
{
    int flag = 0;//是否查找成功标记
    if (!Tree) {
        p = f;
        flag = 0;//未查找成功
        return false;
    }
    else if (key == Tree->data) {
        p = Tree;
        flag = 1; //查找成功
        return true;
    }
    else if (key < Tree->data) {//在左子树继续查找
        flag = 0;
        return SearchBST(Tree->lchild, Tree, p, key);
    }
    else if (key > Tree->data) {//在右子树继续查找
        flag = 0;
        return SearchBST(Tree->rchild, Tree, p, key);
    }
}

Status InsertBST(BiTree &Root, KeyType key)     //二叉排序树未找到关键字的插入和构造一棵二叉排序树,Tree为传引用指针
{
    BiTree p, s;
    if (!SearchBST(Root, NULL, p, key))    //查找不成功
    {
        s = (struct BiTNode *) malloc(sizeof(BiTNode));
        s->data = key;
        s->lchild = s->rchild = NULL;
        if (p == NULL)    //二叉排序树为空的时候，结点*s被插入为新的根结点
            Root = s;
        else if (key < p->data)
            p->lchild = s;//结点*s被插为左孩子
        else
            p->rchild = s;//结点*s被插为右孩子
    }
    return OK;
}

void PreOrderTraverse(BiTree Tree)//先序遍历
{
    if (Tree != NULL) {
        printf(", ");
        printf("%d", Tree->data);
        PreOrderTraverse(Tree->lchild); //访问左子树结点
        PreOrderTraverse(Tree->rchild);//访问右子树结点
    }
}

void InOrderTraverse(BiTree Tree)//中序遍历
{
    if (Tree != NULL) {
        printf(", ");
        InOrderTraverse(Tree->lchild);//访问左子树结点
        printf("%d", Tree->data);
        InOrderTraverse(Tree->rchild);//访问右子树结点
    }
}

void VisitBiTree(BiTree Tree) //输出根节点
{
    printf("%d", Tree->data);
}

int Delete(BiTree &Tree)//删除节点
{
    BiTree q, s;
    if (!Tree->rchild) {    //右子树为空
        q = Tree;
        Tree = Tree->lchild;//重接它的左子树
        free(q);
    }
    else if (!Tree->lchild) {   //左子树为空
        q = Tree;
        Tree = Tree->rchild; //重接它的右子树
        free(q);
    }
    else {  //左右子树均不为空
        q = Tree;
        s = Tree->lchild;
        while (s->rchild) {   //在右子树上搜索待删结点的前驱
            q = s;
            s = s->rchild;
        }
        Tree->data = s->data;  //s指向被删除结点的前驱
        if (q != Tree) {
            q->rchild = s->lchild;//重接*q的右子树
        }
        else {
            q->lchild = s->lchild;//重接*q的左子树
        }
        delete s;
    }
    return true;
}

int DeleteBST(BiTree &Tree, KeyType key)//二叉排序树找到关键字的删除
{
    if (!Tree)
        return false;
    else {
        if (key == Tree->data) {
            return Delete(Tree);  //找到关键字为key的数据元素
        }
        else if (key < Tree->data) {
            return DeleteBST(Tree->lchild, key);//关键字小于结点的话，即在左子树
        }
        else {
            return DeleteBST(Tree->rchild, key); //关键字大于结点的话，即在右子树
        }
    }
}

void PrintTree(BiTree Tree)//打印二叉排序树
{
    VisitBiTree(Tree);//打印根节点
    PreOrderTraverse(Tree->lchild);//打印左子树
    PreOrderTraverse(Tree->rchild);//打印右子树
}
