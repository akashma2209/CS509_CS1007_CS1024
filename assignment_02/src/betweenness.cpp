#include "betweenness.hpp"
#include <vector>
#include <queue>
#include <stack>
using namespace std;

vector<double> betweennessCentrality(
    int V,
    const vector<int>& row_ptr,
    const vector<int>& col_idx)
{
    vector<double> centrality(V, 0.0);
    for (int s = 0; s < V; s++)
    {
        vector<vector<int>> predecessor(V);
        vector<int> distance(V, -1);
        vector<double> sigma(V, 0.0);
        vector<double> dependency(V, 0.0);
        queue<int> q;
        stack<int> st;
        distance[s] = 0;
        sigma[s] = 1.0;
        q.push(s);
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            st.push(v);

            for (int i = row_ptr[v]; i < row_ptr[v + 1]; i++)
            {
                int w = col_idx[i];

                if (distance[w] == -1)
                {
                    distance[w] = distance[v] + 1;
                    q.push(w);
                }

                if (distance[w] == distance[v] + 1)
                {
                    sigma[w] += sigma[v];
                    predecessor[w].push_back(v);
                }
            }
        }
        while (!st.empty())
        {
            int w = st.top();
            st.pop();

            for (int v : predecessor[w])
            {
                if (sigma[w] != 0)
                {
                    dependency[v] +=
                        (sigma[v] / sigma[w]) *
                        (1.0 + dependency[w]);
                }
            }
            if (w != s)
            {
                centrality[w] += dependency[w];
            }
        }
    }
    for (int i = 0; i < V; i++)
    {
        centrality[i] /= 2.0;
    }
    return centrality;
}
