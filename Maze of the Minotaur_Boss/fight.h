/*
Author:         Aaron Meche
Program:        Homework 6 - Challenge of the Minotaur Turn-Based RPG - fight.h
Description:    This is the header file for the Fight class
Date Due:       03/19/19
Date Created:   03/07/19
Date Last Mod:  03/17/19
Input:          N/A
Process:        N/A
Output:         N/A
Assumptions:    That the character.h, character.cpp, knight.h, knight.cpp, archer.h, archer.cpp, mage.h,
				mage.cpp, minotaur.h, and minotaur.cpp files exist and are in the same folder.
*/

#pragma once
#include "character.h"
#include "knight.h"
#include "archer.h"
#include "mage.h"
#include "minotaur.h"
//#include "troll.h"				Implement these later, minibosses
//#include "gladiator.h"

using namespace std;

class Fight
{
	public:
		void knightBattleMinotaur(Knight &a, Minotaur &b); // function for Knight vs Minotaur
		void archerBattleMinotaur(Archer &a, Minotaur &b); // function for Archer vs Minotaur
		void mageBattleMinotaur(Mage &a, Minotaur &b); // function for Archer vs Minotaur
};