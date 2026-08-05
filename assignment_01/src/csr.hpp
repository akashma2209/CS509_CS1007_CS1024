#ifndef CSR_HPP
#define CSR_HPP
#include <vector>
using namespace std;

struct CSR
{
    vector<int> row_ptr;
    vector<int> col_idx;
};
CSR convertToCSR(const vector<vector<int>>& adj);
#endif