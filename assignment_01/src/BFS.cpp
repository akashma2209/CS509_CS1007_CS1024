#include "BFS.hpp"
#include <iostream>
#include <vector>
#include <queue>
#include <chrono>

using namespace std;
void BFS(const CSR &csr, int source)
{
    auto start = chrono::high_resolution_clock::now();
    int V = csr.row_ptr.size() - 1;
    vector<bool> visited(V, false);
    vector<int> distance(V, -1);
    queue<int> q;
    visited[source] = true;
    distance[source] = 0;
    q.push(source);
    cout << "\nAlgorithm: BFS" << endl;
    cout << "Source: " << source << endl;
    cout << "Traversal: ";

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int i = csr.row_ptr[u]; i < csr.row_ptr[u + 1]; i++)
        {
            int v = csr.col_idx[i];

            if (!visited[v])
            {
                visited[v] = true;
                distance[v] = distance[u] + 1;
                q.push(v);
            }
        }
    }

    cout << endl;
    cout << "Distances:" << endl;
    for (int i = 0; i < V; i++)
    {
        cout << i << " " << distance[i] << endl;
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Execution time: " << duration.count()<< " microseconds" << endl;
}