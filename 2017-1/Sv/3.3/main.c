
#include"3.3.h"
int main() {
	char a[100] = {"4+(3*3-6)/3#"/*"(8+4)*3/2-1#"*/};
	printf("��׺���ʽΪ��\n");
	puts(a);
	char b[100] = { '\0' };
	transform(b,a);
	printf("\n��׺���ʽΪ��\n");
	puts(b);
	int c = count(b);
	printf("\n���Ϊ��\n");
	printf("%d", c);
}