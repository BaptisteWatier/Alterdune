#ifndef ACTACTION_H
#define ACTACTION_H

#include <string>

class ActAction {
protected:
    std::string id;
    std::string texte;
    int mercyImpact;

public:
    ActAction(const std::string& id, const std::string& texte, int mercyImpact);

    std::string getId() const;
    std::string getTexte() const;
    int getMercyImpact() const;

};
#endif