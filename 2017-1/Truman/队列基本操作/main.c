#include"Queue.h"
int main() {
	srand(time(0));
	int i,a,n,temp;
	LinkQueue Q;
	n = rand() % 10 + 5;
	InitQueue(&Q);
	printf("���%d�����ֽ����У�\n",n);
	for (i = 0; i < n; i++) {
		a = rand() % 100 + 1;
		printf("%d ", a);
		EnQueue(&Q, a);
	}
	printf("\n������ǰ���У�\n");
	QueueTraverse(Q);
	n = rand() % 4+1;
	printf("\nɾ��ǰ%d������Ԫ�أ����У�:\n",n);
	for (i = 0; i < n; i++) {
		DeQueue(&Q, &temp);
		printf("%d ", temp);
	}
	printf("\n������ǰ���У�\n");
	QueueTraverse(Q);
	printf("\n��ǰ���г��ȣ�\n%d\n", QueueLength(Q));
	printf("��ն���\n");
	ClearQueue(&Q);
	n = rand() % 10 + 1;
	printf("�������%d�����ֽ����У�\n", n);
	for (i = 0; i < n; i++) {
		a = rand() % 100 + 1;
		printf("%d  ", a);
		EnQueue(&Q, a);
	}
	printf("\n������ǰ���У�\n");
	QueueTraverse(Q);
	printf("\n���ٶ���\n");
	DestroyQueue(&Q);
}