#include "�Թ����.h"
int main()
{
	MazeType maze;//�Թ��ṹ  
	SqStack stack;//˳��ջ���洢�Թ�·��  
	PosType start, end;//�Թ��������յ㣻  
	start.x = 0; start.y = 1;//�Թ������  
	end.x = 8; end.y = 9;//�Թ����յ�  
	InitMaze(&maze);//�Թ���ʼ��  
	printf("�Թ���״��\n");
	PrintMaze(&maze);//��ӡ�Թ���״  
	if (TRUE == MazePath(&stack, maze, start, end))
		printf("�Թ��ɽ�.\n");
	else
		printf("�Թ����ɽ�.\n");
	return 0;
}

Status InitStack(SqStack *S)
{
	//����һ����ջS  
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S->base)//����ʧ��  
	{
		printf("�����ڴ�ʧ��.\n");
		exit(0);
	}
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}

Status InitMaze(MazeType *M) 
{
	//��ʼ���Թ�����  
	int i, j;
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

	M->maze = (char **)malloc(sizeof(char *)*ROW);
	M->footprint = (int **)malloc(sizeof(int *)*ROW);
	if (!M->maze || !M->footprint)
	{
		printf("����ռ�ʧ�ܣ��Թ��޷���ʼ��.\n");
		return ERROR;
		exit(0);
	}
	for (i = 0; i<ROW; i++)
	{
		M->maze[i] = (char *)malloc(sizeof(char)*COLUMN);
		M->footprint[i] = (int *)malloc(sizeof(int)*COLUMN);
		if (!M->maze[i] || !M->footprint[i])
		{
			printf("����ռ�ʧ�ܣ��Թ���ʼ��ʧ��.\n");
			return ERROR;
			exit(0);
		}
	}
	for (i = 0; i<ROW; i++)
	{
		for (j = 0; j<COLUMN; j++)
		{
			M->maze[i][j] = mz[i][j];
			M->footprint[i][j] = 0;
		}
	}
	M->row = ROW;//��  
	M->column = COLUMN;//��  
	return OK;
}

Status DestroyStack(SqStack *S) 
{
	//����ջS��S���ٴ���  
	if (!S)//SΪ��  
	{
		printf("ָ��Ϊ�գ��ͷ�ʧ��.\n");
		exit(0);
	}
	free(S);
	return OK;
}

Status ClearStack(SqStack *S)
{
	//��ջS��Ϊ��ջ  
	if (!S)//S������  
		return FALSE;
	S->top = S->base;//ֱ�ӽ�ջ��ָ��ָ��ջ��  
	return OK;
}

Status StackEmpty(SqStack S)
{
	//��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE  
	if (S.top == S.base)
		return TRUE;
	else
		return FALSE;
}

int StackLength(SqStack S)
{
	//����SԪ�صĸ�������ջ�ĳ���  
	return S.stacksize;
}

Status GetTop(SqStack S, SElemType *e) 
{
	//��ջ��Ϊ�գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�FALSE  
	if (S.top == S.base) 
	{
		printf("ջΪ��.\n");
		return FALSE;
	}
	else
	{
		*e = *(S.top - 1);
		printf("ջ��Ԫ�أ�%c\n", *e);
		return OK;
	}
}

Status Push(SqStack *S, SElemType e)
{
	//����Ԫ��eΪ�µ�ջ��Ԫ��  
	if (S->top - S->base >= S->stacksize) //ջ������׷�Ӵ洢�ռ�  
	{
		S->base = (SElemType *)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S->base)
		{
			printf("��������ռ�ʧ��.\n");
			exit(0);
		}
		S->top = S->base + S->stacksize;//����ջ��ָ��  
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
}

Status Pop(SqStack *S, SElemType *e)
{
	//��ջS��Ϊ�գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK,���򷵻�ERROR  
	if (S->top == S->base) //ջΪ��
	{
		printf("ջΪ��.\n");
		return ERROR;
	}
	*e = *(--S->top);
	return OK;
}

