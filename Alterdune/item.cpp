#include "item.h"

using namespace std;

Item::Item(const string& name, const string& type, int value, int quantity)
{
	this->name = name;
	this->type = type;
	this->value = value;
	this->quantity = quantity;
}

bool Item::useOne() 
{
	if(quantity > 0)
	{
		quantity--;
		return true;
	}
	return false;
}

string Item::getName() const
{
	return name;
}

int Item::getQuantity() const
{
	return quantity;
}

string Item::getDescription() const
{
	return "Soigne " + to_string(value) + " HP";
}

int Item::getValue() const
{
	return value;
}
