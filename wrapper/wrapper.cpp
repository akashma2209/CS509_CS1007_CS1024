#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// Build and Run Function
// Works on Windows and Linux / Ubuntu / WSL

void buildAndRun(const string& sourceFiles, const string& executablePath)
{
    string executable;
    string runCommand;

#ifdef _WIN32

    // Windows
    executable = executablePath + ".exe";

    // Convert / to \ for Windows
    runCommand = executable;
    for(char& ch : runCommand)
    {
        if(ch == '/')
        {
            ch = '\\';
        }
    }

#else

    // Linux / Ubuntu / WSL
    executable = executablePath;
    // Linux requires ./ to execute a program
    runCommand = "./" + executable;

#endif

    // Compile

    string compileCommand = "g++ -std=c++17 " + sourceFiles + " -o " + executable;
    cout << "\nCompiling...\n";
    int result = system(compileCommand.c_str());
    if(result != 0)
    {
        cout << "\nCompilation failed.\n";
        return;
    }
    cout << "Compilation successful.\n";

    // Run
    cout << "Running program...\n\n";
    result = system(runCommand.c_str());
    if(result != 0)
    {
        cout << "\nProgram exited with an error.\n";
    }
}

// Assignment 1
void assignment1()
{
    char choice;
    cout << "\nAssignment 1\n";
    cout << "-------------------------\n";
    cout << "1. BFS_DFS Graph\n";
    cout << "2. SSSP\n";

    cout << "Enter choice: ";
    cin >> choice;
    switch(choice)
    {
        
        // BFS / DFS
        case '1':
        {
            cout << "\nRunning BFS_DFS Graph...\n";
            buildAndRun( "assignment_01/driver/driver_csr.cpp " "assignment_01/src/SSSP_Graph.cpp", "assignment_01/executables/dfs_bfs");
            break;
        }
        
        // SSSP
        case '2':
        {
            cout << "\nRunning CSR...\n";
            buildAndRun( "assignment_01/driver/driver_csr.cpp " "assignment_01/src/SSSP_Graph.cpp", "assignment_01/executables/csr");

            cout << "\nRunning SSSP...\n";
            buildAndRun( "assignment_01/driver/driver_sssp.cpp " "assignment_01/src/SSSP_Graph.cpp", "assignment_01/executables/sssp");
            break;
        }

        default:
            cout << "\nInvalid choice.\n";
    }
}

// Assignment 2
void assignment2()
{
    char choice;
    cout << "\nAssignment 2\n";
    cout << "-------------------------\n";
    cout << "1. Triangle Counting\n";
    cout << "2. Betweenness Centrality\n";
    cout << "3. Connected Components\n";

    cout << "Enter choice: ";
    cin >> choice;
    switch(choice)
    {
        
        // Triangle Counting
        case '1':
        {
            cout << "\nRunning Triangle Counting...\n";
            buildAndRun( "assignment_02/driver/driver_triangle_counting.cpp " "assignment_02/src/Triangle_Counting.cpp " "common/csr/src/CSR.cpp " "common/csr/src/driver_csr.cpp", "assignment_02/executables/triangle_counting");
            break;
        }

        // Betweenness Centrality
        case '2':
        {
            cout << "\nRunning Betweenness Centrality...\n";
            buildAndRun( "assignment_02/driver/driver_betweenness.cpp " "assignment_02/src/betweenness.cpp " "assignment_01/src/csr.cpp", "assignment_02/executables/betweenness");
            break;
        }
        
        // Connected Components
        case '3':
        {
            cout << "\nRunning Connected Components...\n";
            buildAndRun( "assignment_02/driver/driver_connected_components.cpp " "assignment_02/src/connected_component.cpp " "assignment_01/src/csr.cpp", "assignment_02/executables/connected_components");
            break;
        }

        default:
            cout << "\nInvalid choice.\n";
    }
}



// Assignment 3

void assignment3()
{
    char choice;
    cout << "\nAssignment 3\n";
    cout << "-------------------------\n";
    cout << "1. Gradient Descent\n";
    cout << "2. Maxflow-Mincut\n";

    cout << "Enter choice: ";
    cin >> choice;

    switch(choice)
    {
        
        // Gradient Descent
        case '1':
        {
            cout << "\nRunning Gradient Descent...\n";
            buildAndRun( "assignment_03/driver/driver_gradient_descent.cpp " "assignment_03/src/Gradient_Descent.cpp", "assignment_03/executables/Gradient_descent");
            break;
        }
       
        // Maxflow-Mincut
        case '2':
        {
            cout << "\nRunning Maxflow-Mincut...\n";
            buildAndRun( "assignment_03/driver/driver_maxflow_mincut.cpp " "assignment_03/src/Maxflow_Mincut.cpp " "common/csr/src/CSR.cpp " "common/csr/src/driver_csr.cpp", "assignment_03/executables/maxflow_mincut");
            break;
        }

        default:
            cout << "\nInvalid choice.\n";
    }
}

// Assignment 4
void assignment4()
{
    char choice;
    cout << "\nAssignment 4\n";
    cout << "-------------------------\n";
    cout << "1. K-Means Clustering\n";
    cout << "2. FastMap\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch(choice)
    {  
        // K-Means
        case '1':
        {
            cout << "\nRunning K-Means Clustering...\n";
            buildAndRun( "assignment_04/driver/driver_km.cpp " "assignment_04/src/kmeans.cpp", "assignment_04/executables/kmeans");
            break;
        }

        // FastMap
        case '2':
        {
            cout << "\nRunning FastMap...\n";
            buildAndRun( "assignment_04/driver/driver_fastmap.cpp " "assignment_04/src/FastMap.cpp", "assignment_04/executables/fastmap");
            break;
        }
        default:
            cout << "\nInvalid choice.\n";
    }
}



// Main


int main()
{
    char choice;


    while(true)
    {
        cout << "\n";
        cout << "====================================\n";
        cout << "        CS509 Buddy Assignment Menu\n";
        cout << "====================================\n";

        cout << "Press 1. Assignment 1\n";
        cout << "Press 2. Assignment 2\n";
        cout << "Press 3. Assignment 3\n";
        cout << "Press 4. Assignment 4\n";
        cout << "Press 5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;


        switch(choice)
        {
            case '1':
                assignment1();
                break;

            case '2':
                assignment2();
                break;

            case '3':
                assignment3();
                break;

            case '4':
                assignment4();
                break;

            case '5':
                cout << "\nExiting...\n";
                return 0;

            default:
                cout << "\nInvalid choice.\n";
        }
    }


    return 0;
}