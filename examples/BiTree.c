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

#include "BiTree.h"

extern char input[];
extern int input_i;

Status CreateBiTree(BiTree *T) {
    char ch = input[input_i];
    input_i++;
    if(ch == '#') { 
        *T = NULL;
    } else {
        if( !(*T = (BiTree)malloc(sizeof(BiTNode))) ) {
            return OVERFLOW;
        }
        (*T)->data = ch;              // 生成根结点
        CreateBiTree(&(*T)->lchild);   // 构造左子树
        CreateBiTree(&(*T)->rchild);   // 构造右子树
    }
    return OK;  
}

void PostOrderTraverseTree(BiTree T) {
    if(T) {
        PostOrderTraverseTree(T->lchild); // 遍历左子树
        PostOrderTraverseTree(T->rchild); // 遍历右子树
        printf("%c", T->data);             // 访问结点
    }
}

