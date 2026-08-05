#include "csr.hpp"
using namespace std;
CSR convertToCSR(const vector<vector<int>>& adj)
{
    CSR csr;
    csr.row_ptr.push_back(0);
    for (const auto &neighbors : adj)
    {
        for (int vertex : neighbors)
        {
            csr.col_idx.push_back(vertex);
        }
        csr.row_ptr.push_back(csr.col_idx.size());
    }
    return csr;
}