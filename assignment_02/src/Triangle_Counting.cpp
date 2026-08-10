#include "Triangle_Counting.hpp"

bool isConnected(CSR &graph,int u,int v) //Checking if vertex is persent in between a and b
{
    int start = graph.row_ptr[u];
    int end = graph.row_ptr[u + 1];
    for(int i = start; i < end; i++)
    {
        if(graph.col_idx[i] == v)
        {
            return true;
        }
    }
    return false;
}

void countTriangle(CSR &graph, Triangle tri[], int &t_count)
{
    t_count = 0;  //Counter to store number of triangle
    for(int u = 0; u < graph.vertices; u++) // Check every vertex
    {
        int start = graph.row_ptr[u];
        int end = graph.row_ptr[u + 1];
        for(int i = start; i < end; i++) // Take pairs of neighbours
        {
            int v = graph.col_idx[i];
            if(v <= u) 
            {
                continue;
            }
            for(int j = i + 1; j < end; j++)
            {
                int w = graph.col_idx[j];
                if(w <= v)
                {
                    continue;
                }
                if(isConnected(graph, v, w)) // Check whether v and w are connected
                {
                    if(t_count < MAX)
                    {
                        tri[t_count].a = u;
                        tri[t_count].b = v;
                        tri[t_count].c = w;
                        t_count++;
                    }
                }
            }
        }
    }
}