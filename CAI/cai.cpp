/*
Author:         Aaron Meche
Program:        Homework 3 - Multiplication/Division Computer Assisted Instruction Implementation File
Description:    This file holds the function definitions for the CAI program.
Date Due:       02/12/19
Date Created:   02/06/19
Date Last Mod:  02/11/19
Input:          N/A
Process:        N/A
Output:         N/A
Assumptions:    That cai.h exists.
*/

#include <iostream>
#include "cai.h"

using std::cout;
using std::cin;
using std::endl;

/*
Function:		CAI::CAI
Description:	CAI default constructor. It initializes all private data members to 0 when CAI object is created
Input:          N/A
Process:        N/A
Output:         N/A
Assumptions:    N/A
*/

CAI::CAI()
{
	for(int i = 0; i < 10; i++)
	{
		incorrectCount[i] = 0;
		correctAnswer[i] = 0;
		remainderArray[i] = 0;
	}
	correctCount = 0;
}

/*
Function:		int CAI::getIncorrect(int position)
Description:	Gets the incorrect counter data member, used later in the print function to display incorrect answer attempts for each question
Input:          Position in data member array
Process:        N/A
Output:         Returns the count at the input position
Assumptions:    N/A
*/

int CAI::getIncorrect(int position)
{
	return incorrectCount[position];
}

/*
Function:		int CAI::getCorrect()
Description:	Gets the correct counter data member, used later in the print function to display correct answer attempts for each question
Input:          N/A
Process:        N/A
Output:         Returns the total count of corret answers stored in correctCount
Assumptions:    N/A
*/

int CAI::getCorrect()
{
	return correctCount;
}

/*
Function:		int CAI::getAnswer(int position)
Description:	Gets the answer for each math question from the correctAnswer array
Input:          Position in data member array
Process:        N/A
Output:         Returns the answer stored in correctAnswer at the input position
Assumptions:    N/A
*/

int CAI::getAnswer(int position)
{
	return correctAnswer[position];
}

/*
Function:		int CAI::getRemainder(int position)
Description:	Gets the remainder value, from the division problems, stored in the remainderArray at the input position
Input:          Position in the data member array
Process:        N/A
Output:         Returns the remainder result from the division questions stored in the remainderArray at the input position
Assumptions:    N/A
*/

int CAI::getRemainder(int position)
{
	return remainderArray[position];
}

/*
Function:		void CAI::setIncorrect(int position)
Description:	Set function to increment the incorrect answer count data member, incorrectCount, used in the print function
Input:          Position in the data member array
Process:        Increments the counter, returns nothing
Output:         N/A
Assumptions:    N/A
*/

void CAI::setIncorrect(int position)
{
	incorrectCount[position]++;
}

/*
Function:		void CAI::setCorrect()
Description:	Set function to increment the correct answer count data member, correctCount, used in the print function to show
				how many answers were correct with 0 incorrect answers.
Input:          N/A
Process:        Increments the counter, returns nothing
Output:         N/A
Assumptions:    N/A
*/

void CAI::setCorrect()
{
	correctCount++;
}

/*
Function:		void CAI::setIncorrect(int position)
Description:	Set function to store the answer to each math question into an array at the int input position, used later for printing
Input:          Position in the data member array and the answer to be stored in the correctAnswer array
Process:        Stores the answer in the correctAnswer array at the input position
Output:         N/A
Assumptions:    N/A
*/

void CAI::setAnswer(int position, int answer)
{
	correctAnswer[position] = answer;
}

/*
Function:		void CAI::setRemainder
Description:	Set function to store the remainder from the division questions into the remainderArray, used laer for printing
Input:          Position in the data member array and the remainder from the division problem to be stored ni the remainderArray
Process:        Stores the remainder in the remainderArray at the input position
Output:         N/A
Assumptions:    N/A
*/

void CAI::setRemainder(int position, int remainder)
{
	remainderArray[position] = remainder;
}

