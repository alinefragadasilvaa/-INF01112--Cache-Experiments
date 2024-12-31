#ifndef SCHEDULING_H 
#define SCHEDULING_H

#include "../utils.hpp"

class Item { 
public:
    int width; 
    int height;
    int profit; 

    Item(int w, int h);
};

class Level {
public:
    int total_width;
    int used_width;
    int height;
    std::vector<Item> items;

    Level(int tw);
    bool check_level(Item item, int min_width);
    void schedule_item(Item item);
};

class Strip {
public:
    int total_width;
    int height; 
    std::vector<Item> items;
    std::vector<Level> levels;

    Strip(int tw);
    void kp01();
};

#endif  