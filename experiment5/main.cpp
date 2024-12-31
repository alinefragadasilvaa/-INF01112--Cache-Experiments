#include "quick.hpp"

int main(int argc, char* argv[]) {
    int MAX_SIZE = 2000000;

    if (argc < 2) {
        std::cout << "Try ./experiment3 <numbers file path>" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]); 

    if (!file.is_open()) {
        std::cout << "File Error" << std::endl;
        return 1;
    }

    int numbers[MAX_SIZE]; 
    int count = 0; 

    std::string line;

    while (std::getline(file, line)) {
        int num = std::stoi(line); 
        numbers[count] = num; 
        count++;
    }
    

    file.close();


    Quick::quick_sort(numbers, 0, count - 1); 
    

    for (int i = 0; i < count; ++i) {
        std::cout << numbers[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}
