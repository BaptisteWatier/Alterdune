#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "item.h"

class Player; 

class Inventory {
protected:
    std::vector<Item> items;

public:
    Inventory(const std::vector<Item>& items);

    void addItem(const Item& item);
    void showItems() const;
    void useItem(int a, Player& p);
};

#endif