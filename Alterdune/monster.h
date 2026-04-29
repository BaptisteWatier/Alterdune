#ifndef MONSTER_H
#define MONSTER_H

#include <vector>
#include <string>

#include "character.h"

class Monster : public Character{
protected:
    std::string monsterCategory; 
    int mercy;
    int mercyGoal;
    std::vector<std::string> actIds;

public:
    Monster(const std::string& name, int hp, int hpMax, int atk, int def, const std::string& monsterCategory, int mercy, int mercyGoal, const std::vector<std::string>& actIds);

    std::string getMonsterCategory() const;
    int getMercy() const;
    int getMercyGoal() const;
    std::vector<std::string> getActIds() const;
    
    void displayInfo() const override;
    void changeMercy(int);
    bool canBeSpared() const;
    void resetMercy();
};

#endif
