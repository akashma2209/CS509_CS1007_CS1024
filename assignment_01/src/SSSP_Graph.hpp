#ifndef CSR_GRAPH_HPP
#define CSR_GRAPH_HPP

struct CSR
{
    int *row_ptr;
    int *col_idx;
    int *values;
    int vertices;
    int edges;
};


// Convert Edge List to CSR
CSR convertToCSR(int source[], int destination[],int weight[],int edges,int vertices);

// Single Source Shortest Path using Dijkstra
void dijkstraCSR(CSR graph,int source,const char *outputFile,double executionTime);

// Free dynamically allocated CSR arrays
void freeCSR(CSR &graph);
#endif