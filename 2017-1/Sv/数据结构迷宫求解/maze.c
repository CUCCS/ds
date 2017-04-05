#include "maze.h"
Status InitStack(SqStack *S){
    S->base = (SElemType *) malloc (STACK_INIT_SIZE*sizeof(SElemType));
    if (!S->base) { exit(OVERFLOW); }
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return OK;
}

Status StackEmpty(SqStack S){
    if(S.base == S.top){return TRUE; }
    else { return FALSE; }
}

Status Pop(SqStack *S,SElemType *e){
    if(S->top == S->base){ return ERROR;}
*e = *(--S->top);
    return OK;
}

Status Push(SqStack *S,SElemType e){
    if (S->top-S->base>=S->stacksize){
        S->base = (SElemType *)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(SElemType));
        if(!S->base){exit(OVERFLOW);}
        S->top = S->base + S->stacksize;
        S	->stacksize += STACKINCREMENT;
    }
    *S->top++ = e;
    return OK;
}//Push
Status MazePath(MazeType maze,PosType start,PosType end){
    SqStack S;
    InitStack(&S);
    SElemType e;
    MazeType footprint;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            footprint[i][j]=0;
        }
    }
    PosType curpos = start;//当前位置为入口位置
    int curstep = 1;//探索第一步
    do{
    if(Pass(curpos,maze,footprint)){//当前位置可通过
        FootPrint(curpos, footprint);
        e.ord=curstep;e.seat=curpos;e.di=1;
        Push(&S,e);
        if((curpos.x==end.x)&&(curpos.y==end.y)){
            PRINT(maze,&S) ;
            return (TRUE);
        }
        curpos=NextPos(curpos, 1,maze);
        curstep++;
    }
    else{//当前位置不能通过
        if(!StackEmpty(S)){
            Pop(&S,&e);
            while(e.di==4&&!StackEmpty(S)){
                MarkPrint(e.seat,footprint);Pop(&S,&e);//留下不能通过的标记并退回一步
            }
            if(e.di<4){
                e.di++;
                //e=NewElem(e.ord, e.seat, e.di);
                Push(&S,e);
                curpos=NextPos(e.seat,e.di,maze);
            }
        }
    }
    }while(!StackEmpty(S));
    return FALSE;
}
int Pass(PosType curpos,MazeType maze,MazeType footprint){
           if(maze[curpos.x][curpos.y]==0&&footprint[curpos.x][curpos.y]==0){return 1;}
           else {return 0;}
}
void FootPrint(PosType curpos,MazeType footprint){
    footprint[curpos.x][curpos.y]=1;
}
PosType NextPos(PosType a,int b,MazeType maze){
    if(b==1&&maze[a.x][a.y+1]==0){a.y++;}
    else if (b==2&&maze[a.x+1][a.y]==0){a.x++;}
    else if(b==3&&maze[a.x][a.y-1]==0){a.y--;}
    else if(b==4&&maze[a.x-1][a.y]==0){a.x--;}
    return a;
}
void MarkPrint(PosType seat,MazeType footprint){
    footprint[seat.x][seat.y]=1;
}
SElemType NewElem(int curstep,PosType b,int di){
    SElemType e;
    e.ord=curstep;
    e.seat = b;
    e.di = di;
    return e;
}
void PRINT(MazeType maze,SqStack* S){
    SElemType *p;
    p=S->base;
    while(p!=S->top){
        maze[p->seat.x][p->seat.y]=3;
        p++;
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            printf("%d ",maze[i][j]);
        }
        printf("\n");
    }
}


