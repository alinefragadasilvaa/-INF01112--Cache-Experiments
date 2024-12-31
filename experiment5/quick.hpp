#ifndef QUICK_H 
#define QUICK_H

#include "../utils.hpp"

namespace Quick {
    void swap(int* a, int* b);
    int lomuto(int numbers[2000000], int low, int high);
    void quick_sort(int numbers[2000000], int low, int high);

};

#endif  