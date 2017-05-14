#include "Queue.h"

/*这些test+函数名的宏*/
/*用于测试对应函数运行是否正常*/
/*并打印相关信息*/
#define testInitQueue(Q) debug_print("Initialize queue Q \n");CHECK(InitQueue(&(Q)));
#define testTraverseQueue(Q) 	debug_print("Traverse Q : ");CHECK(TraverseQueue((Q)));printf("\n\n");
#define testEnQueue(Q,data) debug_print("Enqueue %d \n",(data));CHECK(EnQueue(&(Q), (data)));
#define testGetHead(Q,pData) debug_print("Get head of Q \n");CHECK(GetHead((Q),(pData)));debug_print("The result is : %d \n\n",*(pData));
#define testDeQueue(Q,pData) debug_print("Dequeue \n");CHECK(DeQueue(&(Q), (pData)));debug_print("The result is : %d \n\n",*(pData));
#define testSizeOfQueue(Q,pResult) debug_print("Get size of Q \n");CHECK(SizeOfQueue((Q),(pResult)));debug_print("The result is : %d \n\n",*(pResult));
#define testClearQueue(Q) debug_print("Clear queue Q \n");CHECK(ClearQueue(&(Q)));

int main(void) {
	Queue Q;
	Elemtype data;/*存放DeQueue函数和GetHead函数的返回结果*/
	int size;/*存放SizeOfQueue函数的返回结果*/

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

	/*在队空时出队，返回ERROR，程序中止*/
	testDeQueue(Q, &data);

	return 0;
}