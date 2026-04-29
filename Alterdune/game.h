#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include <map>

#include "player.h"
#include "monster.h"
#include "bestiary.h"
#include "battle.h"
#include "actAction.h"
#include "item.h"
#include "inventory.h"

class Game {
protected:
    Player player;
    Bestiary bestiary;

    std::vector<Monster> monsters;
    std::vector<ActAction> actCatalog;

    bool gameOver;

public:
    Game(const Player& player, const Bestiary& bestiary,
        const std::vector<Monster>& monsters,
        const std::vector<ActAction>& actCatalog);

    void start();
    void showMenu();

    void showPlayerStats();
    void showPlayerItems();
    void showBestiary();

    void startBattle();

    bool loadItems(const std::string& filename);
    bool loadMonsters(const std::string& filename);
    void initActCatalog();

    Monster getRandomMonster() const;

    bool isGameOver() const;
    void checkEndGame();
    void showEnding() const;
};

#endif
