#include "MapPath.h"
int main()
{
	Array A = {
		1,1,1,1,0,0,1,0,0 ,
		1,1,1,0,0,0,0,0,0 ,
		1,1,1,0,0,0,0,0,0 ,
		1,0,0,1,1,1,0,0,0 ,
		0,0,0,1,1,1,0,0,0 ,
		0,0,0,1,1,1,0,1,0 ,
		1,0,0,0,0,0,1,1,1 ,
		0,0,0,0,0,1,1,1,1 ,
		0,0,0,0,0,0,1,1,1
	};
	Graph G;
	LinkQueue Q;
	CreatGraph(&G, A);
	for (int i = 1; i < MAX + 1; i++) {
		for (int j = 1; j < MAX + 1; j++) {
			if (i != j) {
				Q = BFSTraverse(G, i, j);//������ȱ�������i��j����С·��
				Print(Q, i, j);
			}

		}
		printf("\n");
	}
}