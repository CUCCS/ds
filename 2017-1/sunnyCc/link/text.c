#include "link.h"
#include <stdio.h>


int main(void)
{
	int choice, data, d = 0;
	LinkQueue Q;

	if (InitQueue(&Q) == 1)
	{
		printf("队列创建成功！\n");
	}
	else
	{
		printf("队列创建失败！\n");
	}

	printf("-----------------------------------------\n");
	printf("     1、入栈\n");
	printf("     2、出栈\n");
	printf("     3、遍历\n");
	printf("     4、取队首元素\n");
	printf("     5、队列长度\n");
	printf("     6、判断队列是否为空\n");
	printf("     7、请空队列\n");
	printf("     8、销毁队列\n");
	printf("     9、退出\n");

	while (1)
	{
		printf("-----------------------------------------\n");
		printf("请输入你的选择：\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("请输入入栈元素：\n");
			scanf("%d", &data);
			if (EnQueue(&Q, data))
			{
				printf("%d入栈成功！\n", data);
			}
			break;
		case 2:
			if (DeQueue(&Q, d))
			{
				printf("出栈成功！\n");
			}
			break;
		case 3:

			if (QueueTraverse(Q))
			{
				printf("遍历成功！\n");
			}
			break;
		case 4:
			GetHead(Q, &d);
			printf("取队首元素 %d 成功\n", d);
			break;
		case 5:
			printf("队列长度为 %d\n", QueueLength(Q));
			break;
		case 6:
			if (QueueEmpty(Q))
			{
				printf("队列为空！\n");
			}
			else
			{
				printf("队列不为空！\n");
			}
			break;
		case 7:
			if (ClearQueue(&Q))
			{
				printf("清空成功！\n");
			}
			break;
		case 8:
			if (DestroyQueue(&Q));
			{
				printf("队列已经被销毁！\n");
			}
			break;
		case 9:
			return 0;
		}
	}
}