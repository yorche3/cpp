#include "naive_sort.h"

namespace naive_sort {

std::vector<int> selection_sort(const std::vector<int> arr) {
    if (arr.empty() || arr.size() == 1) {
        return arr;
    }

    std::vector<int> result = arr;
    int n = result.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (result[j] < result[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            std::swap(result[i], result[min_idx]);
        }
    }
    return result;
}

std::vector<int> bubble_sort(const std::vector<int> arr) {
    if (arr.empty() || arr.size() == 1) {
        return arr;
    }

    std::vector<int> result = arr;
    int n = result.size();
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (result[j] > result[j + 1]) {
                std::swap(result[j], result[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
    return result;
}

std::vector<int> insertion_sort(const std::vector<int> arr) {
    if (arr.empty() || arr.size() == 1) {
        return arr;
    }

    std::vector<int> result = arr;
    int n = result.size();
    for (int i = 1; i < n; ++i) {
        int key = result[i];
        int j = i - 1;
        while (j >= 0 && result[j] > key) {
            result[j + 1] = result[j];
            --j;
        }
        result[j + 1] = key;
    }
    return result;
}

} // namespace naive_sort