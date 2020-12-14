/*
Author:         Aaron Meche
Program:        Homework 6 - Challenge of the Minotaur Turn-Based RPG - knight.h
Description:    This is the header file for the Knight class, derived from the Character class
Date Due:       03/19/19
Date Created:   03/07/19
Date Last Mod:  03/17/19
Input:          N/A
Process:        N/A
Output:         N/A
Assumptions:    That the character.h and knight.h files exist and are in the same folder
*/

#pragma once
#include "character.h"
#include "minotaur.h"
#include <iostream>
#include <string>

class Knight : public Character
{
	public:
		Knight(string iname);							// Knight constructor
		~Knight();										// Knight destructor
		string getName();								// get function for name
		void setName(string iname);						// set function for name
		void setKnight(bool input);						// set function for knight bool
		bool getKnight();								// get function for knight bool
		void offense(Knight&, Minotaur&, int choice);	// offense function for the knight vs minotaur fight
		void defense(Knight&, Minotaur&, int choice);	// defense function for the knight vs minotaur fight

	private:
		string name;
		bool knight;
};