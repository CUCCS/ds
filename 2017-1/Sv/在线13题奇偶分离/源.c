#include"List.h"
int main() {
	srand(time(0));
	int n = rand() % 10 + 1;
	LinkList L = (LinkList)malloc(sizeof(LNode));
	LinkList L1 = (LinkList)malloc(sizeof(LNode));
	LinkList L2 = (LinkList)malloc(sizeof(LNode));
	CreateList(L, n);
	printf("���������\n");
	PRINT(L);
	printf("\n��������ż����:\n");
	SperateList(L, L1, L2, n);
	printf("���У�\n");
	PRINT(L1);
	printf("ż�У�\n");
	PRINT(L2);
	//ʱ�临�Ӷ�O(n),��ż���봴���б���һ������
}