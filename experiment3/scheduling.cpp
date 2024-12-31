#include "scheduling.hpp"

// Item Constructor
Item::Item(int w, int h) : width(w), height(h), profit(w*h) {}

// Level Constructor
Level::Level(int tw) : total_width(tw), used_width(0), height(0) {}

// Scheduling/Strip Constructor
Strip::Strip(int tw) : total_width(tw), height(0) {}

// Check level following the BFDH approaches
bool Level::check_level(Item item, int min_width) {
    return (used_width + item.width <= total_width) && (total_width - used_width - item.width < min_width);
}

// Add item in the level
void Level::schedule_item(Item item) {
    used_width += item.width;
    if(item.height > height) {
        height = item.height;
    }
    items.push_back(item);
}

// Compare items height for KP01 strategy
bool compare_height(const Item &x, const Item &y) {
    return x.height > y.height;
}

void Strip::kp01() {
    std::vector<std::vector<int>> K(items.size() + 1, std::vector<int>(total_width + 1));
    std::vector<Item> items_cp(items);
    int line, column;

    // Sort the items according to nonincreasing hj values
    std::sort(items_cp.begin(), items_cp.end(), compare_height);
       
    while(items_cp.size() != 0) {
        // Open a new shelf in the strip by packing the first unpacked item
        Level new_level(total_width);
        new_level.schedule_item(items_cp[0]); // experiment[0] is j* that boot the level
        levels.push_back(new_level);
        items_cp.erase(items_cp.begin());

        // Solve the KP01 instance associated with the shelf
        for(int i = 0; i <= items_cp.size(); i++) {
            for(int w = 0; w <= total_width - levels[levels.size() - 1].used_width; w++) { // capacity is W - wj*
                if (i == 0 || w == 0) {
                    K[i][w] = 0;
                } else if (items_cp[i - 1].width <= w) {
                    K[i][w] = std::max(items_cp[i - 1].profit + K[i - 1][w - items_cp[i - 1].width], K[i - 1][w]);
                } else {
                     K[i][w] = K[i - 1][w];
                }   
            }
        }

        // Pack the selected items onto the shelf
        line = items_cp.size();
        column = total_width - levels[levels.size() - 1].used_width;

        while(line > 0 && line > 0) {
            if(K[line][column] != K[line-1][column]) {
                column = column - items_cp[line-1].width;
                levels[levels.size() - 1].schedule_item(items_cp[line -1]);
                items_cp.erase(items_cp.begin() + (line-1));
            } 
            line--;
        }
    }
}