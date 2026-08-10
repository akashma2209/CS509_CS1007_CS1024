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

        case '1':
        {
            cout << "\nCompiling Triangle Counting...\n";

            system("g++ -std=c++17 " "assignment_02\\driver\\driver_triangle_counting.cpp " "assignment_02\\src\\Triangle_Counting.cpp " "common\\csr\\src\\CSR.cpp ""common\\csr\\src\\driver_csr.cpp ""-o assignment_02\\executables\\triangle_counting.exe" );
            cout << "\nRunning Triangle Counting...\n";
            system(".\\assignment_02\\executables\\triangle_counting.exe");
            break;
        }

        case '2':
        {
            cout << "\nCompiling Betweenness Centrality...\n";

            system( "cd assignment_02 && " "g++ -std=c++17 " "driver\\driver_betweenness.cpp " "src\\betweenness.cpp " "..\\Assignment_01\\src\\csr.cpp " "-o betweenness.exe");
            cout << "\nRunning Betweenness Centrality...\n";
            system("cd assignment_02 && ""betweenness.exe");
            break;
        }

        case '3':
        {
            cout << "\nCompiling Connected Components...\n";

            system( "cd assignment_02 && " "g++ -std=c++17 " "driver\\driver_connected_components.cpp " "src\\connected_component.cpp " "..\\Assignment_01\\src\\csr.cpp ""-o connected_components.exe");
            cout << "\nRunning Connected Components...\n";
            system("cd assignment_02 && ""connected_components.exe");
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
        cout << "2. Assignment 2\n";
        cout << "3. Exit\n";
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
                cout << "\nExiting...\n";
                return 0;

            default:
                cout << "\nInvalid choice.\n";
        }
    }
    return 0;
}