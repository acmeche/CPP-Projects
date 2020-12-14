/*
Author:         Aaron Meche
Program:        Homework 2 - Worker Class Functions File
Description:    This File contains the function implementations for the Worker class
Date Due:       02/05/19
Date Created:   01/24/19
Date Last Mod:  02/02/19

Input:          N/A
Process:        N/A
Output:         N/A
Assumptions:    That the worker.h file exist and are in the same folder.
*/

#include "worker.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::flush;
using std::endl;
using std::setprecision;
using std::fixed;

/*
Function:		Worker::Worker
Description:	Worker default constructor. It initializes all private data members to 0 when Worker object is created
Input:          N/A
Process:        N/A
Output:         N/A
Assumptions:    N/A
*/

Worker::Worker()
{
	managerPay = 0;
	hourlyPay = 0;
	commissionPay = 0;
	piecePay = 0;
}

/*
Function:		Worker::calculatePay
Description:	The function calculates pay based on the paycode entered by the user using a switch statement and sums/stores the
				value in the prviate data member function to be used later in the bar chart function.
				Case 1: Calculates manager pay. Manager pay is not processed in any way, so this case just returns the manager pay.
						Adds and stores manager pay in the private variable managerPay to be used later in the bar chart function.
				Case 2: Calculates hourly worker pay. Hourly wage and amount of hours are input by user. Hourly pay is calculated
						by multiplaying wage by hours worked. If hours worked is > 40, worker receives the regular wage + overtime.
						Adds and stores hourly pay in the private variable hourlyPay to be used later in the bar chart function.
				Case 3: Calculates commission worker pay. Total weekly sales are input by user. Commission worker pay is calculated
						by multiplying total weekly sales by 5.7% (or .057).
						Adds and stores commission worker pay in the private variable commissionPay to be used later in the bar chart function.
				Case 4: Calculates piece worker pay. Number if pieces and amount of money per piece are niput by the user. Piece worker
						pay is calculated by multiplying the number of pieces by the price per piece.
						Adds and stores piece worker pay in the private variable piecePay to be used later in the bar chart function.
				Case 5: Displays a statement that indicates the program is exiting the loop and generating the bar chart. Paycode is
						set to 5 in the driver file, so the loop is exited after this switch statement breaks and the loop iterates.
				Default: If anything other than the cases is entered, gives an invalid paycode error message.
Input:          User input paycode as well as prompted input used for worker pay calculation and bar chart generation
Process:        Calculates pay based on paycode entered and user input
Output:         Each switch statement displays the pay for each worker or an error message
Assumptions:    N/A
*/

void Worker::calculatePay(int paycode)
{
	int pieces = 0;
	float salary = 0;
	float wage = 0;
	float hours = 0;
	float weekSales = 0;
	float pwage = 0;

	switch (paycode) {
	case 1:
		cout << "Manager selected. Enter weekly salary: " << endl;
		cin >> salary;
		cout << "Manager's pay is: " << setprecision(2) << fixed << salary << endl << endl;
		setManager(salary);
		break;
	case 2:
		cout << std::setprecision(2);
		cout << "Hourly worker selected. Enter hourly wage: " << endl;
		cin >> wage;
		cout << "Enter the hours worked: " << endl;
		cin >> hours;
		if (hours > 40)
		{
			float overtime = hours - 40;
			hours = 40;
			overtime = overtime * (wage * 1.5);
			wage = (wage * hours + overtime);
			cout << "Hourly worker's pay is: " << setprecision(2) << fixed << wage << endl << endl;
			setHourly(wage);
		}
		else
		{
			wage *= hours;
			cout << "Hourly worker's pay is: " << setprecision(2) << fixed << wage << endl << endl;
			setHourly(wage);
		}
		break;
	case 3:
		cout << "Commission worker selected. Enter weekly sales: " << endl;
		cin >> weekSales;
		weekSales = 250 + (weekSales * .057);
		cout << "Commission worker pay is: " << setprecision(2) << fixed << weekSales << endl << endl;
		setCommission(weekSales);
		break;
	case 4:
		cout << "Piece worker selected. Enter the number of pieces: " << endl;
		cin >> pieces;
		cout << "Enter wage per piece: " << endl;
		cin >> pwage;
		pwage *= pieces;
		cout << "Piece worker pay is: " << setprecision(2) << fixed << pwage << endl << endl;
		setPiece(pwage);
		break;
	case 5:
		cout << "Pay Calculator terminated. Generating bar chart..." << endl << endl;
		break;
	default:
		cout << "Invalid paycode" << endl;
		break;
	}
}

