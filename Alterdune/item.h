#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
protected:
    std::string name;
    std::string type; // classe ?
    int value;
    int quantity;

public:
    Item(const std::string& name, const std::string& type, int value, int quantity);

    std::string getName() const;
    std::string getDescription() const;
    int getValue() const;
    int getQuantity() const;

    bool useOne();
};

#endif
