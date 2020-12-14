#pragma once
class Worker
{
	private:
		int pieces;
		float salary;			//store manager salary
		float hours;
		float wage;				//store hourly wage
		float weekSales;		//store commission wage
		float pwage;			//store piece worker wage

		float totalPay1;		//total manager payment
		float totalPay2;		//total hourly payment
		float totalPay3;		//total commission payment
		float totalPay4;		//total piece worker payment
								//make getters and setters for totalPay variables

	public:
	
		Worker();
		void calculatePay(int paycode);
};