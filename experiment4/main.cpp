#include "quick.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Try ./experiment3 <numbers file path>" << std::endl;
        return 1;
    } 

    std::ifstream file(argv[1]); // Substitua pelo nome do arquivo

    if (!file.is_open()) {
        std::cout << "File Error" << std::endl;
        return 1;
    }

    std::vector<int> numbers; 
    std::string line;

    // Ler o arquivo linha por linha
    while (std::getline(file, line)) {
        int num = std::stoi(line); // Converter a linha para número
        numbers.push_back(num);
    }

    file.close();

    Quick::quick_sort(numbers, 0, numbers.size());

    for (const int number : numbers) {
        std::cout << number << " ";
    }

    std::cout << std::endl;

    return 0;
}