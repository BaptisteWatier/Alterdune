
#include "bestiary.h"
#include "monster.h"

#include <iostream>

using namespace std;

Bestiary::Bestiary(const vector<Monster>& defeatedMonsters, const vector<string>& results)
{
    this->defeatedMonsters = defeatedMonsters;
    this->results = results;
}

void Bestiary::showBestiary() const
{
    if (defeatedMonsters.empty())
    {
        cout << "Aucun monstre n'a encore ete vaincu !" << endl;
        return;
    }

    cout << "========== BESTIAIRE DES MONSTRES VAINCUS ==========" << endl;

    for (int i = 0; i < defeatedMonsters.size(); i++)
    {
        Monster m = defeatedMonsters[i];

        cout << "Nom : " << m.getName() << endl;
        cout << "Categorie : " << m.getMonsterCategory() << endl;
        cout << "Stats : HP Max[" << m.getHpMax() << "] | Attaque[" << m.getAtk() << "] | Defense[" << m.getDef() << "]" << endl;
        cout << "Resultat du combat : " << results[i] << endl;
        cout << "----------------------------------------------------" << endl;
    }
}

void Bestiary::addEntry(const Monster& m, const string& resultat)
{
    defeatedMonsters.push_back(m);
    results.push_back(resultat);
}
