#ifndef ACTACTION_H
#define ACTACTION_H

#include <string>

using namespace std;

class ActAction {
protected:
    string id;
    string texte;
    int mercyImpact;

public:
    ActAction(string id, string texte, int mercyImpact);

    string getTexte();
    string getMercyImpact();
    
}
