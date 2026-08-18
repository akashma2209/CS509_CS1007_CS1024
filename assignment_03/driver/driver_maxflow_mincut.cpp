#include <iostream>
#include <fstream>
#include <filesystem>
#include <chrono>
#include <string>
#include "../src/maxflow_Mincut.hpp"
#include "../../common/csr/src/CSR.hpp"
#include "../../common/csr/src/driver_csr.hpp"
using namespace std;
namespace fs = filesystem;

// Print result on terminal and file
void print(ostream &out,int src,int sink,int maxflow,int capacity,int srcSide[],int scr_count,int sinkSide[],
                int sink_count,CutEdge cutEdges[],int edge_count,double time)
{
    out << "Algorithm: maxflow-Mincut\n\n";
    out << "Source: " << src << "\n";
    out << "Sink: " << sink << "\n\n";
    out << "Maximum flow: " << maxflow << "\n";
    out << "Minimum cut capacity: " << capacity << "\n\n";
    out << "Source side: ";
    for(int i = 0; i < scr_count; i++)
    {
        out << srcSide[i] << " ";
    }
    out << "\nSink side: ";
    for(int i = 0; i < sink_count; i++)
    {
        out << sinkSide[i] << " ";
    }
    out << "\n\nCut edges:\n";

    for(int i = 0; i < edge_count; i++)
    {
        out << cutEdges[i].u << " "<< cutEdges[i].v << " "<< cutEdges[i].capacity << "\n";
    }
    out << "\nExecution time: " << time << " ms\n";
}

// Read SOURCE and SINK
void read_ss( string input, int &scr, int &sink)
{
    ifstream fin(input);
    int vertex;
    int edges;
    fin >> vertex >> edges;

     // Skip complete adjacency list
    for(int i = 0; i < vertex; i++)
    {
        int vertex;
        int degree;
        fin >> vertex >> degree;
        for(int j = 0; j < degree; j++)
        {
            int neighbour;
            int capacity;
            fin >> neighbour >> capacity;
        }
    }
    // Read scr and its vertex
    string word;
    fin >> word >> scr;
    fin >> word >> sink;
    fin.close();
}


int main()
{
    string input = "assignment_03/tests/maxflow_mincut"; //input file
    string csr_out ="common/csr/outputs/graph"; //csr generated file
    string output ="assignment_03/outputs/maxflow_mincut"; //Output file
    
    genCSR(input); // Generate CSR

    if(fs::exists(output)) //Remove old maxflow output file
    {
        for(auto file : fs::directory_iterator(output))
        {
            if(file.path().extension() == ".txt")
            {
                fs::remove(file.path());
            }
        }
    }

    //Reading all file with 
    for(auto file : fs::directory_iterator(csr_out))
    {
        if(file.path().extension() != ".txt")
        {
            continue;
        }
        cout << "\nRunning : " << file.path().filename().string() << "\n";
        string inputs =input + "/" +file.path().filename().string();

        int scr;
        int sink;
        read_ss(inputs, scr, sink);
       
        ifstream fin(file.path());  // Read CSR
        int vertex;
        int edges;
        fin >> vertex >> edges; // Read number of vertices and edges
        // Create CSR arrays
        int *rowPtr = new int[vertex + 1];
        int *colIdx = new int[edges];
        int *values = new int[edges];
       
        for(int i = 0; i <= vertex; i++) // Read row pointer
        {
            fin >> rowPtr[i];
        }
        for(int i = 0; i < edges; i++)  // Read column indices
        {
            fin >> colIdx[i];
        }
        for(int i = 0; i < edges; i++) // Read weights
        {
            fin >> values[i];
        }
        fin.close();

        
        CSR graph; // Create CSR object
        graph.vertices = vertex;
        graph.edges = edges;
        graph.row_ptr = rowPtr;
        graph.col_idx = colIdx;
        graph.values = values;

        // Output arrays
        int *srcSide = new int[vertex];
        int *sinkSide = new int[vertex];

        CutEdge *cutEdges = new CutEdge[edges];
        int maxflow;
        int capacity;
        int scr_count;
        int sink_count;
        int edge_count;

        auto start =chrono::high_resolution_clock::now(); // Start maxflow timing
        maxflowMincut( graph, scr, sink, maxflow, capacity, srcSide, scr_count, sinkSide, sink_count, cutEdges, edge_count);
        auto stop =chrono::high_resolution_clock::now(); //// Stop Kruskal timing
        double time = chrono::duration<double, milli>(stop - start ).count();

        // Output file
        string out = output + "/" + file.path().filename().string();

        ofstream fout(out);
        if(!fout)
        {
            cout << "Cannot create output file.\n";
        }
        else
        {
            print( cout, scr, sink, maxflow, capacity, srcSide, scr_count, sinkSide, sink_count, cutEdges, edge_count,time); // Print to terminal
            print(fout,scr,sink,maxflow,capacity,srcSide,scr_count,sinkSide,sink_count,cutEdges,edge_count,time); // Print to file
            fout.close();
            cout << "Output : " << out << "\n";
        }
    }
    return 0;
}