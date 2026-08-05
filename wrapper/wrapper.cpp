#include <iostream>
#include <cstdlib>

using namespace std;

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
        case '1':
        {
            cout << "\nCompiling BFS_DFS Graph...\n";
            system("cd assignment_01 && " "g++ -std=c++17 driver\\driver_csr.cpp " "src\\SSSP_Graph.cpp " "-o executables\\csr.exe");
            cout << "\nRunning BFS_DFS Graph...\n";
            system("cd assignment_01 && " "executables\\dfs_bfs.exe");
            break;
        }

        case '2':
        {
            cout << "\nCompiling CSR...\n";
            system( "cd assignment_01 && " "g++ -std=c++17 " "driver\\driver_csr.cpp " "src\\SSSP_Graph.cpp " "-o executables\\csr.exe" );
            cout << "\nRunning CSR...\n";
            system( "cd assignment_01 && " "executables\\csr.exe" );
            cout << "\nCompiling SSSP...\n";
            system("cd assignment_01 && " "g++ -std=c++17 " "driver\\driver_sssp.cpp " "src\\SSSP_Graph.cpp " "-o executables\\sssp.exe" );
            cout << "\nRunning SSSP...\n";
            system( "cd assignment_01 && " "executables\\sssp.exe" );
            break;
        }

        default:
            cout << "\nInvalid choice.\n";
    }
}

int main()
{
    char choice;
    while(true)
    {
        cout << "\n====================================\n";
        cout << "        CS509 Buddy Assignment Menu\n";
        cout << "====================================\n";
        cout << "1. Assignment 1\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch(choice)
        {
            case '1':
                assignment1();
                break;

            case '2':
                cout << "\nExiting...\n";
                return 0;

            default:
                cout << "\nInvalid choice.\n";
        }
    }

    return 0;
}