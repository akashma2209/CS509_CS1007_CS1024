#ifndef BETWEENNESS_HPP
#define BETWEENNESS_HPP
#include <vector>
std::vector<double> betweennessCentrality(
    int V,
    const std::vector<int>& row_ptr,
    const std::vector<int>& col_idx
);
#endif