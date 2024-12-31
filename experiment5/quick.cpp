#include "quick.hpp"

// Função para trocar dois elementos
void Quick::swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Função Lomuto para particionar o array
int Quick::lomuto(int numbers[2000000], int low, int high) {

    int pivot = numbers[high]; 
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (numbers[j] <= pivot) {
            i++;
            Quick::swap(&numbers[i], &numbers[j]);
        }
    }
    Quick::swap(&numbers[i + 1], &numbers[high]);
    return (i + 1);
}

// Função principal do Quick Sort
void Quick::quick_sort(int numbers[2000000], int low, int high) {
    if (low < high) {
        int p = Quick::lomuto(numbers, low, high);
        
        Quick::quick_sort(numbers, low, p - 1);
        Quick::quick_sort(numbers, p + 1, high);
       
    }
}