#include "Bestiary.h"
#include "Monster.h"

using namespace std;

Bestiary::Bestiary(vector<Monster> defeatedMonsters, vector<string> results) 
{
	this->defeatedMonsters = defeatedMonsters;
	this->results = results;
}

void Bestiary::showBestiary()
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

void Bestiary::addEntry(Monster m, string resultat) 
{
    defeatedMonsters.push_back(m);
    results.push_back(resultat);
}
