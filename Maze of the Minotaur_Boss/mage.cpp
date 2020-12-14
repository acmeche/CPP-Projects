/*
Author:         Aaron Meche
Program:        Homework 6 - Challenge of the Minotaur Turn-Based RPG - mage.cpp
Description:    This is the implementation file for the Mage class
Date Due:       03/19/19
Date Created:   03/07/19
Date Last Mod:  03/17/19
Input:          N/A
Process:        N/A
Output:         N/A
Assumptions:    That the character.h, minotaur.h, and mage.h files exist and are in the same folder.
*/

#include "character.h"
#include "mage.h"
#include "minotaur.h"
#include <iostream>
#include <string>

using namespace std;

/*
Function:		Mage::Mage:Character
Description:	Constructor for the Mage derived class, a derivative of the Character class
Input:          N/A
Process:        Uses set functions to set all the data members of Mage
Output:         N/A
Assumptions:    N/A
*/

Mage::Mage(string iname)
	: Character()
{
	setWeapon("Staff of Magic");
	setDamage(4);
	setHealth(20);
	setName(iname);
	setFrozen(0);
	setMage(1);
}

/*
Function:		Mage::~Mage()
Description:	Destructor for the Mage derived class, a derivative of the Character class
Input:          N/A
Process:        N/A
Output:         N/A
Assumptions:    N/A
*/

Mage::~Mage()
{

}

/*
Function:		string Mage::getName()
Description:	Accessor function for the name private data member name
Input:          N/A
Process:        N/A
Output:         Returns the private data member name
Assumptions:    N/A
*/

string Mage::getName()
{
	return name;
}

/*
Function:		void Mage::setName(string iname)
Description:	Mutator function for the name private data member
Input:          N/A
Process:        Sets the private data member name to the iname argument sent into the function
Output:         N/A
Assumptions:    N/A
*/

void Mage::setName(string iname)
{
	name = iname;
}

/*
Function:		void Mage::setMage(bool input)
Description:	Mutator function for the mage private data member
Input:          N/A
Process:        Sets the private data member mage to the input argument sent into the function
Output:         N/A
Assumptions:    N/A
*/

void Mage::setMage(bool input)
{
	mage = input;
}

/*
Function:		bool Mage::getMage()
Description:	Accessor function for the mage private data member name
Input:          N/A
Process:        N/A
Output:         Returns the private data member mage
Assumptions:    N/A
*/

bool Mage::getMage()
{
	return mage;
}

/*
Function:		bool Mage::getFrozen()
Description:	Accessor function for the frozen private data member name
Input:          N/A
Process:        N/A
Output:         Returns the private data member frozen
Assumptions:    N/A
*/

bool Mage::getFrozen()
{
	return frozen;
}

/*
Function:		bool Mage::setFrozen()
Description:	Mutator function for the frozen private data member name
Input:          N/A
Process:        N/A
Output:         Sets frozen to the f input sent in as an argument
Assumptions:    N/A
*/

void Mage::setFrozen(bool f)
{
	frozen = f;
}

/*
Function:		void Mage::offense(Mage& a, Minotaur& b, int choice)
Description:	Holds all the attack choices for the Mage class. The two attacks that the Mage has are
				Blizzard and Fireball. Fireball does base damagem Blizzard does less damage but has a chance
				to apply Frozen to the enemy. If the Frozen status is triggered, the minotaur will do -2 damage 
				during his attack phase. This also changes the Fireball attack to Burning Blizzard, which is a move 
				that does +2 extra damage, but removes the Frozen effect.
Input:          Mage, Minotaur classes by reference, and an integer determining which attack the user
				wants to use.
Process:        If statements determine which attack the user wishes to use. Random number generator determines whether
				or not Frozen is triggered.
Output:         N/A
Assumptions:    N/A
*/

