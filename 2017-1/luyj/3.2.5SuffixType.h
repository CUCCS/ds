
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_INIT_SIZE 100

typedef char *SElemType;
typedef double SElem;
typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;
typedef struct _SqStack
{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

typedef struct _SqStack1
{
	SElem *base;
	SElem *top;
	int stacksize;
}SqStack1;

typedef enum
{
	true,
	false
}bool;


//��ջ��Ϊ�գ�ɾ��ջ��Ԫ�أ���e������ֵ��
Status Pop(SqStack*s, SElemType*e);

//�ж�ջ�Ƿ�Ϊ�գ�
bool StackEmpty(SqStack*s);

//����һ����ջ��
Status InitStack(SqStack*s);

//����Ԫ��eΪ�µ�ջ��Ԫ�أ�
Status Push(SqStack*s, SElemType e);

//��ջ��Ϊ�գ���e����ջ��Ԫ�أ�
Status GetTop(SqStack *s, SElemType *e);


Status Pop1(SqStack1*s, SElem*e);
bool StackEmpty1(SqStack1*s);
Status InitStack1(SqStack1*s);
Status Push1(SqStack1*s, SElem e);

//�ж�����������ȼ���
int Level(char character);
bool Precede(SElemType*c, char ch);

//�ж��Ƿ�Ϊ�������
bool IN(char ch);

//��ch�����飻
Status Pass(char suffix[50], char ch);

//ʵ�ֺ�׺ʽ��
void transform(char suffix[100], char exp[50][50], SqStack*s);

//���ú�׺ʽ���ݼ�����ջ�ͷ���ջ�������ݵļ�+-*/���㣻
void EvaluateExpression(SqStack *s2, SqStack1*s3, char suffix[100]);