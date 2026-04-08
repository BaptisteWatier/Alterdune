#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include "Bestiary.h"
#include "Player.h"
#include "actAction.h"
#include "Monster.h"

using namespace std;

class Game {
protected:
    Player player;
    vector<Monster> monsterPool;
    Bestiary bestiary;
    vector<string> actIds;
    vector<ActAction> actActions;

public:
    Game(Player player, vector<Monster> monsterPool, Bestiary bestiary, vector<string> actIds, vector<ActAction> actActions);

    void init();
    void mainMenu();
    void itemCSV(string);
    void monsterCSV(string);
    void startRandomBattle();
    void showEnding();
};

#endif
