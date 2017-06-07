/*******************************************************************************
  文件名: 
  项目:   
  模块:   
  作者:   huangwei
  版本:   0.1
  创建于:  
  描述:

  修改历史:
  日期:     修改人:    修改描述:

 *********************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

int main(int argc, char* argv[])
{
    Graph g;
    Status ret;
    VertexRelation *vr = (VertexRelation *)malloc(sizeof(VertexRelation));

    const char file_path[] = "t_graph.1.txt";

    ret = LoadVertexRelation(file_path, &g, &vr);
    if(ret == OK) {
        ret = CreateGraph(&g, vr);
        Print(g);
    } else {
        fprintf(stderr, "load vertex relation from file failed with ret_code = %d\n", ret);
    }

    return 0;
}

