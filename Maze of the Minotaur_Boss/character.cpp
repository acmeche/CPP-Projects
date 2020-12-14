/*
Author:         Aaron Meche
Program:        Homework 6 - Challenge of the Minotaur Turn-Based RPG - character.cpp
Description:    This is the implementation file for the Character class
Date Due:       03/19/19
Date Created:   03/07/19
Date Last Mod:  03/17/19
Input:          N/A
Process:        N/A
Output:         N/A
Assumptions:    That the character.h file exists and is in the same folder.
*/

#include "character.h"
#include <iostream>
#include <string>

using namespace std;

Character::Character()
{
	setWeapon("Unarmed");
	setHealth(0);
	setDamage(0);
}

Character::~Character()
{

}

string Character::getWeapon()
{
	return weapon;
}

int Character::getDamage()
{
	return damage;
}

int Character::getHealth()
{
	return health;
}

void Character::setWeapon(string iweapon)
{
	weapon = iweapon;
}

void Character::setDamage(int idamage)
{
	damage = idamage;
}

void Character::setHealth(int ihealth)
{
	health = ihealth;
}