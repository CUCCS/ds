#define MAX 64 //Բ�̵ĸ������Ϊ64  
typedef struct {
	int s[MAX]; //�����ϵ�Բ�̴洢���  
	int top; //ջ���������������Բ��  
	char name; //���ӵ����֣�������A��B��C�е�һ��  
}Stack;
typedef enum {
	ERROR,
	OK
}Status;

int GetTop(Stack S);
int Pop(Stack *S);
Status Push(Stack *S, int e);
Status Create(Stack temp[], int n);
Status Hanoi(Stack temp[], int max);