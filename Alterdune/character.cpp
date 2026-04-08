#include "Character.h"

using namespace std;

Character::Character(string name, int hp, int hpMax, int atk, int def) 
{
	this->name = name;
	this->hp = hp;
	this->hpMax = hpMax;
	this->atk = atk;
	this->def = def;
}

void Character::takeDamage(int damage) //Coucou
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

string Character::getName() {
	return name;
}

int Character::getHp() {
	return hp;
}

int Character::getHpMax() {
	return hpMax;
}

int Character::getAtk() {
	return atk;
}

int Character::getDef() {
	return def;
}

void Character::setHp(int newHp) 
{
	hp = newHp;
}