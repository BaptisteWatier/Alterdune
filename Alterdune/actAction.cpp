
#include "actAction.h"

using namespace std;

ActAction::ActAction(const string& id, const string& texte, int mercyImpact)
{
	this->id = id;
	this->texte = texte;
	this->mercyImpact = mercyImpact;
}

string ActAction::getId() const {
	return id;
}

string ActAction::getTexte() const {
	return texte;
}

int ActAction::getMercyImpact() const{
	return mercyImpact;
}
