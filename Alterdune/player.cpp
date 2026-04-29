#include "player.h"
#include <iostream>

using namespace std;

Player::Player(const string& name, int hp, int hpMax, int atk, int def, int victories, int killCount, int sparedCount, const Inventory& inventory)
	    : Character(name, hp, hpMax, atk, def), 
	     inventory(inventory)
{
	this->victories = victories;
	this->killCount = killCount;
	this->sparedCount = sparedCount;
}

Inventory& Player::getInventory()
{
	return inventory;
}

int Player::getVictories() const
{
	return victories;
}

int Player::getKillCount() const
{
	return killCount;
}

int Player::getSparedCount() const
{
	return sparedCount;
}

void Player::addVictory() 
{
	victories++;
}

void Player::addKill() 
{
	killCount++;
}

void Player::addSpared() 
{
	sparedCount++;
}

void Player::showStat() const
{
	cout << "Name: " << getName() << endl;
	cout << "HP: " << getHp() << "/" << getHpMax() << endl;
	cout << "ATK: " << getAtk() << endl;
	cout << "DEF: " << getDef() << endl;
	cout << "Victories: " << victories << endl;
	cout << "Kills: " << killCount << endl;
	cout << "Spared: " << sparedCount << endl;
}

void Player::displayInfo() const
{
	showStat();
}