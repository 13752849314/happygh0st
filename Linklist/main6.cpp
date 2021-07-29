//
// Created by 37157 on 2021/7/20.
//
#include "Graph/Graph.h"

int main() {
//    auto G = (MGraph *) malloc(sizeof(MGraph));
//    Init_MGraph(G, true);
//    DFS(G);
//    cout<<endl;
//    BFS(G,0);
//    cout<<endl;
//    BFS1(G,0);

    auto G = (ALGrapg *) malloc(sizeof(ALGrapg));
    Init_ALGrapg(G, true);
    cout<<Adjacent(G,'D','E', true)<<endl;
    DFS(G);
    cout<<endl;
    BFS(G,0);
    return 0;
}
