#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
protected:
    std::string name;
    int hp;
    int hpMax;
    int atk;
    int def;

public:
    Character(const std::string& name, int hp, int hpMax, int atk, int def);

    void takeDamage(int damage);
    void heal(int amount);
    bool isAlive();


    std::string getName() const;
    int getHp() const;
    int getHpMax() const;
    int getAtk() const;
    int getDef() const;

    void setHp(int newHp);
    virtual void displayInfo() const = 0;
};

#endif