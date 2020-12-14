#include "character.h"
#include "knight.h"
#include "archer.h"
#include "mage.h"
#include "minotaur.h"
#include "fight.h"
#include <iostream>
#include <string>

using namespace std;
/*
int main()
{
	Character c;

	//***********Character Test***********
	cout << "Default weapon for character: " << c.getWeapon() << endl;
	cout << "Default health for character: " << c.getHealth() << endl;
	cout << "Default Damage for character: " << c.getDamage() << endl;

	Knight k("Arthur"); // test knight

	//***********Character - Knight Test***********
	cout << "Default weapon for Knight: " << k.getWeapon() << endl;
	cout << "Default health for Knight: " << k.getHealth() << endl;
	cout << "Default Damage for Knight: " << k.getDamage() << endl;
	cout << "Default name for Knight: " << k.getName() << endl;

	int classChoice;
	string name;

	cout << "Would you like to play as a Knight, Mage, or Archer? (This is a test, not completed yet)" << endl
		<< "1.) Knight" << endl
		<< "2.) Mage" << endl
		<< "3.) Archer" << endl;
	cin >> classChoice;

	if (classChoice == 1)
	{
		cout << "You have chosen to play as the Knight. Enter your name." << endl;
		cin >> name;
		Knight p1(name);
		cout << "You, " << p1.getName() << ", have chosen to take up your " << p1.getWeapon() << " and face the Minotaur's challenge." << endl;
	}

	else if (classChoice == 2)
	{
		cout << "You have chosen to play as the Mage. Enter your name." << endl;
		cin >> name;
		Mage p1(name);
		cout << "You, " << p1.getName() << ", have chosen to take up your " << p1.getWeapon() << " and face the Minotaur's challenge." << endl;
	}

	else if (classChoice == 3)
	{
		cout << "You have chosen to play as the Archer. Enter your name." << endl;
		cin >> name;
		Archer p1(name);
		cout << "You, " << p1.getName() << ", have chosen to take up your " << p1.getWeapon() << " and face the Minotaur's challenge." << endl;
	}

	else
	{
		cout << "You have chosen not to take up the Minotaur's Challenge. You will most likely live longer because of it. Good luck, coward." << endl;
		system("pause");
		//bool done = true;		Set this in a loop
		return 0;
	}

	cout << "Character creation successful on Knight, Mage, Archer, and Exit functions. Now testing battle functions and Minotaur constructor." << endl << endl;
	cout << "Minotaur Default Constructor test: " << endl;
	Minotaur m;
	//***********Character - Minotaur Test***********
	cout << "Default weapon for Minotaur: " << m.getWeapon() << endl;
	cout << "Default health for Minotaur: " << m.getHealth() << endl;
	cout << "Default Damage for Minotaur: " << m.getDamage() << endl;
	cout << "Default name for Minotaur: " << m.getName() << endl << endl;

	//***********Battle Test***********
	Fight f;
	/*
	cout << "Boss fight, Knight aganist the Minotaur test: " << endl;
	f.knightBattleMinotaur(k, m);
	cout << "Knight final health: " << k.getHealth() << endl;
	cout << "Minotaur final health: " << m.getHealth() << endl;
	
	Archer l("Artemis");
	Minotaur n;

	cout << "Boss fight, Archer aganist the Minotaur test: " << endl;
	f.archerBattleMinotaur(l, n);
	cout << "Archer final health: " << l.getHealth() << endl;
	cout << "Minotaur final health: " << n.getHealth() << endl;
	*/
	/*
	Mage p("Merlin");
	Minotaur o;

	cout << "Boss fight, Mage aganist the Minotaur test: " << endl;
	f.mageBattleMinotaur(p, o);
	cout << "Mage final health: " << p.getHealth() << endl;
	cout << "Minotaur final health: " << o.getHealth() << endl;
	
	system("pause");
}*/