#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Inventory.h"

using namespace std;

class Player {
protected:
    int victories;
    int killCount;
    int sparedCount;
    Inventory inventory;

public:
    Player(int victories, int killCount, int sparedCount, Inventory inventory);

    void addVictory();
    void addKill();
    void addSpared();
    void showStat();
};

#endif
