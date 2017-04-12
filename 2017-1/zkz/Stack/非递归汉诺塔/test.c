
#include "Stack.h"

/*��ӡ3�����ӵ����*/
/*����С������Ϊ�˼�װ�Լ��Ǹ�����*/
#define showColumns() \
printf("Column1 : ");\
Traverse(column[0]);\
printf("\nColumn2 : ");\
Traverse(column[1]);\
printf("\nColumn3 : ");\
Traverse(column[2]);\
printf("\n\n")

/*����ṹ��*/
/*ÿ������ṹ������ĸ����� �� */
/*ת��Բ�̵�����+��������+������ȥ+��ת����*/
typedef struct _task{
	char mount;
	char from;
	char to;
	char temp;
}task;

/*�ڲ��ı�Elemtype�������*/
/*ʹtask���Գ���ջ*/
int encodeTask(task t) {
	return *(int *)&t;
}
task decodeTask(int n) {
	return *(task*)&n;
}

int main() {
	Stack column[3],S;/*3������+ģ��ݹ��ջ*/
	int n;/*��ŵ������*/
	int i;/*ѭ������*/

	InitStack(&column[0]);
	InitStack(&column[1]);
	InitStack(&column[2]);
	InitStack(&S);

	n = 5;
	for (i = n; i >= 1; --i) {
		Push(column[0], i);
	}

	showColumns();

	/*��ʼ��*/
	/*������ջS��һ��ʼ��һ������n��Բ�̴���1ת�Ƶ���3��������*/
	task t = {n,1,3,2};
	Push(S, encodeTask(t));
	
	/*ѭ���������ֱ������ջ��*/
	while (!isStackEmpty(S)) {
		/*��ȡ��ǰ����*/
		t = decodeTask(pop(S));
		/*����ǰ�����mountΪ1����ִ�иö���*/
		if (t.mount == 1) {
			printf("%d -> %d \n", t.from, t.to);
			Push(column[t.to - 1], pop(column[t.from - 1]));
			showColumns();
		}
		/*���򽫵�ǰ������Ϊ3��С����*/
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