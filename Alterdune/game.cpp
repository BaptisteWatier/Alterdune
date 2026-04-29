#include "game.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <random>

using namespace std;

Game::Game(const Player& player, const Bestiary& bestiary, const vector<Monster>& monsters, const vector<ActAction>& actCatalog)
    : player(player), bestiary(bestiary), monsters(monsters), actCatalog(actCatalog)
{
    gameOver = false;
}

void Game::start()
{
    cout << endl;
    cout << "========== DEBUT DE PARTIE ==========" << endl;
    cout << "Nom du joueur : " << player.getName() << endl;
    cout << "HP : " << player.getHp() << "/" << player.getHpMax() << endl;

    cout << endl;
    cout << "Inventaire initial :" << endl;
    player.getInventory().showItems();

    while (!gameOver)
    {
        showMenu();
    }
}

void Game::showMenu()
{
    int choice;

    cout << endl;
    cout << "========== MENU PRINCIPAL ==========" << endl;
    cout << "1. Bestiaire" << endl;
    cout << "2. Demarrer un combat" << endl;
    cout << "3. Statistiques du personnage" << endl;
    cout << "4. Items" << endl;
    cout << "5. Quitter" << endl;
    cout << "Votre choix : ";
    cin >> choice;

    if (choice == 1)
    {
        showBestiary();
    }
    else if (choice == 2)
    {
        startBattle();
        checkEndGame();
    }
    else if (choice == 3)
    {
        showPlayerStats();
    }
    else if (choice == 4)
    {
        showPlayerItems();
    }
    else if (choice == 5)
    {
        gameOver = true;
        cout << "Fin du jeu." << endl;
    }
    else
    {
        cout << "Choix invalide." << endl;
    }
}

void Game::showPlayerStats()
{
    cout << endl;
    cout << "========== STATISTIQUES DU PERSONNAGE ==========" << endl;
    player.showStat();
}

void Game::showPlayerItems()
{
    cout << endl;
    cout << "========== INVENTAIRE ==========" << endl;
    player.getInventory().showItems();

    char choice;
    cout << "Voulez-vous utiliser un item ? (o/n) : ";
    cin >> choice;

    if (choice == 'o' || choice == 'O')
    {
        int index;
        cout << "Entrez le numero de l'item : ";
        cin >> index;

        player.getInventory().useItem(index, player);
    }
}

void Game::showBestiary()
{
    cout << endl;
    cout << "========== BESTIAIRE ==========" << endl;
    bestiary.showBestiary();
}

void Game::startBattle()
{
    if (monsters.empty())
    {
        cout << "Aucun monstre n'est disponible." << endl;
        return;
    }

    Monster monster = getRandomMonster();

    cout << endl;
    cout << "========== DEBUT DU COMBAT ==========" << endl;
    cout << "Vous affrontez : " << monster.getName() << endl;
    cout << "Categorie : " << monster.getMonsterCategory() << endl;
    cout << "HP : " << monster.getHp() << "/" << monster.getHpMax() << endl;
    cout << "Mercy : " << monster.getMercy() << "/" << monster.getMercyGoal() << endl;

    Battle battle(player, monster, monster.getActIds(), actCatalog);
    string result = battle.start();

    if (result == "killed")
    {
        player.addVictory();
        player.addKill();
        bestiary.addEntry(monster, "Tué");

        cout << "Vous avez gagne le combat en tuant le monstre." << endl;
    }
    else if (result == "spared")
    {
        player.addVictory();
        player.addSpared();
        bestiary.addEntry(monster, "Épargné");

        cout << "Vous avez gagne le combat en epargnant le monstre." << endl;
    }
    else if (result == "lost")
    {
        cout << "Vous avez perdu le combat." << endl;
        gameOver = true;
    }
}

bool Game::loadItems(const std::string& filename)
{
    ifstream file(filename);

    if (!file)
    {
        cerr << "Erreur : fichier introuvable : " << filename << endl;
        return false;
    }

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);

        string name, type, valueStr, quantityStr;

        if (!getline(ss, name, ';') ||
            !getline(ss, type, ';') ||
            !getline(ss, valueStr, ';') ||
            !getline(ss, quantityStr, ';'))
        {
            cerr << "Ligne mal formee dans " << filename << " : " << line << endl;
            continue;
        }

        int value = stoi(valueStr);
        int quantity = stoi(quantityStr);

        Item item(name, type, value, quantity);
        player.getInventory().addItem(item);
    }

    return true;
}

