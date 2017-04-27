#include "Algorithm.h"
int main()
{
	MazeType maze;//迷宫结构  
	SqStack stack;//顺序栈，存储迷宫路径  
	PosType start, end;//迷宫的起点和终点；  
	start.x = 0; start.y = 1;//迷宫的起点  
	end.x = 8; end.y = 9;//迷宫的终点  
	InitMaze(&maze);//迷宫初始化  
	printf("迷宫形状：\n");
	PrintMaze(&maze);//打印迷宫形状  
	if (TRUE == MazePath(&stack, maze, start, end))//栈中有可走的路径,则输出迷宫可解
		printf("迷宫可解.\n");
	else
		printf("迷宫不可解.\n");
	return 0;
}
//构造一个空栈S 
Status InitStack(SqStack *S)
{
	 //给栈分配存储空间
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S->base)//如果分配失败  
	{
		printf("分配内存失败.\n");
		exit(0);
	}
	S->top = S->base;//将栈顶指针指向栈底指针
	S->stacksize = STACK_INIT_SIZE;//将栈的大小初始化为100
	return OK;
}
//初始化迷宫数据 
Status InitMaze(MazeType *M)
{	 
	int i, j;
	//自己定义迷宫形状；
	char mz[ROW][COLUMN] = {
		'#',' ','#','#','#','#','#','#','#','#',
		'#',' ',' ','#',' ',' ',' ','#',' ','#',
		'#',' ',' ','#',' ',' ',' ','#',' ','#',
		'#',' ',' ',' ',' ','#','#',' ',' ','#',
		'#',' ','#','#','#',' ',' ',' ',' ','#',
		'#',' ',' ',' ','#',' ','#',' ','#','#',
		'#',' ','#',' ',' ',' ','#',' ',' ','#',
		'#',' ','#','#','#',' ','#','#',' ','#',
		'#','#',' ',' ',' ',' ',' ',' ',' ',' ',
		'#','#','#','#','#','#','#','#','#','#'
	};

	M->maze = (char **)malloc(sizeof(char *)*ROW);//给迷宫分配存储空间
	M->footprint = (int **)malloc(sizeof(int *)*ROW);//给记录走过的路径分配存储空间
	if (!M->maze || !M->footprint)
	{
		printf("申请空间失败，迷宫无法初始化.\n");
		return ERROR;
		exit(0);
	}
	for (i = 0; i<ROW; i++)
	{
		M->maze[i] = (char *)malloc(sizeof(char)*COLUMN);
		M->footprint[i] = (int *)malloc(sizeof(int)*COLUMN);
		if (!M->maze[i] || !M->footprint[i])
		{
			printf("申请空间失败，迷宫初始化失败.\n");
			return ERROR;
			exit(0);
		}
	}
	for (i = 0; i<ROW; i++)
	{
		for (j = 0; j<COLUMN; j++)
		{
			M->maze[i][j] = mz[i][j];//将迷宫M初始化为自己定义的迷宫形状
			M->footprint[i][j] = 0;//将足迹全部记为0
		}
	}
	M->row = ROW;//行  
	M->column = COLUMN;//列  
	return OK;
}

//销毁栈S，S不再存在  
Status DestroyStack(SqStack *S)
{
	if (!S)//S为空  
	{
		printf("指针为空，释放失败.\n");
		exit(0);//正常退出程序
	}
	free(S);
	return OK;
}

Status ClearStack(SqStack *S)
{
	//把栈S置为空栈  
	if (!S)//S不存在  
		return FALSE;
	S->top = S->base;//直接将栈顶指针指向栈底  
	return OK;
}

Status StackEmpty(SqStack S)
{
	//若栈S为空栈，则返回TRUE，否则返回FALSE  
	if (S.top == S.base)
		return TRUE;
	else
		return FALSE;
}

//返回S元素的个数，即栈的长度  
int StackLength(SqStack S)
{
	return S.stacksize;
}

//若栈不为空，则用e返回S的栈顶元素，并返回OK；否则返回FALSE  
Status GetTop(SqStack S, SElemType *e)
{
	if (S.top == S.base)
	{
		printf("栈为空.\n");
		return FALSE;
	}
	else
	{
		*e = *(S.top - 1);//获得栈顶元素
		printf("栈顶元素：%c\n", *e);
		return OK;
	}
}

//插入元素e为新的栈顶元素  
Status Push(SqStack *S, SElemType e)
{
	if (S->top - S->base >= S->stacksize) //栈已满，追加存储空间  
	{
		S->base = (SElemType *)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S->base)
		{
			printf("重新申请空间失败.\n");
			exit(0);
		}
		S->top = S->base + S->stacksize;//更改栈顶指针  
		S->stacksize += STACKINCREMENT;//增加栈的长度
	}
	*S->top++ = e;//将e设为栈顶指针
	return OK;
}

