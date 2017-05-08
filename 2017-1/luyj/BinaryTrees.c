#include "BinaryTrees.h"
int i = 0;
int high = 0;
int wide[50] = { 0 };
int swide = 0;

void valInit(int *level, int wide[50], int *count, int *ncounts)
{
	int j;
	*level = 0;
	i = 0;
	*count = 0;
	*ncounts = 0;
	swide = 0;
	for (j = 0; j < 50; j++)
	{
		wide[j] = 0;
	}
}

char AbstractWord(char*s)
{

	char ch = s[i];
	i++;
	return ch;
}



Status CreateBiTree(BiTree *T,char *s) 
{
	char ch;
	ch = AbstractWord(s);
	if (ch == ' ')
	{
		*T = NULL;
	}
	else
	{
		*T = (BiTNode*)malloc(sizeof(BiTNode));
		if (!T)
		{
			return OVERFLOW;
		}

		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild, s); // 构造左子树
		CreateBiTree(&(*T)->rchild, s);// 构造右子树
							 
	}
	return OK;
}



Status PostOrderTraverse(BiTree T)
{
	if (T)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%c", T->data);
	} 
	return OK;
}



Status destoryBiTree(BiTree T)
{
	if (!T)
	{
		return ERROR;
	}
	else
	{
		destoryBiTree(T->lchild);
		destoryBiTree(T->rchild);
		free (T);
	}
}



int Max(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	else
	{
		return y;
	}
}



int getHigh(BiTree T)
{
	int high = 0;
	int lhigh;
	int rhigh;
	if (!T)
	{
		return 0;
	}
	else
	{
		
		lhigh = getHigh(T->lchild);
		rhigh = getHigh(T->rchild);
		high = Max(lhigh, rhigh)+1;
		return high;
	}
	
}



int getWide(BiTree T, int level)
{
	if (T == NULL)
	{
		return 0;
	}
	wide[level]++;
	if (swide < wide[level])
	{
		swide = wide[level];
	}
	getWide(T->lchild, level + 1);
	getWide(T->rchild, level + 1);
	return swide;
}



void CountLeaf(BiTree T, int *count,int *ncounts)
{
	if (T)
	{
		(*ncounts)++;
		if ((T->lchild==NULL) && (T->rchild==NULL))
		{
			(*count)++;     // 对叶子结点计数
		}
		CountLeaf(T->lchild, count,ncounts);
		CountLeaf(T->rchild, count,ncounts);
	}
}

bool QueueEmpty(LinkQueue*Q)
{
	if (Q->front == Q->rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Status EnQueue(LinkQueue*Q, BiTNode e)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)
	{
		return ERROR;
	}
	else
	{
		p->data = e;
		p->next = NULL;
		Q->rear->next = p;
		Q->rear = p;
	}
}

Status DeQueue(LinkQueue*Q, BiTNode*e)
{
	if (Q->front == Q->rear)
	{
		return ERROR;
	}
	QNode *p = Q->front->next; //指向队头;
	*e = p->data;
	Q->front->next = p->next;
	if (Q->rear == p)
	{
		Q->rear = Q->front;
	}
	free(p);
	return OK;
}

Status InitQueue(LinkQueue *Q)
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front)
	{
		return ERROR;
	}
	Q->front->next = NULL;
	return OK;
}


bool isComplete(BiTree T)
{
	if (!T)
	{
		return true;  //首先判断空树.根据完全二叉树定义,判断空树为完全二叉树;
	}

	int isL = 0; //用以标记;
	LinkQueue q;
	InitQueue(&q);  //建立空队列;
	BiTree t = T;
	EnQueue(&q, *T);//树根结点入队列;

	//开始广度优先遍历;
	while (QueueEmpty(&q)!=NULL)
	{
		DeQueue(&q,t);
		if (T->lchild != NULL)
		{
			if (t->lchild != NULL)
			{
				/*如果isL==1则说明此结点的左边已经有没有孩子或只有左孩子的结点，
				此时该结点还有孩子，则说明此树为不完全二叉树。*/
				if (isL == 1)  
				{
					return false;
				}
				EnQueue(&q, *(t->lchild));
			}
			if (t->rchild != NULL)
			{
				EnQueue(&q, *(t->rchild));
			}
			if (t->lchild == NULL && t->rchild != NULL)
			{
				return false;
			}
			if (t->lchild != NULL&&t->rchild == NULL||t->lchild==NULL&&t->rchild==NULL)
			{
				/*从左向右遍历时如果左边出现结点的
				左孩子不为空但右孩子为空，或左孩子右孩子都为空则isL=1;*/
				isL = 1;  
			}
		}
	}
	return true;
}

//输出后序式表达式;
void printBiTree(BiTree T)
{
	printf("后序式表达式为：\n");
	PostOrderTraverse(T);
	printf("\n");
}

void printLeafNumber(BiTree T,int count,int ncounts)
{
	printf("叶子结点个数为:%d\n", count);
	printf("非叶子结点个数为:%d\n", ncounts - count);
}

void printIsComplete(BiTree T)
{
	if (isComplete(T) == true)
	{
		printf("此树是完全二叉树");
	}
	else
	{
		printf("此树不是完全二叉树");
	}
}
