/*
Author:         Aaron Meche
Program:        Homework 6 - Challenge of the Minotaur Turn-Based RPG - archer.cpp
Description:    This is the implementation file for the Archer class
Date Due:       03/19/19
Date Created:   03/07/19
Date Last Mod:  03/17/19
Input:          N/A
Process:        N/A
Output:         N/A
Assumptions:    That the character.h, minotaur.h, and archer.h files exist and are in the same folder.
*/

#include "character.h"
#include "archer.h"
#include "minotaur.h"
#include <iostream>
#include <string>

using namespace std;

/*
Function:		Archer::Archer:Character
Description:	Constructor for the Archer derived class, a derivative of the Character class
Input:          N/A
Process:        Uses set functions to set all the data members of Archer
Output:         N/A
Assumptions:    N/A
*/

Archer::Archer(string iname)
	: Character()
{
	setWeapon("Bow");
	setDamage(3);
	setHealth(25);
	setName(iname);
	setArcher(1);
	setTrick(0);
}

/*
Function:		Arher::~Archer()
Description:	Destructor for the Archer derived class, a derivative of the Character class
Input:          N/A
Process:        N/A
Output:         N/A
Assumptions:    N/A
*/

Archer::~Archer()
{

}

/*
Function:		string Archer::getName()
Description:	Accessor function for the name private data member name
Input:          N/A
Process:        N/A
Output:         Returns the private data member name
Assumptions:    N/A
*/

string Archer::getName()
{
	return name;
}

/*
Function:		void Archer::setName(string iname)
Description:	Mutator function for the name private data member
Input:          N/A
Process:        Sets the private data member name to the iname argument sent into the function
Output:         N/A
Assumptions:    N/A
*/

void Archer::setName(string iname)
{
	name = iname;
}

/*
Function:		void Archer::setArcher(bool input)
Description:	Mutator function for the archer private data member
Input:          N/A
Process:        Sets the private data member archer to the input argument sent into the function
Output:         N/A
Assumptions:    N/A
*/

void Archer::setArcher(bool input)
{
	archer = input;
}

/*
Function:		bool Archer::getArcher()
Description:	Accessor function for the archer private data member name
Input:          N/A
Process:        N/A
Output:         Returns the private data member archer
Assumptions:    N/A
*/

bool Archer::getArcher()
{
	return archer;
}

/*
Function:		bool Archer::setTrick()
Description:	Mutator function for the trickShot private data member name
Input:          N/A
Process:        N/A
Output:         Sets frozen to the input sent in as an argument
Assumptions:    N/A
*/

void Archer::setTrick(bool input)
{
	trickShot = input;
}

/*
Function:		bool Mage::getTrick()
Description:	Accessor function for the trickShot private data member name
Input:          N/A
Process:        N/A
Output:         Returns the private data member trickShot
Assumptions:    N/A
*/

bool Archer::getTrick()
{
	return trickShot;
}

/*
Function:		void Archer::offense(Archer& a, Minotaur& b, int choice)
Description:	Holds all the attack choices for the Archer class. The two attacks that the Archer has are
				Arrow Shot and Critical Shot. Arrow shot does base damage. Critical shot does 2x base damage
				but has a 50% chance to fail. If the Trick Shot status is triggered in the defense stage, then 
				both attacks do +2 damage.
Input:          Archer, Minotaur classes by reference, and an integer determining which attack the user
				wants to use.
Process:        If statements determine which attack the user wishes to use. Random number generator determines whether
				or not Critical Shot lands.
Output:         N/A
Assumptions:    N/A
*/

