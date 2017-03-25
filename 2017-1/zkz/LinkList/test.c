#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkList.h"

/*这两个宏用于指定随机生成链表时长度的范围*/
#define MAXLEN 7
#define MINLEN 2
/*用于处理每个LinkList函数的返回值*/
#define SOLVEFLAG \
do {\
	switch (flag) {\
	case OK:\
		break;\
	case ERROR:\
		DEBUG && printf("ERROR");\
		return 1;\
		break;\
	case OVERFLOW:\
		DEBUG && printf("OVERFLOW");\
		return 1;\
		break;\
	default:\
		break;\
	}\
} while (0)

int main(void) {
	srand(time(0));
	srand(rand());

	LinkList La = NEWNODE;
	LinkList Lb = NEWNODE;
	LinkList Lc = NEWNODE;
	int flag;
	flag = CreateList(La, rand() % (MAXLEN - MINLEN + 1) + MINLEN);
	SOLVEFLAG;
	flag = CreateList(Lb, rand() % (MAXLEN - MINLEN + 1) + MINLEN);
	SOLVEFLAG;
	flag = MergeList(La, Lb, Lc);
	SOLVEFLAG;
	printf("La : ");
	flag = TravelList(La);
	SOLVEFLAG;
	printf("\nLb : ");
	flag = TravelList(Lb);
	SOLVEFLAG;
	printf("\nLc : ");
	flag = TravelList(Lc);
	SOLVEFLAG;
	printf("\n");
}