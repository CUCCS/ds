#include <stdio.h>
#include <stdlib.h>

#define OK      1
#define ERROR   0
#define TRUE    1
#define FALSE   0
#define OVERFLOW -2
#define STACK_INIT_SIZE 100   //存储空间初始分配量 
#define STACKINCREMENT 10     //存储空间分配增量
#define COL 10	    //迷宫行数
#define ROW 10      //迷宫列数
#define RANGE 10      //迷宫列数

typedef int Status; //定义Status为int类型

typedef struct{					
	//迷宫类型
	char **maze;    //迷宫数据
	int **footprint;//足迹数据
	int row;        //行数
	int col;        //列数
}MazeType;

typedef struct{
	//迷宫位置坐标
	int x;
	int y;
}PosType;

typedef struct{
	//栈元素类型
	int ord;		//通道块在路径上的“序号”
	PosType seat;	//通道块在迷宫中的“坐标位置”
	int di;			//从此通信块走向下一通道块的"方向"
}SElemType;		    

typedef struct{		
	//顺序栈结构定义
	SElemType *base;	//栈底指针
	SElemType *top;		//栈顶指针
	int stacksize;		//当前已分配的存储空间
}SqStack;

/*-------------基本操作的函数原型说明-----------*/
Status InitStack(SqStack *S);			//构造一个空栈S
Status StackEmpty(SqStack S);			//若栈S为空栈，则返回TRUE，否则返回FALSE
Status GetTop(SqStack S,SElemType *e);	//若栈不为空，则用e返回S的栈顶元素，并返回OK；否则返回FALSE
Status Push(SqStack *S,SElemType e);	//插入元素e为新的栈顶元素
Status Pop(SqStack *S,SElemType *e);	//若栈S不为空，则删除S的栈顶元素，用e返回其值，并返回OK,否则返回ERROR


