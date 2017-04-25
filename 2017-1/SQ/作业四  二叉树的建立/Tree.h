
typedef char ElemType;

typedef struct BiTNode { //�������ṹ����
	ElemType data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

typedef enum {
	OK,        // OK = 0
	ERROR,     //ERROR = 1
	OVERFLOW   //OVERFLOW = 2
}Status;//��������״̬ 

//==========�������Ļ�������=============// 
Status PostOrderTraverse(BiTree T);

//==========����һ�����ַ�������ʽ���� ������ ������������һ�ö�����=============// 
Status CreateBiTree(BiTree *T);

//==========���������ɶ�������������������н���=============// 
int Search(char ino[], char p);
Status CrtBT(BiTree *T, char pre[], char ino[], int ps, int is, int n);
void print(char *pre, char *in, BiTree T);
