/*
Author:         Aaron Meche
Program:        Homework 4 - Word Font Class Implementation File
Description:    This File is the implementation file for the Wordfont class.
Date Due:       02/19/19
Date Created:   01/16/19
Date Last Mod:  02/18/19

Input:          N/A
Process:        N/A
Output:         N/A
Assumptions:    That the wordfont.h file exists and is in the same folder.
*/

#include <iostream>
#include <iomanip>

#include "wordfont.h"

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::right;
/*
Function:		WordFont::WordFont
Description:	Default constructor for the WordFont object. Sets "bold" to false and initializes the MD Vector to 0.
Input:          N/A
Process:        N/A
Output:         N/A
Assumptions:    N/A
*/
WordFont::WordFont()
// using the class initialization list to construct vector as a [MAX_HEIGHT][MAX_WIDTH] mulitdemensional vector, initialized to all 0
	: myMultiVector(MAX_HEIGHT, vector<char>(MAX_WIDTH, 0))
{
	bold = false;
}

/*
Function:		void WordFont::setBold
Description:	Mutator function for the private data member "bold" in the WordFont class. Bold determines
				whether the letter(s) are bold or not in the program.
Input:          The user input value for the bool.
Process:        Changes the bool to true if 1 is sent in as an argument.
Output:         N/A
Assumptions:    N/A
*/

void WordFont::setBold(int b) {
	if (b == 1) {
		bold = true;
	}
}

/*
Function:		void WordFont::<Letter>
Description:	The following functions all generate letters depending on user input. These functions are
				called in the switch statement in the driver.cpp file and generate letters depending on user
				input.
Input:          The user input value for the letter, the symbol used to generate each letter, and the font size.
Process:        Each letter function takes in the same 3 arguments and generates the letter based on those
				arguments (letter position in the char array, symbol, and the font size).
Output:         N/A
Assumptions:    N/A
*/

void WordFont::A(int letter, char symbol, int fontSize)
{
	// calculate offset for this letter within the overall bitmap
	int offset = (fontSize*letter) + (2 * letter);
	int currentRow = 0;
	int rows = 1;
	if (bold) {
		rows = 2;
		for (int i = 0; i < fontSize; i++) 
		{
			myMultiVector[currentRow][i + offset] = symbol;
		}
		currentRow++;
	}
	// draws top of A if not bold, turns into 2nd row if it is bold
	for (int i = 0; i < fontSize; i++) {
		myMultiVector[currentRow][i + offset] = symbol;
	}
	if (!bold)
	{
		currentRow++;
	}

	// calculates how many rows to draw before the next horizontal line and after the horizontal line
	int height = fontSize - 2;
	if (bold) {
		height -= 1;
	}
	int first_height = (height / 2) -1;
	int second_height = (height - first_height) + 1;

	if (bold)
	{
		for (int i = 0; i < first_height+1; i++) 
		{
			myMultiVector[currentRow][0 + offset] = symbol;
			myMultiVector[currentRow][1 + offset] = symbol;
			myMultiVector[currentRow][0 + offset + fontSize - 1] = symbol;
			myMultiVector[currentRow][0 + offset + fontSize - 2] = symbol;
			currentRow++;
		}
	}
	else 
	{
		for (int i = 0; i < first_height; i++) 
		{
			myMultiVector[currentRow][0 + offset] = symbol;
			myMultiVector[currentRow][0 + offset + fontSize - 1] = symbol;
			currentRow++;
		}
	}


	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < fontSize; j++) {
			myMultiVector[currentRow][j + offset] = symbol;
		}
		currentRow++;
	}

	if (bold)
	{
		for (int i = 0; i < second_height - 2; i++) {
			myMultiVector[currentRow][0 + offset] = symbol;
			myMultiVector[currentRow][1 + offset] = symbol;
			myMultiVector[currentRow][0 + offset + fontSize - 1] = symbol;
			myMultiVector[currentRow][0 + offset + fontSize - 2] = symbol;
			currentRow++;
		}
	}
	else
	{	
		for (int i = 0; i < second_height-1; i++) 
		{
			myMultiVector[currentRow][0 + offset] = symbol;
			myMultiVector[currentRow][0 + offset + fontSize - 1] = symbol;
			currentRow++;
		}
	}

}

