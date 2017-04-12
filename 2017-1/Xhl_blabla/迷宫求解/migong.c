#include "migong.h"
int main()
{
	//初始化迷宫
	srand((unsigned)time(NULL));  //用时间做种，每次产生随机数不一样
	int i, j;
	Initmingong();//初始化迷宫
	Printmigong();//打印迷宫
	position end;//迷宫的出口
	end.x = MazeScale - 2;
	end.y = MazeScale - 2;
	int flag = 0;//用于判断迷宫是否有解
	//迷宫主体
	Mystack path;//记录路径的栈
	Initstack(&path);//初始化路径 ，初始化栈长?
	position curp;//正在走的通道块坐标
	curp.x = 1; //先将其初始化为入口
	curp.y = 1;
	int curstep = 1;//探索的步数
	do
	{
		if (Pass(curp))//当前位置可以通过，即未曾走到过
		{
			Print_curp(curp);
			Footprint(curp, curstep);//留下足迹
			SElement e;
			//初始化e
			e.di = 1;//设定探索方向
			e.ord = curstep;
			e.seat.x = curp.x;
			e.seat.y = curp.y;
			Push(&path, e);//将路径入栈
			printf("将（%d %d)入栈\n\n", curp.x, curp.y);
			if (curp.x == end.x&&curp.y == end.y)//如果到达终点 就退出
			{
				flag = 1;
				break;
			}
			//找下一个被试块
			curp = Nextposition(curp, 1);//找到前一个被试块东面的路径块作为被试块，优先试最东边的块
			Print_direct(e,curp);
			curstep++;//探步数增加
		}
		//用于当某点不能通过时，进行对某点的出栈并且尝试下一方向
		else  //当前被试路径不能通过
		{
			Print_uncurp(curp);
			if (isStackempty(&path))
			{
				SElement e;
				Pop(&path, &e);//退回上一步
				Print_direct_result(e);
				curstep--;
				//将这一段所有周围被测试过的路从栈中清除
				while (e.di == 4 && isStackempty(&path))
				{
					Markprint(e.seat);
					printf("四个方向均不可走 弹出（%d %d)  ", e.seat.x, e.seat.y);
					Pop(&path, &e);
					printf("退回 (%d %d)\n\n", e.seat.x, e.seat.y);
					curstep--;	
				}
				//如果当前栈顶还有未被测试的路径就测试剩余的周围路径
				if (e.di < 4)
				{
					curp = Nextposition(e.seat, e.di + 1);
					e.di++;
					curstep++;
					Print_direct( e,curp);
					Push(&path, e);
				}
			}
		}
	} while (isStackempty(&path));
	printf("\n");
	Print_result(flag,path);
	clear(&path);
	return 0;
}
//打印可以通过的步子
void Print_curp(position a)
{
	printf("(%d %d) 可以通过\n",a.x,a.y);
}
//打印不能通过的步子
void Print_uncurp(position a)
{
	printf("(%d %d) 不能通过\n", a.x, a.y);
}
//初始化迷宫的墙和路
void Initmingong()
{
	printf("请选择初始化迷宫的方式：\n  \n1 随机初始化  \n2 用矩阵初始化   \n请输入");
	int x;
	int i, j;
	scanf("%d", &x);
	if (x == 1)
	{
		for (i = 0; i < MazeScale; i++)
		{
			for (j = 0; j < MazeScale; j++)
			{
				Maze[i][j] = rand() % 2;//0为可走通路 ，1为墙元素	
			}
		}
		//初始化墙壁
		for (i = 0; i < MazeScale; i++)
		{
			Maze[0][i] = 1;
			Maze[MazeScale - 1][i] = 1;
		}
		for (i = 0; i < MazeScale; i++)
		{
			Maze[i][0] = 1;
			Maze[i][MazeScale - 1] = 1;
		}
	}
	else if(x==2)
	{
       int num[6][6] = { {1,1,1, 1,1,1},{1,0,0, 0,1,1},{1,0,0,1,0,1},{1,0,0, 0,1,1},{1,1,0, 0,0,1},{1,1,1, 1,1,1} };
	   int y;
		for (i = 0; i < MazeScale; i++)
		{
			for (j = 0; j < MazeScale; j++)
			{
				Maze[i][j] = num[i][j];//0为可走通路 ，1为墙元素	
			}
		}
	}
	//设(1,1)为入口，（MazeScale-2，MazeScale-2）为出口
		Maze[1][1] = 0;
		Maze[MazeScale - 2][MazeScale - 2] = 0;
}
//打印刚被初始化的迷宫
void Printmigong()
{
	//打印出迷宫
	char x;
	int i, j;
	printf("图形版\n");
	for (i = 0; i < MazeScale; i++)
	{
		printf("|");
		for (j = 0; j < MazeScale; j++)
		{
			x = Maze[i][j] == 0 ? ' ' : '#';
			printf("%c", x);
		}
		printf("|\n");
	}
	printf("-----------------\n");
	printf("数字版(0是路  1是墙）\n");
	for (i = 0; i < MazeScale; i++)
	{
		printf("|");
		for (j = 0; j < MazeScale; j++)
		{
			printf("%d ", Maze[i][j]);
		}
		printf("|\n");
	}
}
//打印出运行的结果;
void Print_result(int flag, Mystack path)
{
if (flag == 1)
	{
	    printf("迷宫有解\n  #为墙  @为所走路径\n");
		int i, j;
		char x;
		Maze[1][1] = 2;
		for (i =0; i< MazeScale; i++)
		{
			printf("|");
			for (j =0; j< MazeScale; j++)
			{
				if (Maze[i][j] <= 0)
				{
					x = ' ';
				}
				else if (Maze[i][j] == 1)
				{
					x = '#';
				}
				else
				{
					x = '@';
				}
				printf("%c", x);
			}
			printf("|\n");
		}
	}
	else
	{
		printf("迷宫无解\n");
	}
}
//创建一个栈如果创建成功则返回1，否则就返回0
int Initstack(Mystack * s)
{
	s->base = (SElement*)malloc(STACK_INIT_SIZE * sizeof(SElement));//为栈分配初始空间
	if (!s->base)
		return 0;
	s->top = s->base;//设定为空栈
	s->stacksize = STACK_INIT_SIZE;
	return 1;
}
//检验当前位置是否可以通过
int Pass(position p)
{
	if (Maze[p.x][p.y] == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//留下足迹
void Footprint(position p, int step)
{
	Maze[p.x][p.y] = step;
}
//插入元素为e的元素，成功返回1 失败返回0
int Push(Mystack* s, SElement e)
{
	if (s->top - s->base >= STACK_INIT_SIZE)//如果栈满了，进行再扩大
	{
		s->base = (SElement*)realloc(s->base, (s->stacksize + STACKINCREMENT) * sizeof(SElement));
		if (NULL != s->base)
		{
			return 0;
		}
		s->top = s->base + s->stacksize;
		s->stacksize += STACKINCREMENT;
	}
	*(s->top) = e;
	s->top++;
	return 1;
}
//按顺时针方向从东开始寻找矩阵当中某一个位置的临近位置
position Nextposition(position now, int direction)
{
	position next;
	int x = now.x;
	int y = now.y;
	switch (direction)
	{
	case 1:
		//东
	{
		next.x = x;
		next.y = y + 1;
		break;
	}
	//南
	case 2: {
		next.x = x + 1;
		next.y = y;
		break;
	}
			//西
	case 3: {
		next.x = x;
		next.y = y - 1;
		break;
	}
			//北
	case 4:
	{
		next.x = x - 1;
		next.y = y;
		break;
	}
	default:break;
	}
	return next;
}
//打印要走的方向
void Print_direct(SElement e,position a)
{
	switch (e.di)
	{
        case 1:
			printf("测试向东走 (%d %d)\n",a.x,a.y);
	         break;
		case 2:
			printf("测试向南走 (%d %d)\n", a.x, a.y);
			break;
		case 3:
			printf("测试向西走 (%d %d)\n", a.x, a.y);
			break;
		case 4:
			printf("测试向北走 (%d %d)\n", a.x, a.y);
			break;
	}	
}
//打印测试方向失败的结果
void Print_direct_result(SElement e)
{
	switch (e.di)
	{
	case 1:
		printf("测试向东走失败   ");
		printf("退回(%d %d)\n\n", e.seat.x, e.seat.y);
		break;
	case 2:
		printf("测试向南走失败   ");
		printf("退回(%d %d)\n\n", e.seat.x, e.seat.y);
		break;
	case 3:
		printf("测试向西走失败   "); 
		printf("退回(%d %d)\n\n", e.seat.x, e.seat.y);
		break;
	case 4:
		printf("测试向北走失败   ");
		printf("退回(%d %d)\n\n", e.seat.x, e.seat.y);
		break;
	}
}
//判断栈是否为空，如果是空的就返回0，否则就返回1
int isStackempty(Mystack *s)
{
	//判断栈是否为空，如果是空的就返回0，否则就返回1
	if (s->top == s->base)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
//弹出栈顶元素赋值给e弹出成功返回1，弹出失败返回0
int Pop(Mystack* s, SElement* e)
{
	if (isStackempty(s))
	{
		*e = *(s->top - 1);
		s->top--;
		return 1;
	}
	else
	{
		return 0;
	}
}
//路径不可走的话就留下-1的标记
void Markprint(position p)
{
	Maze[p.x][p.y] = -1;
}
void clear(Mystack *pS)
{
	if (NULL == pS) //如果
	{
		return;
	}
	free(pS->base);
}