#include <iostream>
#include <fstream>
#include <climits>
#include "SSSP_Graph.hpp"
using namespace std;

CSR convertToCSR(int source[],int destination[],int weight[],int edges,int vertices)
{
    CSR graph;

    graph.vertices = vertices;
    graph.edges = edges;
    graph.row_ptr = new int[vertices+1];
    graph.col_idx = new int[edges];
    graph.values = new int[edges];

    for(int i=0;i<=vertices;i++)
    {
        graph.row_ptr[i]=0;
    }
    for(int i=0;i<edges;i++)
    {
        graph.row_ptr[source[i]+1]++;
    }

    for(int i=1;i<=vertices;i++)
    {
        graph.row_ptr[i]+=graph.row_ptr[i-1];
    }
    int *temp=new int[vertices];

    for(int i=0;i<vertices;i++)
    {
        temp[i]=graph.row_ptr[i];
    }
        
    for(int i=0;i<edges;i++)
    {
        int pos=temp[source[i]];
        graph.col_idx[pos]=destination[i];
        graph.values[pos]=weight[i];
        temp[source[i]]++;
    }
    delete [] temp;
    return graph;
}




void dijkstraCSR(
    CSR graph,
    int source,
    const char *outputFile,
    double executionTime
)
{
    int *dist = new int[graph.vertices];
    bool *visited = new bool[graph.vertices];

    for(int i = 0; i < graph.vertices; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[source] = 0;

    for(int count = 0; count < graph.vertices - 1; count++)
    {
        int u = -1;
        int minimum = INT_MAX;

        for(int i = 0; i < graph.vertices; i++)
        {
            if(!visited[i] && dist[i] < minimum)
            {
                minimum = dist[i];
                u = i;
            }
        }

        if(u == -1)
            break;

        visited[u] = true;

        for(int i = graph.row_ptr[u];
            i < graph.row_ptr[u + 1];
            i++)
        {
            int v = graph.col_idx[i];
            int w = graph.values[i];

            if(!visited[v] &&
               dist[u] != INT_MAX &&
               dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    ofstream fout(outputFile);

    // Terminal
    cout << "\nAlgorithm: SSSP\n";
    cout << "Source: " << source << "\n\n";
    cout << "Vertex\tDistance\n";

    // File
    fout << "Algorithm: SSSP\n";
    fout << "Source: " << source << "\n\n";
    fout << "Vertex\tDistance\n";

    for(int i = 0; i < graph.vertices; i++)
    {
        cout << i << "\t";
        fout << i << "\t";

        if(dist[i] == INT_MAX)
        {
            cout << "INF";
            fout << "INF";
        }
        else
        {
            cout << dist[i];
            fout << dist[i];
        }

        cout << endl;
        fout << endl;
    }

    cout << "\nExecution Time : "
         << executionTime
         << " ms\n";

    fout << "\nExecution Time : "
         << executionTime
         << " ms\n";

    fout.close();

    delete[] dist;
    delete[] visited;
}


void freeCSR(CSR &graph)
{

    delete [] graph.row_ptr;

    delete [] graph.col_idx;

    delete [] graph.values;


}