#include "ActAction.h"

using namespace std;

ActAction::ActAction(string id, string texte, int mercyImpact) 
{
	this->id = id;
	this->texte = texte;
	this->mercyImpact = mercyImpact;
}

string ActAction::getId() {
	return id;
}

string ActAction::getTexte() {
	return texte;
}

string ActAction::getMercyImpact() {
	return mercyImpact;
}
