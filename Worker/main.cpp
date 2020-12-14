#include <iostream>
#include <iomanip>
#include "worker.h"

using std::cout;
using std::cin;
using std::flush;
using std::endl;
using std::setprecision;
using std::fixed;

int main()
{
	Worker worker;
	int paycode = 0;
	while (paycode != 5)
	{
		cout << "Please enter paycode (enter 5 to exit and create the bar chart): " << endl;
		cin >> paycode;
		worker.calculatePay(paycode); //make getters and setters for payment variables
	}

	system("pause");
}