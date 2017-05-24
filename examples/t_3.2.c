/*******************************************************************************
  文件名: 
  项目:   
  模块:   
  作者:   huangwei
  版本:   0.1
  创建于:  
  描述:

  修改历史:
  日期:     修改人:    修改描述:

 *********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "3.2.h"

Status matching(SqStack S, char *exp, char dict[]) {
    int state = 1;
    int i = 0;
    int len = strlen(exp);
    SElemType e;

    DEBUG && printf("%lu\n", strlen(exp));

    while (i <= len && state) {
        switch(*exp) {
            case '(':  
            case '[':  
            case '{':  
                DEBUG && printf("hit ( with %c\n", *exp);
                Push(&S, *exp++); 
                i++;
                break;
            case ')': 
            case ']':  
            case '}':  
                DEBUG && printf("hit ) with %c \n", GetTop(S));
                if(!IsStackEmpty(&S) && GetTop(S) == dict[(int)*exp]) {
                    DEBUG && printf("poped\n");
                    Pop(&S, &e);  
                    DEBUG && printf("poped with %c %d %c\n", e, i, *exp);
                } else {
                    state = 0;
                }
                exp++;
                i++;
                break;  
            default:
                DEBUG && printf("%c\n", *exp);
                i++;
                exp++;
                break;
        }
    }

    if (IsStackEmpty(&S) && state) {
        return OK; 
    }

    return ERROR;
}

int main(int argc, char* argv[])
{

    SqStack S;
    Status ret;
    char dict[127];
    char test[100];
    scanf("%s", (unsigned char *)&test);

    // make dict hashmap
    dict[']'] = '[';
    dict[')'] = '(';
    dict['}'] = '{';

    InitStack(&S, STACK_SIZE);

    ret = matching(S, test, dict);

    if(ret == OK) {
        printf("matched!\n");
    } else {
        printf("not matched!\n");
    }

    return 0;
}

