#include <stdio.h>
#include <stdlib.h>
//注释
#define  MAXSIZE 20
//二叉树结点的结构体表示形式
typedef struct BitNode
{
	char    data;
	struct BitNode* left, *right;
}BitTree;

//栈的结构体表示形式
typedef struct stackelem
{
	BitTree* a[MAXSIZE];
	int top;
}Stack;

//队列的结构体的表示形式
typedef struct queueelem
{
	BitTree* b[MAXSIZE];
	int front, rear;
}Queue;

//创建二叉树，利用递归的方法
//按前序次序输入。 如 A # #(#表示空树)
BitTree* Create()
{
	char ch;
	scanf("%c", &ch);
	getchar();    //吃掉空格符
	if (ch == '#')
	{
		return NULL;
	}
	else
	{
		BitTree* btree = (BitTree*)malloc(sizeof(BitTree));
		if (NULL == btree)
		{
			return NULL;
		}
		btree->data = ch;
		btree->left = Create();
		btree->right = Create();
		return btree;
	}
}

//前序遍历，递归的方法
void Preorder(BitTree* bt)
{
	if (NULL != bt)
	{
		printf("%c ", bt->data);
		Preorder(bt->left);
		Preorder(bt->right);
	}
}

//前序遍历的非递归实现
/*
思想：利用栈来实现；根结点进栈，之后栈非空，弹出，接着根节点的右结点进栈，之后，左节点进栈；接着，弹出栈顶元素（输出）,
此结点的右结点进栈，之后左节点进栈，弹出栈顶元素（输出）...一直这样下去，直到栈为空。
*/
void Preorder2(BitTree* bt)
{
	BitTree* p;
	Stack st;
	st.top = -1;
	if (NULL == bt)
	{
		return;
	}
	else
	{
		st.top++;
		st.a[st.top] = bt;
		while (st.top != -1)
		{
			p = st.a[st.top];
			st.top--;
			printf("%c ", p->data);
			if (p->right != NULL)
			{
				st.top++;
				st.a[st.top] = p->right;
			}
			if (p->left != NULL)
			{
				st.top++;
				st.a[st.top] = p->left;
			}
		}
	}
}

//中序遍历，递归实现
void Inorder(BitTree* bt)
{
	if (NULL != bt)
	{
		Inorder(bt->left);
		printf("%c ", bt->data);
		Inorder(bt->right);
	}
}

//中序遍历，非递归实现
/*
思想：利用栈。从根节点开始，循环，只要有左子节点则进栈，直到左子节点为空。接着弹出栈顶输出，判断该结点是否有右子节点，
若有则进栈，若没有继续弹栈。有右子节点的情况，判断该节点是否有左子节点，有则进栈，直到左子节点为空；若该右子节点没有
左子节点，则弹栈；判断弹出的节点，是否有右子节点，若有则进栈，没有继续弹栈；接着又要判断刚进栈的这个节点，是否有左子节点，
有则进栈，没有则继续弹栈。重复下去....
栈空，是判定条件。
*/
void Inorder2(BitTree* bt)
{
	BitTree* p, *q;
	Stack st;
	st.top = -1;
	if (NULL == bt)
	{
		return;
	}
	else
	{
		while (bt != NULL)
		{
			st.top++;
			st.a[st.top] = bt;
			bt = bt->left;
		}
		while (st.top != -1)
		{
			p = st.a[st.top];
			st.top--;
			printf("%c ", p->data);
			while (p->right != NULL)
			{
				st.top++;
				st.a[st.top] = p->right;
				q = p->right;
				while (q->left != NULL)
				{
					st.top++;
					st.a[st.top] = q->left;
					q = q->left;
				}
				break;
			}
		}
	}
}

//后序遍历，递归实现
void Postorder(BitTree* bt)
{
	if (bt != NULL)
	{
		Postorder(bt->left);
		Postorder(bt->right);
		printf("%c ", bt->data);
	}
}

//后序遍历，非递归实现
/*
算法思想：利用栈来实现。从根结点开始，只要左子节点非空，则进栈，直到左子节点为空为止。取出栈顶元素（只是取，并非弹栈），判断
1:取出的栈顶元素是否有右子节点，或者右子节点是否被访问过，若满足条件（无右子节点，或者右子节点被访问过），则输出该结点，
同时弹栈，并且记录下该访问的节点。
2:取出的栈顶元素，若有右子节点，且未被访问过，则指针继续移动到右子节点，重复一开始是否又左子节点的判断。
*/
void Postorder2(BitTree* bt)
{
	Stack st;
	st.top = -1;
	BitTree* t;
	do
	{
		while (bt != NULL)
		{
			st.top++;
			st.a[st.top] = bt;
			bt = bt->left;
		}
		t = NULL;
		while (st.top != -1)
		{
			bt = st.a[st.top];
			if (bt->right == t)  //t:表示为null，或者右子节点被访问过了。
			{
				printf("%c ", bt->data);
				st.top--;
				t = bt;  //t记录下刚刚访问的节点
			}
			else
			{
				bt = bt->right;
				break;
			}
		}
	} while (st.top != -1);
}

//求二叉树的高度，递归实现
int Height(BitTree* bt)
{
	int depth1, depth2;
	if (NULL == bt)
	{
		return 0;
	}
	else
	{
		depth1 = Height(bt->left);
		depth2 = Height(bt->right);
		if (depth1>depth2)
		{
			return (depth1 + 1);
		}
		else
		{
			return (depth2 + 1);
		}
	}
}

//层次遍历二叉树,用队列来实现
void TraversalOfLevel(BitTree* bt)
{
	Queue q;
	q.front = q.rear = 0;
	if (bt != NULL)
	{
		printf("%c ", bt->data);
	}
	q.b[q.front] = bt;
	q.rear = q.rear + 1;
	while (q.front<q.rear)
	{
		bt = q.b[q.front];
		q.front = q.front + 1;
		if (bt->left != NULL)
		{
			printf("%c ", bt->left->data);
			q.b[q.rear] = bt->left;
			q.rear = q.rear + 1;
		}
		if (bt->right != NULL)
		{
			printf("%c ", bt->right->data);
			q.b[q.rear] = bt->right;
			q.rear = q.rear + 1;
		}
	}
}

int main()
{
	BitTree* btr = Create();
	printf("前序遍历：递归和非递归实现：\n");
	Preorder(btr);
	printf("\n");
	Preorder2(btr);
	printf("\n");
	printf("中序遍历：递归和非递归实现：\n");
	Inorder(btr);
	printf("\n");
	Inorder2(btr);
	printf("\n");
	exit(1);//
	printf("后序遍历：递归和非递归实现：\n");
	Postorder(btr);
	printf("\n");
	Postorder2(btr);
	printf("\n");
	printf("二叉树的高度：\n");
	int Hgt = Height(btr);
	printf("%d \n", Hgt);
	printf("层次遍历二叉树:\n");
	TraversalOfLevel(btr);
	printf("\n");
	return 0;
}
