#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

using namespace std;

class Character {
protected:
    string name;
    int hp;
    int hpMax;
    int atk;
    int def;

public:
    Character(string name, int hp, int hpMax, int atk, int def);

    void takeDamage(int damage);
    void heal(int amount);
    bool isAlive();

    string getName();
    int getHp();
    int getHpMax();
    int getAtk();
    int getDef();

    void setHp(int newHp);
};

#endif