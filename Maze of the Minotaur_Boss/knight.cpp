/*
Author:         Aaron Meche
Program:        Homework 6 - Challenge of the Minotaur Turn-Based RPG - knight.cpp
Description:    This is the implementation file for the Knight class
Date Due:       03/19/19
Date Created:   03/07/19
Date Last Mod:  03/17/19
Input:          N/A
Process:        N/A
Output:         N/A
Assumptions:    That the character.h, minotaur.h, and knight.h files exist and are in the same folder.
*/

#include "character.h"
#include "knight.h"
#include "minotaur.h"
#include <iostream>
#include <string>

using namespace std;

/*
Function:		Knight::Knight:Character
Description:	Constructor for the Knight derived class, a derivative of the Character class
Input:          N/A
Process:        Uses set functions to set all the data members of Knight
Output:         N/A
Assumptions:    N/A
*/

Knight::Knight(string iname)
	: Character()
{
	setWeapon("Sword");
	setDamage(2);
	setHealth(30);
	setName(iname);
	setKnight(1);
}

/*
Function:		Knight::~Knight()
Description:	Destructor for the Knight derived class, a derivative of the Character class
Input:          N/A
Process:        N/A
Output:         N/A
Assumptions:    N/A
*/

Knight::~Knight()
{

}

/*
Function:		string Knight::getName()
Description:	Accessor function for the name private data member name
Input:          N/A
Process:        N/A
Output:         Returns the private data member name
Assumptions:    N/A
*/

string Knight::getName()
{
	return name;
}

/*
Function:		void Knight::setName(string iname)
Description:	Mutator function for the name private data member
Input:          N/A
Process:        Sets the private data member name to the iname argument sent into the function
Output:         N/A
Assumptions:    N/A
*/

void Knight::setName(string iname)
{
	name = iname;
}

/*
Function:		void Knight::setKnight(bool input)
Description:	Mutator function for the knight private data member
Input:          N/A
Process:        Sets the private data member knight to the input argument sent into the function
Output:         N/A
Assumptions:    N/A
*/

void Knight::setKnight(bool input)
{
	knight = input;
}

/*
Function:		bool Knight::getKnight()
Description:	Accessor function for the knight private data member name
Input:          N/A
Process:        N/A
Output:         Returns the private data member knight
Assumptions:    N/A
*/

bool Knight::getKnight()
{
	return knight;
}

/*
Function:		void Knight::offense(Knight& a, Minotaur& b, int choice)
Description:	Holds all the attack choices for the Knight class. The two attacks that the Knight has are
				Slash and Stab. Slash does base damage. Stab does +1 base damage but has 80% accuracy.
Input:          Knight, Minotaur classes by reference, and an integer determining which attack the user
				wants to use.
Process:        If statements determine which attack the user wishes to use. Random number generator determines whether
				or not Stab lands.
Output:         N/A
Assumptions:    N/A
*/

void Knight::offense(Knight& a, Minotaur& b, int choice)
{
	if (choice == 1)
	{
		cout << a.getName() << " uses Slash attack! " << b.getName() << " takes " << a.getDamage() << " damage!" << endl << endl;
		b.setHealth(b.getHealth() - a.getDamage());
		cout << a.getName() << " Health: " << a.getHealth() << endl;
		cout << b.getName() << " Health: " << b.getHealth() << endl << endl;
	}
	else if (choice == 2)
	{
		int accuracy = rand() % 100 + 1;
		if (accuracy <= 80)
		{
			cout << a.getName() << "'s stab attack lands! Damage increased by +1!" << endl << endl;
			b.setHealth(b.getHealth() - (a.getDamage() + 1));
			cout << a.getName() << " Health: " << a.getHealth() << endl;
			cout << b.getName() << " Health: " << b.getHealth() << endl << endl;
		}

		else
		{
			cout << a.getName() << "'s stab attack misses the mark and deals -1 damage!" << endl << endl;
			b.setHealth(b.getHealth() - (a.getDamage() - 1));
			cout << a.getName() << " Health: " << a.getHealth() << endl;
			cout << b.getName() << " Health: "<< b.getHealth() << endl << endl;
		}
	}
}

/*
Function:		void Knight::defense(Knight& a, Minotaur& b, int choice)
Description:	Holds all the defense choices for the Knight class. The Block command blocks 50% damage dealt by the Minotaur
				and has a 25% chance to trigger Stalwart Blade Counter, which deals +2 damage back to the Minotaur. The dodge 
				command is a 25% chance to escape all damage.
Input:          Knight, Minotaur classes by reference, and an integer determining which attack the user
				wants to use.
Process:        If statements determine which defense option the user wishes to use. Random number generator
				determines whether or not the passive effects listed above are triggered.
Output:         N/A
Assumptions:    N/A
*/

void Knight::defense(Knight& a, Minotaur& b, int choice)
{
	if (choice == 1)
	{
		int counter = rand() % 100 + 1;
		if (counter >= 25)
		{
			cout << a.getName() << " blocks and counter-attacks with Stalwart Blade Counter for 2 damage!" << endl << endl;
			a.setHealth(a.getHealth() - (b.getDamage() / 2));
			b.setHealth(b.getHealth() -  2);
			cout << a.getName() << " Health: " << a.getHealth() << endl;
			cout << b.getName() << " Health: " << b.getHealth() << endl << endl;
		}

		else
		{
			cout << a.getName() << " blocks and takes " << b.getDamage() << " damage!" << endl;
			a.setHealth(a.getHealth() - (b.getDamage() / 2));
			cout << a.getName() << " Health: " << a.getHealth() << endl;
			cout << b.getName() << " Health: " << b.getHealth() << endl << endl;
		}
	}
	else if (choice == 2)
	{
		int saveThrow = rand() % 100 + 1;
		if (saveThrow <= 25)
		{
			cout << "You successfully dodged the attack and take no damage!" << endl;
			cout << a.getName() << " Health: " << a.getHealth() << endl;
			cout << b.getName() << " Health: " << b.getHealth() << endl << endl;
		}

		else
		{
			cout << "Dodge failed! You take " << b.getDamage() << " damage!" << endl;
			a.setHealth(a.getHealth() - b.getDamage());
			cout << a.getName() << " Health: " << a.getHealth() << endl;
			cout << b.getName() << " Health: " << b.getHealth() << endl << endl;
		}
	}
}
