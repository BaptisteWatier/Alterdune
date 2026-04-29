#include <iostream>

#include "inventory.h"
#include "player.h"

using namespace std;

Inventory::Inventory(const vector<Item>& items)
{
    this->items = items;
}

void Inventory::addItem(const Item& item)
{
    items.push_back(item);
}

void Inventory::showItems() const
{
    for (int i = 0; i < items.size(); i++)
    {
        cout << i + 1 << ". "
            << items[i].getName()
            << " x" << items[i].getQuantity()
            << " - " << items[i].getDescription()
            << endl;
    }
}

void Inventory::useItem(int index, Player& p)
{
    index--; 

    if(index >= 0 && index < items.size())
    {
        if(items[index].useOne() == true)
        {
            p.heal(items[index].getValue());
        }
    }
}