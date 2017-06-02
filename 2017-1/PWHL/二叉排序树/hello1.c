#include "hello.h"
int k = 0;
int main()
{
	FILE *fp;
	char z[4] = "\n";
	fp = fopen("BSTOutput.txt", "a");
	int  number[num_length] = { 8, 10,14, 3, 1,  6, 4, 7, 5, 19,  22, 30 };
	int search[s_length] = { 13, 8, 5, 20, 6 };
	BiTree T = NULL;
	int i;
	for (i = 0; i < 12; i++)
	{
		InsertBST(&T, number[i]);
		T->data;
	}
	print(T, fp);
	fputs(z, fp);
	//printf("\n"); 
	for (i = 0; i < 5; i++)
	{//如果插入失败  就进行删除操作 
		k = 0;//初始化计数的数字 
		if (!InsertBST(&T, search[i]))
		{
			DeleteBST(&T, search[i]);
		}
		print(T, fp);
		//printf("\n"); 
		fputs(z, fp);
	}
	fclose(fp);
	return 0;
}
