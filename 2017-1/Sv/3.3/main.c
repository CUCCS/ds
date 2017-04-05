
#include"3.3.h"
int main() {
	char a[100] = {"4+(3*3-6)/3#"/*"(8+4)*3/2-1#"*/};
	printf("中缀表达式为：\n");
	puts(a);
	char b[100] = { '\0' };
	transform(b,a);
	printf("\n后缀表达式为：\n");
	puts(b);
	int c = count(b);
	printf("\n结果为：\n");
	printf("%d", c);
}