void WordFont::B(int letter, char symbol, int fontSize)
{
	// calculate offset for this letter within the overall bitmap
	int offset = (fontSize*letter) + (2 * letter);
	int currentRow = 0;

	int rows = 1;
	if (bold) {
		rows = 2;
		for (int i = 0; i < fontSize; i++) {
			myMultiVector[currentRow][i + offset] = symbol;
		}
		currentRow++;
	}

	// draws top of B
	for (int i = 0; i < fontSize; i++) {
		myMultiVector[currentRow][i + offset] = symbol;
	}
	if (!bold)
	{
		currentRow++;
	}

	// calculates how many rows to draw before the next horizontal line and after the horizontal line
	int height = fontSize - 2;
	int first_height = (height / 2) - 1;
	int second_height = height - first_height;
	
	if (bold) {
		height -= 1;
		for (int i = 0; i < first_height; i++) {
			myMultiVector[currentRow][0 + offset] = symbol;
			myMultiVector[currentRow][1 + offset] = symbol;
			myMultiVector[currentRow][0 + offset + fontSize - 1] = symbol;
			myMultiVector[currentRow][0 + offset + fontSize - 2] = symbol;
			currentRow++;
		}
	}

	else
	{
		for (int i = 0; i < first_height; i++) {
			myMultiVector[currentRow][0 + offset] = symbol;
			myMultiVector[currentRow][0 + offset + fontSize - 1] = symbol;
			currentRow++;
		}
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < fontSize; j++) {
			myMultiVector[currentRow][j + offset] = symbol;
		}
		currentRow++;
	}
	if (bold)
	{
		for (int i = 0; i < second_height - 3; i++) {
			myMultiVector[currentRow][0 + offset] = symbol;
			myMultiVector[currentRow][1 + offset] = symbol;
			myMultiVector[currentRow][0 + offset + fontSize - 1] = symbol;
			myMultiVector[currentRow][0 + offset + fontSize - 2] = symbol;
			currentRow++;
		}

		for (int i = 0; i < fontSize; i++) {
			myMultiVector[currentRow][i + offset] = symbol;
		}
		currentRow++;
		for (int i = 0; i < fontSize; i++) {
			myMultiVector[currentRow][i + offset] = symbol;
		}
	}
	
	else
	{
		for (int i = 0; i < second_height - 1; i++) 
		{
			myMultiVector[currentRow][0 + offset] = symbol;
			myMultiVector[currentRow][0 + offset + fontSize - 1] = symbol;
			currentRow++;
		}

		for (int i = 0; i < fontSize; i++) {
			myMultiVector[currentRow][i + offset] = symbol;
		}
	}

}

void WordFont::O(int letter, char symbol, int fontSize)
{
	// calculate offset for this letter within the overall bitmap
	int offset = (fontSize*letter) + (2 * letter);
	int currentRow = 0;

	int rows = 1;
	if (bold) {
		rows = 2;
	}

	// draws top of O
	for (int i = 0; i < fontSize; i++) {
		myMultiVector[currentRow][i + offset] = symbol;
	}
	currentRow++;
	if (bold)
	{
		for (int i = 0; i < fontSize; i++) {
			myMultiVector[currentRow][i + offset] = symbol;
		}
		currentRow++;
	}
	// calculates how many rows to draw before the next horizontal line and after the horizontal line
	int height = fontSize - 2;
	if (bold) {
		height -= 2;
		for (int i = 0; i < height; i++) {
			myMultiVector[currentRow][0 + offset] = symbol;
			myMultiVector[currentRow][1 + offset] = symbol;
			myMultiVector[currentRow][0 + offset + fontSize - 1] = symbol;
			myMultiVector[currentRow][0 + offset + fontSize - 2] = symbol;
			currentRow++;
		}
	}
	else
	{ 
		for (int i = 0; i < height; i++) {
			myMultiVector[currentRow][0 + offset] = symbol;
			myMultiVector[currentRow][0 + offset + fontSize - 1] = symbol;
			currentRow++;
		}
	}


	for (int i = 0; i < rows - 1; i++) {
		for (int j = 0; j < fontSize; j++) {
			myMultiVector[currentRow][j + offset] = symbol;
		}
		currentRow++;
	}

	for (int i = 0; i < fontSize; i++) {
		myMultiVector[currentRow][i + offset] = symbol;
	}
}

