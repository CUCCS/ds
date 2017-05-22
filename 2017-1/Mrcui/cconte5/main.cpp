#include<stdio.h>
#include<stdlib.h>

typedef struct BiTNode {

    char data;
    struct BiTNode *lchild;//左孩子指针
    struct BiTNode *rchild; //右孩子指针
} BiTNode, *BiTree;

int CreateBiTree(BiTree &Tree);//按先序序列创建二叉树
int MCreateBiTree(BiTree &Tree);//按中序序列创建二叉树
void VisitBiTree(BiTree Tree);//输出根节点
void PreOrderTraverse(BiTree Tree);//先序遍历
void InOrderTraverse(BiTree Tree);//中序遍历
void PostOrderTraverse(BiTree Tree);//后序遍历

int CreateBiTree(BiTree &Tree) {//按先序序列创建二叉树
    char data;
    data = getchar();
    if (data == ' ') {  //按先序次序输入二叉树中结点的值（一个字符），‘ ’表示空树
        Tree = NULL;
    }
    else {
        Tree = (BiTree) malloc(sizeof(BiTNode));
        Tree->data = data;  //生成根结点
        CreateBiTree(Tree->lchild);  //生成左子树
        CreateBiTree(Tree->rchild); //生成右子树
    }
    return 0;
}

int MCreateBiTree(BiTree &Tree) {//按中序序列创建二叉树
    char data;
    data = getchar();
    if (data == ' ') {  //按先序次序输入二叉树中结点的值（一个字符），‘ ’表示空树
        Tree = NULL;
    }
    else {
        Tree = (BiTree) malloc(sizeof(BiTNode));
        CreateBiTree(Tree->lchild);  //生成左子树
        Tree->data = data;  //生成根结点
        CreateBiTree(Tree->rchild); //生成右子树
    }
    return 0;
}

void VisitBiTree(BiTree Tree) {//输出根节点
    if (Tree->data != ' ') {
        printf("%c ", Tree->data);
    }
}

void PreOrderTraverse(BiTree Tree) {//先序遍历
    if (Tree != NULL) {

        VisitBiTree(Tree); //访问根节点
        PreOrderTraverse(Tree->lchild); //访问左子树结点
        PreOrderTraverse(Tree->rchild);//访问右子树结点
    }
}

void InOrderTraverse(BiTree Tree) {//中序遍历
    if (Tree != NULL) {

        InOrderTraverse(Tree->lchild);//访问左子树结点

        VisitBiTree(Tree);//访问根节点

        InOrderTraverse(Tree->rchild);//访问右子树结点
    }
}

void PostOrderTraverse(BiTree Tree) {//后序遍历
    if (Tree != NULL) {

        PostOrderTraverse(Tree->lchild); //访问左子树结点

        PostOrderTraverse(Tree->rchild); //访问右子树结点

        VisitBiTree(Tree); //访问根节点
    }
}


int main() {
    BiTree Tree;
    CreateBiTree(Tree);
    printf("先序遍历二叉树：\n");
    PreOrderTraverse(Tree);
    printf("\n");
    printf("中序遍历二叉树：\n");
    InOrderTraverse(Tree);
    printf("\n");
    printf("后序遍历二叉树：\n");
    PostOrderTraverse(Tree);
    printf("\n");
    return 0;
}

/*测试用例*/
/*ABDG   EH  I K  C F  */
/*ABD F   CE   */