//若栈S不为空，则删除S的栈顶元素，用e返回其值，并返回OK,否则返回ERROR  
Status Pop(SqStack *S, SElemType *e)
{
	if (S->top == S->base) //如果栈为空
	{
		printf("栈为空.\n");
		return ERROR;
	}
	*e = *(--S->top);
	return OK;
}
Status PrintMaze(MazeType *M)
{
	int i, j;
	for (i = 0; i<M->row; i++)
	{
		for (j = 0; j<M->column; j++)
		{
			printf("%c", M->maze[i][j]);//输出迷宫  
		}
		printf("\n");
	}
	printf("\n");
	return OK;
}

//输出迷宫的路径  
Status PrintFoot(MazeType *M, SqStack *S)
{
	int i, j;
	SElemType *p;
	for (i = 0; i<M->row; i++)
	{
		for (j = 0; j<M->column; j++)
		{
			M->footprint[i][j] = 0;//先将路径全部初始化为0
		}
	}
	p = S->base;
	if (S->base == S->top)
	{
		printf("栈为空.\n");
		return FALSE;
	}
	while (p != S->top)//栈不为空
	{
		M->footprint[p->seat.x][p->seat.y] = 1;
		*p++;
	}
	for (i = 0; i<M->row; i++)
	{
		for (j = 0; j<M->column; j++)
		{
			printf("%d", M->footprint[i][j]);
		}
		printf("\n");
	}

	return OK;
}

//若迷宫maze中存在从入口start到出口end的通道，则求得一条存放在栈中（从栈底  
//到栈顶），并返回TRUE；否则返回FALSE  
Status MazePath(SqStack *S, MazeType maze, PosType start, PosType end)
{
	
	int curstep = 1;//当前步数  
	SElemType e;
	PosType curpos = start;//当前位置  
	InitStack(S);//初始化栈  
	do {
		if (TRUE == Pass(&maze, curpos))//如果能够通过
		{
			FootPrint(&maze, curpos);//将当前位置设置为1
			e = NewSElem(curstep, curpos, 1);//创建新节点
			Push(S, e);//将e入栈
			if ((curpos.x == end.x) && (curpos.y == end.y))//到达终点（出口）
			{  
				printf("迷宫路径:\n");
				PrintFoot(&maze, S);
				return TRUE;
			}
			curpos = NextPos(curpos, 1);
			curstep++;//当前位置+1获取下一个位置
		}
		else {//当前位置不能通过  
			if (!StackEmpty(*S))
			{
				Pop(S, &e);//如果栈不为空，将e退出栈
				while (e.direction == 4 && !StackEmpty(*S))
				{
					MarkPrint(&maze, e.seat);//标记当前位置
					Pop(S, &e);
				}
				if (e.direction<4)
				{
					e.direction++;
					Push(S, e);//插入新元素
					curpos = NextPos(e.seat, e.direction);
				}
			}
		}
	} while (!StackEmpty(*S));
	return FALSE;
}

//将迷宫的当前位置pos设置为"走过"，即footprint该位置为1  
Status FootPrint(MazeType *M, PosType pos)
{
	if ((pos.x>M->row) || (pos.y>M->column))//如果位置越位
		return FALSE;
	M->footprint[pos.x][pos.y] = 1;
	return TRUE;
}

//判断当前位置是否可通，即为走过的通道块  
Status Pass(MazeType *M, PosType pos)
{
	if ((pos.x>M->row) || (pos.y>M->column))//如果位置越位
	{
		exit(0);
	}
	if ((0 == M->footprint[pos.x][pos.y]) && (M->maze[pos.x][pos.y] == ' '))
		return TRUE;
	else
		return FALSE;
}

SElemType NewSElem(int step, PosType pos, int d)
{
	//创建新结点，用step，pos，d初始化该结点  
	SElemType e;
	e.number = step;
	e.seat = pos;
	e.direction = d;
	return e;
}

//获取pos位置d方向的位置  
PosType NextPos(PosType pos, int d)
{
	switch (d) {
	case 1://东  
		pos.x++;
		break;
	case 2://南  
		pos.y++;
		break;
	case 3://西  
		pos.x--;
		break;
	case 4://北  
		pos.y--;
		break;
	default:
		printf("位置编号出错.\n");
	}
	return pos;
}

Status MarkPrint(MazeType *M, PosType pos)
{
	if (pos.x>M->row || pos.y>M->column)//标记位置越位
	{
		return ERROR;
	}
	M->footprint[pos.x][pos.y] = 1;	//将迷宫M的走过的位置设为1  
	return OK;
}