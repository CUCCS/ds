#include"operation.h"
#include <string.h>
int main() {
	char a[100] = { "7+(3*4-6)/3#" };
	int c;
	printf("��׺���ʽΪ��\n");
	puts(a);
	char b[100] = { '\0' };
	transform(b, a);
	printf("\n��׺���ʽΪ��\n");
	puts(b);
	c = count(b);
	printf("\n���Ϊ��\n");
	printf("%d", c);
	printf("\n");
	return 0;
}
