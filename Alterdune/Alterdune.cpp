#include <iostream>
#include "game.h"
#include "player.h"
#include "inventory.h"
#include "bestiary.h"

using namespace std;

int main() {
    string playerName;
    cout << "Entrez le nom de votre personnage : ";
    cin >> playerName;

    Inventory inventory({});
    Player player(playerName, 100, 100, 10, 5, 0, 0, 0, inventory);

    Bestiary bestiary({}, {});

    Game game(player, bestiary, {}, {});

    game.initActCatalog();

    if (!game.loadItems("items.csv") || !game.loadMonsters("monsters.csv"))
    {
        cerr << "Arret du programme : impossible de charger les donnees." << endl;
        return 1;
    }

    game.start();

    return 0;
}
