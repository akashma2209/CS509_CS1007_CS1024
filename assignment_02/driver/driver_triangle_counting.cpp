#include <iostream>
#include <fstream>
#include <filesystem>
#include <chrono>
#include <string>
#include "../src/Triangle_Counting.hpp"
#include "../../common/csr/src/CSR.hpp"
#include "../../common/csr/src/driver_csr.hpp"
using namespace std;
namespace fs = filesystem;

// Printing result on Terminal and  File
void printTriangleResult(ostream &out,Triangle tri[],int t_count,double time)
{
    out << "Algorithm: Triangle Counting" << "\n";
    out << "Total triangles: "<< t_count<< "\n";

    if(t_count > 0) // Print maximum 10 triangles
    {
        out << "Triangles found:" << "\n";
        int c = t_count;
        if(c > 10)
        {
            c = 10;
        }
        for(int i = 0; i < c; i++)
        {
            out << "("<< tri[i].a<< ", "<< tri[i].b<< ", "<< tri[i].c<< ")"<< "\n";
        }
        if(t_count > 10) //If there are more than 10 traingles 
        {
            out << "more triangles..."<< "\n";
        }
    }
    out << "Execution time: "<< time<< " ms"<< "\n";
}

int main()
{
    string input ="assignment_02/tests/triangle_counting"; //Input file
    string csr_out ="common/csr/outputs/graph";  //CSR output file
    string output ="assignment_02/outputs/triangle_counting";  //Output file

    cout << "Generating CSR files..." << "\n";
    genCSR(input); // Generate CSR from adjacency-list input
    cout << "CSR generation completed." << "\n";
    if(filesystem::exists(output)) //Removing old output file
    {
        for(auto file : filesystem::directory_iterator(output))
        {
            if(file.path().extension() == ".txt")
            {
                filesystem::remove(file.path());
            }
        }
    }
    for(const auto &file : fs::directory_iterator(csr_out)) //Reading all file with .txt  extension
    {
        if(file.path().extension() != ".txt")
        {
            continue;
        }
        cout << "\n";
        cout << "Running : " << file.path().filename().string() << "\n";

        ifstream fin(file.path()); //Opening CSR file
        if(!fin)
        {
            cout << "Cannot open CSR file." << "\n";
            continue;
        }
        int vertex;
        int edges;
        fin >> vertex >> edges; // Read number of vertex and edges
        int *rowPtr =new int[vertex + 1];  
        int *colIdx =new int[edges];
        int *values =new int[edges];

        for(int i = 0; i <= vertex; i++) // Read row pointer
        {
            fin >> rowPtr[i];
        }
        for(int i = 0; i < edges; i++) // Read column index
        {
            fin >> colIdx[i];
        }
        for(int i = 0; i < edges; i++) // Read edge weights
        {
            fin >> values[i];
        }
        fin.close();

        CSR graph;  // Create CSR structure
        graph.vertices = vertex;
        graph.edges = edges;
        graph.row_ptr = rowPtr;
        graph.col_idx = colIdx;
        graph.values = values;

        Triangle *tri =new Triangle[MAX];   // Store the triangles found by the algorithm
        int t_count = 0;
    
        auto start =chrono::high_resolution_clock::now(); //Start Triangle Counting  Timer
        countTriangle( graph, tri,t_count);
        auto end =chrono::high_resolution_clock::now(); //Start Triangle Counting  Timer
        double time =chrono::duration<double, milli>(end - start).count();
     
        string out = output + "/" +file.path().filename().string(); // Create output file
        ofstream fout(out);
        if(!fout)
        {
            cout << "Cannot create output file." << "\n";
            continue;
        }

        printTriangleResult(cout,tri,t_count, time); //Print result on terminal
        printTriangleResult(fout,tri,t_count,time);  //Store result on file
        fout.close();
        cout << "Output: "<< out<< "\n";
    }
    return 0;
}