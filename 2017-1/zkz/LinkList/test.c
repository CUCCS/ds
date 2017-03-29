#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkList.h"

/*������������ָ�������������ʱ���ȵķ�Χ*/
#define MAXLEN 7
#define MINLEN 2
/*���ڴ���ÿ��LinkList�����ķ���ֵ*/
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