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
int Depth(BiTree Tree);//计算二叉树的高度
int Width(BiTree Tree);//计算二叉树的宽度
int CountTreeLeaf(BiTree Tree);//计算二叉树中叶子节点的个数
int CountunTreeLeaf(BiTree Tree); //计算二叉树中非叶子节点的个数

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


int Depth(BiTree Tree) {//计算二叉树高度
    int depth1, depth2;
    if (Tree == NULL)
        return 0;
    else {
        depth1 = Depth(Tree->lchild);
        depth2 = Depth(Tree->rchild);
        if (depth1 > depth2)
            return (depth1 + 1);
        else
            return (depth2 + 1);
    }
}


int Width(BiTree Tree) {//计算二叉树宽度
    BiTree queue[1000];
    int front = -1, rear = -1;

    int flag = 0, count = 0,pright;// pright用于指向树中层的最右边的结点，标志flag记录层中结点数的最大值。
    if (Tree != NULL) {
        rear++;
        queue[rear] = Tree;
        flag = 1;
        pright = rear;
    }
    while (front < pright) {
        front++;
        Tree = queue[front];
        if (Tree->lchild != NULL) {
            rear++;
            queue[rear] = Tree->lchild;
            count++;
        }
        if (Tree->rchild != NULL) {
            rear++;
            queue[rear] = Tree->rchild;
            count++;
        }
        if (front == pright)// 当前层已遍历完毕

        {
            if (flag < count)
                flag = count;
            count = 0;
            pright = rear;
        }
    }

    return flag;
}

int CountTreeLeaf(BiTree Tree) {//计算二叉树中叶子节点的个数

    if (Tree == NULL) //如果节点为空，则返回0

        return 0;

    else if ((Tree->lchild == NULL) && (Tree->rchild == NULL))//否则如果节点左右孩子有一个为空，另一个存在，则返回1

        return 1;

    else

        return (CountTreeLeaf(Tree->lchild) + CountTreeLeaf(Tree->rchild));//否则返回左右子树叶子节点之和

}
int CountunTreeLeaf(BiTree Tree) {//计算二叉树中非叶子节点的个数

    if (Tree == NULL) //如果节点为空，则返回0

        return 0;

    else if ((Tree->lchild == NULL) &&(Tree->rchild == NULL))//否则如果节点左右孩子都为空，另一个存在，则返回0

        return 0;


    else
        return (1+CountunTreeLeaf(Tree->lchild) + CountunTreeLeaf(Tree->rchild));


}
int main() {
    BiTree Tree;
    int depth,width,leaf,unleaf;
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
    depth=Depth( Tree);
    printf("二叉树的高度是:%d",depth);
    width=Width(Tree);
    printf("\n二叉树的宽度是:%d",width);
    leaf= CountTreeLeaf(Tree);
    printf("\n二叉树的叶子节点个数是:%d",leaf);
    unleaf=CountunTreeLeaf(Tree);
    printf("\n二叉树的非叶子节点个数是:%d",unleaf);

    return 0;
}


/*测试用例*/
/*ABDG   EH  I K  C F  */
/*ABD F   CE   */