/*
Function:		void CAI::multiplicationTest()
Description:	Function that initiates the multiplication portion of the math test. Asks 5 randomly generated
				multiplication questions. If the answer is wrong, the user is given a randomly generated negative
				response and prompted to try again for a max of 3 attempts (maxed at 3 in order to force the loop
				closed, after 3 attempts the question is skipped). If the user's answer is correct and the user 
				has given 0 incorrect answers, then the correctCounter is incremented. If the user inputs an
				incorrrect answer, the incorrectAnswer counter is incremented. Both of these counters are used
				for printing purposes at the end of the program. The answer to the question is also stored in 
				the correctAnswer array, again used for printing purposes at the end.
Input:          User will input an answer after each question prompt.
Process:        The multiplicands will be randomly generated and then multiplied together. After giving an answer,
				a text response will be randomly generated and displayed based on whether the answer was correct
				or incorrect.
Output:         A random response will be generated. The text of the response will depend on both the RNG and whether
				the answer was correct or incorrect.
Assumptions:    The user is a child.
*/

void CAI::multiplicationTest()
{
	int num1 = 0;					// randomly generated number 1
	int num2 = 0;					// randomly generated number 2
	int solution = 0;				// variable to store the answer
	int answer = 0;					// variable for user's input answer
	bool done = 0;					// bool to keep inner while loop running

	for (int i = 0; i < 5; i++)
	{
		num1 = rand() % 10;
		num2 = rand() % 10;
		solution = num1 * num2;
		setAnswer(i, solution);
		done = 0;
		cout << "What is " << num1 << " * " << num2 << "?" << endl;
		cin >> answer;

		while (done == 0)
		{
			if (answer == solution)
			{
				correctResponse(); 
				done = 1;
			}
			else if (answer != solution)
			{
				setIncorrect(i);
				if (getIncorrect(i) == 3)
				{
					cout << "Max attempts have been made. Moving on to the next question." << endl; // if statement to check if the user has answered 3 times, skips the question if true
					done = 1;
					continue;
				}

				incorrectResponse();

				cout << "What is product of " << num1 << " * " << num2 << "?" << endl;
				cin >> answer;
			}

			if (answer == solution && getIncorrect(i) == 0)
			{
				setCorrect();
			}
		}// end inner while
	}// end for loop
}

/*
Function:		void CAI::divisionTest()
Description:	Function that initiates the division portion of the math test. Asks 5 randomly generated
				division questions. If the answer is wrong, the user is given a randomly generated negative
				response and prompted to try again for a max of 3 attempts (maxed at 3 in order to force the loop
				closed, after 3 attempts the question is skipped). If the user's answer is correct and the user
				has given 0 incorrect answers, then the correctCounter is incremented. If the user inputs an
				incorrrect answer, the incorrectAnswer counter is incremented. Both of these counters are used
				for printing purposes at the end of the program. The answer, and also the remainder, are stored in
				the correctAnswer and remainderArray arrays, again used for printing purposes at the end.
Input:          User will input an answer after each question prompt.
Process:        The divisor/dividend will be randomly generated and then divided. After giving a quotient and its remainder,
				a text response will be randomly generated and displayed based on whether the answer was correct
				or incorrect.
Output:         A random response will be generated. The text of the response will depend on both the RNG and whether
				the answer was correct or incorrect.
Assumptions:    The user is a child.
*/

