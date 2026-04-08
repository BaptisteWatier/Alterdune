#include "Monster.h"

using namespace std;

Monster::Monster(string monsterCategory, int mercy, int mercyGoal, vector<string> actIds); 
{
	this->monsterCategory = monsterCategory;
	this->mercy = mercy;
	this->mercyGoal = mercyGoal;
	this->actIds = actIds;
}

void Monster::resetMercy() 
{
    mercy = 0;
}

bool Monster::canBeSpared() 
{
    if (mercy >= mercyGoal) 
    {
        return true;
    } else 
    {
        return false;
    }
}

void Monster::changeMercy(int amount) 
{
    mercy += amount;

    if (mercy < 0) 
    {
        mercy = 0;
    }
    if (mercy > mercyGoal) 
    {
        mercy = mercyGoal;
    }
}
