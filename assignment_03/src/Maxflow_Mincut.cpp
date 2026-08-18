#include "Maxflow_Mincut.hpp"
#include <climits>
using namespace std;

// Internal residual edge
struct FlowEdge
{
    int to;
    int capacity;
    int rev_idx;
};

// Dinic graph
struct DinicGraph
{
    FlowEdge **edges;
    int *edgeCount;
    int *edgeCapacity;

    int vertex;
};

DinicGraph dinic_graph(int vertex, int initialCapacity) // Create Dinic graph
{
    DinicGraph graph;
    graph.vertex = vertex;
    graph.edges = new FlowEdge*[vertex];
    graph.edgeCount = new int[vertex];
    graph.edgeCapacity = new int[vertex];

    for(int i = 0; i < vertex; i++)
    {
        graph.edgeCount[i] = 0;
        graph.edgeCapacity[i] = initialCapacity;
        graph.edges[i] =new FlowEdge[initialCapacity];
    }
    return graph;
}

void addEdge(DinicGraph &graph,int u,int v,int capacity)  // Add residual edge
{
    if(graph.edgeCount[u] >= graph.edgeCapacity[u])
    {
        int newCapacity =graph.edgeCapacity[u] * 2;
        FlowEdge *newEdges =new FlowEdge[newCapacity];
        for(int i = 0; i < graph.edgeCount[u]; i++)
        {
            newEdges[i] =graph.edges[u][i];
        }
        graph.edges[u] = newEdges;
        graph.edgeCapacity[u] =newCapacity;
    }

    if(graph.edgeCount[v] >= graph.edgeCapacity[v])
    {
        int newCapacity =graph.edgeCapacity[v] * 2;
        FlowEdge *newEdges =new FlowEdge[newCapacity];
        for(int i = 0;i < graph.edgeCount[v];i++)
        {
            newEdges[i] =graph.edges[v][i];
        }
        graph.edges[v] = newEdges;
        graph.edgeCapacity[v] =newCapacity;
    }
    int forwardIndex = graph.edgeCount[u];
    int reverseIndex =graph.edgeCount[v];
    // Forward residual edge
    graph.edges[u][forwardIndex].to = v;
    graph.edges[u][forwardIndex].capacity = capacity;
    graph.edges[u][forwardIndex].rev_idx =reverseIndex;
    // Reverse residual edge
    graph.edges[v][reverseIndex].to = u;
    graph.edges[v][reverseIndex].capacity = 0;
    graph.edges[v][reverseIndex].rev_idx =forwardIndex;
    graph.edgeCount[u]++;
    graph.edgeCount[v]++;
}

bool bfs(DinicGraph &graph,int source,int sink,int level[]) // BFS Creates level graph
{
    for(int i = 0; i < graph.vertex; i++)
    {
        level[i] = -1;
    }
    int *queue = new int[graph.vertex];
    int front = 0;
    int rear = 0;
    queue[rear++] = source;
    level[source] =0;
    while(front < rear)
    {
        int u =queue[front++];
        for(int i = 0; i < graph.edgeCount[u]; i++)
        {
            FlowEdge &edge =graph.edges[u][i];
            if(edge.capacity > 0 &&level[edge.to] == -1)
            {
                level[edge.to] =level[u] + 1;
                queue[rear++] =edge.to;
            }
        }
    }
    bool reachable = (level[sink] != -1);
    return reachable;
}

int sendFlow( DinicGraph &graph, int u, int sink, int flow, int level[], int nextEdge[]) // DFS Sends flow through level graph
{
    if(u == sink)
    {
        return flow;
    }

    while(nextEdge[u] <graph.edgeCount[u])
    {
        int edgeIndex =nextEdge[u];
        FlowEdge &edge =graph.edges[u][edgeIndex];
        if(edge.capacity > 0 &&level[edge.to] ==level[u] + 1)
        {
            int newFlow =flow;
            if(edge.capacity <newFlow)
            {
                newFlow =edge.capacity;
            }
            int result =sendFlow(graph,edge.to,sink,newFlow,level,nextEdge);
            if(result > 0)
            {
                // Reduce forward capacity
                edge.capacity -=result;
                // Increase reverse capacity
                graph.edges[edge.to][edge.rev_idx].capacity +=result;
                return result;
            }
        }
        nextEdge[u]++;
    }


    return 0;
}

void find_src(DinicGraph &graph,int source,bool visited[]) // Find vertices reachable from source in residual graph
{
    for(int i = 0;i < graph.vertex;i++)
    {
        visited[i] =false;
    }
    int *queue =new int[graph.vertex];
    int front = 0;
    int rear = 0;
    queue[rear++] =source;
    visited[source] =true;
    while(front < rear)
    {
        int u =queue[front++];
        for(int i = 0;i < graph.edgeCount[u];i++)
        {
            FlowEdge &edge =graph.edges[u][i];
            if(edge.capacity > 0 &&!visited[edge.to])
            {
                visited[edge.to] =true;
                queue[rear++] =edge.to;
            }
        }
    }
}

// Main Maxflow-Mincut function
void maxflowMincut(CSR &graph,int source,int sink,int &maxFlow,int &cutCapacity,int sourceSide[],int &src_count,int sinkSide[],
    int &sink_count,CutEdge cutEdges[],int &edge_count)
{
    int vertex =graph.vertices;
    int edges =graph.edges;
    maxFlow = 0;
    cutCapacity = 0;
    src_count = 0;
    sink_count = 0;
    edge_count = 0;

    DinicGraph residual = dinic_graph(vertex, 4); // Create residual graph

    for(int u = 0;u < vertex;u++) // Add original directed edges
    {
        int start =graph.row_ptr[u];
        int end =graph.row_ptr[u + 1];
        for(int i = start;i < end;i++)
        {
            int v =graph.col_idx[i];
            int capacity =graph.values[i];
            if(capacity > 0)
            {
                addEdge(residual,u,v,capacity);
            }
        }
    }
     // Allocate Dinic arrays
    int *level =new int[vertex];
    int *nextEdge =new int[vertex];

    // Dinic maximum-flow algorithm
    while(bfs( residual, source, sink, level))
    {
        for(int i = 0; i < vertex; i++)
        {
            nextEdge[i] =0;
        }

        while(true)
        {
            int flow =sendFlow(residual,source,sink,INT_MAX,level,nextEdge);
            if(flow == 0)
            {
                break;
            }
            maxFlow +=flow;
        }
    }

    // Find minimum-cut source side
    bool *visited = new bool[vertex];
    find_src( residual, source, visited);

    for(int i = 0;i < vertex;i++)
    {
        if(visited[i])
        {
            sourceSide[src_count++] =i;
        }
        else
        {
            sinkSide[sink_count++] =i;
        }
    }

    for(int u = 0;u < vertex;u++) // Find cut edges
    {
        int start =graph.row_ptr[u];
        int end =graph.row_ptr[u + 1];
        for(int i = start; i < end; i++)
        {
            int v =graph.col_idx[i];
            int capacity =graph.values[i];

            if(visited[u] &&!visited[v] &&capacity > 0)
            {
                cutEdges[edge_count].u =u;
                cutEdges[edge_count].v =v;
                cutEdges[edge_count].capacity =capacity;
                cutCapacity +=capacity;
                edge_count++;
            }
        }
    }
}
// g++ -std=c++17 assignment_03\driver\driver_maxflow_mincut.cpp assignment_03\src\Maxflow_Mincut.cpp common\csr\src\CSR.cpp common\csr\src\driver_csr.cpp -o assignment_03\executables\maxflow_mincut.exe

// .\assignment_03\executables\maxflow_mincut.exe