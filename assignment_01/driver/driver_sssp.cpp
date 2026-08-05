#include <iostream>
#include <fstream>
#include <chrono>
#include <filesystem>
#include "../src/SSSP_Graph.hpp"
using namespace std;
namespace fs = std::filesystem;

int main()
{
    int c =1;
    string input = "outputs/graph/csr";
    string output = "outputs/sssp";

    for(const auto &file : fs::directory_iterator(input))
    {
        if(file.path().extension() != ".txt")
            continue;
        string testName = file.path().stem().string();
        string outputFile = output + "/output_" + to_string(c) + ".txt";
        c++;
    
        cout << "\n=====================================\n";
        cout << "Running : " << testName << "\n";

        ifstream fin(file.path());
        if(!fin)
        {
            cout << "Cannot open input file." << endl;
            continue;
        }
        CSR graph;
        fin >> graph.vertices >> graph.edges;
        graph.row_ptr = new int[graph.vertices + 1];
        graph.col_idx = new int[graph.edges];
        graph.values = new int[graph.edges];

        // Row Pointer
        for(int i = 0; i <= graph.vertices; i++)
        {
            fin >> graph.row_ptr[i];
        }

        // Column Index
        for(int i = 0; i < graph.edges; i++)
        {
            fin >> graph.col_idx[i];
        }

        // Values
        for(int i = 0; i < graph.edges; i++)
        {
            fin >> graph.values[i];
        }
        int source;
        fin >> source;
        fin.close();
        auto start = chrono::high_resolution_clock::now();
        // Measure only algorithm execution
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
            for(int i = graph.row_ptr[u];i < graph.row_ptr[u + 1]; i++)
            {
                int v = graph.col_idx[i];
                int w = graph.values[i];

                if(!visited[v] && dist[u] != INT_MAX && dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                }
            }
        }

        auto end = chrono::high_resolution_clock::now();
        double time =chrono::duration<double, milli>(end - start).count();
        delete[] dist;
        delete[] visited;

        // Print and save output
        dijkstraCSR(graph, source, outputFile.c_str(), time);

        delete[] graph.row_ptr;
        delete[] graph.col_idx;
        delete[] graph.values;
    }

    cout << "\n=====================================\n";
    cout << "All SSSP tests completed." << endl;

    return 0;
}