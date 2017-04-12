#include "Queue.h"

/*��Щtest+�������ĺ�*/
/*���ڲ��Զ�Ӧ���������Ƿ�����*/
/*����ӡ�����Ϣ*/
#define testInitQueue(Q) debug_print("Initialize queue Q \n");CHECK(InitQueue(&(Q)));
#define testTraverseQueue(Q) 	debug_print("Traverse Q : ");CHECK(TraverseQueue((Q)));printf("\n\n");
#define testEnQueue(Q,data) debug_print("Enqueue %d \n",(data));CHECK(EnQueue(&(Q), (data)));
#define testGetHead(Q,pData) debug_print("Get head of Q \n");CHECK(GetHead((Q),(pData)));debug_print("The result is : %d \n\n",*(pData));
#define testDeQueue(Q,pData) debug_print("Dequeue \n");CHECK(DeQueue(&(Q), (pData)));debug_print("The result is : %d \n\n",*(pData));
#define testSizeOfQueue(Q,pResult) debug_print("Get size of Q \n");CHECK(SizeOfQueue((Q),(pResult)));debug_print("The result is : %d \n\n",*(pResult));
#define testClearQueue(Q) debug_print("Clear queue Q \n");CHECK(ClearQueue(&(Q)));

int main(void) {
	Queue Q;
	Elemtype data;/*���DeQueue������GetHead�����ķ��ؽ��*/
	int size;/*���SizeOfQueue�����ķ��ؽ��*/

	testInitQueue(Q);
	testTraverseQueue(Q);
	testSizeOfQueue(Q, &size);

	testEnQueue(Q, 5);
	testTraverseQueue(Q);
	testSizeOfQueue(Q, &size);

	testEnQueue(Q, 15);
	testTraverseQueue(Q);
	testSizeOfQueue(Q, &size);

	testEnQueue(Q, 25);
	testTraverseQueue(Q);
	testSizeOfQueue(Q, &size);

	testGetHead(Q, &data);

	testDeQueue(Q, &data);
	testTraverseQueue(Q);

	testDeQueue(Q, &data);
	testTraverseQueue(Q);

	testDeQueue(Q, &data);
	testTraverseQueue(Q);

	testEnQueue(Q, 1);
	testEnQueue(Q, 2);
	testEnQueue(Q, 3);
	testTraverseQueue(Q);
	testClearQueue(Q);

	testTraverseQueue(Q);

	/*�ڶӿ�ʱ���ӣ�����ERROR��������ֹ*/
	testDeQueue(Q, &data);

	return 0;
}