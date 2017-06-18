#include <stdio.h>
#include "LinkList.h"
#define length 20
int main() {
	LinkList A = CreatList(length),
		a1 = CreatList(length/2),
		a2 = CreatList(length/2);
	TraverseList(A);
	SeparateList(A, a1, a2);
	TraverseList(a1);
	TraverseList(a2);
	return 0;
}