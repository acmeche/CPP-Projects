/*
Author:         Aaron Meche
Program:        Homework 4 - Word Font Class Driver
Description:    This File is the driver for the Wordfont class. User inputs a word/letters, a symbol, a font size, and a
				bold yes/no switch, and the program prints the letters out using that symbol.
Date Due:       02/19/19
Date Created:   01/16/19
Date Last Mod:  02/18/19

Input:          User inputs a word or combination of letters, a symbol, a font size, and a 1/0 for boldening
				the word or not.
Process:        The program takes the letter(s) input by the user, the symbol, the font size, and the bold switch
				and generates the letter(s) as the input symbols.
Output:         The program will print the letters input by the user as the symbols that were input by the user.
Assumptions:    That the wordfont.h and wordfont.cpp files exist and are in the same folder.
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "wordfont.h"

using namespace std;

int main()
{
	WordFont wf;
	char word[MAX_LETTERS];
	int fontSize;
	int bold;
	char pixelChar;

	cout << "Enter a word (" << MAX_LETTERS << " letters or less), using a, e, i, o, u, t, p, d, f, h, m, l, c, s, b: ";
	cin >> word;
	cout << "Enter the pixel character you want to draw (The program will draw the word using your chosen character): ";
	cin >> pixelChar;
	cout << "Enter font size (8-12): ";
	cin >> fontSize;
	cout << "Bold (0=NO 1=YES): ";
	cin >> bold;

	wf.setBold(bold);

	int i = 0;
	while (word[i] != '\0') {
		char c = tolower(word[i]);
		switch (c) {
		case 'a':
			wf.A(i, pixelChar, fontSize);
			break;
		case 'b':
			wf.B(i, pixelChar, fontSize);
			break;
		case 'c':
			wf.C(i, pixelChar, fontSize);
			break;
		case 'd':
			wf.D(i, pixelChar, fontSize);
			break;
		case 'e':
			wf.E(i, pixelChar, fontSize);
			break;
		case 'f':
			wf.F(i, pixelChar, fontSize);
			break;
		case 'h':
			wf.H(i, pixelChar, fontSize);
			break;
		case 'i':
			wf.I(i, pixelChar, fontSize);
			break;
		case 'l':
			wf.L(i, pixelChar, fontSize);
			break;
		case 'm':
			wf.M(i, pixelChar, fontSize);
			break;
		case 'o':
			wf.O(i, pixelChar, fontSize);
			break;
		case 'p':
			wf.P(i, pixelChar, fontSize);
			break;
		case 's':
			wf.S(i, pixelChar, fontSize);
			break;
		case 't':
			wf.T(i, pixelChar, fontSize);
			break;
		case 'u':
			wf.U(i, pixelChar, fontSize);
			break;
		default:
			break;
		}
		i++;
	}

	wf.Print();
	system("pause");
}