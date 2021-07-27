//
// Created by 37157 on 2021/7/20.
//

#include "Graph.h"

bool visited[MaxVertexNum];

/**
 * �����ڽӾ���
 * @param G
 * @param direction �Ƿ�Ϊ����ͼ
 */
void Init_MGraph(MGraph *&G, bool direction) {
    int vex, arc;
    VertexType Ver[MaxVertexNum];
    for (auto &i : G->Edge) {
        for (int &j : i) {
            j = 0;
        }
    }
    cout << "Please input the number of vertex:" << endl;
    cin >> vex;
    G->vexnum = vex;
    cout << "Please input the name of each vertex:" << endl;
    for (int i = 0; i < G->vexnum; i++) {
        cin >> Ver[i];
        G->Vex[i] = Ver[i];
    }
    cout << "Please input the number of arc:" << endl;
    cin >> arc;
    G->arcnum = arc;
    cout << "Please input the arc such as (A B 3)" << endl;
    for (int i = 0; i < G->arcnum; i++) {
        VertexType a, b;
        int value, a_index, b_index;
        cin >> a >> b >> value;
        a_index = Get_vex_num(G, a);
        b_index = Get_vex_num(G, b);
        G->Edge[a_index][b_index] = value;
        if (direction) {
            G->Edge[b_index][a_index] = value;
        }
    }
}

/**
 * Ѱ������Ϊx�Ľ�������
 * @param G
 * @param x
 * @return ������Ϊ-1Ѱ��ʧ��
 */
int Get_vex_num(MGraph *G, VertexType x) {
    for (int i = 0; i < G->vexnum; i++) {
        if (x == G->Vex[i]) return i;
    }
    return -1;
}

/**
 * �ж�ͼG���Ƿ���ڱ�(x,y)
 * @param G
 * @param x
 * @param y
 * @param direction �Ƿ�����ͼ
 * @return
 */
bool Adjacent(MGraph *G, VertexType x, VertexType y, bool direction) {
    int x_index = Get_vex_num(G, x);
    int y_index = Get_vex_num(G, y);
    if (!direction && G->Edge[x_index][y_index] != 0) return true;
    if (direction) {
        if (G->Edge[x_index][y_index] != 0 || G->Edge[y_index][x_index] != 0) return true;
    }
    return false;
}

void DFSM(MGraph *G, int i) {
    int j;
    cout << G->Vex[i] << "->";
    visited[i] = true;
    for (j = 0; j < G->vexnum; j++) {
        if (G->Edge[i][j] != 0 && !visited[j]) {
            DFSM(G, j);
        }
    }
}

void DFS(MGraph *G) {
    int i;
    for (i = 0; i < G->vexnum; i++) {//��־������ʼ��
        visited[i] = false;
    }
    for (i = 0; i < G->vexnum; i++) {
        if (!visited[i]) {
            DFSM(G, i);
        }
    }
}

void BFS(MGraph *G, int k) {
    int i, j, f = 0, r = 0;
    int cq[MaxVertexNum];//�������
    for (i = 0; i < MaxVertexNum; i++) {//��־������ʼ��
        visited[i] = false;
    }
    for (i = 0; i < MaxVertexNum; i++) {//���г�ʼ��
        cq[i] = -1;
    }
    cout << G->Vex[k] << "->";
    visited[k] = true;
    cq[r] = k;
    while (cq[f] != -1) {
        i = cq[f];
        f = f + 1;
        for (j = 0; j < G->vexnum; j++) {
            if (G->Edge[i][j] != 0 && !visited[j]) {
                cout << G->Vex[j] << "->";
                visited[j] = true;
                r = r + 1;
                cq[r] = j;
            }
        }
    }
}
