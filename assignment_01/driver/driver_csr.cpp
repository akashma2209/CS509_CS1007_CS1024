#include <iostream>
#include <fstream>
#include <chrono>
#include <filesystem>
#include "../src/SSSP_Graph.hpp"

using namespace std;
namespace fs = std::filesystem;

void printCSR(ostream &out, CSR graph)
{
    out << graph.vertices << " " << graph.edges << endl;
    // Row Pointer
    for(int i = 0; i <= graph.vertices; i++)
    {
        out << graph.row_ptr[i] << " ";
    }
    out << endl;
    // Column Index
    for(int i = 0; i < graph.edges; i++)
    {
        out << graph.col_idx[i] << " ";
    }
    out << endl;
    // Edge Weights
    for(int i = 0; i < graph.edges; i++)
    {
        out << graph.values[i] << " ";
    }
    out << endl;
}

int main()
{
    int c =1;
    string input = "tests/sssp";
    string output = "outputs/graph/csr";

    if(!fs::exists(output))
    {
        fs::create_directories(output);
    }
    for(auto &file : fs::directory_iterator(input))
    {
        if(file.path().extension() != ".txt")
            continue;
        string outputFile = output + "/output_" + to_string(c) + ".txt"; //Creating output file loctaion for CSR
        c++;
        // cout << "\n Running : " ;  Use to check code is working or not

        ifstream fin(file.path());

        if(!fin)
        {
            cout << "Cannot open input file." << endl;
            continue;
        }

        int vertices, totalEdges;
        fin >> vertices >> totalEdges;
        int source[100000];
        int destination[100000];
        int weight[100000];

        int edges = 0;
        // Read adjacency list
        for(int i = 0; i < vertices; i++)
        {
            int u, degree;
            fin >> u >> degree;
            for(int j = 0; j < degree; j++)
            {
                source[edges] = u;
                fin >> destination[edges];
                fin >> weight[edges];
                edges++;
            }
        }
        // Read source vertex
        string temp;
        int startVertex;
        fin >> temp >> startVertex;
        fin.close();
        CSR graph = convertToCSR(source, destination, weight, edges, vertices);        
        // Save CSR file
        ofstream fout(outputFile);
        if(!fout)
        {
            cout << "Cannot create output file." << endl;
        }
        else
        {
            printCSR(fout, graph);
            // Store source at last line
            fout << startVertex << endl;
            fout.close();
        }

        delete[] graph.row_ptr;
        delete[] graph.col_idx;
        delete[] graph.values;
    }
    return 0;
}

