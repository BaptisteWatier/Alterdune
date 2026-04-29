
#include <iostream>
#include "monster.h"
#include "character.h"

using namespace std;

Monster::Monster(const string& name, int hp, int hpMax, int atk, int def, const string& monsterCategory, int mercy, int mercyGoal, const vector<string>& actIds)
            : Character(name, hp, hpMax, atk, def)
{
    this->monsterCategory = monsterCategory;
    this->mercy = mercy;
    this->mercyGoal = mercyGoal;
    this->actIds = actIds;


}

string Monster::getMonsterCategory() const {
    return monsterCategory;
}

int Monster::getMercy() const {
    return mercy;
}

int Monster::getMercyGoal() const {
    return mercyGoal;
}

vector<string> Monster::getActIds() const {
    return actIds;
}

void Monster::resetMercy()
{
    mercy = 0;
}

bool Monster::canBeSpared() const
{
    if(mercy >= mercyGoal)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Monster::changeMercy(int amount)
{
    mercy = mercy + amount;

    if(mercy < 0)
    {
        mercy = 0;
    }
    if(mercy > mercyGoal)
    {
        mercy = mercyGoal;
    }
}

void Monster::displayInfo() const
{
    cout << name << " - " << monsterCategory
        << " HP: " << hp << "/" << hpMax << endl;
}
