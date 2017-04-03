#include "migong.h"
int main()
{
	//��ʼ���Թ�
	srand((unsigned)time(NULL));  //��ʱ�����֣�ÿ�β����������һ��
	int i, j;
	Initmingong();//��ʼ���Թ�
	Printmigong();//��ӡ�Թ�
	position end;//�Թ��ĳ���
	end.x = MazeScale - 2;
	end.y = MazeScale - 2;
	int flag = 0;//�����ж��Թ��Ƿ��н�
	//�Թ�����
	Mystack path;//��¼·����ջ
	Initstack(&path);//��ʼ��·�� ����ʼ��ջ��?
	position curp;//�����ߵ�ͨ��������
	curp.x = 1; //�Ƚ����ʼ��Ϊ���
	curp.y = 1;
	int curstep = 1;//̽���Ĳ���
	do
	{
		if (Pass(curp))//��ǰλ�ÿ���ͨ������δ���ߵ���
		{
			Print_curp(curp);
			Footprint(curp, curstep);//�����㼣
			SElement e;
			//��ʼ��e
			e.di = 1;//�趨̽������
			e.ord = curstep;
			e.seat.x = curp.x;
			e.seat.y = curp.y;
			Push(&path, e);//��·����ջ
			printf("����%d %d)��ջ\n\n", curp.x, curp.y);
			if (curp.x == end.x&&curp.y == end.y)//��������յ� ���˳�
			{
				flag = 1;
				break;
			}
			//����һ�����Կ�
			curp = Nextposition(curp, 1);//�ҵ�ǰһ�����Կ鶫���·������Ϊ���Կ飬��������ߵĿ�
			Print_direct(e,curp);
			curstep++;//̽��������
		}
		//���ڵ�ĳ�㲻��ͨ��ʱ�����ж�ĳ��ĳ�ջ���ҳ�����һ����
		else  //��ǰ����·������ͨ��
		{
			Print_uncurp(curp);
			if (isStackempty(&path))
			{
				SElement e;
				Pop(&path, &e);//�˻���һ��
				Print_direct_result(e);
				curstep--;
				//����һ��������Χ�����Թ���·��ջ�����
				while (e.di == 4 && isStackempty(&path))
				{
					Markprint(e.seat);
					printf("�ĸ������������ ������%d %d)  ", e.seat.x, e.seat.y);
					Pop(&path, &e);
					printf("�˻� (%d %d)\n\n", e.seat.x, e.seat.y);
					curstep--;	
				}
				//�����ǰջ������δ�����Ե�·���Ͳ���ʣ�����Χ·��
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
//��ӡ����ͨ���Ĳ���
void Print_curp(position a)
{
	printf("(%d %d) ����ͨ��\n",a.x,a.y);
}
//��ӡ����ͨ���Ĳ���
void Print_uncurp(position a)
{
	printf("(%d %d) ����ͨ��\n", a.x, a.y);
}
//��ʼ���Թ���ǽ��·
void Initmingong()
{
	printf("��ѡ���ʼ���Թ��ķ�ʽ��\n  \n1 �����ʼ��  \n2 �þ����ʼ��   \n������");
	int x;
	int i, j;
	scanf("%d", &x);
	if (x == 1)
	{
		for (i = 0; i < MazeScale; i++)
		{
			for (j = 0; j < MazeScale; j++)
			{
				Maze[i][j] = rand() % 2;//0Ϊ����ͨ· ��1ΪǽԪ��	
			}
		}
		//��ʼ��ǽ��
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
				Maze[i][j] = num[i][j];//0Ϊ����ͨ· ��1ΪǽԪ��	
			}
		}
	}
	//��(1,1)Ϊ��ڣ���MazeScale-2��MazeScale-2��Ϊ����
		Maze[1][1] = 0;
		Maze[MazeScale - 2][MazeScale - 2] = 0;
}
//��ӡ�ձ���ʼ�����Թ�
void Printmigong()
{
	//��ӡ���Թ�
	char x;
	int i, j;
	printf("ͼ�ΰ�\n");
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
	printf("���ְ�(0��·  1��ǽ��\n");
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
//��ӡ�����еĽ��;
void Print_result(int flag, Mystack path)
{
if (flag == 1)
	{
	    printf("�Թ��н�\n  #Ϊǽ  @Ϊ����·��\n");
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
		printf("�Թ��޽�\n");
	}
}
//����һ��ջ��������ɹ��򷵻�1������ͷ���0
int Initstack(Mystack * s)
{
	s->base = (SElement*)malloc(STACK_INIT_SIZE * sizeof(SElement));//Ϊջ�����ʼ�ռ�
	if (!s->base)
		return 0;
	s->top = s->base;//�趨Ϊ��ջ
	s->stacksize = STACK_INIT_SIZE;
	return 1;
}
//���鵱ǰλ���Ƿ����ͨ��
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
//�����㼣
void Footprint(position p, int step)
{
	Maze[p.x][p.y] = step;
}
//����Ԫ��Ϊe��Ԫ�أ��ɹ�����1 ʧ�ܷ���0
int Push(Mystack* s, SElement e)
{
	if (s->top - s->base >= STACK_INIT_SIZE)//���ջ���ˣ�����������
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
//��˳ʱ�뷽��Ӷ���ʼѰ�Ҿ�����ĳһ��λ�õ��ٽ�λ��
position Nextposition(position now, int direction)
{
	position next;
	int x = now.x;
	int y = now.y;
	switch (direction)
	{
	case 1:
		//��
	{
		next.x = x;
		next.y = y + 1;
		break;
	}
	//��
	case 2: {
		next.x = x + 1;
		next.y = y;
		break;
	}
			//��
	case 3: {
		next.x = x;
		next.y = y - 1;
		break;
	}
			//��
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
//��ӡҪ�ߵķ���
void Print_direct(SElement e,position a)
{
	switch (e.di)
	{
        case 1:
			printf("�������� (%d %d)\n",a.x,a.y);
	         break;
		case 2:
			printf("���������� (%d %d)\n", a.x, a.y);
			break;
		case 3:
			printf("���������� (%d %d)\n", a.x, a.y);
			break;
		case 4:
			printf("�������� (%d %d)\n", a.x, a.y);
			break;
	}	
}
//��ӡ���Է���ʧ�ܵĽ��
void Print_direct_result(SElement e)
{
	switch (e.di)
	{
	case 1:
		printf("��������ʧ��   ");
		printf("�˻�(%d %d)\n\n", e.seat.x, e.seat.y);
		break;
	case 2:
		printf("����������ʧ��   ");
		printf("�˻�(%d %d)\n\n", e.seat.x, e.seat.y);
		break;
	case 3:
		printf("����������ʧ��   "); 
		printf("�˻�(%d %d)\n\n", e.seat.x, e.seat.y);
		break;
	case 4:
		printf("��������ʧ��   ");
		printf("�˻�(%d %d)\n\n", e.seat.x, e.seat.y);
		break;
	}
}
//�ж�ջ�Ƿ�Ϊ�գ�����ǿյľͷ���0������ͷ���1
int isStackempty(Mystack *s)
{
	//�ж�ջ�Ƿ�Ϊ�գ�����ǿյľͷ���0������ͷ���1
	if (s->top == s->base)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
//����ջ��Ԫ�ظ�ֵ��e�����ɹ�����1������ʧ�ܷ���0
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
//·�������ߵĻ�������-1�ı��
void Markprint(position p)
{
	Maze[p.x][p.y] = -1;
}
void clear(Mystack *pS)
{
	if (NULL == pS) //���
	{
		return;
	}
	free(pS->base);
}