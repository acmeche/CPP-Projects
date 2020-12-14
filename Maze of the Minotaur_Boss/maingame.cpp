/*
Author:         Aaron Meche
Program:        Homework 6 - Challenge of the Minotaur Turn-Based RPG
Description:    This File is the main game program for the Challenge of the Minotaur project.
Date Due:       03/19/19
Date Created:   03/07/19
Date Last Mod:  03/17/19
Input:          User will be prompted to enter an integer to choose a class. The user will then be prompted
				to enter a name for their character. The user will then be prompted to enter integers during
				attack and defense phases of the program, which will determine which attack and defense ability
				the character will use.
Process:        The program will determine which class to create, the name of the user's character, and 
				which attack/defense ability will be used based on user input. The enemy and character's
				health will be calculated based on math calculations and user choice input.
Output:         The prorgam will continually print text as the battle between user and the minotaur progresses.
Assumptions:    That the character.h, character.cpp, knight.h, knight.cpp, archer.h, archer.cpp, mage.h,
				mage.cpp, minotaur.h, minotaur.cpp, fight.h, and fight.cpp files exist and are in the same
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

int main()
{
	bool done = 0;
	bool doneChoice;
	int classChoice;
	string name;
	Fight f;

	cout << "Welcome to the Challenge of the Minotaur game! In this game, you will choose a character class from the list (Knight, Mage, or Archer), "
		 << "name your character, and use him/her to fight the Minotaur! First, you will choose your character's class." << endl;

	while (!done)																													// loop to keep the game running
	{
		cout << "Would you like to play as a Knight, Mage, or Archer?" << endl														// prompt the user to choose class
			<< "1.) Knight (High health/defense, low damage output)" << endl
			<< "2.) Mage (Low health, medium defense, medium damage output, and a random chance healing spell)" << endl
			<< "3.) Archer (Medium health, low defense, high dodge chance, high damage output)" << endl;
		cin >> classChoice;

		if (classChoice == 1)																										// functions for the Knight class
		{
			cout << "You have chosen to play as the Knight. Enter your name." << endl;
			cin >> name;
			Knight p1(name);
			cout << "You, " << p1.getName() << ", have chosen to take up your " << p1.getWeapon() << " and face the Minotaur's challenge." << endl << endl;
			Minotaur m;
			f.knightBattleMinotaur(p1, m);
			if (p1.getHealth() <= 0)
			{
				cout << "Knight final health: " << p1.getHealth() << endl;
				cout << "Minotaur final health: " << m.getHealth() << endl << endl;
				cout << "You were slain by the Minotaur. Would you like to try again? (0 to try again, 1 to quit)" << endl;
				cin >> doneChoice;
				done = doneChoice;
			}

			else if (m.getHealth() <= 0)
			{
				cout << "Knight final health: " << p1.getHealth() << endl;
				cout << "Minotaur final health: " << m.getHealth() << endl;
				cout << "You slayed the Minotaur! Would you like to try again? (0 to try again, 1 to quit)" << endl;
				cin >> doneChoice;
				done = doneChoice;
			}
		}

		else if (classChoice == 2)																									// functions for the Mage class
		{
			cout << "You have chosen to play as the Mage. Enter your name." << endl;
			cin >> name;
			Mage p1(name);
			cout << "You, " << p1.getName() << ", have chosen to take up your " << p1.getWeapon() << " and face the Minotaur's challenge." << endl << endl;
			Minotaur m;
			f.mageBattleMinotaur(p1, m);
			if (p1.getHealth() <= 0)
			{
				cout << "Mage final health: " << p1.getHealth() << endl;
				cout << "Minotaur final health: " << m.getHealth() << endl << endl;
				cout << "You were slain by the Minotaur. Would you like to try again? (0 to try again, 1 to quit)" << endl;
				cin >> doneChoice;
				done = doneChoice;
			}

			else if (m.getHealth() <= 0)
			{
				cout << "Mage final health: " << p1.getHealth() << endl;
				cout << "Minotaur final health: " << m.getHealth() << endl;
				cout << "You slayed the Minotaur! Would you like to try again? (0 to try again, 1 to quit)" << endl;
				cin >> doneChoice;
				done = doneChoice;
			}
		}

		else if (classChoice == 3)																									// functions for Archer class		
		{
			cout << "You have chosen to play as the Archer. Enter your name." << endl;
			cin >> name;
			Archer p1(name);
			cout << "You, " << p1.getName() << ", have chosen to take up your " << p1.getWeapon() << " and face the Minotaur's challenge." << endl << endl;
			Minotaur m;
			f.archerBattleMinotaur(p1, m);
			if (p1.getHealth() <= 0)
			{
				cout << "Archer final health: " << p1.getHealth() << endl;
				cout << "Minotaur final health: " << m.getHealth() << endl << endl;
				cout << "You were slain by the Minotaur. Would you like to try again? (0 to try again, 1 to quit)" << endl;
				cin >> doneChoice;
				done = doneChoice;
			}

			else if (m.getHealth() <= 0)
			{
				cout << "Archer final health: " << p1.getHealth() << endl;
				cout << "Minotaur final health: " << m.getHealth() << endl;
				cout << "You slayed the Minotaur! Would you like to try again? (0 to try again, 1 to quit)" << endl;
				cin >> doneChoice;
				done = doneChoice;
			}
		}

		else
		{
			cout << "You have chosen not to take up the Minotaur's Challenge. You will most likely live longer because of it. Good luck, coward." << endl;
			done = 1;
		}
	}
	system("pause");
}