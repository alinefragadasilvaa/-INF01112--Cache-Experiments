#include "scheduling.hpp"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Try ./experiment2 <strip width> <items file path>" << std::endl;
        return 1;
    } 

    int strip_w = std::stoi(argv[1]);
    std::string items_f = argv[2];

    Strip strip(strip_w);

    std::ifstream file(items_f);
    if (!file.is_open()) {
        std::cout << "File Error" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) { // Lê uma linha por vez
        std::stringstream ss(line);
        std::string part;
        std::vector<std::string> parts;

        while (std::getline(ss, part, ',')) { // Divide a linha em células usando ',' como delimitador
            parts.push_back(part);
        }

        Item new_item(std::stoi(parts[1]), std::stoi(parts[2]));
        strip.items.push_back(new_item);
    }

    file.close();

    strip.kp01();

    for (const Level &level : strip.levels) {
        for (const Item &item : level.items) {
            std::cout << "(" << item.width << ", " << item.height << ")";
        }
        std::cout << std::endl;
    }

    return 0;
}