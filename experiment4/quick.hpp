#ifndef QUICK_H 
#define QUICK_H

#include "../utils.hpp"

namespace Quick {
    void swap(int* a, int* b);
    int lomuto(std::vector<int>& numbers, int low, int high);
    void quick_sort(std::vector<int>& numbers, int low, int high);

};

#endif  