/*
Author:         Aaron Meche
Program:        Homework 6 - Challenge of the Minotaur Turn-Based RPG -charactere.h
Description:    This is the header file for the Character class, used as a base for Minotaur,
				Knight, Archer, and Mage classes
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

using namespace std;

class Character
{
	private:
		string weapon;
		int health;
		int damage;

	public:
		Character();
		~Character();

		string getWeapon();
		int getHealth();
		int getDamage();
		void setWeapon(string);
		void setHealth(int);
		void setDamage(int);

};