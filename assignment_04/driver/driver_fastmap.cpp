#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <iomanip>
#include <chrono>
#include "../src/FastMap.hpp"

using namespace std;
namespace fs = std::filesystem;

int main()
{
    string inputFolder = "assignment_04/tests/fastmap";
    string outputFolder = "assignment_04/outputs/fastmap";

    // Create output folder if it does not exist
    if(!fs::exists(outputFolder))
    {
        fs::create_directories(outputFolder);
    }

    // Process every FastMap test file
    for(auto file : fs::directory_iterator(inputFolder))
    {
        if(file.path().extension() != ".txt")
        {
            continue;
        }

        ifstream fin(file.path());

        if(!fin)
        {
            cout << "Cannot open input file: "
                 << file.path().string() << "\n";
            continue;
        }

        int objects;
        int targetDimensions;

        fin >> objects >> targetDimensions;

        // Allocate distance matrix
        double **distance = new double*[objects];

        for(int i = 0; i < objects; i++)
        {
            distance[i] = new double[objects];
        }

        // Read complete distance matrix
        for(int i = 0; i < objects; i++)
        {
            for(int j = 0; j < objects; j++)
            {
                fin >> distance[i][j];
            }
        }

        fin.close();

        // Allocate coordinate matrix
        double **coordinates = new double*[objects];

        for(int i = 0; i < objects; i++)
        {
            coordinates[i] = new double[targetDimensions];
        }

        // Store pivots selected for each dimension
        int *pivotA = new int[targetDimensions];
        int *pivotB = new int[targetDimensions];

        // Measure only FastMap algorithm execution time
        auto start = chrono::high_resolution_clock::now();

        fastMap(
            distance,
            objects,
            targetDimensions,
            coordinates,
            pivotA,
            pivotB
        );

        auto end = chrono::high_resolution_clock::now();

        double executionTime =
            chrono::duration<double, milli>(end - start).count();

        // Create output file
        string outputFile =
            outputFolder + "/" +
            file.path().filename().string();

        ofstream fout(outputFile);

        if(!fout)
        {
            cout << "Cannot create output file: "
                 << outputFile << "\n";

            for(int i = 0; i < objects; i++)
            {
                delete[] distance[i];
                delete[] coordinates[i];
            }

            delete[] distance;
            delete[] coordinates;
            delete[] pivotA;
            delete[] pivotB;

            continue;
        }

        // Output formatting
        fout << fixed << setprecision(6);

        fout << "Algorithm: FastMap\n";
        fout << "Target dimensions: "
             << targetDimensions << "\n";

        fout << "Pivots per dimension:\n";

        for(int dim = 0; dim < targetDimensions; dim++)
        {
            fout << "Dim " << dim + 1 << ": "
                 << pivotA[dim] << " "
                 << pivotB[dim] << "\n";
        }

        fout << "Object coordinates:\n";

        for(int i = 0; i < objects; i++)
        {
            fout << i << ":";

            for(int dim = 0; dim < targetDimensions; dim++)
            {
                fout << " " << coordinates[i][dim];
            }

            fout << "\n";
        }

        fout << "Execution time: "
             << executionTime << " ms\n";

        fout.close();

        // Also print result to terminal
        cout << "\n========================================\n";
        cout << "Test file: "
             << file.path().filename().string() << "\n";
        cout << "========================================\n";

        cout << fixed << setprecision(6);

        cout << "Algorithm: FastMap\n";
        cout << "Target dimensions: "
             << targetDimensions << "\n";

        cout << "Pivots per dimension:\n";

        for(int dim = 0; dim < targetDimensions; dim++)
        {
            cout << "Dim " << dim + 1 << ": "
                 << pivotA[dim] << " "
                 << pivotB[dim] << "\n";
        }

        cout << "Object coordinates:\n";

        for(int i = 0; i < objects; i++)
        {
            cout << i << ":";

            for(int dim = 0; dim < targetDimensions; dim++)
            {
                cout << " " << coordinates[i][dim];
            }

            cout << "\n";
        }

        cout << "Execution time: "
             << executionTime << " ms\n";

        // Free memory
        for(int i = 0; i < objects; i++)
        {
            delete[] distance[i];
            delete[] coordinates[i];
        }

        delete[] distance;
        delete[] coordinates;
        delete[] pivotA;
        delete[] pivotB;
    }

    return 0;
}