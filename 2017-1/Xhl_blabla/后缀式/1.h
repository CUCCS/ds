//����ð�˳��ջ�ĳ���ʽջ��
//ֻ�ܴ�����һ�����ŵ�����ʽ  ����������Ҫ��ȫ�� int ����
//ֻ�ܽ��д�����ļ���  ��Ϊû�������ݴ�����λ
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SUANSHUSHI_NUM 20//�����ʽ�����ڵ�����ĳ���
#define DATE_NUM 10      //ջ���ַ���Ԫ�صĳ���
#define STACR_INIT_SIZE 100
#define  STACR_ADD_SIZE 10
#define  WEIDU_NUM 20;
typedef struct ElemType
{
	char  *date;
	struct ElemType *pNext;
}ElemType;
typedef int status;//�����ı���
typedef struct
{
	ElemType  *base;
	ElemType   *top;
}stack;//���ڴ洢������Ͳ�������ջ  
status initstack(stack *s);//��ʼ��ջ  
status destory(stack *s);//����ջ
status isStackempty(stack s);//����ջ�Ƿ�Ϊ��  �Ƿ���0 �񷵻�1
status judgenumber(char x);//�����ж������ֻ��ǲ����� ��������� 1 ���޷�����-1  ���緵��-10 ���ַ���0
status rank_list(stack*, char x[]);//���ں�׺ʽ������
status cal_list(stack);//���ں�׺ʽ��������  �����ֺ������
char** conversion(char x[]);//�����ַ����Ĳ��
status judge_pre(char);//���ַ������ȼ����бȽ�  ���ȼ�Խ������Խ��
status push(stack *s, char *e);
status initstack(stack* s);//����һ����ջ������û���κ���Ч���ݣ�  
status Pop_Stack(stack *S, char ** val);
void Traverse_Stack(stack s);//��ӡջ
int cal(int a, int b, char x);//����

