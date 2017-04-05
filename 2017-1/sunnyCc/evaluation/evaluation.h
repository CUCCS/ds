#pragma once
#define TRUE 1  
#define FALSE 0  
#define Stack_Size 50  

typedef struct
{
	char elem[Stack_Size];
	int top;
}SeqStack;     /*�����ջ�Ķ���*/

typedef struct
{
	int elem[Stack_Size];
	int top;
}nSeqStack;   /* ������ջ�Ķ���*/

void InitStack(SeqStack *S);  /*��ʼ�������ջ*/
void InitStackn(nSeqStack *S); /*��ʼ��������ջ*/
int IsEmpty(SeqStack *S); /*�ж�ջSΪ��ջʱ����ֵΪ�棬��֮Ϊ��*/
int IsEmptyn(nSeqStack *S); /*�ж�ջSΪ��ջʱ����ֵΪ�棬��֮Ϊ��*/
int IsFull(SeqStack *S); /*�ж�ջSΪ��ջʱ����ֵΪ�棬��֮Ϊ��*/
int IsFulln(nSeqStack *S);   /*�ж�ջSΪ��ջʱ����ֵΪ�棬��֮Ϊ��*/
int Push(SeqStack *S, char x);   /*�����ջ��ջ����*/
int Pushn(nSeqStack *S, int x); /*������ջ��ջ����*/
int Pop(SeqStack *S, char *x);  /*�����ջ��ջ����*/
int Popn(nSeqStack *S, int *x);  /*������ջ��ջ����*/
char GetTop(SeqStack *S);  /*�����ջȡջ��Ԫ�غ���*/
int GetTopn(nSeqStack *S);  /*������ջȡջ��Ԫ�غ���*/
int Isoperator(char ch);   /*�ж������ַ��Ƿ�Ϊ���������,�Ƿ���TRUE,���Ƿ���FALSE*/
char Compare(char ch1, char ch2);  /*�Ƚ���������ȼ�����*/
int Execute(int a, char op, int b);  /*���㺯��*/
int ExpEvaluation(); /*����һ�����������ʽ��������ֵ��optr��operand�ֱ�Ϊ�����ջ��������ջ��OPSΪ���������*/
