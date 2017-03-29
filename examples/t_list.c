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

#include "myds.h"
#include "list.h"

void dbgprint(LinkList L, int max) {
	int i;
    for(i = 1; i <= max; i++) {
        ElemType e;
        Status status = GetElem_L(L, i, &e);
        if(status != OK) {
            fprintf(stderr, "%s\n", "GetElem_L failed");
            exit(1);
        }
        printf("%8d", e);
    }
    printf("\n");
}


int main(int argc, char* argv[])
{
	int max = 3;

    /***
     * 测试CreateList_L
     */
	LinkList L = (LNode *)malloc(sizeof(LNode));
	Status status = CreateList_L(L, max);
    if(status != OK) {
        fprintf(stderr, "%s\n", "CreateList_L failed");
        exit(1);
    }
	
    /**
     * 测试GetElem_L
     */
    dbgprint(L, max);

	/**
     * 测试ListInsert_L
     */
    status = ListInsert_L(L, 2, 10);
    dbgprint(L, max+1);

    status = ListInsert_L(L, 2, 20);
    if(status != OK) {
        fprintf(stderr, "%s\n", "ListInsert_L failed!");
        exit(1);
    }
    dbgprint(L, max+2);

    status = ListDelete_L(L, 3);
    if(status != OK) {
        fprintf(stderr, "%s\n", "ListDelete_L failed!");
        exit(1);
    }
    dbgprint(L, max+1);

    status = ListDelete_L(L, 1);
    if(status != OK) {
        fprintf(stderr, "%s\n", "ListDelete_L failed!");
        exit(1);
    }
    dbgprint(L, max);

	status = ClearList(L);
    switch(status) {
        case OK:
            printf("ClearList OK!\n");
            break;
        case ERROR:
            fprintf(stderr, "%s\n", "ClearList failed!");
            exit(1);
            break;
        default:
            fprintf(stderr, "%s\n", "ClearList failed with unknown status code!");
            exit(1);
            break;
    }

    return 0;
}

