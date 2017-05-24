#pragma once

#include <stdlib.h>
#define M 3
#define Node struct _Node
/*测试*/
#define DEBUG 0
#define debug_print(...) if(DEBUG)printf(__VA_ARGS__)

typedef enum _bool {false,true}bool;
typedef int Elemtype;
/*3阶B树每个节点最多有3个子树和2个关键字*/
typedef struct _Node {
	Node* parent;
	int usedKeys;
	Elemtype keys[M - 1 + 1] ;//预留一位便于进行分裂操作
	Node* childs[M + 1];
}*BTree;

Node* newNode() {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->parent = NULL;
	temp->usedKeys = 0;
	for (int i = 0; i < M; ++i) {
		temp->keys[i] = 0;
		temp->childs[i] = NULL;
	}
	temp->childs[M ] = NULL;
	return temp;
}
bool isFull(Node* node) {
	return node->usedKeys == M - 1;
}
bool isLeaf(Node* node) {
	for (int i = 0; i <= node->usedKeys; ++i) {
		if (node->childs[i])return false;
	}
	return true;
}
BTree newBTree() {
	return newNode();
}
void showNode(Node* node) {
	printf("====== 【Node 0x%p】 ======\n",node);
	printf("Parent : 0x%p\nUsedkeys : %d\n",node->parent,node->usedKeys);
	printf("Keys : ");
	for (int i = 0; i < M ; ++i)printf("%d ", node->keys[i]); printf("\n");
	printf("Childs : ");
	for (int i = 0; i < M+1; ++i)printf("0x%p ", node->childs[i]); printf("\n");
	printf("=============================\n");
}
/*将data按顺序添加进数组arr中*/
void AppendElemtype(Elemtype* arr, int size , Elemtype data) {
	int pos = 0;
	while (arr[pos] && data > arr[pos] && pos<=size-1)++pos;
	for (int i = size-2; i >= pos; --i) {
		arr[i + 1] = arr[i];
	}
	arr[pos] = data;
}
void AppendNodeStar(Node** arr,int size,Node*data) {
	int pos = 0;
	while (arr[pos] && data->keys[0] > arr[pos]->keys[0] && pos <= size - 1)++pos;
	for (int i = size - 2; i >= pos; --i) {
		arr[i + 1] = arr[i];
	}
	arr[pos] = data;
}
/*将data从数组arr中删除*/
void DeleteElemtype(Elemtype* arr, int size, Elemtype data) {
	int pos=0;
	while (data > arr[pos] && pos <= size-1)++pos;
	for (int i = pos;i<size-1; ++i) {
		arr[i] = arr[i + 1];
	}
	arr[size - 1] = 0;
}
void DeleteNodeStar(Node** arr, int size, Node* data) {
	int pos = 0;
	while (data->keys[0] > arr[pos]->keys[0] && pos <= size - 1)++pos;
	for (int i = pos; i<size - 1; ++i) {
		arr[i] = arr[i + 1];
	}
	arr[size - 1] = NULL;
}
/*以data为界，将node拆分为两个node*/
void DivideNode(Node* node, Elemtype data, Node** p1, Node**p2) {
	*p1 = newNode();
	*p2 = newNode();
	debug_print(__FUNCTION__"(0x%p,%d,0x%p,0x%p)\n", node, data, *p1, *p2);
	if (DEBUG)showNode(node);
	/*拆分keys与childs*/
	for (int i = 0; i <= M; ++i) {
		/*childs*/
		if (node->childs[i] && node->childs[i]->keys[0] < data) {
			(*p1)->childs[(*p1)->usedKeys] = node->childs[i];
			(*p1)->childs[(*p1)->usedKeys]->parent = *p1;
		}
		else if (node->childs[i] && node->childs[i]->keys[0] > data) {
			(*p2)->childs[(*p2)->usedKeys] = node->childs[i];
			(*p2)->childs[(*p2)->usedKeys]->parent = *p2;
		}
		if (i == M)break;
		/*keys*/
		if (node->keys[i] < data) {
			(*p1)->keys[(*p1)->usedKeys++] = node->keys[i];
		}
		else if (node->keys[i] > data) {
			(*p2)->keys[(*p2)->usedKeys++] = node->keys[i];
		}
	}
	debug_print("After divide : \n");
	if (DEBUG)showNode(*p1),showNode(*p2);
}
Elemtype swapWithMid(Elemtype* arr, int size, Elemtype data) {
 	Elemtype* _arr = (Elemtype*)malloc((size + 1) * sizeof(Elemtype));
	for (int i = 0; i < size; ++i)_arr[i] = arr[i];
	AppendElemtype(_arr, size, data);
	int pos = (size + 1) / 2;
	Elemtype mid = _arr[pos];
	DeleteElemtype(arr, size, mid);
	AppendElemtype(arr, size-1 , data);
	free(_arr);
	return mid;
}
bool Find(BTree root, Elemtype data) {
	int pos = 0;
	while (data > root->keys[pos] && pos<root->usedKeys)pos += 1;
	if (data == root->keys[pos])
		return true;
	else
		return root->childs[pos] ? Find(root->childs[pos], data) : false;
}
BTree Insert(BTree root, Elemtype data) {
	if (!isLeaf(root)) {
		int pos = 0;
		while (data > root->keys[pos] && pos< root->usedKeys)++pos;
		/*执行Insert(child,data)*/
		root = Insert(root->childs[pos],data);
		while (root->parent)root = root->parent;
		return root;
	}
	//程序执行到这里说明root是叶节点
	//然后先添加，再考虑超没超
	AppendElemtype(root->keys, M, data); root->usedKeys += 1;
	//如果超了，再分裂
	while (root->usedKeys == M) {
		Node*a, *b;
		data = root->keys[M/2];
		DivideNode(root, data, &a, &b);
		Node* parent = root->parent;
		if (parent) {
			DeleteNodeStar(parent->childs, M, root);
		}
		else {
			parent = newNode();
		}
		a->parent = parent;
		b->parent = parent;
		AppendElemtype(parent->keys, M , data);
		parent->usedKeys += 1;
		AppendNodeStar(parent->childs, M+1, a);
		AppendNodeStar(parent->childs, M+1, b);
		free(root);
		root = parent;
	}
	return root;
}
BTree Remove(BTree root, Elemtype data) {}
/*按层遍历输出B树*/
typedef struct _QueueNode {
	Node* data;
	struct _QueueNode* prev;
	struct _QueueNode* next;
}QueueNode;
typedef struct _Queue {
	QueueNode* front;
	QueueNode* rear;
}Queue;
Queue newQueue() {
	Queue q; q.front = q.rear = NULL; return q;
}
Queue EnQueue(Queue q,Node* data) {
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = data; temp->next = temp->prev = NULL;
	//如果是空队列
	if (!q.front) {
		q.front = q.rear = temp;
	}
	else {
		temp->prev = q.rear;
		q.rear->next = temp;
		q.rear = temp;
	}
	return q;
}
Queue DeQueue(Queue q, Node** result) {
	if (q.front == q.rear) {
		*result = q.front->data;
		free(q.front);
		q.front = q.rear = NULL;
	}
	else {
		*result = q.front->data;
		QueueNode* temp = q.front;
		q.front = q.front->next;
		free(temp);
	}
	return q;
}
void BFSprint(BTree root) {
	Queue q = newQueue();
	Node* front;
	q = EnQueue(q, root);
	do {
		q = DeQueue(q, &front);
		for (int i = 0; i < front->usedKeys; ++i) {
			printf("%d", front->keys[i]);
			if (q.front || front->childs[0] || i<=front->usedKeys-1&&front->keys[i+1]) {
				printf(", ");
			}
		}
		for (int i = 0; i < M; ++i) {
			if (front->childs[i])
				q = EnQueue(q, front->childs[i]);
		}
	} while (q.front);
}