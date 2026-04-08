#ifndef BESTIARY_H
#define BESTIARY_H

#include <string>
#include <vector>
#include "Monster.h"

using namespace std;

class Bestiary {
protected:
    vector<Monster> defeatedMonsters;
    vector<string> results;

public:
    Bestiary(vector <Monster> defeatedMonsters, vector <string> results);

    void addEntry(Monster, string);
    void showBestiary();

};

#endif
