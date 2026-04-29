#include "character.h"

using namespace std;

Character::Character(const string& name, int hp, int hpMax, int atk, int def) 
{
	this->name = name;
	this->hp = hp;
	this->hpMax = hpMax;
	this->atk = atk;
	this->def = def;
}

void Character::takeDamage(int damage) 
{
	if (hp - damage > 0)
	{
		hp = hp - damage;
	}
	else
	{
		hp = 0;
	}
}

void Character::heal(int amount) 
{
	if (hp + amount < hpMax)
	{
		hp = hp + amount;
	}
	else
	{
		hp = hpMax;
	}
}

bool Character::isAlive() 
{
	if (hp != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

string Character::getName() const {
	return name;
}

int Character::getHp() const {
	return hp;
}

int Character::getHpMax() const {
	return hpMax;
}

int Character::getAtk() const{
	return atk;
}

int Character::getDef() const {
	return def;
}

void Character::setHp(int newHp) 
{
	hp = newHp;
}