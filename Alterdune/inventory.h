#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <vector>
#include "Item.h"
#include "Player.h"

using namespace std;

class Inventory {
protected:
    vector<Item> Items;

public:
    Inventory(string name, string type, int value, int quantity);

    void addItem(Item);
    void showItems();
    void useItem(int, Player&);
};

#endif