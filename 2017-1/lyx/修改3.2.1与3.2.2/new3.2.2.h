 #include <stdio.h> 
 #include <stdlib.h> 
 #include <time.h>//��������� 
 #define STACK_INIT_SIZE 100//����곣�� 
 typedef char SElemType;//����SElemTypeΪ�ַ��� 
 typedef enum 
{	OK, 
 	ERROR, 
	OVERFLOW 
 }Status;//ö�ٿ��ܵ����� 
 typedef struct _SqStack 
 {   SElemType *top; 
     SElemType*base; 
   	 int stacksize; 
 }SqStack;//����ṹ�� 
 typedef enum 
 {	true, 
 	false 
 }bool;//���岼�� 
 Status InitStack(SqStack *s);//����һ����ջ 
 Status brackets(SqStack *s,char*test);//����ƥ�亯�� 
 bool StackEmpty(SqStack *s);//��ջsΪ��ջ���򷵻�TRUE�����򷵻�FALSE 
 Status Pop(SqStack *s,SElemType *e);//��ջ���գ���ɾ��s��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR 
 Status GetTop(SqStack *s,SElemType *e);//��ջ���գ�����e����s��ջ��Ԫ�أ�������OK�����򷵻�ERROR 
 Status Push(SqStack *s,SElemType e);//����Ԫ��eΪ�µ�ջ��Ԫ�� 