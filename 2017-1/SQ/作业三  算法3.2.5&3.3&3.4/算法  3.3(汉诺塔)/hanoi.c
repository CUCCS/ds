//参考百度博文← ←
#include <stdio.h>  
#include <math.h>
#include "hanoi.h"
 
int GetTop(Stack S){ //取栈顶元素
	return S.s[S.top];
}
int Pop(Stack *S){ //出栈  
	return S->s[S->top--];
}
Status Push(Stack *S, int e){ //入栈  
	if (e <= 0) {
		return ERROR;
	}
	S->s[++S->top] = e;
	return OK;
}
Status Create(Stack temp[], int n){ //给结构数组设置初值  
	if (n <= 0) {
		return ERROR;
	}
	temp[0].name = 'A';
	temp[0].top = n - 1;
	//把所有的圆盘按从大到小的顺序放在柱子A上  
	for (int i = 0; i < n; i++) {
		temp[0].s[i] = n - i;
	}
	//柱子B，C上开始没有没有圆盘  
	temp[1].top = temp[2].top = 0;
	for (int i = 0; i < n; i++) {
		temp[1].s[i] = temp[2].s[i] = 0;
	}
	//若n为偶数，按顺时针方向依次摆放 A B C  
	if (n % 2 == 0){
		temp[1].name = 'B';
		temp[2].name = 'C';
	}
	else{
		//若n为奇数，按顺时针方向依次摆放 A C B  
		temp[1].name = 'C';
		temp[2].name = 'B';
	}
	return OK;
}

Status Hanoi(Stack temp[], int max){ //移动汉诺塔的主要函数  
	int i, k; //累计移动的次数  
	i = k = 0;
	int ch, temp1, temp2;
	if (max <= 0) {
		return ERROR;
	}
	while (k < max)
	{
		//按顺时针方向把圆盘1从现在的柱子移动到下一根柱子  
		ch = Pop(&temp[i % 3]);
		Push(&temp[(i + 1) % 3], ch);
		printf("Move disk %d from %c to %c\n", ch, temp[i % 3].name, temp[(i + 1) % 3].name);
		i++;
		//把另外两根柱子上可以移动的圆盘移动到新的柱子上  
		if (k < max){
			temp1 = GetTop(temp[(i + 1) % 3]);
			temp2 = GetTop(temp[(i - 1) % 3]);
			//把非空柱子上的圆盘移动到空柱子上，当两根柱子都为空时，移动较小的圆盘  
			if (temp1 == 0 ||temp2 > 0 &&temp1 > temp2){
				ch = Pop(&temp[(i - 1) % 3]);
				Push(&temp[(i + 1) % 3], ch);
				++k;
				printf("Move disk %d from %c to %c\n", ch, temp[(i - 1) % 3].name,temp[(i + 1) % 3].name);
			}
			else{
				ch = Pop(&temp[(i + 1) % 3]);
				Push(&temp[(i - 1) % 3], ch);
				++k;
				printf("Move disk %d from %c to %c\n", ch, temp[(i + 1) % 3].name, temp[(i - 1) % 3].name);
			}
		}
	}
}
int main(){
	int n, max;
	printf("请输入汉诺塔的阶数：");
	scanf("%d", &n); //输入圆盘的个数  
	max = pow(2, n) - 1; //移动的次数应等于2^n - 1
	Stack S[3]; //三根柱子的信息用结构数组存储  
	Create(S, n); //给结构数组设置初值  
	Hanoi(S, max); //移动汉诺塔的主要函数  
	printf("移动次数为：%d", max);
	return 0;
}