void Archer::offense(Archer& a, Minotaur& b, int choice)
{
	int trickArrow = 0;
	int trickCrit = 0;
	trickArrow = a.getDamage() + 2;
	trickCrit = (a.getDamage() + 2) * 2;


	if (choice == 1)
	{
		if (a.getTrick() == 1)
		{
			cout << a.getName() << " uses Trick Arrow Shot! " << b.getName() << " takes " << trickArrow << " damage!" << endl << endl;
			b.setHealth(b.getHealth() - (trickArrow));
			cout << a.getName() << " Health: " << a.getHealth() << endl;
			cout << b.getName() << " Health: " << b.getHealth() << endl << endl;
		}

		else if (a.getTrick() == 0)
		{
			cout << a.getName() << " uses Arrow Shot! " << b.getName() << " takes " << a.getDamage() << " damage!" << endl << endl;
			b.setHealth(b.getHealth() - a.getDamage());
			cout << a.getName() << " Health: " << a.getHealth() << endl;
			cout << b.getName() << " Health: " << b.getHealth() << endl << endl;
		}
	}
	else if (choice == 2)
	{
		int accuracy = rand() % 100 + 1;
		if (accuracy <= 50)
		{
			if (a.getTrick() == 1)
			{
				cout << a.getName() << " uses Trick Critical Shot! " << b.getName() << " takes " << trickCrit << " damage!" << endl << endl;
				b.setHealth(b.getHealth() - trickCrit);
				cout << a.getName() << " Health: " << a.getHealth() << endl;
				cout << b.getName() << " Health: " << b.getHealth() << endl << endl;
			}

			else if (a.getTrick() == 0)
			{
				cout << a.getName() << "'s Critical Shot lands! Damage increased by 2x!" << endl << endl;
				b.setHealth(b.getHealth() - (a.getDamage() * 2));
				cout << a.getName() << " Health: " << a.getHealth() << endl;
				cout << b.getName() << " Health: " << b.getHealth() << endl << endl;
			}

		}

		else
		{
			cout << a.getName() << "'s Critical Shot misses the mark and does 0 damage!" << endl << endl;
			cout << a.getName() << " Health: " << a.getHealth() << endl;
			cout << b.getName() << " Health: " << b.getHealth() << endl << endl;
		}
	}
}

/*
Function:		void Archer::defense(Archer& a, Minotaur& b, int choice)
Description:	Holds all the defense choices for the Archer class. The Block command
				blocks 25% damage dealt by the Minotaur. The dodge command is a 60% chance to escape all damage and has
				a 25% chance to trigger Trick Shot, which increases the damage of the next attack by +2 (Arrow Shot does
				+2 damage, Critical Shot will do (base + 2) * 2).
Input:          Archer, Minotaur classes by reference, and an integer determining which attack the user
				wants to use.
Process:        If statements determine which defense option the user wishes to use. Random number generator
				determines whether or not the passive effects listed above are triggered.
Output:         N/A
Assumptions:    N/A
*/

void Archer::defense(Archer& a, Minotaur& b, int choice)
{
	int blockVal = 0;
	blockVal = b.getDamage() * .75;
	if (choice == 1)
	{
		cout << a.getName() << " blocks and takes " << blockVal << " damage!" << endl << endl;
		a.setHealth(a.getHealth() - (blockVal));
		cout << a.getName() << " Health: " << a.getHealth() << endl;
		cout << b.getName() << " Health: " << b.getHealth() << endl << endl;
	}
	else if (choice == 2)
	{
		int saveThrow = rand() % 100 + 1;
		int counter = rand() % 100 + 1;
		if (saveThrow <= 60 && counter <= 25)
		{
			cout << "You successfully dodged the attack and take no damage!" << endl;
			cout << "Trick shot triggered! Your next attack (Arrow Shot or Critical Strike) does + 1 damage!" << endl;
			a.setTrick(1);
			cout << a.getName() << " Health: " << a.getHealth() << endl;
			cout << b.getName() << " Health: " << b.getHealth() << endl << endl;
		}

		else if (saveThrow <= 60 && counter > 25)
		{
			cout << "You successfully dodged the attack and take no damage!" << endl;
			cout << "Trick shot failed! Your next attack does base damage." << endl;
			cout << a.getName() << " Health: " << a.getHealth() << endl;
			cout << b.getName() << " Health: " << b.getHealth() << endl << endl;
		}

		else if(saveThrow > 60 && saveThrow <= 100)
		{
			cout << "Dodge failed! You take " << b.getDamage() << " damage!" << endl;
			a.setHealth(a.getHealth() - b.getDamage());
			cout << a.getName() << " Health: " << a.getHealth() << endl;
			cout << b.getName() << " Health: " << b.getHealth() << endl << endl;
		}
	}
}