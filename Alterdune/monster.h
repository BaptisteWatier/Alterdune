#ifndef MONSTER_H
#define MONSTER_H

#include <string>

using namespace std;

class Monster {
protected:
    string monsterCategory; // Classe ?
    int mercy;
    int mercyGoal;
    vector<string> actIds;

public:
    Monster(string monsterCategory, int mercy, int mercyGoal, vector<string> actIds);

    string getMonsterCategory();
    int getMercy();
    int getMercyGoal();
    vector<string> getActIds();

    void changeMercy(int);
    bool canBeSpared();
    void resetMercy();
};

#endif
