/*
Author:         Aaron Meche
Program:        Homework 6 - Challenge of the Minotaur Turn-Based RPG - minotaur.h
Description:    This is the header file for the Minotaur class, derived from the Character class
Date Due:       03/19/19
Date Created:   03/07/19
Date Last Mod:  03/17/19
Input:          N/A
Process:        N/A
Output:         N/A
Assumptions:    That the character.h file exists and is in the same folder
*/

#pragma once
#include "character.h"
#include <iostream>
#include <string>

class Minotaur : public Character
{
public:
	Minotaur();							// Constructor
	~Minotaur();						// Destructor
	string getName();					// get function for the name
	void setName(string iname);			// set function for the name
	void attack(Minotaur& a);			// function that determines which attack the Minotaur will use
	int getCooldown();					// get function for the cooldown, which regulates how often he can use his Ultimate ability
	void setCooldown(int set);			// set function for cooldown
	int getAttack();					// returns the attack value that is used to determine which attack the minotaur will use
	void setAttack(int input);			// set function for the attack value

private:
	string name;						// string for the enemy name
	int cooldown;						// int that stores the cooldown calue
	int attacknum;						// int that stores the attack value
};