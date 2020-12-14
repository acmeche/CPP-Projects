/*
Author:         Aaron Meche
Program:        Homework 6 - Challenge of the Minotaur Turn-Based RPG - fight.cpp
Description:    This is the implementation file for the Fight class
Date Due:       03/19/19
Date Created:   03/07/19
Date Last Mod:  03/17/19
Input:          N/A
Process:        N/A
Output:         N/A
Assumptions:    That the character.h, character.cpp, knight.h, knight.cpp, archer.h, archer.cpp, mage.h,
				mage.cpp, minotaur.h, minotaur.cpp, and fight.h files exist and are in the same
				folder.
*/

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
Function:		void Fight::knightBattleMinotaur(Knight &a, Minotaur &b)
Description:	Function that controls the battle text between the Knight class and the Minotaur.
Input:          Knight and Minotaur class references are sent in as function arguments so that their member data and functions
				can be used and altered.
Process:        The function calls the offense and defense functions for the Knight at the appropriate time, as well as the
				attack function for the Minotaur.
Output:         N/A
Assumptions:    The Knight and Minotaur classes have been instantiated in a different scope.
*/

void Fight::knightBattleMinotaur(Knight &a, Minotaur &b)
{
	int choice = 0;
	cout << "The challenge of the Minotaur will now commence! Steel yourself, brave " << a.getName() << "! You will initiate the first strike." << endl << endl;
	while (a.getHealth() >= 1 && b.getHealth() >= 1)
	{
		cout << "It is your turn. Attack!" << endl
			 << "1.) Slash (base damage " << a.getDamage() << ")" << endl
			 << "2.) Stab (base damage + 1, accuracy = 80%)" << endl;
		cin >> choice;
		a.offense(a, b, choice);																											// Knight attack function

		if (a.getHealth() <= 0 || b.getHealth() <= 0)
		{
			continue;
		}

		cout << "It is now the Minotaur's turn!" << endl;
		b.attack(b);																														// minotaur attack function
		cout << "1.) Block (-50% damage taken, 75% chance to counter with Stalwart Blade Counter, deals 2 damage to attacker)" << endl		// knight defense function
			 << "2.) Dodge (25% chance to dodge attack, avoiding all damage)" << endl;
		cin >> choice;
		a.defense(a, b, choice);
	}
}

/*
Function:		void Fight::archerBattleMinotaur(Archer &a, Minotaur &b)
Description:	Function that controls the battle text between the Archer class and the Minotaur.
Input:          Archer and Minotaur class references are sent in as function arguments so that their member data and functions
				can be used and altered.
Process:        The function calls the offense and defense functions for the Archer at the appropriate time, as well as the
				attack function for the Minotaur.
Output:         N/A
Assumptions:    The Archer and Minotaur classes have been instantiated in a different scope.
*/

void Fight::archerBattleMinotaur(Archer &a, Minotaur &b)
{
	int choice = 0;
	cout << "The challenge of the Minotaur will now commence! Steel yourself, brave " << a.getName() << "! You will initiate the first strike." << endl << endl;

	while (a.getHealth() >= 1 && b.getHealth() >= 1)
	{
		if (a.getTrick() == 1)
		{
			cout << "It is your turn. Attack! (Trick shot enabled, all attacks do +2 damage!)" << endl
				 << "1.) Arrow Shot (base damage " << a.getDamage() << " + 2)" << endl
				 << "2.) Critical Shot ((base damage + 2) * 2, accuracy = 50%)" << endl;
			cin >> choice;
			a.offense(a, b, choice); // archer attack function if special Trick Attack is triggered
			a.setTrick(0);
		}

		else
		{
			cout << "It is your turn. Attack!" << endl
				 << "1.) Arrow Shot (base damage " << a.getDamage() << ")" << endl
				 << "2.) Critical Shot (base damage * 2, accuracy = 50%)" << endl;
			cin >> choice;
			a.offense(a, b, choice); // archer attack function
		}

		if (a.getHealth() <= 0 || b.getHealth() <= 0)
		{
			continue;
		}

		cout << "It is now the Minotaur's turn!" << endl;
		b.attack(b);										// minotaur attack function
		cout << "1.) Block (-25% damage taken)" << endl		// archer defense function
			 << "2.) Dodge (60% chance to dodge attack, avoiding all damage, 25% chance to enable Trick Shot (base damage +2 on next attack)" << endl;
		cin >> choice;
		a.defense(a, b, choice);
	}
}

/*
Function:		void Fight::mageBattleMinotaur(Mage &a, Minotaur &b)
Description:	Function that controls the battle text between the Mage class and the Minotaur.
Input:          Mage and Minotaur class references are sent in as function arguments so that their member data and functions
				can be used and altered.
Process:        The function calls the offense and defense functions for the Mage at the appropriate time, as well as the
				attack function for the Minotaur.
Output:         N/A
Assumptions:    The Mage and Minotaur classes have been instantiated in a different scope.
*/

void Fight::mageBattleMinotaur(Mage &a, Minotaur &b)
{
	int choice = 0;
	cout << "The challenge of the Minotaur will now commence! Steel yourself, brave " << a.getName() << "! You will initiate the first strike." << endl << endl;

	while (a.getHealth() >= 1 && b.getHealth() >= 1)
	{
		if (a.getFrozen() == 1)
		{
			cout << "It is your turn. Attack! (Enemy is frozen, Fireball changed to Burning Blizzard!)" << endl					// Mage attack function if enemy is frozen
				<< "1.) Burning Blizzard (base damage " << a.getDamage() << " + 2 attack and removes Frozen effect)" << endl
				<< "2.) Blizzard (base damage -1)" << endl;
			cin >> choice;
			a.offense(a, b, choice);
		}

		else
		{
			cout << "It is your turn. Attack!" << endl
				 << "1.) Fireball (base damage " << a.getDamage() << ")" << endl
				 << "2.) Blizzard (base damage -1, 20% chance to apply Frozen to enemy)" << endl;
			cin >> choice;
			a.offense(a, b, choice);																// mage attack function
		}

		if (a.getHealth() <= 0 || b.getHealth() <= 0)
		{
			continue;
		}

		cout << "It is now the Minotaur's turn!" << endl;
		b.attack(b);																				// minotaur attack function
		cout << "1.) Magic Barrier (-50% damage taken, 50% damage reflected at enemy)" << endl		// mage defense function
			 << "2.) Dodge (50% chance to dodge attack, avoiding all damage, 40% chance to enable Serene Heal)" << endl;
		cin >> choice;
		a.defense(a, b, choice);
	}
}
