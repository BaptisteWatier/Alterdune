#include <iostream>
#include <random>
#include "battle.h"


using namespace std;

Battle::Battle( Player& p, Monster& m, const std::vector<std::string>& actIds, const std::vector<ActAction>& actActions)
	: p(p), m(m), actIds(actIds), actActions(actActions)
{
}

std::string Battle::start() 
{
	while (p.isAlive())  
	{
		if (!m.isAlive())
		{
			return "killed";
		}
		int n;
		cout << "A toi de jouer !  (1)FIGHT (2)ACT (3)ITEM (4)MERCY" << endl;
		cin >> n;
		if (n == 1)
		{
			doFight();
		}
		else if (n == 2)
		{
			doAct();
		}
		else if (n == 3)
		{
			doItem();
		}
		else if (n == 4)
		{
			if (doMercy() == true)
			{
				return "spared";
			}
			cout << "La jauge mercy n'est pas totalement remplie !" << endl;
		}
		else
		{
			cout << "Choix invalide." << endl;
			continue;
		}

		if (m.isAlive())
		{
			monsterFight();
		}		
	}
	return "lost";
}

void Battle::doFight() 
{
	random_device rd;      
	mt19937 gen(rd());     
	uniform_int_distribution<> dist(0, m.getHpMax());
	int damage = dist(gen);

	m.takeDamage(damage);
	cout << "Vous attaquez le monstre et infligez " << damage << " degats." << endl;
}

void Battle::doAct()
{
	vector<string> actIds = m.getActIds();

	if (actIds.empty())
	{
		cout << "Aucune action ACT disponible pour ce monstre." << endl;
		return;
	}

	cout << "Actions ACT disponibles :" << endl;

	for (int i = 0; i < actIds.size(); i++)
	{
		cout << i + 1 << ". " << actIds[i] << endl;
	}

	int choice;
	cout << "Choisis une action : ";
	cin >> choice;

	choice--;

	if (choice < 0 || choice >= actIds.size())
	{
		cout << "Choix invalide." << endl;
		return;
	}

	string selectedId = actIds[choice];
	bool found = false;

	for (int i = 0; i < actActions.size(); i++)
	{
		if (actActions[i].getId() == selectedId)
		{
			cout << actActions[i].getTexte() << endl;

			m.changeMercy(actActions[i].getMercyImpact());

			cout << "Mercy : " << m.getMercy()
				<< "/" << m.getMercyGoal() << endl;

			found = true;
			break;
		}
	}

	if (!found)
	{
		cerr << "Erreur : l'action ACT '" << selectedId
			<< "' n'existe pas dans le catalogue." << endl;
	}
}

void Battle::doItem()
{
	p.getInventory().showItems();

	int itemChoice;
	cout << "Choisissez un item : ";
	cin >> itemChoice;

	p.getInventory().useItem(itemChoice, p);
}

bool Battle::doMercy()
{
	if (m.canBeSpared())
	{
		return true;
	}
	return false;
}

void Battle::monsterFight()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, p.getHpMax());
	int damage = dist(gen);

	p.takeDamage(damage);
	cout << "Le monstre attaque et inflige " << damage << " degats." << endl;
}