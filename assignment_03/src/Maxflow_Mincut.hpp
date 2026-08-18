#ifndef MAXFLOW_MINCUT_HPP
#define MAXFLOW_MINCUT_HPP

#include "../../common/csr/src/CSR.hpp"

struct CutEdge
{
    int u;
    int v;
    int capacity;
};

// Dinic's Maximum Flow + Minimum Cut
void maxflowMincut(
    CSR &graph,
    int source,
    int sink,
    int &maxFlow,
    int &cutCapacity,
    int sourceSide[],
    int &sourceSideCount,
    int sinkSide[],
    int &sinkSideCount,
    CutEdge cutEdges[],
    int &cutEdgeCount
);

#endif