void Mage::offense(Mage& a, Minotaur& b, int choice)
{
	if (choice == 1)
	{
		if (a.getFrozen() == 1)
		{
			int extraDamage = 0;
			extraDamage = a.getDamage() + 2;
			cout << a.getName() << " uses Burning Blizzard! " << b.getName() << " takes " << extraDamage << " damage! (Base damage + 2, removes Frozen effect)" << endl << endl;
			b.setHealth(b.getHealth() - (extraDamage));
			a.setFrozen(0);
			cout << a.getName() << " Health: " << a.getHealth() << endl;
			cout << b.getName() << " Health: " << b.getHealth() << endl << endl;
		}
		
		else if (a.getFrozen() == 0)
		{
			cout << a.getName() << " uses Fireball! " << b.getName() << " takes " << a.getDamage() << " damage!" << endl << endl;
			b.setHealth(b.getHealth() - a.getDamage());
			cout << a.getName() << " Health: " << a.getHealth() << endl;
			cout << b.getName() << " Health: " << b.getHealth() << endl << endl;
		}
	}
	else if (choice == 2)
	{
		int freeze = rand() % 100 + 1;
		int blizzardDmg = 0;
		blizzardDmg = a.getDamage() - 1;
		if (freeze <= 50)
		{
			cout << a.getName() << " uses Blizzard! " << b.getName() << " takes " << blizzardDmg << " damage and is Frozen! (" << b.getName() << " deals -2 damage until Burning Blizzard is cast)" << endl << endl;
			b.setHealth(b.getHealth() - blizzardDmg);
			a.setFrozen(1);

			cout << a.getName() << " Health: " << a.getHealth() << endl;
			cout << b.getName() << " Health: " << b.getHealth() << endl << endl;

		}

		else
		{
			cout << a.getName() << " uses Blizzard! " << b.getName() << " takes " << blizzardDmg << " damage!" << endl << endl;
			b.setHealth(b.getHealth() - blizzardDmg);
			cout << a.getName() << " Health: " << a.getHealth() << endl;
			cout << b.getName() << " Health: " << b.getHealth() << endl << endl;
		}
	}
}

/*
Function:		void Mage::defense(Mage& a, Minotaur& b, int choice)
Description:	Holds all the defense choices for the Mage class. If the Frozen status is triggered,
				the minotaur will do -2 damage during his attack phase. The Magic Barrier command
				blocks 50% damage dealt by the Minotaur and reflects that same amount back to the 
				Minotaur as health damage. The dodge command is a chance to escape all damage and has 
				a chance to trigger Serene Heal, which heals the Mage for +5, or less to ensure that
				max health cannot exceed his base health of 20.
Input:          Mage, Minotaur classes by reference, and an integer determining which attack the user
				wants to use.
Process:        If statements determine which defense option the user wishes to use. Random number generator
				determines whether or not the passive effects listed above are triggered.
Output:         N/A
Assumptions:    N/A
*/

void Mage::defense(Mage& a, Minotaur& b, int choice)
{
	int blockVal = 0;
	blockVal = b.getDamage() / 2;
	//int freezeCount = 3;			implement a cooldown possibly later
	if (a.getFrozen() == 1)
	{
		blockVal = (b.getDamage() - 2) / 2;
	}
	if (choice == 1)
	{
		cout << a.getName() << " uses Magic Barrier and takes " << blockVal << " damage! Magic Barrier reflects " << blockVal << " damage back at " << b.getName() << "!" << endl << endl;
		a.setHealth(a.getHealth() - blockVal);
		b.setHealth(b.getHealth() - blockVal);
		cout << a.getName() << " Health: " << a.getHealth() << endl;
		cout << b.getName() << " Health: " << b.getHealth() << endl << endl;
	}
	else if (choice == 2)
	{
		int saveThrow = rand() % 100 + 1;
		int heal = rand() % 100 + 1;
		int calcHealth = 0;
		if (a.getHealth() + 5 > 20)
		{
			calcHealth = 20 - a.getHealth();
		}

		else
		{
			calcHealth = 5;
		}

		if (saveThrow <= 50 && heal <= 40)
		{
			cout << "You successfully dodged the attack and take no damage!" << endl;
			cout << "Serene Heal triggered! You heal yourself for " << calcHealth << " health!" << endl;
			a.setHealth(a.getHealth() + calcHealth);
			cout << a.getName() << " Health: " << a.getHealth() << endl;
			cout << b.getName() << " Health: " << b.getHealth() << endl << endl;
		}

		else if (saveThrow <= 50 && heal > 35)
		{
			cout << "You successfully dodged the attack and take no damage!" << endl;
			cout << "Serene Heal failed. Your Health remains the same." << endl;
			cout << a.getName() << " Health: " << a.getHealth() << endl;
			cout << b.getName() << " Health: " << b.getHealth() << endl << endl;
		}

		else if (saveThrow > 51 && saveThrow <= 100)
		{
			if (a.getFrozen() == 1)
			{
				cout << "Dodge failed! You take " << b.getDamage() << " damage!" << endl;
				a.setHealth(a.getHealth() - (b.getDamage() - 2));
				cout << a.getName() << " Health: " << a.getHealth() << endl;
				cout << b.getName() << " Health: " << b.getHealth() << endl << endl;
			}

			else
			{
				cout << "Dodge failed! You take " << b.getDamage() << " damage!" << endl;
				a.setHealth(a.getHealth() - (b.getDamage()));
				cout << a.getName() << " Health: " << a.getHealth() << endl;
				cout << b.getName() << " Health: " << b.getHealth() << endl << endl;
			}

		}
	}
}