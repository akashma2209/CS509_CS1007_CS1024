#include "connected_component.hpp"
#include <vector>
#include <queue>
using namespace std;

vector<int> connectedComponents(
    int V,
    const vector<int>& row_ptr,
    const vector<int>& col_idx)
{
    vector<int> component(V, -1);
    int component_id = 0;
    for (int start = 0; start < V; start++)
    {
        if (component[start] != -1){
            continue;
        }
        queue<int> q;
        component[start] = component_id;
        q.push(start);

        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (int i = row_ptr[v]; i < row_ptr[v + 1]; i++)
            {
                int neighbour = col_idx[i];
                if (component[neighbour] == -1)
                {
                    component[neighbour] = component_id;
                    q.push(neighbour);
                }
            }
        }
        component_id++;
    }
    return component;
}


 