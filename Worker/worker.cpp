#include "worker.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::flush;
using std::endl;
using std::setprecision;
using std::fixed;

Worker::Worker()
{
	pieces = 0;
	salary = 0;			//store manager salary
	hours = 0;
	wage = 0;				//store hourly wage
	weekSales = 0;		//store commission wage
	pwage = 0;			//store piece worker wage

	totalPay1 = 0;
	totalPay2 = 0;
	totalPay3 = 0;
	totalPay4 = 0;
}

void Worker::calculatePay(int paycode)
{

	switch (paycode) {
	case 1:
		cout << "Manager selected. Enter weekly salary: " << endl;
		cin >> salary;
		cout << "Manager's pay is: " << setprecision(2) << fixed << salary << endl;
		totalPay1 += salary;
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
			cout << "Hourly worker's pay is: " << setprecision(2) << fixed << wage << endl;
			totalPay2 += wage;
		}
		else
		{
			wage *= hours;
			cout << "Hourly worker's pay is: " << setprecision(2) << fixed << wage << endl;
			totalPay2 += wage;
		}
		break;
	case 3:
		cout << "Commission worker selected. Enter weekly sales: " << endl;
		cin >> weekSales;
		weekSales = 250 + (weekSales * .057);
		cout << "Commission worker pay is: " << setprecision(2) << fixed << weekSales << endl;
		totalPay3 += weekSales;
		break;
	case 4:
		cout << "Piece worker selected. Enter the number of pieces: " << endl;
		cin >> pieces;
		cout << "Enter wage per piece: " << endl;
		cin >> pwage;
		pwage *= pieces;
		cout << "Piece worker pay is: " << setprecision(2) << fixed << pwage << endl;
		totalPay4 += pwage;
		break;
	case 5:
		cout << "Program terminated. Thank you for using Aaron's Fancypants Pay Calculator!" << endl;
		break;
	default:
		cout << "Invalid paycode" << endl;
		break;
	}
}