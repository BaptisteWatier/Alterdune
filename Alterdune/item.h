#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item {
protected:
    string name;
    string type;
    int value;
    int quantity;

public:
    Item(string name, string type, int value, int quantity);

    bool useOne();
    void getDescription();
};

#endif
