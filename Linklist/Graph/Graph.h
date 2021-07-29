//
// Created by 37157 on 2021/7/20.
//

#ifndef LINKLIST_GRAPH_H
#define LINKLIST_GRAPH_H

#include <iostream>

#define MaxVertexNum 100 //��󶥵���Ŀ
using namespace std;

//�ڽӾ���
typedef char VertexType;//������������
typedef int EdgeType;//��Ȩͼ�б���Ȩֵ����������
typedef struct {
    VertexType Vex[MaxVertexNum]{};
    EdgeType Edge[MaxVertexNum][MaxVertexNum]{};
    int vexnum{}, arcnum{};
} MGraph;

//�ڽӱ�
typedef struct ArcNode {//�߱���
    int adjvex;//�ñ�ָ��Ķ���λ��
    struct ArcNode *next;//ָ����һ���ߵ�ָ��
    EdgeType info;//�ñߵ�Ȩֵ
} ArcNode;
typedef struct VNode {//�������
    VertexType data;//������Ϣ
    ArcNode *first;//ָ���һ�������ö���ıߵ�ָ��
} VNode, AdjList[MaxVertexNum];
typedef struct {
    AdjList vertices;//�ڽӱ�
    int vexnum, arcnum;//ͼ�Ķ������ͱ���
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
