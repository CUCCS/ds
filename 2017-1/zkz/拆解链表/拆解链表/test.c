#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Linklist.h"

#define MAXLEN 5
#define MINLEN 0

int test() {
	Linklist list, l1, l2;

	srand(rand());
	InitList(&list,rd(MINLEN, MAXLEN));

	printf("list : ");
	TraverseList(list);

	checkStatu(DivideList(list,&l1,&l2));
	printf("\n\nDivide list as l1 and l2 \n");
	printf("l1->data : %d \n", l1->data);
	printf("l1   : ");
	TraverseList(l1->next);

	printf("l2->data : %d \n", l2->data);
	printf("l2   : ");
	TraverseList(l2->next);
}
int main() {
	srand(time(0));
	while (1) {
		system("cls");
		test();
		system("pause");
	}
}