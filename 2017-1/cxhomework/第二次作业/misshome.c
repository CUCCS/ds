//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//struct stack_node
//{
//	int x; //路径坐标x
//	int y; //路径坐标y
//	struct stack_node *next;
//};
//typedef struct stack_node stack_list;
//typedef stack_list * link;
#include "misshome.h";

link path = NULL; //路径栈指针
link push(link stack, int x, int y) //栈数据的存入
{
	link new_node;
	new_node = (link)malloc(sizeof(stack_list));
	if (!new_node)
	{
		printf("内存分配失败! \n");
		return NULL;
	}
	new_node->x = x;
	new_node->y = y;
	new_node->next = stack;
	stack = new_node;
	return stack;
}
link pop(link stack, int *x, int *y) //栈数据的取出
{
	link top;
	if (stack != NULL)
	{
		top = stack;
		stack = stack->next;
		*x = stack->x;
		*y = stack->y;
		free(top);
		return stack;
	}
	else
		*x = -1;
}

void migong(int maze[8][11])
{
	int i, j;
	i = 1;
	for (j = 1; j<11; j++)
		maze[i][j] = 1;
	j = 1;
	for (i = 1; i<8; i++)
		maze[i][j] = 1;
	i = 7;
	for (j = 1; j<11; j++)
		maze[i][j] = 1;
	j = 10;
	for (i = 1; i<8; i++)
		maze[i][j] = 1;
	srand(time(NULL));
	for (i = 2; i<7; i++)
		for (j = 2; j<10; j++)
			maze[i][j] = rand() % 2;
	printf("迷宫\n");
	for (i = 1; i<8; i++)
	{
		for (j = 1; j<11; j++)
			printf("%3d", maze[i][j]);
		printf("\n");
	}
}
void main()
{
	int maze[8][11];
	int endx, endy;
	int startx, starty;
	int x, y, i, j;
	migong(maze);
	printf("输入开始点坐标(1,1开始): ");
	scanf("%d %d", &startx, &starty);
	while (maze[startx][starty] != 0)
	{
		printf("重新输入: ");
		scanf("%d %d", &startx, &starty);
	}
	printf("输入终点坐标: ");
	scanf("%d %d", &endx, &endy);
	while (maze[endx][endy] != 0)
	{
		printf("重新输入: ");
		scanf("%d %d", &endx, &endy);
	}
	x = startx; y = starty;
	while (x != endx || y != endy)
	{
		maze[x][y] = 2;
		if (maze[x - 1][y] <= 0) //上
		{
			x = x - 1;
			path = push(path, x, y);
		}
		else
			if (maze[x + 1][y] <= 0) //下
			{
				x = x + 1;
				path = push(path, x, y);
			}
			else
				if (maze[x][y - 1] <= 0) //左
				{
					y = y - 1;
					path = push(path, x, y);
				}
				else
					if (maze[x][y + 1] <= 0) //右
					{
						y = y + 1;
						path = push(path, x, y);
					}
					else
					{
						maze[x][y] = 3; //退栈
						path = pop(path, &x, &y);
					}
	}
	maze[x][y] = 2; //标示最后一点
	printf("迷宫路径如下图所示: \n");
	for (i = 1; i<8; i++)
	{
		for (j = 1; j<11; j++)
			printf("%3d", maze[i][j]);
		printf("\n");
	}
}