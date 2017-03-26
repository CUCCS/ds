#include "migong.h"
int main()
{
	//��ʼ���Թ�
	srand((unsigned)time(NULL));  //��ʱ�����֣�ÿ�β����������һ��
	int i, j;
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
	//��(1,1)Ϊ��ڣ���MazeScale-2��MazeScale-2��Ϊ����
	Maze[1][1] = 0;
	Maze[MazeScale-2][MazeScale-2] = 0;
	//��ӡ���Թ�
	char x;
	printf("ͼ�ΰ�\n");
	for (i = 0; i < MazeScale; i++)
	{
		printf("|");
		for (j = 0; j < MazeScale; j++)
		{	
			 x = Maze[i][j] == 0 ?' ' : '#';
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
	position end;//�Թ��ĳ���
	end.x = MazeScale - 2;
	end.y = MazeScale - 2;
	//�����ж��Թ��Ƿ��н�
	int flag = 0;
	//�Թ�����
	Mystack path;//��¼·����ջ
	Initstack(&path);//��ʼ��·�� ����ʼ��ջ��?
	position curp;//�����ߵ�ͨ��������
	               //�Ƚ����ʼ��Ϊ���
	curp.x = 1;
	curp.y = 1;
	int curstep = 1;//̽���Ĳ���
	do
	{
		if (Pass(curp))//��ǰλ�ÿ���ͨ������δ���ߵ���
		{
			Footprint(curp, curstep);//�����㼣
			SElement e;
			//��ʼ��e
			e.di = 1;//�趨̽������
			e.ord = curstep;
			e.seat.x = curp.x;
			e.seat.y = curp.y;
			Push(&path, e);//��·����ջ
			if (curp.x == end.x&&curp.y == end.y)//��������յ� ���˳�
			{
				flag = 1;
				break;
			}
			//����һ�����Կ�
			curp = Nextposition(curp, 1);//�ҵ�ǰһ�����Կ鶫���·������Ϊ���Կ飬��������ߵĿ�
			curstep++;//̽��������
		}
		//���ڵ�ĳ�㲻��ͨ��ʱ�����ж�ĳ��ĳ�ջ���ҳ�����һ����
		else  //��ǰ����·������ͨ��
		{
			if (isStackempty(&path))
			{
				SElement e;
				Pop(&path, &e);//�˻���һ��
				curstep--;
				//����һ��������Χ�����Թ���·��ջ�����
				while (e.di == 4 && isStackempty(&path))
				{
					Markprint(e.seat);
					Pop(&path, &e);
					curstep--;
				}
				//�����ǰջ������δ�����Ե�·���Ͳ���ʣ�����Χ·��
				if (e.di < 4)
				{
					curp = Nextposition(e.seat, e.di + 1);
					e.di++;
					curstep++;
					Push(&path, e);
				}
			}
		}
	} while (isStackempty(&path));
	printf("\n");
	if (flag == 1)
	{
		printf("�Թ��н�\n");
	}
	else
	{
		printf("�Թ��޽�\n");
	}
      clear(&path);
	return 0;
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
	if (NULL==pS) //���
	{
		return;
	}
	else
	{
		SElement *p = pS->top; //����Ԫ��pָ��ջ��Ԫ��
		SElement *q = NULL; //����Ԫ��q����ʼֵΪ��

		while (p != pS->base) //���ջ��Ϊ��
		{
			q = --p; //qָ��p����һ��Ԫ��
			free(p);  //�ͷ�p��ָ���ջ��Ԫ��
			p = q;  //��q��ָ���Ԫ�ظ���p
		}
		pS->top = pS->base;
	}
	free(pS->top);
}