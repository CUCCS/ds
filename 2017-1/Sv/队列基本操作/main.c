#include"Queue.h"
int main() {
	srand(time(0));
	int i,a,n,temp;
	LinkQueue Q;
	n = rand() % 10 + 5;
	InitQueue(&Q);
	printf("随机%d个数字进队列：\n",n);
	for (i = 0; i < n; i++) {
		a = rand() % 100 + 1;
		printf("%d ", a);
		EnQueue(&Q, a);
	}
	printf("\n遍历当前队列：\n");
	QueueTraverse(Q);
	n = rand() % 4+1;
	printf("\n删除前%d个队伍元素（出列）:\n",n);
	for (i = 0; i < n; i++) {
		DeQueue(&Q, &temp);
		printf("%d ", temp);
	}
	printf("\n遍历当前队列：\n");
	QueueTraverse(Q);
	printf("\n当前队列长度：\n%d\n", QueueLength(Q));
	printf("清空队列\n");
	ClearQueue(&Q);
	n = rand() % 10 + 1;
	printf("重新随机%d个数字进队列：\n", n);
	for (i = 0; i < n; i++) {
		a = rand() % 100 + 1;
		printf("%d  ", a);
		EnQueue(&Q, a);
	}
	printf("\n遍历当前队列：\n");
	QueueTraverse(Q);
	printf("\n销毁队列\n");
	DestroyQueue(&Q);
}