void WordFont::C(int letter, char symbol, int fontSize) // Bold needs to be fixed
{
	// calculate offset for this letter within the overall bitmap
	int offset = (fontSize*letter) + (2 * letter);
	int currentRow = 0;

	int rows = 1;
	if (bold) {
		rows = 2;
		// draws top of C
		for (int i = 0; i < fontSize; i++) {
			myMultiVector[currentRow][i + offset] = symbol;
		}
		currentRow++;
	}

	// draws top of C
	for (int i = 0; i < fontSize; i++) {
		myMultiVector[currentRow][i + offset] = symbol;
	}
	currentRow++;

	// calculates how many rows to draw before the next horizontal line and after the horizontal line
	int height = fontSize - 2;

	if (bold) {
		height -= 2;
		for (int i = 0; i < height; i++) {
			myMultiVector[currentRow][0 + offset] = symbol;
			myMultiVector[currentRow][1 + offset] = symbol;
			currentRow++;
		}
	}

	else
	{
		for (int i = 0; i < height; i++) {
			myMultiVector[currentRow][0 + offset] = symbol;
			currentRow++;
		}
	}

	for (int i = 0; i < rows - 1; i++) {
		for (int j = 0; j < fontSize; j++) {
			myMultiVector[currentRow][j + offset] = symbol;
		}
		currentRow++;
	}

	for (int i = 0; i < fontSize; i++) {
		myMultiVector[currentRow][i + offset] = symbol;
	}
}

void WordFont::D(int letter, char symbol, int fontSize) // Bold needs to be fixed
{
	// calculate offset for this letter within the overall bitmap
	int offset = (fontSize*letter) + (2 * letter);
	int currentRow = 0;

	int rows = 1;
	if (bold) 
	{
		rows = 2;
	}

	// draws top of D
	for (int i = 0; i < fontSize-1; i++) 
	{
		myMultiVector[currentRow][i + offset] = symbol;
	}
	currentRow++;

	if (bold)
	{
		for (int i = 0; i < fontSize; i++)
		{
			myMultiVector[currentRow][i + offset] = symbol;
		}
		currentRow++;
	}

	// calculates how many rows to draw before the next horizontal line and after the horizontal line
	int height = fontSize - 2;
	if (bold) {
		height -= 2;
		for (int i = 0; i < height; i++) {
			myMultiVector[currentRow][0 + offset] = symbol;
			myMultiVector[currentRow][1 + offset] = symbol;
			myMultiVector[currentRow][0 + offset + fontSize - 1] = symbol;
			myMultiVector[currentRow][0 + offset + fontSize - 2] = symbol;
			currentRow++;
		}
	}

	else
	{
		for (int i = 0; i < height; i++) 
		{
			myMultiVector[currentRow][0 + offset] = symbol;
			myMultiVector[currentRow][0 + offset + fontSize - 1] = symbol;
			currentRow++;
		}
	}


	for (int i = 0; i < rows - 1; i++) 
	{
		for (int j = 0; j < fontSize; j++) 
		{
			myMultiVector[currentRow][j + offset] = symbol;
		}
		currentRow++;
	}

	// draws bottom of D
	for (int i = 0; i < fontSize-1; i++) 
	{
		myMultiVector[currentRow][i + offset] = symbol;
	}
}

void WordFont::T(int letter, char symbol, int fontSize) // needs bold
{
	// calculate offset for this letter within the overall bitmap
	int offset = (fontSize*letter) + (2 * letter);
	int currentRow = 0;

	int rows = 1;
	if (bold) 
	{
		for (int i = 0; i < fontSize; i++) 
		{
			myMultiVector[currentRow][i + offset] = symbol;
		}
		currentRow++;
	}

	// draws top of T
	for (int i = 0; i < fontSize; i++) 
	{
		myMultiVector[currentRow][i + offset] = symbol;
	}
	currentRow++;

	if (bold)
	{
		int width = (fontSize - 2) / 2;

		for (int i = 0; i < fontSize - 2; i++) 
		{
			myMultiVector[currentRow][width + offset] = symbol;
			myMultiVector[currentRow][width + offset+1] = symbol;
			currentRow++;
		}
	}
	else
	{
		// calculates how many rows to draw before the next horizontal line and after the horizontal line
		int width = (fontSize - 2) / 2;

		for (int i = 0; i < fontSize - 1; i++) 
		{
			myMultiVector[currentRow][width + offset] = symbol;
			currentRow++;
		}
	}
}

