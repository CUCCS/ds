//�ο��ٶȲ��ġ� ��
#include <stdio.h>  
#include <math.h>
#include "hanoi.h"
 
int GetTop(Stack S){ //ȡջ��Ԫ��
	return S.s[S.top];
}
int Pop(Stack *S){ //��ջ  
	return S->s[S->top--];
}
Status Push(Stack *S, int e){ //��ջ  
	if (e <= 0) {
		return ERROR;
	}
	S->s[++S->top] = e;
	return OK;
}
Status Create(Stack temp[], int n){ //���ṹ�������ó�ֵ  
	if (n <= 0) {
		return ERROR;
	}
	temp[0].name = 'A';
	temp[0].top = n - 1;
	//�����е�Բ�̰��Ӵ�С��˳���������A��  
	for (int i = 0; i < n; i++) {
		temp[0].s[i] = n - i;
	}
	//����B��C�Ͽ�ʼû��û��Բ��  
	temp[1].top = temp[2].top = 0;
	for (int i = 0; i < n; i++) {
		temp[1].s[i] = temp[2].s[i] = 0;
	}
	//��nΪż������˳ʱ�뷽�����ΰڷ� A B C  
	if (n % 2 == 0){
		temp[1].name = 'B';
		temp[2].name = 'C';
	}
	else{
		//��nΪ��������˳ʱ�뷽�����ΰڷ� A C B  
		temp[1].name = 'C';
		temp[2].name = 'B';
	}
	return OK;
}

Status Hanoi(Stack temp[], int max){ //�ƶ���ŵ������Ҫ����  
	int i, k; //�ۼ��ƶ��Ĵ���  
	i = k = 0;
	int ch, temp1, temp2;
	if (max <= 0) {
		return ERROR;
	}
	while (k < max)
	{
		//��˳ʱ�뷽���Բ��1�����ڵ������ƶ�����һ������  
		ch = Pop(&temp[i % 3]);
		Push(&temp[(i + 1) % 3], ch);
		printf("Move disk %d from %c to %c\n", ch, temp[i % 3].name, temp[(i + 1) % 3].name);
		i++;
		//���������������Ͽ����ƶ���Բ���ƶ����µ�������  
		if (k < max){
			temp1 = GetTop(temp[(i + 1) % 3]);
			temp2 = GetTop(temp[(i - 1) % 3]);
			//�ѷǿ������ϵ�Բ���ƶ����������ϣ����������Ӷ�Ϊ��ʱ���ƶ���С��Բ��  
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
	printf("�����뺺ŵ���Ľ�����");
	scanf("%d", &n); //����Բ�̵ĸ���  
	max = pow(2, n) - 1; //�ƶ��Ĵ���Ӧ����2^n - 1
	Stack S[3]; //�������ӵ���Ϣ�ýṹ����洢  
	Create(S, n); //���ṹ�������ó�ֵ  
	Hanoi(S, max); //�ƶ���ŵ������Ҫ����  
	printf("�ƶ�����Ϊ��%d", max);
	return 0;
}