/*
Function:		Worker::getManager
Description:	Accessor function for the managerPay private data member of the Worker class
Input:          N/A
Process:        N/A
Output:         Function returns the value stored in the managerPay private data member of the Worker class
Assumptions:    N/A
*/

float Worker::getManager()
{
	return managerPay;
}

/*
Function:		Worker::getHourly
Description:	Accessor function for the hourlyPay private data member of the Worker class
Input:          N/A
Process:        N/A
Output:         Function returns the value stored in the hourlyPay private data member of the Worker class
Assumptions:    N/A
*/

float Worker::getHourly()
{
	return hourlyPay;
}

/*
Function:		Worker::getCommission
Description:	Accessor function for the commissionPay private data member of the Worker class
Input:          N/A
Process:        N/A
Output:         Function returns the value stored in the commissionPay private data member of the Worker class
Assumptions:    N/A
*/

float Worker::getCommission()
{
	return commissionPay;
}

/*
Function:		Worker::getPiece
Description:	Accessor function for the piecePay private data member of the Worker class
Input:          N/A
Process:        N/A
Output:         Function returns the value stored in the piecePay private data member of the Worker class
Assumptions:    N/A
*/

float Worker::getPiece()
{
	return piecePay;
}

/*
Function:		Worker::setManager
Description:	Mutator function for the managerPay private data member of the Worker class
Input:          Pay calculated in the clculatePay function as a float
Process:        Calculated pay is added and stored in private member variable managerPay
Output:         N/A
Assumptions:    N/A
*/

void Worker::setManager(float initManager)
{
	managerPay += initManager;
}

/*
Function:		Worker::setHourly
Description:	Mutator function for the hourlyPay private data member of the Worker class
Input:          Pay calculated in the clculatePay function as a float
Process:        Calculated pay is added and stored in private member variable hourlyPay
Output:         N/A
Assumptions:    N/A
*/

void Worker::setHourly(float initHourly)
{
	hourlyPay += initHourly;
}

/*
Function:		Worker::setCommission
Description:	Mutator function for the managerPay private data member of the Worker class
Input:          Pay calculated in the clculatePay function as a float
Process:        Calculated pay is added and stored in private member variable commissionPay
Output:         N/A
Assumptions:    N/A
*/

void Worker::setCommission(float initCommission)
{
	commissionPay += initCommission;
}

/*
Function:		Worker::setPiece
Description:	Mutator function for the piecePay private data member of the Worker class
Input:          Pay calculated in the clculatePay function as a float
Process:        Calculated pay is added and stored in private member variable piecePay
Output:         N/A
Assumptions:    N/A
*/

void Worker::setPiece(float initPiece)
{
	piecePay += initPiece;
}

/*
Function:		Worker::barChart
Description:	Void function that generates an asterisk bar chart based on total pay of each worker processed.
				Each asterisk in the bar chart represents $100.
Input:          Total pay for each worker that is stored in the private member variables managerPay, hourlyPay,
				commissionPay, and piecePay
Process:        Each total is divided by 100 and stored in a variable. Then, the loop iterates a certain number
				of times based on the result of that division.
Output:         Each time each loop iterates, it displays an asterisk
Assumptions:    N/A
*/

void Worker::barChart(float managerPay, float hourlyPay, float commissionPay, float piecePay)
{
	int bar = 0;
	bar = managerPay / 100;
	cout << "Manager:     ";
	for (int i = 0; i < bar; i++)
	{
		cout << "*";
	}
	cout << endl;

	bar = hourlyPay / 100;
	cout << "Hourly:      ";
	for (int i = 0; i < bar; i++)
	{
		cout << "*";
	}
	cout << endl;

	bar = commissionPay / 100;
	cout << "Commission:  ";
	for (int i = 0; i < bar; i++)
	{
		cout << "*";
	}
	cout << endl;

	bar = piecePay / 100;
	cout << "Pieceworker: ";
	for (int i = 0; i < bar; i++)
	{
		cout << "*";
	}
	cout << endl;
}

/*
Function:		Worker::callChart
Description:	Accessor function for the private member function barChart stored in the Worker class
Input:          A Worker object
Process:        N/A
Output:         See output for barChart function
Assumptions:    N/A
*/

void Worker::callChart(Worker worker)
{
	worker.barChart(worker.getManager(), worker.getHourly(), worker.getCommission(), worker.getPiece());
}