void WordFont::I(int letter, char symbol, int fontSize) // needs bold
{
	// calculate offset for this letter within the overall bitmap
	int offset = (fontSize*letter) + (2 * letter);
	int currentRow = 0;

	int width = 0;

	if (bold) {
		// draws top of I
		for (int i = 0; i < fontSize; i++) 
		{
			myMultiVector[currentRow][i + offset] = symbol;
		}
		currentRow++;
	}

	// draws top of T
	for (int i = 0; i < fontSize; i++) 
	{
		myMultiVector[currentRow][i + offset] = symbol;
	}

	if (!bold)
	{
		currentRow++;
	}
	// calculates how many rows to draw before the next horizontal line and after the horizontal line
	width = (fontSize - 2) / 2;
	if (bold)
	{
		for (int i = 0; i < fontSize - 2; i++) 
		{
			myMultiVector[currentRow][width + offset] = symbol;
			myMultiVector[currentRow][width + offset+1] = symbol;
			currentRow++;
		}

		for (int i = 0; i < fontSize; i++) 
		{
			myMultiVector[currentRow-1][i + offset] = symbol;
			myMultiVector[currentRow][i + offset] = symbol;
		}
	}
	else
	{
		for (int i = 0; i < fontSize - 2; i++) 
		{
			myMultiVector[currentRow][width + offset] = symbol;
			currentRow++;
		}
		for (int i = 0; i < fontSize; i++) 
		{
			myMultiVector[currentRow][i + offset] = symbol;
		}
	}

}

void WordFont::H(int letter, char symbol, int fontSize)
{
	// calculate offset for this letter within the overall bitmap
	int offset = (fontSize*letter) + (2 * letter);
	int currentRow = 0;

	int rows = 1;
	if (bold) {
		rows = 2;
	}
	
	// calculates how many rows to draw before the next horizontal line and after the horizontal line
	int height = fontSize - 2;
	int first_height = height / 2;
	int second_height = height - first_height;

	if (bold) 
	{
		height -= 1;
		for (int i = 0; i < first_height; i++) 
		{
			myMultiVector[currentRow][0 + offset] = symbol;
			myMultiVector[currentRow][1 + offset] = symbol;
			myMultiVector[currentRow][0 + offset + fontSize - 1] = symbol;
			myMultiVector[currentRow][0 + offset + fontSize - 2] = symbol;
			currentRow++;
		}
	}

	else
	{
		for (int i = 0; i < first_height; i++) 
		{
			myMultiVector[currentRow][0 + offset] = symbol;
			myMultiVector[currentRow][0 + offset + fontSize - 1] = symbol;
			currentRow++;
		}
	}


	for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < fontSize; j++) 
		{
			myMultiVector[currentRow][j + offset] = symbol;
		}
		currentRow++;
	}

	if (bold)
	{
		for (int i = 0; i < second_height; i++) 
		{
			myMultiVector[currentRow][0 + offset] = symbol;
			myMultiVector[currentRow][1 + offset] = symbol;
			myMultiVector[currentRow][0 + offset + fontSize - 1] = symbol;
			myMultiVector[currentRow][0 + offset + fontSize - 2] = symbol;
			currentRow++;
		}
	}
	else
	{
		for (int i = 0; i < second_height +1; i++) 
		{
			myMultiVector[currentRow][0 + offset] = symbol;
			myMultiVector[currentRow][0 + offset + fontSize-1] = symbol;
			currentRow++;
		}
	}

}

