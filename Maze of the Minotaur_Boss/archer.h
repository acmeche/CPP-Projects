/*
Author:         Aaron Meche
Program:        Homework 6 - Challenge of the Minotaur Turn-Based RPG - archer.h
Description:    This is the header file for the Archer class, derived from the Character class
Date Due:       03/19/19
Date Created:   03/07/19
Date Last Mod:  03/17/19
Input:          N/A
Process:        N/A
Output:         N/A
Assumptions:    That the character.h and Archer.h files exist and are in the same folder
*/

#pragma once
#include "character.h"
#include "minotaur.h"
#include <iostream>
#include <string>

class Archer : public Character
{
public:
	Archer(string iname);							// Archer constructor
	~Archer();										// Archer destructor
	string getName();								// get function for name
	void setName(string iname);						// set function for name
	void setArcher(bool input);						// set function for archer bool
	bool getArcher();								// get function for archer bool
	bool getTrick();								// get function for trickShot, an archer mechanic used to increase attack damage
	void setTrick(bool);							// set function for trickShot
	void offense(Archer&, Minotaur&, int choice);	// offense function for the mage vs minotaur fight
	void defense(Archer&, Minotaur&, int choice);	// defense function for the mage vs minotaur fight
private:
	string name;
	bool archer;
	bool trickShot;									//bool to determine if trick shot was triggered
};