void CAI::divisionTest()
{
	int quotient = 0;				// variable for the quotient of the randomly generated problem
	int remain = 0;					// variable for the quotient's remainder
	int answer = 0;					// input answer
	int rAnswer = 0;				// input remainder	
	int num1 = 0;					// randomly generated number 1
	int num2 = 0;					// randomly generated number 2

	for (int i = 5; i < 10; i++)
	{
		num1 = rand() % 10;
		num2 = rand() % 10;
		while(num2 == 0)					// check to ensure there is no division by 0, if num2 is 0, reroll randomizer until not 0
		{
			if (num2 == 0)
			{
				num2 = rand() % 10;
			}
		}

		quotient = num1 / num2;
		remain = num1 % num2;
		setAnswer(i, quotient);
		setRemainder(i, remain);
		bool done = 0;
		cout << "What is " << num1 << " / " << num2 << "?" << endl;
		cin >> answer;                             
		cout << "What is the remainder?" << endl;
		cin >> rAnswer;

		while (done == 0)
		{
			if (answer == quotient && rAnswer == remain)
			{
				correctResponse();
				done = 1;
			}
			else
			{
				setIncorrect(i); 
				incorrectResponse();
				if (getIncorrect(i) == 3)
				{
					cout << "Max attempts have been made. Moving on to the next question." << endl;		// if statement to check if the user has answered 3 times, skips the question if true
					done = 1;
					continue;
				}
				cout << "What is the quotient of " << num1 << " / " << num2 << "?" << endl;
				cin >> answer;                        
				cout << "What is the remainder?" << endl;
				cin >> rAnswer;
			}

			if (answer == quotient && rAnswer == remain && getIncorrect(i) == 0)
			{
				setCorrect();
			}
		}// end of inner while
	}// end of for loop
}

/*
Function:		viod CAI::correctResponse()
Description:	Function that generates a positive text response depending on the randomly generated number using a 
				series of switch statements. This function is used when the user inputs a correct response in the
				multiplication/division functions.
Input:          N/A
Process:        Generates a random number and outputs a random text response depending on the number and the case that
				is triggered by that number.
Output:         N/A
Assumptions:    N/A
*/

void CAI::correctResponse()
{
	int posResponse = 0;
	posResponse = rand() % 4;

	switch (posResponse)
	{
	case 0:
		cout << "Right! Keep it up!\n" << endl;
		break;
	case 1:
		cout << "That is correct!\n" << endl;
		break;
	case 2:
		cout << "Way to go!\n" << endl;
		break;
	case 3:
		cout << "Very good!\n" << endl;
		break;
	case 4:
		cout << "Keep at it, winner!\n" << endl;
		break;
	default:
		break;
	}
}

/*
Function:		viod CAI::correctResponse()
Description:	Function that generates a negative text response depending on the randomly generated number using a
				series of switch statements. This function is used when the user inputs an incorrect response in the
				multiplication/division functions.
Input:          N/A
Process:        Generates a random number and outputs a random text response depending on the number and the case that
				is triggered by that number.
Output:         N/A
Assumptions:    N/A
*/

void CAI::incorrectResponse()
{
	int negResponse = 0;
	negResponse = rand() % 4;
	switch (negResponse)
	{
	case 0:
		cout << "Wrong answer. Give it another shot.\n" << endl;
		break;
	case 1:
		cout << "That is incorrect.\n" << endl;
		break;
	case 2:
		cout << "Please try again.\n" << endl;
		break;
	case 3:
		cout << "Incorrect, try again.\n" << endl;
		break;
	case 4:
		cout << "Wrong. Please try again.\n" << endl;
		break;
	default:
		break;
	}
}

/*
Function:		void CAI::printResults(CAI cai)
Description:	This function prints the correct answers to each question, the number of incorrect answers
				per question, and the final tally of correct answers.
Input:          A CAI object.
Process:        Prints the correct answers to each question, the number of incorrect answers per question, 
				and the final tally of correct answers.
Output:         N/A
Assumptions:    N/A
*/

void CAI::printResults(CAI cai)
{
	cout << "\nThe test is now complete.\n" << endl;
	int j = 1;
	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
		{
			cout << "The correct answer for question number " << j << " is: " << cai.getAnswer(i) << ". (" << cai.getIncorrect(i) << " wrong answers)" << endl;
			j++;
		}

		else
		{
			cout << "The correct answer for question number " << j << " is " << cai.getAnswer(i) << " with a remainder of " << cai.getRemainder(i)
				<< ". (" << cai.getIncorrect(i) << " wrong answers)" << endl;
			j++;
		}
	}

	cout << "\nYou got " << cai.getCorrect() << "/10 questions correct!" << endl;
}