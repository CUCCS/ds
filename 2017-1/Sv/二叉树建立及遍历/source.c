#include"Tree.h"
int main(){
    char *p=(char*)malloc(100*sizeof(char));
	//scanf("%s",p);
	//用0代替空树结点
	//p = "ABDG000EH00I0K00C0F00";
        p = "ABD0F000CE000";
	printf("测试字符串:\n%s\n", p);
	BiTNode *T=NULL;
	printf("后序序列：\n");
	T=CreateBiTree(T,p);
	Preorder(T);
}