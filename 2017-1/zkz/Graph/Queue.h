#pragma once
#include <stdlib.h>
typedef enum _bool { false, true } bool;
typedef char Elemtype;
typedef struct _Node {
	Elemtype data;
	struct _Node* prior;
	struct _Node* next;
}Node;
typedef struct _Queue {
	Node* front;
	Node* rear;
	Node* lastOut;
}Queue;
Queue newQueue();
bool isEmpty(Queue q);
void EnQueue(Queue* q, Elemtype data);
void DeQueue(Queue*q);
void TraverseQueue(Queue q);