void WordFont::L(int letter, char symbol, int fontSize) // Bold needs to be fixed
{
	// calculate offset for this letter within the overall bitmap
	int offset = (fontSize*letter) + (2 * letter);
	int currentRow = 0;

	int rows = 1;
	if (bold) 
	{
		rows = 2;
	}

	// calculates how many rows to draw before the next horizontal line and after the horizontal line
	int height = fontSize - 1;
	if (bold) 
	{
		height -= 1;

		for (int i = 0; i < height; i++) {
			myMultiVector[currentRow][0 + offset] = symbol;
			myMultiVector[currentRow][1 + offset] = symbol;
			currentRow++;
		}
	}
	else
	{
		for (int i = 0; i < height; i++) 
		{
			myMultiVector[currentRow][0 + offset] = symbol;
			currentRow++;
		}
	}


		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < fontSize; j++) {
				myMultiVector[currentRow][j + offset] = symbol;
			}
			currentRow++;
		}

}

void WordFont::P(int letter, char symbol, int fontSize)
{
	// calculate offset for this letter within the overall bitmap
	int offset = (fontSize*letter) + (2 * letter);
	int currentRow = 0;

	int rows = 1;

	if (bold) 
	{
		rows = 2;
		for (int i = 0; i < fontSize; i++) 
		{
			myMultiVector[currentRow][i + offset] = symbol;
		}
		currentRow++;
	}

	// draws top of P
	for (int i = 0; i < fontSize; i++) 
	{
		myMultiVector[currentRow][i + offset] = symbol;
	}

	if (!bold)
	{
		currentRow++;
	}


	// calculates how many rows to draw before the next horizontal line and after the horizontal line
	int height = fontSize - 2;
	int first_height = (height / 2) - 1;
	int second_height = (height - first_height) + 1;

	if (bold) 
	{
		for (int i = 0; i < first_height; i++) {
			myMultiVector[currentRow][0 + offset] = symbol;
			myMultiVector[currentRow][1 + offset] = symbol;
			myMultiVector[currentRow][0 + offset + fontSize - 1] = symbol;
			myMultiVector[currentRow][-1 + offset + fontSize - 1] = symbol;
			currentRow++;
		}

	}

	else
	{ 
		for (int i = 0; i < first_height; i++) 
		{
			myMultiVector[currentRow][0 + offset] = symbol;
			myMultiVector[currentRow][0 + offset + fontSize - 1] = symbol;
			currentRow++;
		}
	}

	for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < fontSize; j++) 
		{
			myMultiVector[currentRow][j + offset] = symbol;
		}
		currentRow++;
	}

	if (bold)
	{
		for (int i = 0; i < second_height - 2; i++) 
		{
			myMultiVector[currentRow][0 + offset] = symbol;
			myMultiVector[currentRow][1 + offset] = symbol;
			currentRow++;
		}
	}

	else
	{
		for (int i = 0; i < second_height - 1; i++) 
		{
			myMultiVector[currentRow][0 + offset] = symbol;
			currentRow++;
		}
	}
}

void WordFont::F(int letter, char symbol, int fontSize)
{
	// calculate offset for this letter within the overall bitmap
	int offset = (fontSize*letter) + (2 * letter);
	int currentRow = 0;

	int rows = 1;
	if (bold) 
	{
		rows = 2;
		for (int i = 0; i < fontSize; i++) 
		{
			myMultiVector[currentRow][i + offset] = symbol;
		}
		currentRow++;
	}

	// draws top of F
	for (int i = 0; i < fontSize; i++) 
	{
		myMultiVector[currentRow][i + offset] = symbol;
	}

	if (!bold)
	{
		currentRow++;
	}

	// calculates how many rows to draw before the next horizontal line and after the horizontal line
	int height = fontSize - 2;
	if (bold) 
	{
		height -= 1;
	}
	int first_height = (height / 2)-1;
	int second_height = (height - first_height) + 1;

	if (bold)
	{
		for (int i = 0; i < first_height + 1; i++)
		{
			myMultiVector[currentRow][0 + offset] = symbol;
			myMultiVector[currentRow][1 + offset] = symbol;
			currentRow++;
		}
	}
	else
	{
		for (int i = 0; i < first_height; i++)
		{
			myMultiVector[currentRow][0 + offset] = symbol;
			currentRow++;
		}
	}

	for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < fontSize; j++) 
		{
			myMultiVector[currentRow][j + offset] = symbol;
		}
		currentRow++;
	}

	if (bold)
	{
		for (int i = 0; i < second_height - 2; i++) 
		{
			myMultiVector[currentRow][0 + offset] = symbol;
			myMultiVector[currentRow][1 + offset] = symbol;
			currentRow++;
		}
	}
	else
	{
		for (int i = 0; i < second_height - 1; i++) {
			myMultiVector[currentRow][0 + offset] = symbol;
			currentRow++;
		}
	}
}

