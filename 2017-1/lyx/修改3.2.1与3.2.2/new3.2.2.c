#include "new3.2.2.h" 
int main () 
{ 
 SqStack s;//�����ջ 
 Status ret;//����ֵ 
 int x=0;//��������x 
 srand(time (0));//����� 
 x = rand()%10;//ʹ�������֤��0-9֮�� 
 char test[10];//����һ���ַ�������СΪ10 
 char s_test[6] = { '{','}','(',')','[',']'};//�����ַ�������ö�ٳ��ַ� 
 for(int i = 0;i<x;i++)//�����ַ��� 
 { 
  test[i] = s_test[rand()%6];//��ʼ���ַ��� 
  } 
  test[x] = '\0';//ʹ���һ���ַ�Ϊ�����ַ� 
  printf("��������ַ���\n");//��ʾ����ַ� 
  puts(test);//���������ɵ��ַ��� 
  printf("process");//���� 
  InitStack(&s);//����һ����ջ 
  ret=brackets(&s,test);//����ƥ�亯�� ����ֵ����ret 
  if(ret==OK){//���retΪOK 
      printf("matched");//ƥ��ɹ� 
  } 
  else{//���ret��ΪOK 
	  printf("don't matched");//ƥ�䲻�ɹ� 
  } 
}