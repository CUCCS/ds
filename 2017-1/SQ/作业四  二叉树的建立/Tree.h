
typedef char ElemType;

typedef struct BiTNode { //二叉树结构定义
	ElemType data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

typedef enum {
	OK,        // OK = 0
	ERROR,     //ERROR = 1
	OVERFLOW   //OVERFLOW = 2
}Status;//函数返回状态 

//==========二叉树的基本操作=============// 
Status PostOrderTraverse(BiTree T);

//==========方法一，以字符串的形式“根 左子树 右子树”定义一棵二叉树=============// 
Status CreateBiTree(BiTree *T);

//==========方法二，由二叉树的先序和中序序列建树=============// 
int Search(char ino[], char p);
Status CrtBT(BiTree *T, char pre[], char ino[], int ps, int is, int n);
void print(char *pre, char *in, BiTree T);
