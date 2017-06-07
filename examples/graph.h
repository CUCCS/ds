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
#ifdef __cplusplus
extern "C" {
#endif

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "myds.h"

#define MAX_LINE 32
#define COL_SEP " ,"

typedef unsigned int Vertex; /* 顶点，从0开始编号 */
typedef enum {
    Undigraph, /* 无向图 */
    Digraph,   /* 有向图 */
    UnNetwork, /* 无向网 */
    DiNetwork /* 有向网 */
} GraphKind; /* 图的种类 */

typedef struct {
    int v;
    int w;
    int weight;
} VertexRelation;

typedef struct {
    GraphKind kind; /* 图的种类 */
    int **matrix; /* 邻接矩阵，保存带权弧值 */
    int vexnum; /* 顶点数 */
    int arcnum; /* 弧数 */
} Graph;

/* 方法接口（函数指针） */
Status CreateGraph(Graph *g, VertexRelation *vr); /* 按定义构造图 */

int FirstAdjVex(Graph g, Vertex v); /* 返回 v 的“第一个邻接点” 。若该顶点在 G 中没有邻接点，则返回“空”。 */
int NextAdjVex(Graph g, Vertex v, Vertex w); /* 返回 v 的“第一个邻接点” 。若该顶点在 G 中没有邻接点，则返回“空”。 */
void Print(Graph g); /* 打印图的邻接矩阵 */

/* 从文件中读取弧/边集 */
Status LoadVertexRelation(const char *file_path, Graph *g, VertexRelation **vr);

#endif

#ifdef __cplusplus
}
#endif

