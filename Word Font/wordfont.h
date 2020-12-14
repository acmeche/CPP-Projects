/*
Author:         Aaron Meche
Program:        Homework 4 - Word Font Class Header File
Description:    This File is the header file for the Wordfont class.
Date Due:       02/19/19
Date Created:   01/16/19
Date Last Mod:  02/18/19

Input:          N/A
Process:        N/A
Output:         N/A
Assumptions:    That the wordfont.cpp file exists and is in the same folder.
*/

#pragma once

#include <vector>

#define MAX_WIDTH   110									// max width is the height * letters + empty spaces
#define MAX_HEIGHT  12									// max font size
#define MAX_LETTERS 8									// max amount of letters

using std::vector;

class WordFont
{
public:
	WordFont();
	void Print();										// function to print the matrix
	void setBold(int b);								// function to set the bold bool input by user, determines if word will be bold or not
	void A(int letter, char symbol, int fontSize);		// all of the following functions generate their corresponding letters
	void B(int letter, char symbol, int fontSize);
	void O(int letter, char symbol, int fontSize);
	void C(int letter, char symbol, int fontSize);
	void D(int letter, char symbol, int fontSize);
	void T(int letter, char symbol, int fontSize);
	void I(int letter, char symbol, int fontSize);
	void H(int letter, char symbol, int fontSize);
	void L(int letter, char symbol, int fontSize);
	void P(int letter, char symbol, int fontSize);
	void F(int letter, char symbol, int fontSize);
	void E(int letter, char symbol, int fontSize);
	void U(int letter, char symbol, int fontSize);
	void M(int letter, char symbol, int fontSize);
	void S(int letter, char symbol, int fontSize);

private:
														// vector declaration
	vector<vector<char>> myMultiVector;
	bool bold;
};
