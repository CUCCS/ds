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

#include "BTree.h"

char input[] = {'A', 'B', 'D', 'G', '#', '#','#', 'E', 'H', '#', '#', 'I', '#', 'K', '#', '#', 'C', '#', 'F', '#', '#', '\0'};
int input_i = 0;

int main(int argc, char* argv[])
{
    BiTree T = NULL;
    Status ret;

    ret = CreateBiTree(&T);

    if(ret == OK) {
        printf("二叉树 %s 创建成功\n", input);
    }

    printf("该二叉树的后序序列输出为：\n");
    PostOrderTraverseTree(T);

    printf("\n");

    return 0;
}