/*------------基本操作的算法描述-----------*/
Status InitStack(SqStack *S){
	//构造一个空栈S
	S->base=(SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if(!S->base)	exit(OVERFLOW);//分配失败
	S->top=S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}//InitStack

Status StackEmpty(SqStack S){
	//若栈S为空栈，则返回TRUE，否则返回FALSE
	if(S.top == S.base)
		return TRUE;
	else
		return FALSE;
}//StackEmpty

Status GetTop(SqStack S,SElemType *e){
	//若栈不为空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
	if(S.top == S.base){
		return ERROR;
	}
	else{
		*e=*(S.top-1);
		return OK;
	}
}//GetTop

Status Push(SqStack *S,SElemType e){
	//插入元素e为新的栈顶元素
	if((S->top - S->base) >= S->stacksize){
		//栈已满，追加存储空间
		S->base = (SElemType *)realloc(S->base,(S->stacksize + STACKINCREMENT)*sizeof(SElemType));
		if(!S->base) exit(OVERFLOW);
		S->top = S->base + S->stacksize;//更改栈顶指针
		S->stacksize += STACKINCREMENT;
	}
	*S->top++=e;
	return OK;
}//Push

Status Pop(SqStack *S,SElemType *e){
	//若栈S不为空，则删除S的栈顶元素，用e返回其值，并返回OK,否则返回ERROR
	if(S->top==S->base) return ERROR;
	*e=*(--S->top);
	return OK;
}//Pop


/*-----------走迷宫程序-----------*/
Status InitMaze(MazeType *M)
{
	//初始化迷宫数据
	char mz[ROW][COL]={
		'#','#','#','#','#','#','#','#','#','#',
		'#',' ',' ','#',' ',' ',' ','#',' ','#',
		'#',' ',' ','#',' ',' ',' ','#',' ','#',
		'#',' ',' ',' ',' ','#','#',' ',' ','#',
		'#',' ','#','#','#',' ',' ',' ',' ','#',
		'#',' ',' ',' ','#',' ','#',' ','#','#',
		'#',' ','#',' ',' ',' ','#',' ',' ','#',
		'#',' ','#','#','#',' ','#','#',' ','#',
		'#','#',' ',' ',' ',' ',' ',' ',' ','#',
		'#','#','#','#','#','#','#','#','#','#'
	};

	M->maze = (char **)malloc(sizeof(char *)*ROW);
	M->footprint=(int **)malloc(sizeof(int *)*ROW);
	if(!M->maze||!M->footprint){
		printf("申请空间失败，迷宫无法初始化.\n");
		return ERROR;
		exit(0);
	}
	
	for(int i=0;i<ROW;i++){
		M->maze[i]=(char *)malloc(sizeof(char)*COL);
		M->footprint[i]=(int *)malloc(sizeof(int)*COL);
		if(!M->maze[i]||!M->footprint[i])
		{
			printf("申请空间失败，迷宫初始化失败.\n");
			return ERROR;
			exit(0);
		}
	}

	for(int i=0;i<ROW;i++){
		for(int j=0;j<COL;j++){
			M->maze[i][j]=mz[i][j];  //将数据写入到数据结构
			M->footprint[i][j]=0;
		}
	}
	M->row = ROW;//行
	M->col = COL;//列
	return OK;
}

Status PrintMaze(MazeType *M){
	//输出迷宫
	int i,j;
	for(i=0;i<M->row;i++){
		for(j=0;j<M->col;j++){
			switch(M->maze[i][j])
			 {              
			 case ' ': 
                 printf("□");                  
				 break;              
			 case '#':                  
				 printf("■");                  
				 break; 
			}
		}
	
	printf("\n");
	}	
	return OK;
}

Status FootPrint(MazeType *mase,PosType pos){
	//将迷宫的当前位置pos设置为"走过"，即footprint该位置为1
	mase->footprint[pos.x][pos.y]=1;
	return TRUE;
}

Status Pass(MazeType *M,PosType pos){
	//判断当前位置是否可通，即为走过的通道块
	if((0==M->footprint[pos.x][pos.y])&&(M->maze[pos.x][pos.y]==' '))
		return TRUE;
	else
		return FALSE;
}

SElemType NewSElem(int step,PosType pos,int d){
	//创建新结点，用step，pos，d初始化该结点
	SElemType e;
	e.ord=step;
	e.seat=pos;
	e.di=d;
	return e;
}

PosType NextPos(PosType pos,int d){
	//获取pos位置d方向的位置
	switch(d){
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

Status MarkPrint(MazeType *M,PosType pos){
	//将迷宫M的pos位置，设为已走，成功返回OK；否则返回ERROR
	if(pos.x>M->row||pos.y>M->col){
		printf("所要标记位置越位.\n");
		return ERROR;
	}
	M->footprint[pos.x][pos.y]=1;
	return OK;
}

Status PrintFoot(MazeType *M,SqStack *S){
	//输出迷宫的路径
	int i,j;
	SElemType *p;
	for(i=0;i<M->row;i++){
		for(j=0;j<M->col;j++){
			M->footprint[i][j]=0;
		}
	}
	p=S->base;
	if(S->base==S->top)
	{
		printf("栈为空.\n");
		return FALSE;
	}
	while(p!=S->top)
	{
		M->footprint[p->seat.x][p->seat.y]=1;
		*p++;
	}
	for(i=0;i<M->row;i++){
		for(j=0;j<M->col;j++){
			switch(M->footprint[i][j])
			{
			case 0: 
                 printf("■");                  
				 break;              
			 case 1:                  
				 printf("☆");                  
				 break; 
			}
		}
		printf("\n");
	}

	return OK;
}

Status MazePath(SqStack *S,MazeType maze,PosType start,PosType end){
	//若迷宫maze中存在从入口start到出口end的通道，则求得一条存放在栈中（从栈底
	//到栈顶），并返回TRUE；否则返回FALSE
	int curstep=1;//当前步数
	SElemType e;
	PosType curpos=start;//当前位置
	InitStack(S);//初始化栈
	do{
		if(Pass(&maze,curpos))
		{//如果当前位置可以通过,则是未曾走到的通道块
			FootPrint(&maze,curpos);   //留下足迹
			e=NewSElem(curstep,curpos,1);    //创建元素
			Push(S,e);  //将元素放入栈中
			if((curpos.x==end.x)&&(curpos.y==end.y)){//到达终点（出口）
				printf("迷宫路径:\n");
				PrintFoot(&maze,S);   //打印足迹
				return TRUE;
			}
			curpos=NextPos(curpos,1);   //获得下一节点
			curstep++;      //步数加一

		}//if
		else{//当前位置不能通过
			if(!StackEmpty(*S)){
				Pop(S,&e);   //出栈
				while(e.di==4&&!StackEmpty(*S)){   //当判断四个方向都不能通过时
					MarkPrint(&maze,e.seat);   //标记当前位置
					Pop(S,&e);   //出栈
				}//while
				if(e.di<4){   //当判断方向没有四个时
					e.di++;   //换个方向继续判断
					Push(S,e);
					curpos=NextPos(e.seat,e.di);
				}//if
			}//if
		}//else
		//PrintFoot(&maze,S);
	}while(!StackEmpty(*S));
	return FALSE;
}



void main()
{
	MazeType maze;//迷宫结构
	SqStack stack;//顺序栈，存储迷宫路径
	PosType start,end;//迷宫的起点和终点；

	start.x=1;
	start.y=1;//迷宫的起点
	end.x=8;
	end.y=8;//迷宫的终点
	InitMaze(&maze);//迷宫初始化

	printf("迷宫形状：\n");
	PrintMaze(&maze);//打印迷宫形状

	if(MazePath(&stack,maze,start,end))
		printf("迷宫可解.\n");
	else
		printf("迷宫不可解.\n");
}