bool Game::loadMonsters(const std::string& filename)
{
    ifstream file(filename);

    if (!file)
    {
        cerr << "Erreur : fichier introuvable : " << filename << endl;
        return false;
    }

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);

        string category, name;
        string hpStr, atkStr, defStr, mercyGoalStr;
        string act1, act2, act3, act4;

        if (!getline(ss, category, ';') ||
            !getline(ss, name, ';') ||
            !getline(ss, hpStr, ';') ||
            !getline(ss, atkStr, ';') ||
            !getline(ss, defStr, ';') ||
            !getline(ss, mercyGoalStr, ';') ||
            !getline(ss, act1, ';') ||
            !getline(ss, act2, ';') ||
            !getline(ss, act3, ';') ||
            !getline(ss, act4, ';'))
        {
            cerr << "Ligne mal formee dans " << filename << " : " << line << endl;
            continue;
        }

        try
        {
            int hp = stoi(hpStr);
            int atk = stoi(atkStr);
            int def = stoi(defStr);
            int mercyGoal = stoi(mercyGoalStr);

            vector<string> actIds;

            if (act1 != "-") actIds.push_back(act1);
            if (act2 != "-") actIds.push_back(act2);
            if (act3 != "-") actIds.push_back(act3);
            if (act4 != "-") actIds.push_back(act4);

            Monster m(name, hp, hp, atk, def, category, 0, mercyGoal, actIds);
            monsters.push_back(m);
        }
        catch (const exception& e)
        {
            cerr << "Erreur de conversion dans " << filename << " : " << line << endl;
            continue;
        }
    }

    return true;
}

void Game::initActCatalog()
{
    actCatalog.clear();

    actCatalog.push_back(ActAction(
        "JOKE",
        "Vous racontez une blague absurde. Le monstre semble amuse.",
        20
    ));

    actCatalog.push_back(ActAction(
        "COMPLIMENT",
        "Vous faites un compliment au monstre. Il rougit legerement.",
        25
    ));

    actCatalog.push_back(ActAction(
        "DISCUSS",
        "Vous essayez de discuter calmement avec le monstre.",
        15
    ));

    actCatalog.push_back(ActAction(
        "PET",
        "Vous caressez doucement le monstre. Il semble apprecier.",
        30
    ));

    actCatalog.push_back(ActAction(
        "OFFER_SNACK",
        "Vous offrez un snack au monstre. Il semble plus amical.",
        35
    ));

    actCatalog.push_back(ActAction(
        "DANCE",
        "Vous faites une danse ridicule. Le monstre ne sait plus quoi penser.",
        10
    ));

    actCatalog.push_back(ActAction(
        "REASON",
        "Vous tentez de raisonner le monstre.",
        20
    ));

    actCatalog.push_back(ActAction(
        "INSULT",
        "Vous insultez violemment le monstre. Il se met en colere !",
        -30
    ));

    actCatalog.push_back(ActAction(
        "INTIMIDATE",
        "Vous tentez d'intimider le monstre.",
        -25
    ));

    actCatalog.push_back(ActAction(
        "SING",
        "Vous chantez une chanson etrange.",
        20
    ));
}

Monster Game::getRandomMonster() const
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, monsters.size() - 1);

    return monsters[dist(gen)];
}

bool Game::isGameOver() const
{
    return gameOver;
}

void Game::checkEndGame()
{
    if (player.getVictories() >= 10)
    {
        gameOver = true;

        cout << endl;
        cout << "========== FIN DE LA PARTIE ==========" << endl;

        showEnding();
    }
}

void Game::showEnding() const
{
    cout << endl;

    if (player.getKillCount() == player.getVictories())
    {
        cout << "Fin Genocidaire : vous avez tue tous les monstres." << endl;
    }
    else if (player.getSparedCount() == player.getVictories())
    {
        cout << "Fin Pacifiste : vous avez epargne tous les monstres." << endl;
    }
    else
    {
        cout << "Fin Neutre : vous avez parfois tue et parfois epargne." << endl;
    }

    cout << "Victories : " << player.getVictories() << endl;
    cout << "Kills : " << player.getKillCount() << endl;
    cout << "Spared : " << player.getSparedCount() << endl;
}