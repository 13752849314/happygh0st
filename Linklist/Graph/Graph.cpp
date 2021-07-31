//
// Created by 37157 on 2021/7/20.
//

#include "Graph.h"
#include "../utils.h"
#include <string>

using namespace std;
bool visited[MaxVertexNum];

/**
 * 构造邻接矩阵
 * @param G
 * @param direction 是否为无向图
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
 * 寻找名字为x的结点的索引
 * @param G
 * @param x
 * @return 索引，为-1寻找失败
 */
int Get_vex_num(MGraph *G, VertexType x) {
    for (int i = 0; i < G->vexnum; i++) {
        if (x == G->Vex[i]) return i;
    }
    return -1;
}

/**
 * 判断图G中是否存在边(x,y)
 * @param G
 * @param x
 * @param y
 * @param direction 是否无向图
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

EdgeType **Get_matrix(MGraph *G) {
    EdgeType **re;
    re = new EdgeType *[G->vexnum];
    for (int i = 0; i < G->vexnum; i++) {
        re[i] = new EdgeType[G->vexnum];
    }
    for (int i = 0; i < G->vexnum; i++) {
        for (int j = 0; j < G->vexnum; j++) {
            re[i][j] = G->Edge[i][j];
        }
    }
    return re;
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
    for (i = 0; i < G->vexnum; i++) {//标志向量初始化
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
    int cq[MaxVertexNum];//定义队列
    for (i = 0; i < MaxVertexNum; i++) {//标志向量初始化
        visited[i] = false;
    }
    for (i = 0; i < MaxVertexNum; i++) {//队列初始化
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

void BFS1(MGraph *G, int v) {
    for (int i = 0; i < G->vexnum; i++) {
        visited[i] = false;
    }
    cout << G->Vex[v] << "->";
    visited[v] = true;
    LinkQueue<int> L;
    L.EnQueue(v);
    while (!L.Empty()) {
        L.DeQueue(v);
        for (int i = 0; i < G->vexnum; i++) {
            if (G->Edge[v][i] != 0 && !visited[i]) {
                cout << G->Vex[i] << "->";
                visited[i] = true;
                L.EnQueue(i);
            }
        }
    }
}

int Get_vex_num(ALGrapg *G, VertexType x) {
    for (int i = 0; i < G->vexnum; i++) {
        if (G->vertices[i].data == x) return i;
    }
    return -1;
}

void Init_ALGrapg(ALGrapg *&G, bool direction) {
    cout << "Please input the number of vertex and arc:" << endl;
    cin >> G->vexnum >> G->arcnum;
    cout << "Please input the name of vertex:" << endl;
    for (int i = 0; i < G->vexnum; i++) {
        cin >> G->vertices[i].data;
        G->vertices[i].first = nullptr;
    }
    VertexType a, b;
    EdgeType value;
    cout << "Please input the arc such as (A B 3)" << endl;
    for (int i = 0; i < G->arcnum; i++) {
        cin >> a >> b >> value;
        int a_index = Get_vex_num(G, a);
        int b_index = Get_vex_num(G, b);
        ArcNode *s;
        s = (ArcNode *) malloc(sizeof(ArcNode));
        s->info = value;
        s->adjvex = b_index;//邻接点序号
        s->next = G->vertices[a_index].first;
        G->vertices[a_index].first = s;//将新结点插入顶点a的边表头部
        if (direction) {//是无向图
            s = (ArcNode *) malloc(sizeof(ArcNode));
            s->info = value;
            s->adjvex = a_index;
            s->next = G->vertices[b_index].first;
            G->vertices[b_index].first = s;
        }
    }
}

bool Adjacent(ALGrapg *G, VertexType x, VertexType y, bool direction) {
    int x_index = Get_vex_num(G, x);
    int y_index = Get_vex_num(G, y);
    ArcNode *p = G->vertices[x_index].first;
    bool temp = false;
    while (p) {
        if (p->adjvex == y_index) {
            temp = true;
            break;
        }
        p = p->next;
    }
    p = G->vertices[y_index].first;
    bool temp1 = false;
    while (p) {
        if (p->adjvex == x_index) {
            temp1 = true;
            break;
        }
        p = p->next;
    }
    if (direction) {
        return temp && temp1;
    } else {
        return temp;
    }
}

void DFSM(ALGrapg *G, int v) {
    ArcNode *p;
    cout << G->vertices[v].data << "->";
    visited[v] = true;
    p = G->vertices[v].first;
    while (p) {
        if (!visited[p->adjvex]) {
            DFSM(G, p->adjvex);
        }
        p = p->next;
    }
}

void DFS(ALGrapg *G) {
    for (int i = 0; i < G->vexnum; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < G->vexnum; i++) {
        if (!visited[i]) {
            DFSM(G, i);
        }
    }
}

void BFS(ALGrapg *G, int k) {
    ArcNode *p;
    LinkQueue<int> L;
    for (int i = 0; i < G->vexnum; i++) {
        visited[i] = false;
    }
    cout << G->vertices[k].data << "->";
    visited[k] = true;
    L.EnQueue(k);
    while (!L.Empty()) {
        L.DeQueue(k);
        p = G->vertices[k].first;
        while (p) {
            if (!visited[p->adjvex]) {
                cout << G->vertices[p->adjvex].data << "->";
                visited[p->adjvex] = true;
                L.EnQueue(p->adjvex);
            }
            p = p->next;
        }
    }
}

MGraph *Convert(ALGrapg *G) {
    MGraph *re;
    re = (MGraph *) malloc(sizeof(MGraph));
    re->vexnum = G->vexnum;
    re->arcnum = G->arcnum;
    for (int i = 0; i < G->vexnum; i++) {
        re->Vex[i] = G->vertices[i].data;
    }
    for (auto &i : re->Edge) {
        for (int &j : i) {
            j = 0;
        }
    }
    ArcNode *p;
    for (int i = 0; i < G->vexnum; i++) {
        p = G->vertices[i].first;
        while (p) {
            re->Edge[i][p->adjvex] = p->info;
            p = p->next;
        }
    }
    return re;
}

void Prim(MGraph *G) {
    int i, j, k;
    int adjvex[MaxVertexNum] = {0};//记录访问结点
    EdgeType low_cost[MaxVertexNum] = {0};
    low_cost[0] = 0;
    adjvex[0] = 0;
    EdgeType value = 0, min;
    format_mat(G);
    for (i = 1; i < G->vexnum; i++) {
        low_cost[i] = G->Edge[0][i];
        adjvex[i] = 0;
    }
    for (i = 1; i < G->vexnum; i++) {
        min = INF;
        j = 1;
        k = 0;
        while (j < G->vexnum) {
            if (low_cost[j] != 0 && low_cost[j] < min) {
                min = low_cost[j];
                k = j;
            }
            j++;
        }
        cout << G->Vex[adjvex[k]] << "->" << G->Vex[k] << "->" << min << endl;
        value += min;
        low_cost[k] = 0;
        for (j = 1; j < G->vexnum; j++) {
            if (low_cost[j] != 0 && G->Edge[k][j] < low_cost[j]) {
                low_cost[j] = G->Edge[k][j];
                adjvex[j] = k;
            }
        }
    }
    cout << "The min value is:" << value << endl;
    recover_mat(G);
}

void format_mat(MGraph *&G) {
    for (int i = 0; i < G->vexnum; i++) {
        for (int j = 0; j < G->vexnum; j++) {
            if (i != j && G->Edge[i][j] == 0) {
                G->Edge[i][j] = INF;
            }
        }
    }
}

void recover_mat(MGraph *&G) {
    for (int i = 0; i < G->vexnum; i++) {
        for (int j = 0; j < G->vexnum; j++) {
            if (i != j && G->Edge[i][j] == INF) {
                G->Edge[i][j] = 0;
            }
        }
    }
}

void GetEdges(MGraph *G, Arc re[MaxVertexNum]) {
    int index = 0;
    for (int i = 0; i < G->vexnum; i++) {
        for (int j = i + 1; j < G->vexnum; j++) {
            if (G->Edge[i][j] != INF) {
                Arc arc(i, j, G->Edge[i][j]);
                re[index] = arc;
                index++;
            }
        }
    }
}

int get_end(const int vends[], int i) {
    while (vends[i] != 0) {
        i = vends[i];
    }
    return i;
}

void Kruskal(MGraph *G) {
    format_mat(G);
    Arc arc[MaxVertexNum], ret[MaxVertexNum];
    int vends[MaxVertexNum] = {0}, value = 0;
    GetEdges(G, arc);
    quick_sort(arc, 0, G->arcnum - 1);//采用快速排序对权值进行排序
    int m, n, index = 0;
    for (int i = 0; i < G->arcnum; i++) {
        m = get_end(vends, arc[i].str);
        n = get_end(vends, arc[i].fin);
        if (m != n) {
            vends[m] = n;
            ret[index++] = arc[i];
        }
    }
    for (int i = 0; i < index; i++) {
        cout << G->Vex[ret[i].str] << "->" << G->Vex[ret[i].fin] << "->" << ret[i].weight << endl;
        value += ret[i].weight;
    }
    cout << "The min value is:" << value << endl;
    recover_mat(G);
}

void Dijkstra(MGraph *G, VertexType source) {
    int str = Get_vex_num(G, source);
    format_mat(G);
    for (int i = 0; i < G->vexnum; i++) {
        visited[i] = false;
    }
    EdgeType shortest[MaxVertexNum];
    string *path;
    path = new string[G->vexnum];//存储最短路径
    for (int i = 0; i < G->vexnum; i++) {//初始化路径
        path[i].push_back(source);
        path[i].push_back(G->Vex[i]);
    }
    EdgeType **matrix = Get_matrix(G);//获得邻接矩阵
    shortest[str] = 0;//存储最短路径值
    visited[str] = true;//标志向量
    for (int i = 1; i < G->vexnum; i++) {
        EdgeType min = INF;
        int index = 0;
        for (int j = 0; j < G->vexnum; j++) {
            if (!visited[j] && matrix[str][j] < min) {
                min = matrix[str][j];
                index = j;
            }
        }
        shortest[index] = min;
        visited[index] = true;
        for (int m = 0; m < G->vexnum; m++) {
            if (!visited[m] && matrix[str][index] + matrix[index][m] < matrix[str][m]) {
                matrix[str][m] = matrix[str][index] + matrix[index][m];
                //更新路径
                string df;
                df.push_back(G->Vex[m]);
                path[m] = path[index] + df;
            }
        }
    }
    for (int i = 0; i < G->vexnum; i++) {//输出结果
        if (i != str) {
            if (shortest[i] == INF) {
                cout << source << " to " << G->Vex[i] << "Unreachable" << endl;
            } else {
                cout << source << " to " << G->Vex[i] << " the shortest path is:" << endl;
                for (char j : path[i]) {
                    cout << j << "->";
                }
                cout << endl;
                cout << "The min path is:" << shortest[i] << endl;
            }
        }
    }
    recover_mat(G);
}

EdgeType **Floyd(MGraph *G) {
    format_mat(G);
    EdgeType **matrix = Get_matrix(G);
    recover_mat(G);
    int n = G->vexnum;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] > matrix[i][k] + matrix[k][j]) {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }
    return matrix;
}

