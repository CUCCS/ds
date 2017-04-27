#include <stdio.h>
#include <stdlib.h>

extern int i;
typedef char TElemType;

typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;


//���ַ����ַ�����ȡ��;
char AbstractWord(char*s);

//����������;
Status CreateBiTree(BiTree *T, char *s);

//�Ժ���ʽ���;
Status PostOrderTraverse(BiTree T);

//�ݻٶ�����;
Status destoryBiTree(BiTree T);



