#include "../src/kmeans.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <iomanip>
#include <filesystem>

using namespace std;
using namespace chrono;
namespace fs = filesystem;


// Process one input file
void processFile(string inputFile, string outputFile)
{
    
    // OPEN INPUT FILE
    

    ifstream input(inputFile);

    if (!input)
    {
        cout << "Error: Cannot open " << inputFile << endl;
        return;
    }


    
    // READ N, D, K
    

    int N;
    int D;
    int K;

    input >> N >> D >> K;


    // Validate input
    if (N <= 0 || D <= 0 || K <= 0 || K > N)
    {
        cout << "Error: Invalid N, D or K in "<< inputFile << endl;
        return;
    }


    
    // READ POINTS
    

    vector<vector<double>> points( N, vector<double>(D));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < D; j++)
        {
            input >> points[i][j];
        }
    }


    
    // READ MAX ITERATIONS
    

    string word;

    int maxIterations;

    input >> word >> maxIterations;
    // READ TOLERANCE

    double tolerance;

    input >> word >> tolerance;
    input.close();


    
    // CREATE OUTPUT DIRECTORY

    fs::create_directories("outputs/kmean");


    
    // CREATE K-MEANS OBJECT
    

    KMeans kmeans(points, K);


    
    // START TIMER
    

    auto start =high_resolution_clock::now();


    
    // RUN K-MEANS
    kmeans.run(maxIterations, tolerance);


    
    // STOP TIMER
    

    auto end = high_resolution_clock::now();


    double executionTime =duration<double, milli>(end - start).count();


    
    // GET RESULTS
    

    vector<int> clusters =kmeans.getClusters();

    vector<vector<double>> centroids = kmeans.getCentroids();

    double wcss = kmeans.calculateWCSS();

    int iterations =kmeans.getIterations();

    bool converged = kmeans.getConverged();


    
    // OPEN OUTPUT FILE
    

    ofstream output(outputFile);

    if (!output)
    {
        cout << "Error: Cannot create " << outputFile << endl;
        return;
    }


    output << fixed << setprecision(6);


    
    // PRINT OUTPUT
    

    output << "Algorithm: K-Means Clustering\n";

    output << "K: " << K << "\n";


    output << "\n";

    output << "Point assignments:\n";


    for (int i = 0; i < N; i++)
    {
        output << i << " "<< clusters[i] << "\n";
    }


    output << "\n";

    output << "Final centroids:\n";


    for (int i = 0; i < K; i++)
    {
        output << i << ":";

        for (int j = 0; j < D; j++)
        {
            output << " " << centroids[i][j];
        }

        output << "\n";
    }


    output << "\n";

    output << "WCSS: " << wcss << "\n";


    output << "Iterations: " << iterations << "\n";


    output << "Converged: " << (converged ? "true" : "false") << "\n";


    output << "Execution time: " << executionTime<< " ms\n";

    output.close();
    // Show progress on terminal
    cout << "Processed: " << inputFile<< " -> " << outputFile<< endl;
}


int main()
{
    // Folder containing input files
    string testFolder = "tests/kmean";

    // Create outputs folder if it does not exist
    fs::create_directories("outputs/kmean");

    // Process every .txt file in tests folder
    for (const auto& file : fs::directory_iterator(testFolder))
    {
        if (file.path().extension() == ".txt")
        {
            string inputFile = file.path().string();

            string filename =file.path().stem().string();

            string outputFile ="outputs/kmean/" + filename + "_output.txt";

            processFile(inputFile, outputFile);
        }
    }

    cout << "\nAll files processed successfully."<< endl;

    return 0;
}
