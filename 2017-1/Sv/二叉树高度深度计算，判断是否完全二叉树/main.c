#include"Tree.h"
typedef BiTNode QElemType;
int main(){
    char *p=(char*)malloc(100*sizeof(char));
    //scanf("%s",p);
    //用0代替空树结点
    //p = "ABDG000EH00I0K00C0F00";
   // p = "ABD0F000CE000";
    // p = "ABDG00Q00EH00I00CQ00F00";
    //p="ABD00E00CF00G00";
    p="ABD00E00C0F00";
    printf("先序测试字符串:\n%s\n", p);
    BiTNode *T=NULL;
   // printf("后序序列：\n");
    T=CreateBiTree(T,p);
    //Preorder(T);
    //printf("高度：%d\n",Depth(T));
    printf("宽度最大值：%d\n",LevelOrderTraverseTree(T));
    if(CheckComplete(T)==FALSE){
        printf("非完全二叉树");
    }
    else{
		printf("完全二叉树\n");
    }
    
}