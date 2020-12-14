/*
Author:         Aaron Meche
Program:        Homework 3 - Multiplication/Division Computer Assisted Instruction Driver
Description:    This File is the driver for the Computer Assisted Instruction program.
Date Due:       02/12/19
Date Created:   02/06/19
Date Last Mod:  02/11/19
Input:          User will be prompted to enter answers to integer multiplication/division questions.
Process:        The program will print a statement asking for the answer to 5 multiplication and 5 division
				questions. The user will enter one answer for each multiplication statement and also
				the quotient/remainder for each division question. Each answer will be calculated and stored.
Output:         After entering an answer, the program will print a random positive (correct answer) or 
				negative (incorrect answer) text reponse. Each question has a maimum of 3 attemps, after
				which the user will be forced to the next question. At the end, the print function
				will display all the correct answers, the number of wrong answers for each question,
				and the amount of questions that were answered correctly on the first attempt.
Assumptions:    That the cai.h and cai.cpp files exist and are in the same folder.
*/

#include <iostream>						// stream library and custom cai.h header file
#include "cai.h"

using std::cout;						// declarations for namespaces used
using std::cin;
using std::endl;


int main()
{
	CAI cai;							// instantiated CAI object
	cai.multiplicationTest();			// function call to the multiplicationTest function
	cai.divisionTest();					// function call to the divisionTest function
	cai.printResults(cai);				// function call to the printResults function
	system("pause");					// system pause so that the results will stay displayed on the screen
	return 0;
}