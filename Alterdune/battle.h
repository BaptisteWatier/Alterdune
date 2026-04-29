#ifndef BATTLE_H
#define BATTLE_H

#include <string>
#include <vector>

#include "player.h"
#include "monster.h"
#include "actAction.h"

class Battle {
protected:
    Player& p;
    Monster& m;
    std::vector<std::string> actIds;
    std::vector<ActAction> actActions;

public:
    Battle(Player& p, Monster& m, const std::vector<std::string>& actIds, const std::vector<ActAction>& actActions);
    
    std::string start();
    void doFight();
    void doAct();
    void doItem();
    bool doMercy();
    void monsterFight();

};
#endif