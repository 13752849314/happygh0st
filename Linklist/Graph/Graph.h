//
// Created by 37157 on 2021/7/20.
//

#ifndef LINKLIST_GRAPH_H
#define LINKLIST_GRAPH_H

#include <iostream>

#define MaxVertexNum 100 //最大顶点数目
using namespace std;

//邻接矩阵
typedef char VertexType;//顶点数据类型
typedef int EdgeType;//带权图中边上权值的数据类型
typedef struct {
    VertexType Vex[MaxVertexNum]{};
    EdgeType Edge[MaxVertexNum][MaxVertexNum]{};
    int vexnum{}, arcnum{};
} MGraph;

//邻接表
typedef struct ArcNode {//边表结点
    int adjvex;//该边指向的顶点位置
    struct ArcNode *next;//指向下一条边的指针
    EdgeType info;//该边的权值
} ArcNode;
typedef struct VNode {//顶点表结点
    VertexType data;//顶点信息
    ArcNode *first;//指向第一条依附该顶点的边的指针
} VNode, AdjList[MaxVertexNum];
typedef struct {
    AdjList vertices;//邻接表
    int vexnum, arcnum;//图的顶点数和边数
} ALGrapg;

void Init_MGraph(MGraph *&G, bool direction);

int Get_vex_num(MGraph *G, VertexType x);

bool Adjacent(MGraph *G, VertexType x, VertexType y, bool direction);

void DFSM(MGraph *G, int i);

void DFS(MGraph *G);

void BFS(MGraph *G, int k);

void BFS1(MGraph *G, int v);

void Init_ALGrapg(ALGrapg *&G, bool direction);

int Get_vex_num(ALGrapg *G, VertexType x);

bool Adjacent(ALGrapg *G, VertexType x, VertexType y, bool direction);

void DFSM(ALGrapg *G,int v);

void DFS(ALGrapg *G);

void BFS(ALGrapg *G,int k);
#endif //LINKLIST_GRAPH_H
