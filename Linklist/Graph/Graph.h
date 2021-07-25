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

void Init_MGraph(MGraph *&G,bool direction);

int Get_vex_num(MGraph *G,VertexType x);

bool Adjacent(MGraph *G,VertexType x,VertexType y,bool direction);
#endif //LINKLIST_GRAPH_H