Status StackTraverse(const SqStack *S) 
{
	//��ջ�׵�ջ�����ζ�ÿ��Ԫ�ؽ��з���  
	SElemType *p = S->base;
	if (S->base == S->top)
	{
		printf("ջΪ��.\n");
		return FALSE;
	}
	printf("ջ��Ԫ�أ�");
	while (p != S->top)
	{
		printf("x=%d,y=%d\n", p->seat.x, p->seat.y);
		*p++;
	}
	printf("\n");
	return OK;
}

Status PrintMaze(MazeType *M)
{
	//����Թ�  
	int i, j;
	for (i = 0; i<M->row; i++)
	{
		for (j = 0; j<M->column; j++)
		{
			printf("%c", M->maze[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return OK;
}

Status PrintFoot(MazeType *M, SqStack *S)
{
	//����Թ���·��  
	int i, j;
	SElemType *p;
	for (i = 0; i<M->row; i++) 
	{
		for (j = 0; j<M->column; j++)
		{
			M->footprint[i][j] = 0;
		}
	}
	p = S->base;
	if (S->base == S->top)
	{
		printf("ջΪ��.\n");
		return FALSE;
	}
	while (p != S->top)
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

Status MazePath(SqStack *S, MazeType maze, PosType start, PosType end)
{
	//���Թ�maze�д��ڴ����start������end��ͨ���������һ�������ջ�У���ջ��  
	//��ջ������������TRUE�����򷵻�FALSE  
	int curstep = 1;//��ǰ����  
	SElemType e;
	PosType curpos = start;//��ǰλ��  
	InitStack(S);//��ʼ��ջ  
	do {
		if (TRUE == Pass(&maze, curpos))
		{
			FootPrint(&maze, curpos);
			e = NewSElem(curstep, curpos, 1);
			Push(S, e);
			if ((curpos.x == end.x) && (curpos.y == end.y)) 
			{//�����յ㣨���ڣ�  
				printf("�Թ�·��:\n"); 
				PrintFoot(&maze, S);
				return TRUE;
			}
			curpos = NextPos(curpos, 1);
			curstep++;
		}  
		else {//��ǰλ�ò���ͨ��  
			if (!StackEmpty(*S)) 
			{
				Pop(S, &e);
				while (e.direction == 4 && !StackEmpty(*S)) 
				{
					MarkPrint(&maze, e.seat);
					Pop(S, &e);
				}  
				if (e.direction<4) 
				{
					e.direction++;
					Push(S, e);
					curpos = NextPos(e.seat, e.direction);
				}  
			} 
		}
	} while (!StackEmpty(*S));
	return FALSE;
}

Status FootPrint(MazeType *M, PosType pos) 
{
	//���Թ��ĵ�ǰλ��pos����Ϊ"�߹�"����footprint��λ��Ϊ1  
	if ((pos.x>M->row) || (pos.y>M->column))
		return FALSE;
	M->footprint[pos.x][pos.y] = 1;
	return TRUE;
}

Status Pass(MazeType *M, PosType pos)
{
	//�жϵ�ǰλ���Ƿ��ͨ����Ϊ�߹���ͨ����  
	if ((M->row<pos.x) || (M->column<pos.y))
	{
		printf("λ��Խλ.\n");
		exit(0);
	}
	if ((0 == M->footprint[pos.x][pos.y]) && (M->maze[pos.x][pos.y] == ' '))
		return TRUE;
	else
		return FALSE;
}

SElemType NewSElem(int step, PosType pos, int d)
{
	//�����½�㣬��step��pos��d��ʼ���ý��  
	SElemType e;
	e.number = step;
	e.seat = pos;
	e.direction = d;
	return e;
}

PosType NextPos(PosType pos, int d)
{
	//��ȡposλ��d�����λ��  
	switch (d) {
	case 1://��  
		pos.x++;
		break;
	case 2://��  
		pos.y++;
		break;
	case 3://��  
		pos.x--;
		break;
	case 4://��  
		pos.y--;
		break;
	default:
		printf("λ�ñ�ų���.\n");
	}
	return pos;
}

Status MarkPrint(MazeType *M, PosType pos)
{
	//���Թ�M��posλ�ã���Ϊ���ߣ��ɹ�����OK�����򷵻�ERROR  
	if (pos.x>M->row || pos.y>M->column)
	{
		printf("��Ҫ���λ��Խλ.\n");
		return ERROR;
	}
	M->footprint[pos.x][pos.y] = 1;
	return OK;
}