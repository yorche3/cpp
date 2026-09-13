#ifndef NAIVE_SORT_H
#define NAIVE_SORT_H

#include <vector>

namespace naive_sort {

std::vector<int> selection_sort(const std::vector<int> arr);
std::vector<int> bubble_sort(const std::vector<int> arr);
std::vector<int> insertion_sort(const std::vector<int> arr);

} // namespace naive_sort

#endif // NAIVE_SORT_H