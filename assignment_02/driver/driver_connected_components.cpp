#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <filesystem>
#include "../src/connected_component.hpp"
#include "../../Assignment_01/src/csr.hpp"

using namespace std;
using namespace chrono;
namespace fs = std::filesystem;
int main()
{
    const string input = "tests/cc_test";
    const string output = "outputs/cc_output";
    fs::create_directories(output);

    // Delete old output files
    for (const auto& entry : fs::directory_iterator(output))
    {
        if (entry.is_regular_file() &&
            entry.path().extension() == ".txt")
        {
            fs::remove(entry.path());
        }
    }
    for (const auto& entry : fs::directory_iterator(input))
    {
        if (!entry.is_regular_file()){
            continue;
        }

        if (entry.path().extension() != ".txt"){
            continue;
        }

        string inputFile = entry.path().string();
        string fileName = entry.path().filename().string();

        string outputFile =
            output + "/" + fileName;

        ifstream fin(inputFile);

        if (!fin)
        {
            cerr << "Error: Cannot open input file: "<< inputFile << "\n";
            continue;
        }
        ofstream fout(outputFile);
        if (!fout)
        {
            cerr << "Error: Cannot create output file: "<< outputFile << "\n";
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
        vector<int> component =
            connectedComponents(
                V,
                csr.row_ptr,
                csr.col_idx
            );

        auto stop = high_resolution_clock::now();
        auto execution_time =
            duration_cast<microseconds>(
                stop - start
            ).count();

        int number_of_components = 0;

        for (int i = 0; i < V; i++)
        {
            if (component[i] + 1 > number_of_components)
            {
                number_of_components = component[i] + 1;
            }
        }
        fout << "Algorithm: Connected Components\n";

        fout << "Number of components: "<< number_of_components<< "\n";
        fout << "Vertex Component\n";
        for (int i = 0; i < V; i++)
        {
            fout << i << " "<< component[i]<< "\n";
        }
        fout << "Execution time: "<< execution_time / 1000.0<< " ms\n";
        fout.close();
    }
    cout << "\nAll Connected Components tests completed."<< "\n";
    return 0;
}

