#ifndef TRIANGLE_COUNTING_HPP
#define TRIANGLE_COUNTING_HPP
#include "../../common/csr/src/CSR.hpp"

const int MAX = 1000000;
struct Triangle
{
    int a;
    int b;
    int c;
};

bool isConnected(CSR &graph, int u, int v);
void countTriangle(CSR &graph, Triangle triangles[], int &triangleCount);
#endif