#include "BinaryTree.h"
int main()
{
	BiTree T = NULL;
	Status ret;
	TElemType str1[50] = "ABDG###EH##I#K##C#F##";
	TElemType str2[50] = "ABD#F###CE###";

	ret = CreateBiTree(&T, str1);//"ret" is used to text wether the operation of Create succeed or not
	printf("The First Binary Tree : ABDG###EH##I#K##C#F##\n");
	printf("PostOrder Traverse    :  ");
	PostOrderTraverse(T);
	printf("\nDepth                 : %d\n", Depth(T));
	printf("Width                 : %d\n", Width(T));
	printf("LeafCount             : %d\n", Count(T));
	printf("NoLeafCount           : %d\n", NoLeafCount(T));

	extern int count;
	count = 0;//"count" is redefined to begin the second binary's postorder tarverse

	ret = CreateBiTree(&T, str2);
	printf("\n\nThe Second Binary Tree : ABD#F###CE###\n");
	printf("PostOrder Traverse     :  ");
	PostOrderTraverse(T);
	printf("\nDepth                  : %d\n", Depth(T));
	printf("Width                  : %d\n", Width(T));
	printf("LeafCount              : %d\n", Count(T));
	printf("NoLeafCount            : %d\n", NoLeafCount(T));
}