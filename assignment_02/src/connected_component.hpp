#ifndef CONNECTED_COMPONENT_HPP
#define CONNECTED_COMPONENT_HPP
#include <vector>
std::vector<int> connectedComponents(
    int V,
    const std::vector<int>& row_ptr,
    const std::vector<int>& col_idx
);
#endif