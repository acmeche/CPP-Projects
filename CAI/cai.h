/*
Author:         Aaron Meche
Program:        Homework 3 - Multiplication/Division Computer Assisted Instruction Header File
Description:    This File is the header file for the Computer Assisted Instruction class and its data members/functions.
Date Due:       02/12/19
Date Created:   02/06/19
Date Last Mod:  02/11/19
Input:          N/A
Process:        N/A
Output:         N/A
Assumptions:    That cai.cpp exists and holds the definitions for these function
*/

#pragma once
class CAI
{
private:
	int incorrectCount[10];							// a counter that is incremented every time a wrong answer is used, implemented as an array so user can see how many incorrect answers per question
	int correctCount;								// a counter that is incremented every time a correct answer is given with 0 incorrect answers, used to get a total of completely correct answers 
	int correctAnswer[10];							// array to store the answers for each math problem
	int remainderArray[10];							// array to store remainder for the divide questions

public:
	CAI();											// default constructor
	int getIncorrect(int position);					// get/set functions for all the private data members
	int getCorrect();
	int getAnswer(int position);
	int getRemainder(int position);
	void setIncorrect(int position);
	void setCorrect();
	void setAnswer(int position, int answer);
	void setRemainder(int position, int answer);

	void multiplicationTest();						// header for the muliplication test function
	void divisionTest();							// header for the division test function
	void correctResponse();							// header for the correct/incorrect response switch statements
	void incorrectResponse();
	void printResults(CAI);							// header for the print function
};