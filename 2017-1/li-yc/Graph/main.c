#include "Graph.h"

int main() {
	Graph a = CreatGraph(9);
	int x;
	int y;

	InitTestGraph(&a);
	//TraverseGraph(a);

	printf("��ʼ����ÿ���㵽����һ��������·��\n");
	for (x = 1; x <= 9; x++) {
		for (y = 1; y <= 9; y++) {
			if (x != y) {
				printf("<%d --> %d>", x, y);
				BFSTraverse(&a, x - 1, y - 1);
				printf("\n");
			}
		}
	}
	printf("��������\n");
	return 0;
}