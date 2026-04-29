#ifndef BESTIARY_H
#define BESTIARY_H

#include <string>
#include <vector>

#include "monster.h"

class Bestiary {
protected:
    std::vector<Monster> defeatedMonsters;
    std::vector<std::string> results;

public:
    Bestiary(const std::vector<Monster>& defeatedMonsters, const std::vector<std::string>& results);

    void addEntry(const Monster& m, const std::string& r);
    void showBestiary() const;

};
#endif
