
#include "Stack.h"

/*打印3个柱子的情况*/
/*加上小括号是为了假装自己是个函数*/
#define showColumns() \
printf("Column1 : ");\
Traverse(column[0]);\
printf("\nColumn2 : ");\
Traverse(column[1]);\
printf("\nColumn3 : ");\
Traverse(column[2]);\
printf("\n\n")

/*任务结构体*/
/*每个任务结构体包含四个部分 ： */
/*转移圆盘的数量+从哪里来+到哪里去+中转柱子*/
typedef struct _task{
	char mount;
	char from;
	char to;
	char temp;
}task;

/*在不改变Elemtype的情况下*/
/*使task可以出入栈*/
int encodeTask(task t) {
	return *(int *)&t;
}
task decodeTask(int n) {
	return *(task*)&n;
}

int main() {
	Stack column[3],S;/*3个柱子+模拟递归的栈*/
	int n;/*汉诺塔层数*/
	int i;/*循环变量*/

	InitStack(&column[0]);
	InitStack(&column[1]);
	InitStack(&column[2]);
	InitStack(&S);

	n = 5;
	for (i = n; i >= 1; --i) {
		Push(column[0], i);
	}

	showColumns();

	/*初始化*/
	/*即任务栈S里一开始有一个“将n个圆盘从柱1转移到柱3”的任务*/
	task t = {n,1,3,2};
	Push(S, encodeTask(t));
	
	/*循环完成任务，直到任务栈空*/
	while (!isStackEmpty(S)) {
		/*获取当前任务*/
		t = decodeTask(pop(S));
		/*若当前任务的mount为1，则执行该动作*/
		if (t.mount == 1) {
			printf("%d -> %d \n", t.from, t.to);
			Push(column[t.to - 1], pop(column[t.from - 1]));
			showColumns();
		}
		/*否则将当前任务拆解为3个小任务*/
		else {
			task temp3 = { t.mount - 1,t.temp,t.to,t.from };
			task temp2 = { 1,t.from,t.to,t.temp };
			task temp1 = { t.mount - 1,t.from,t.temp,t.to };
			Push(S, encodeTask(temp3));
			Push(S, encodeTask(temp2));
			Push(S, encodeTask(temp1));
		}
	}

	return 0;
}