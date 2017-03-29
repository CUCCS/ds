#include <stdio.h>
#include <stdlib.h>
#include "edit.h"

int main()
{
	SqStack sq;
	int f;
	LineEdit(&sq);//进行行编辑
	DestoryStack(&sq);//将栈销毁
	return 0;

}