#include"operation.h"
#include <string.h>
int main() {
	char a[100] = { "7+(3*4-6)/3#" };
	int c;
	printf("中缀表达式为：\n");
	puts(a);
	char b[100] = { '\0' };
	transform(b, a);
	printf("\n后缀表达式为：\n");
	puts(b);
	c = count(b);
	printf("\n结果为：\n");
	printf("%d", c);
	printf("\n");
	return 0;
}
