#define MAX 64 //圆盘的个数最多为64  
typedef struct {
	int s[MAX]; //柱子上的圆盘存储情况  
	int top; //栈顶，用来最上面的圆盘  
	char name; //柱子的名字，可以是A，B，C中的一个  
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