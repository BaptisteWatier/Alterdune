#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "inventory.h"

class Player : public Character {
protected:
    int victories;
    int killCount;
    int sparedCount;
    Inventory inventory;

public:
    Player(const std::string& name, int hp, int hpMax, int atk, int def, int victories, int killCount, int sparedCount, const Inventory& inventory);

    int getVictories() const;
    int getKillCount() const;
    int getSparedCount() const;

    void addVictory();
    void addKill();
    void addSpared();

    void displayInfo() const override;
    void showStat() const;

    Inventory& getInventory();
};

#endif
