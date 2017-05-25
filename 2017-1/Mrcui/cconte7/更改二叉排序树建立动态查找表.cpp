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


bool SearchBST(BiTree Tree, BiTree f, BiTree &p, KeyType key);//二叉排序树的查找
Status InsertBST(BiTree &Root, KeyType key);     //二叉排序树未找到关键字的插入和构造一棵二叉排序树,Tree为传引用指针
void PreOrderTraverse(BiTree Tree);//先序遍历
void InOrderTraverse(BiTree Tree);//中序遍历
void VisitBiTree(BiTree Tree);//输出根节点
int Delete(BiTree &Tree);//删除节点
int DeleteBST(BiTree &Tree, KeyType key);//二叉排序树找到关键字的删除


bool SearchBST(BiTree Tree, BiTree f, BiTree &p, KeyType key) {
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

        printf("%d, ", Tree->data);
        PreOrderTraverse(Tree->lchild); //访问左子树结点
        PreOrderTraverse(Tree->rchild);//访问右子树结点
    }
}


void InOrderTraverse(BiTree Tree)//中序遍历
{
    if (Tree != NULL) {

        InOrderTraverse(Tree->lchild);//访问左子树结点
        printf("%d, ", Tree->data);
        InOrderTraverse(Tree->rchild);//访问右子树结点
    }

}

void VisitBiTree(BiTree Tree) //输出根节点
{
    if (Tree->data != ' ') {
        printf("%c ", Tree->data);
    }
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

int main() {
    ElementType element[12] = {8, 10, 14, 3, 1, 6, 4, 7, 5, 19, 22, 30};
    KeyType key[5] = {13, 8, 5, 20, 6};
    int i, j, n1, n2;
    BiTree Tree, pp;
    //printf("输入初始化查找表中元素的个数:");
    //scanf("%d", &n1);
    Tree = NULL;
    //printf("输入查找表中各个元素的值:");
    for (i = 0; i < 12; i++) {
        //scanf("%d,", &element[i]);
        InsertBST(Tree, element[i]);
    }
    PreOrderTraverse(Tree);
    printf("\n");
    //printf("输入你要查找的关键字个数:");
    //scanf("%d", &n2);
    //printf("输入关键字:");
    /*for (j = 0; j < 5; j++) {
        scanf("%d,", &key[j]);
    }*/
    for (j = 0; j < 5; j++) {
        if (SearchBST(Tree, NULL, pp, key[j])) {
            DeleteBST(Tree, key[j]);
            PreOrderTraverse(Tree);
            printf("\n");
        }
        else {
            InsertBST(Tree, key[j]);
            PreOrderTraverse(Tree);
            printf("\n");
        }
    }

    return 0;
}
/*测试用例*/
/*查找表:8, 10, 14, 3, 1, 6, 4, 7, 5, 19, 22, 30(8 10 14 3 1 6 4 7 5 19 22 30)*/
/*关键字:13, 8, 5, 20, 6(13 8 5 20 6)*/