#include "new3.2.2.h" 
int main () 
{ 
 SqStack s;//构造空栈 
 Status ret;//返回值 
 int x=0;//定义整数x 
 srand(time (0));//随机数 
 x = rand()%10;//使随机数保证在0-9之间 
 char test[10];//定义一个字符串，大小为10 
 char s_test[6] = { '{','}','(',')','[',']'};//定义字符串，并枚举出字符 
 for(int i = 0;i<x;i++)//遍历字符串 
 { 
  test[i] = s_test[rand()%6];//初始化字符串 
  } 
  test[x] = '\0';//使最后一个字符为结束字符 
  printf("随机产生字符串\n");//表示随机字符 
  puts(test);//输出随机生成的字符串 
  printf("process");//过程 
  InitStack(&s);//构造一个空栈 
  ret=brackets(&s,test);//括号匹配函数 返回值传给ret 
  if(ret==OK){//如果ret为OK 
      printf("matched");//匹配成功 
  } 
  else{//如果ret不为OK 
	  printf("don't matched");//匹配不成功 
  } 
}