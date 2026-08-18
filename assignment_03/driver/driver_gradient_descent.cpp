#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <filesystem>
#include "../src/gradient_descent.hpp"

using namespace std;
namespace fs = std::filesystem;

void runTest(string inputs, string out)
{
    ifstream file(inputs);
    if (!file)
    {
        cout << "Cannot open: " << inputs << endl;
        return;
    }
    int degree;
    double coefficient[100];
    double x;
    double learningRate;
    double tolerance;
    int maxIterations;

    string word;
    file >> word >> degree;
    file >> word;

    for (int i = 0; i <= degree; i++)
    {
        file >> coefficient[i];
    }
    file >> word >> x;
    file >> word >> learningRate;
    file >> word >> tolerance;
    file >> word >> maxIterations;
    file.close();

    double finalX;
    double finalFx;
    int iterations;
    bool converged;

    auto start = chrono::high_resolution_clock::now();

    gradientDescent(coefficient,degree,x,learningRate,tolerance,maxIterations,finalX,finalFx,iterations,converged);
    auto end = chrono::high_resolution_clock::now();
    double executionTime = chrono::duration<double, milli>(end - start).count();
    ofstream output(out);

    if (!output)
    {
        cout << "Cannot create: " << out << endl;
        return;
    }

    output << fixed << setprecision(6);
    output << "Algorithm: Gradient Descent\n";
    output << "Degree: " << degree << "\n";
    output << "Final x: " << finalX << "\n";
    output << "Final f(x): " << finalFx << "\n";
    output << "Iterations: " << iterations << "\n";

    if (converged)
        output << "Converged: true\n";
    else
        output << "Converged: false\n";

    output << "Execution time: " << executionTime << " ms\n";
    output.close();
}

int main(int argc, char *argv[])
{

    string input = "assignment_03/tests/gradient_descent";;
    string output = "assignment_03/outputs/gradient_descent";
    if (!fs::exists(output))
    {
        fs::create_directory(output);
    }

    for (const auto &entry : fs::directory_iterator(input))
    {
        if (entry.path().extension() == ".txt")
        {
            string inputs = entry.path().string();
            string fileName = entry.path().stem().string();
            string out = output + "/" + fileName + "_output.txt";
            runTest(inputs, out);
        }
    }
    cout << "All tests completed.\n";
    return 0;
}

