/*
Author:         Aaron Meche
Program:        Homework 6 - Challenge of the Minotaur Turn-Based RPG - minotaur.cpp
Description:    This is the implementation file for the Minotaur class
Date Due:       03/19/19
Date Created:   03/07/19
Date Last Mod:  03/17/19
Input:          N/A
Process:        N/A
Output:         N/A
Assumptions:    That the character.h and minotaur.h files exist and are in the same folder.
*/

#include "character.h"
#include "minotaur.h"
#include <iostream>
#include <string>

using namespace std;

/*
Function:		Minotaur::Minotaur:Character
Description:	Constructor for the Minotaur derived class, a derivative of the Character class
Input:          N/A
Process:        Uses set functions to set all the data members of Minotaur
Output:         N/A
Assumptions:    N/A
*/

Minotaur::Minotaur()
	: Character()
{
	setWeapon("Axe");
	setDamage(4);
	setHealth(35);
	setName("Minotaur");
}

/*
Function:		Minotaur::~Minotaur
Description:	Destructor for the Minotaur derived class, a derivative of the Character class
Input:          N/A
Process:        N/A
Output:         N/A
Assumptions:    N/A
*/

Minotaur::~Minotaur()
{

}

/*
Function:		string Minotaur::getName()
Description:	Accessor function for the name private data member name
Input:          N/A
Process:        N/A
Output:         Returns the private data member name
Assumptions:    N/A
*/

string Minotaur::getName()
{
	return name;
}

/*
Function:		void Minotaur::setName(string iname)
Description:	Mutator function for the name private data member
Input:          N/A
Process:        Sets the private data member name to the iname argument sent into the function
Output:         N/A
Assumptions:    N/A
*/

void Minotaur::setName(string iname)
{
	name = iname;
}

/*
Function:		int Minotaur::getCooldown()
Description:	Accessor function for the name private data member cooldown
Input:          N/A
Process:        N/A
Output:         Returns the private data member cooldown
Assumptions:    N/A
*/

int Minotaur::getCooldown()
{
	return cooldown;
}

/*
Function:		void Minotaur::setCooldown(int set)
Description:	Mutator function for the cooldown private data member
Input:          N/A
Process:        Sets the private data member cooldown to the set argument sent into the function
Output:         N/A
Assumptions:    N/A
*/

void Minotaur::setCooldown(int set)
{
	cooldown = set;
}

/*
Function:		int Minotaur::getAttack()
Description:	Accessor function for the name private data member attacknum
Input:          N/A
Process:        N/A
Output:         Returns the private data member attacknum
Assumptions:    N/A
*/

int Minotaur::getAttack()
{
	return attacknum;
}

/*
Function:		void Minotaur::setAttack(int input)
Description:	Mutator function for the attacknum private data member 
Input:          N/A
Process:        Sets the private data member attacknum to the input argument sent into the function
Output:         N/A
Assumptions:    N/A
*/

void Minotaur::setAttack(int input)
{
	attacknum = input;
}

/*
Function:		void Minotaur::attack(Minotaur& a)
Description:	This function determines what attack the Minotaur will access using a random number
				generator. After determining which attack is used, the damage is set using the
				set damage function. There is a cooldown mechanic included to stop the Minotaur
				from reusing his ultimate attack too often.
Input:          A Minotaur class object by reference.
Process:        After generating a random number, that number is used to determine which attack the Minotaur will use
				and the damage is set accordingly.
Output:         N/A
Assumptions:    N/A
*/

void Minotaur::attack(Minotaur& a)
{
	a.setAttack(rand() % 100 + 1);
	if (a.getAttack() <= 50 && a.getAttack() >= 0) // normal attack
	{
		cout << a.getName() << " is about to swing his mighty " << a.getWeapon() << " for 4 damage. What will you do?" << endl;
		a.setDamage(4);
	}

	else if (a.getAttack() > 50 && a.getAttack() <= 80)
	{
		cout << a.getName() << " is about to use its Vertical Cleave attack for 7 damage! What will you do?" << endl;
		a.setDamage(7);
	}

	else if (a.getAttack() > 81 && a.getCooldown() == 0)
	{
		cout << a.getName() << " is about to use its ultimate attack, Bull Rush, for 10 damage! What will you do?" << endl;
		a.setDamage(10);
		a.setCooldown(2);	// cooldown mechanic so minotaur can't reuse this attack too often
	}

	else
	{
		cout << a.getName() << " is about to swing his mighty " << a.getWeapon() << " for 4 damage. What will you do?" << endl;
		a.setDamage(4);
	}

	if (a.getCooldown() > 0)
	{
		a.setCooldown(a.getCooldown() - 1);
	}
}