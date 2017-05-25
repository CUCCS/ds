#include"Source.h"
 status CreatBiTree(BiTree *t, char *x)
 {
	ElemType ch, temp;
	ch = x[number];
	number++;
	if (ch == '*')
		 {
		*t = NULL;
		}
	else
		 {
		*t = (BiTree)malloc(sizeof(BitNode));//分配空间进行存储
		if (!(*t))//如果分配失败
			 {
			exit(-1);
			}
		(*t)->date = ch;//生成根节点
		CreatBiTree(&(*t)->lChild, x);//构造左子树
		CreatBiTree(&(*t)->rChild, x);//构造右子树	
		}
	return 1;
	}
void  VisitHouxu(BiTree t)//后续遍历
 {
	if (t == NULL)
		 {
		return;
		}
	VisitHouxu(t->lChild);//访问左子树
	VisitHouxu(t->rChild);//访问右子树
	printf("%c ", t->date);
	}
//后序遍历二叉树
int main()
 {
	BiTree t;
	ElemType  n[num];
	printf("请输入要进行转化的字符串   *代表为空\n");
	scanf("%s", n);
	printf("*代表空\n");
	CreatBiTree(&t, n);//产生二叉树  
	printf("后序遍历的顺序为\n");
	VisitHouxu(t);//后序遍历二叉树
	return 0;
	}