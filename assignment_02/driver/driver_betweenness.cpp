#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <chrono>
#include <filesystem>
#include "../src/betweenness.hpp"
#include "../../Assignment_01/src/csr.hpp"
using namespace std;
using namespace chrono;
namespace fs = std::filesystem;

int main()
{
    const string input = "tests/bc_test";
    const string output = "outputs/bc_output";
    fs::create_directories(output);
    for (const auto& entry : fs::directory_iterator(output))
    {
        if (entry.is_regular_file() &&
            entry.path().extension() == ".txt")
        {
            fs::remove(entry.path());
        }
    }
    cout << "Old output files deleted.\n\n";
    for (const auto& entry : fs::directory_iterator(input))
    {
        if (!entry.is_regular_file())
            continue;
        if (entry.path().extension() != ".txt")
            continue;
        string inputFile = entry.path().string();
        string fileName = entry.path().filename().string();

        string out = output + "/" + fileName;
        ifstream fin(inputFile);
        if (!fin)
        {
            cerr << "Error: Cannot open input file: "<< inputFile << "\n";
            continue;
        }
        ofstream fout(out);
        if (!fout)
        {
            cerr << "Error: Cannot create output file: "<< out << "\n";

            fin.close();
            continue;
        }
        int V, E;
        fin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < V; i++)
        {
            int vertex, degree;
            fin >> vertex >> degree;
            for (int j = 0; j < degree; j++)
            {
                int neighbour;

                fin >> neighbour;

                adj[vertex].push_back(neighbour);
            }
        }
        fin.close();
        CSR csr = convertToCSR(adj);
        auto start = high_resolution_clock::now();

        vector<double> centrality =
            betweennessCentrality(
                V,
                csr.row_ptr,
                csr.col_idx
            );
        auto stop = high_resolution_clock::now();
        auto execution_time =
            duration_cast<microseconds>(
                stop - start
            ).count();
        fout << "Algorithm: Betweenness Centrality\n";
        fout << "Vertex Centrality\n";
        fout << fixed << setprecision(2);
        for (int i = 0; i < V; i++)
        {
            fout << i << " "<<centrality[i]<<"\n";
        }
        fout << "Execution time: "<< execution_time / 1000.0<< " ms\n";
        fout.close();
    }
    cout << "\nAll Betweenness Centrality tests completed."<< "\n";

    return 0;
}