void WordFont::E(int letter, char symbol, int fontSize)
{
	// calculate offset for this letter within the overall bitmap
	int offset = (fontSize*letter) + (2 * letter);
	int currentRow = 0;

	int rows = 1;
	if (bold) 
	{
		rows = 2;
	}

	// draws top of E
	if (bold)
	{
		for (int i = 0; i < fontSize; i++) 
		{
			myMultiVector[currentRow][i + offset] = symbol;
		}
		currentRow++;
	}

	for (int i = 0; i < fontSize; i++) 
	{
		myMultiVector[currentRow][i + offset] = symbol;
	}
	currentRow++;

	// calculates how many rows to draw before the next horizontal line and after the horizontal line
	int height = fontSize - 2;
	if (bold) 
	{
		height -= 1;
	}

	int first_height = (height / 2) -1;
	int second_height = (height - first_height) + 1;
	
	if (bold)
	{
		for (int i = 0; i < first_height; i++)
		{
			myMultiVector[currentRow][0 + offset] = symbol;
			myMultiVector[currentRow][1 + offset] = symbol;
			currentRow++;
		}
	}
	else
	{
		for (int i = 0; i < first_height; i++) 
		{
			myMultiVector[currentRow][0 + offset] = symbol;
			currentRow++;
		}
	}

	for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < fontSize; j++) 
		{
			myMultiVector[currentRow][j + offset] = symbol;
		}
		currentRow++;
	}

	if (bold)
	{
		for (int i = 0; i < second_height - 3; i++) 
		{
			myMultiVector[currentRow][0 + offset] = symbol;
			myMultiVector[currentRow][1 + offset] = symbol;
			currentRow++;
		}
	}
	else
	{
		for (int i = 0; i < second_height - 1; i++) 
		{
			myMultiVector[currentRow][0 + offset] = symbol;
			currentRow++;
		}
	}
	
	for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < fontSize; j++) {
			myMultiVector[currentRow-1][j + offset] = symbol;
		}
		currentRow++;
	}
}

void WordFont::U(int letter, char symbol, int fontSize)
{
	// calculate offset for this letter within the overall bitmap
	int offset = (fontSize*letter) + (2 * letter);
	int currentRow = 0;

	int rows = 1;
	if (bold) 
	{
		rows = 2;
	}

	// calculates how many rows to draw before the next horizontal line and after the horizontal line
	int height = fontSize - 1;
	if (bold) {
		height -= 1;
		for (int i = 0; i < height; i++) 
		{
			myMultiVector[currentRow][0 + offset] = symbol;
			myMultiVector[currentRow][1 + offset] = symbol;
			myMultiVector[currentRow][0 + offset + fontSize - 1] = symbol;
			myMultiVector[currentRow][0 + offset + fontSize - 2] = symbol;
			currentRow++;
		}
	}
	else
	{
		for (int i = 0; i < height; i++) 
		{
			myMultiVector[currentRow][0 + offset] = symbol;
			myMultiVector[currentRow][0 + offset + fontSize - 1] = symbol;
			currentRow++;
		}
	}

	for (int i = 0; i < rows - 1; i++) 
	{
		for (int j = 0; j < fontSize; j++) 
		{
			myMultiVector[currentRow][j + offset] = symbol;
		}
		currentRow++;
	}

	for (int i = 0; i < fontSize; i++) 
	{
		myMultiVector[currentRow][i + offset] = symbol;
	}
}

