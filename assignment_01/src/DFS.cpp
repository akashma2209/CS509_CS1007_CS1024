#include "DFS.hpp"
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

void dfsUtil(const CSR &csr, int u, vector<bool> &visited)
{
    visited[u] = true;
    cout << u << " ";
    for (int i = csr.row_ptr[u]; i < csr.row_ptr[u + 1]; i++)
    {
        int v = csr.col_idx[i];
        if (!visited[v])
        {
            dfsUtil(csr, v, visited);
        }
    }
}

void DFS(const CSR &csr, int v, int source)
{
    auto start = chrono::high_resolution_clock::now();
    int V = csr.row_ptr.size() - 1;
    vector<bool> visited(V, false);
    cout << "\nAlgorithm: DFS" << endl;
    cout << "Source: " << source << endl;
    cout << "Traversal: ";
    dfsUtil(csr, source, visited);
    cout << endl;
    auto end = chrono::high_resolution_clock::now();
    auto duration =
        chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Execution time: "<< duration.count()<< " microseconds" << endl;
}