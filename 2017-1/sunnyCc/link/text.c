#include "link.h"
#include <stdio.h>


int main(void)
{
	int choice, data, d = 0;
	LinkQueue Q;

	if (InitQueue(&Q) == 1)
	{
		printf("���д����ɹ���\n");
	}
	else
	{
		printf("���д���ʧ�ܣ�\n");
	}

	printf("-----------------------------------------\n");
	printf("     1����ջ\n");
	printf("     2����ջ\n");
	printf("     3������\n");
	printf("     4��ȡ����Ԫ��\n");
	printf("     5�����г���\n");
	printf("     6���ж϶����Ƿ�Ϊ��\n");
	printf("     7����ն���\n");
	printf("     8�����ٶ���\n");
	printf("     9���˳�\n");

	while (1)
	{
		printf("-----------------------------------------\n");
		printf("���������ѡ��\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("��������ջԪ�أ�\n");
			scanf("%d", &data);
			if (EnQueue(&Q, data))
			{
				printf("%d��ջ�ɹ���\n", data);
			}
			break;
		case 2:
			if (DeQueue(&Q, d))
			{
				printf("��ջ�ɹ���\n");
			}
			break;
		case 3:

			if (QueueTraverse(Q))
			{
				printf("�����ɹ���\n");
			}
			break;
		case 4:
			GetHead(Q, &d);
			printf("ȡ����Ԫ�� %d �ɹ�\n", d);
			break;
		case 5:
			printf("���г���Ϊ %d\n", QueueLength(Q));
			break;
		case 6:
			if (QueueEmpty(Q))
			{
				printf("����Ϊ�գ�\n");
			}
			else
			{
				printf("���в�Ϊ�գ�\n");
			}
			break;
		case 7:
			if (ClearQueue(&Q))
			{
				printf("��ճɹ���\n");
			}
			break;
		case 8:
			if (DestroyQueue(&Q));
			{
				printf("�����Ѿ������٣�\n");
			}
			break;
		case 9:
			return 0;
		}
	}
}