#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "../src/csr.hpp"
#include "../src/bfs.hpp"
#include "../src/dfs.hpp"

using namespace std;
int main()
{
    ifstream fin("tests/bfs_dfs/graph_2.txt");

    if (!fin)
    {
        cout << "Unable to open file!" << endl;
        return 1;
    }

    int V, E;
    fin >> V >> E;

    vector<vector<int>> adj(V);
    for (int i = 0; i < V; i++)
    {
        int u, degree;
        fin >> u >> degree;
        for (int j = 0; j < degree; j++)
        {
            int v;
            fin >> v;
            adj[u].push_back(v);
        }
    }

    string temp;
    int source;
    fin >> temp >> source;

    fin.close();

    // Converting into CSR
    CSR csr = convertToCSR(adj);
    // Calling BFS Function for BFS traversal
    BFS(csr, source);
    // Calling DFS function for DFS traversal
    DFS(csr, V, source);
    cout<<endl;
    return 0;
}