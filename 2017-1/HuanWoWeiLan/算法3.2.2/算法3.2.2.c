#include <stdio.h>
#include <string.h>
#define MAX_STACK 100

struct stStack
{
   char szStack[MAX_STACK];
   int nTop;
};

void InitStack(stStack *s)
{
    s->nTop = -1;
}

char Push(stStack *s, char c)
{
   if(s->nTop == MAX_STACK - 1)
   return 0;
 
 s->nTop ++;
 s->szStack[s->nTop] = c;
 return c;
}

char Pop(stStack *s)
{
   if (s->nTop == -1)
   {
    return 0;
   }
   char c = s->szStack[s->nTop];
   s->nTop--;
   return c;
}

int Check(char* szText)
{
 stStack *s;
 InitStack(s);
 int nLen = strlen(szText);
 for (int i = 0; i  < nLen; i++)
 {
  char c = szText[i];
  
  switch (c)
  {
  case '(':
  case '{':
  case '[':
   Push(s, c);
   break;
   
  case ')':
   if (Pop(s) != '(')
    return 0;
   break;
  case '}':
   if (Pop(s) != '{')
    return 0;
   break;
  case ']':
   if (Pop(s) != '[')
    return 0;
   break;
  }
 }
 return 1;
}

int main()
{
     char szText[100];
     scanf("%s", szText);
	 if (Check(szText)){
      printf("ºÏ·¨\n"); }
 else
 {
  printf("Ê§°Ü\n");
 }
 return 0;
}