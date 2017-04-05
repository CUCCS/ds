//
//  main.c
//  迷宫求解
//
//  Created by qwe on 17/3/27.
//  Copyright © 2017年 qwe. All rights reserved.
//

#include <stdio.h>

#include"maze.h"
int main()
{
    MazeType maze={
            1,1,1,1,1,1,1,1,1,1,
                1,0,0,1,0,0,0,1,0,1,
                1,0,0,1,0,0,0,1,0,1,
                1,0,0,0,0,1,1,0,0,1,
                1,0,1,1,1,0,0,0,0,1,
                1,0,0,0,1,0,0,0,0,1,
                1,0,1,0,0,0,1,0,0,1,
                1,0,1,1,1,0,1,1,0,1,
                1,1,0,0,0,0,0,0,0,1,
                1,1,1,1,1,1,1,1,1,1
    };
    printf("当前迷宫（0位可通过，1为墙）：\n");
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            printf("%d ",maze[i][j]);
        }
        printf("\n");
    }
    printf("迷宫入口位置：（1，1）\n");
    printf("迷宫出口位置：（8，8）\n");
    PosType start;
    start.x=1;
    start.y=1;
    PosType end;
    end.x=8;
    end .y=8;
//检验是否改变迷宫：
MazePath(maze,start,end);
//    for(int i=0;i<10;i++){
//        for(int j=0;j<10;j++){
//            printf("%d ",maze[i][j]);
//        }
//        printf("\n");
//    }
    printf("（注：3为出迷宫路径）\n");
}