void WordFont::M(int letter, char symbol, int fontSize)
{
	// calculate offset for this letter within the overall bitmap
	int offset = (fontSize*letter) + (2 * letter);
	int currentRow = 0;

	if (bold)
	{
		for (int i = 0; i < fontSize; i++) 
		{
			myMultiVector[currentRow][i + offset] = symbol;
		}
		currentRow++;
	}

	// draws top of M
	for (int i = 0; i < fontSize; i++) 
	{
		myMultiVector[currentRow][i + offset] = symbol;
	}

	if (!bold)
	{
		currentRow++;
	}

	if (bold) 
	{
		int mid_col = fontSize / 2;

		for (int i = 0; i < fontSize - 1; i++) 
		{
			myMultiVector[currentRow][0 + offset] = symbol;
			myMultiVector[currentRow][1 + offset] = symbol;
			myMultiVector[currentRow][0 + offset + mid_col] = symbol;
			myMultiVector[currentRow][-1 + offset + mid_col] = symbol;
			myMultiVector[currentRow][0 + offset + fontSize - 1] = symbol;
			myMultiVector[currentRow][0 + offset + fontSize - 2] = symbol;
			currentRow++;
		}
	}
	else
	{
		int mid_col = fontSize / 2;

		for (int i = 0; i < fontSize - 1; i++) 
		{
			myMultiVector[currentRow][0 + offset] = symbol;
			myMultiVector[currentRow][0 + offset + mid_col] = symbol;
			myMultiVector[currentRow][0 + offset + fontSize - 1] = symbol;
			currentRow++;
		}
	}

}

void WordFont::S(int letter, char symbol, int fontSize)
{
	// calculate offset for this letter within the overall bitmap
	int offset = (fontSize*letter) + (2 * letter);
	int currentRow = 0;

	int rows = 1;
	if (bold) 
	{
		rows = 2;
		for (int i = 0; i < fontSize; i++) 
		{
			myMultiVector[currentRow][i + offset] = symbol;
		}
		currentRow++;
	}

	// draws top of B
	for (int i = 0; i < fontSize; i++) 
	{
		myMultiVector[currentRow][i + offset] = symbol;
	}

	if (!bold)
	{
		currentRow++;
	}

	// calculates how many rows to draw before the next horizontal line and after the horizontal line
	int height = fontSize - 2;
	if (bold) 
	{
		height -= 1;
	}

	int first_height = (height / 2)-1;
	int second_height = height - first_height;

	if (bold) 
	{
		for (int i = 0; i < first_height+1; i++) 
		{
			myMultiVector[currentRow][0 + offset] = symbol;
			myMultiVector[currentRow][1 + offset] = symbol;
			currentRow++;
		}
		for (int i = 0; i < rows; i++) 
		{
			for (int j = 0; j < fontSize; j++) 
			{
				myMultiVector[currentRow][j + offset] = symbol;
			}
			currentRow++;
		}

		for (int i = 0; i < second_height - 3; i++) 
		{
			myMultiVector[currentRow][0 + offset + fontSize - 1] = symbol;
			myMultiVector[currentRow][0 + offset + fontSize - 2] = symbol;
			currentRow++;
		}

		for (int i = 0; i < fontSize; i++) 
		{
			myMultiVector[currentRow][i + offset] = symbol;
		}
		currentRow++;

		for (int i = 0; i < fontSize; i++) 
		{
			myMultiVector[currentRow][i + offset] = symbol;
		}
	}

	else
	{
		for (int i = 0; i < first_height; i++) 
		{
			myMultiVector[currentRow][0 + offset] = symbol;
			currentRow++;
		}
		for (int i = 0; i < rows; i++) 
		{
			for (int j = 0; j < fontSize; j++) 
			{
				myMultiVector[currentRow][j + offset] = symbol;
			}
			currentRow++;
		}
		for (int i = 0; i < second_height - 1; i++) 
		{
			myMultiVector[currentRow][0 + offset + fontSize - 1] = symbol;
			currentRow++;
		}

		for (int i = 0; i < fontSize; i++) 
		{
			myMultiVector[currentRow][i + offset] = symbol;
		}
	}


}

/*
Function:		void WordFont::Print
Description:	Void function that prints out the values stored in the vector given the value is not 0.
Input:          N/A
Process:        Checks each value in the vector for values != 0
Output:         Prints the value in every position of the array that != 0
Assumptions:    N/A
*/

void WordFont::Print()
{
	for (int rows = 0; rows < MAX_HEIGHT; rows++)
	{
		for (int cols = 0; cols < MAX_WIDTH; cols++)
		{
			if (myMultiVector[rows][cols] != 0) {
				cout << myMultiVector[rows][cols];
			}
			else {
				cout << " ";
			}

		}
		// put a new line before printing the next row of data
		cout << endl;
	}
}

