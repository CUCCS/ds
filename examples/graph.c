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
#include <limits.h>
#include <string.h>
#include <errno.h>

#include "graph.h"

Status _InitEmptyMatrix(Graph *g) {
    int i, j;
    int vexnum = g->vexnum;
    g->matrix = (int **)malloc(vexnum * sizeof(int *));
    for(i = 0; i < vexnum; i++) {
        g->matrix[i] = (int *)malloc(vexnum * sizeof(int));
        for(j = 0; j < vexnum; j++) {
            if(g->matrix[i] == NULL) {
                return OVERFLOW;
            }
            if(i == j) {
                g->matrix[i][j] = 0;
            } else {
#ifdef DIJSKTRA
                g->matrix[i][j] = 0;
#else
                g->matrix[i][j] = -1;
#endif
            }
        }
    }

    return OK;
}

Status _CreateUnNetwork(Graph *g, GraphKind kind, VertexRelation **vr) {

    int i = 0, v, w, weight;

    if(!vr || !*vr) {
        fprintf(stderr, "vr is null\n");
    }

    while(i < g->arcnum) {
        v = (*vr[i]).v;
        w = (*vr[i]).w;
        weight = (*vr[i]).weight;
        g->matrix[v][w] = weight;
        g->matrix[w][v] = weight;
        i++;
    }
    g->kind = kind;

    return OK;
}

Status CreateGraph(Graph *g, GraphKind kind, VertexRelation **vr) {
    switch(kind) {
        case UnNetwork: /* 无向网 */
            if(OK == _InitEmptyMatrix(g)) {
                return _CreateUnNetwork(g, kind, vr);
            }
            break;
        case Undigraph: /* 无向图 */
        case Digraph:   /* 有向图 */
        case DiNetwork:/* 有向网 */
        default:
            fprintf(stderr, "%s", "not implemented yet");
            break;
    }

    return ERROR;
}

void Print(Graph g) {
    int vexnum = g.vexnum;
    int i, j;
    
    for(i = 0; i < vexnum; i++) {
        for(j = 0; j < vexnum; j++) {
            printf("%2d ", g.matrix[i][j]);
        }
        printf("\n");
    }
}

Status LoadVertexRelation(const char *file_path, Graph *g, VertexRelation ***vr) {
    char line[MAX_LINE];
    int vexnum, arcnum, i = 0;
    char *col;

    FILE *file = fopen(file_path, "r");
    if(file == NULL) {
        return FILE_NOT_EXIST;
    }
    while(fgets(line, sizeof(line), file)) {
        col = strtok(line, COL_SEP);
        if(col != NULL) {
            if(i == 0) { // 处理文件中的第一行，解析vexnum和arcnum
                vexnum = (int)strtol(col, NULL, 10);
                if(errno == EINVAL) {
                    return FILE_PARSE_ERROR;
                }
                col = strtok(NULL, COL_SEP);
                arcnum = (int)strtol(col, NULL, 10);
                if(errno == EINVAL) {
                    return FILE_PARSE_ERROR;
                }
                *vr = (VertexRelation **)realloc(*vr, arcnum * sizeof(VertexRelation *));
                printf("vexnum:%d arcnum:%d\n", vexnum, arcnum);
            } else { // 处理文件中其他行，解析v, w, weight
                vr[0][i - 1] = (VertexRelation *)malloc(sizeof(VertexRelation));
                (*vr[0][i - 1]).v = (int)strtol(col, NULL, 10);
                if(errno == EINVAL) {
                    return FILE_PARSE_ERROR;
                }
                col = strtok(NULL, COL_SEP);
                (*vr[0][i - 1]).w = (int)strtol(col, NULL, 10);
                if(errno == EINVAL) {
                    return FILE_PARSE_ERROR;
                }
                col = strtok(NULL, COL_SEP);
                (*vr[0][i - 1]).weight = (int)strtol(col, NULL, 10);
                if(errno == EINVAL) {
                    return FILE_PARSE_ERROR;
                }
                printf("%d %d %d\n", (*vr[0][i - 1]).v, (*vr[0][i - 1]).w, (*vr[0][i - 1]).weight);
            }
        }
        i++;
        if(i > arcnum) { // 文件中多余的行不再处理了
            break;
        }
    }
    if(i <= arcnum) { // 文件第一行定义的列数 > 实际文件中定义的边的数量
        return FILE_PARSE_ERROR;
    }
    g->vexnum = vexnum;
    g->arcnum = arcnum;
    fclose(file);

    return OK;
}



