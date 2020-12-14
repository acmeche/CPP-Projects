/*
Author:         Aaron Meche
Program:        Homework 2 - Worker Class Header File
Description:    This File contains all the member data and function prototypes for the Worker class.
Date Due:       02/05/19
Date Created:   01/24/19
Date Last Mod:  02/02/19

Input:          N/A
Process:        N/A
Output:         N/A
Assumptions:    That the worker.cpp file exists and are in the same folder.
*/

#pragma once
class Worker
{
private:
	float managerPay;										// total manager payment
	float hourlyPay;										// total hourly payment
	float commissionPay;									// total commission payment
	float piecePay;											// total piece worker payment
	void barChart(float managerPay, float
		hourlyPay, float commissionPay, float piecePay);	// generates bar chart

public:
	Worker();
	void calculatePay(int paycode);							// function that calculates worker pay based on a user input paycode
	float getManager();										// getter function for the total manager payment
	float getHourly();										// getter function for the total hourly worker payment
	float getCommission();									// getter function for the total commission payment
	float getPiece();										// getter function for the total piece worker payment
	void setManager(float);									// setter function for the total manager payment
	void setHourly(float);									// setter function for the total hourly worker payment
	void setCommission(float);								// setter function for the total commission payment
	void setPiece(float);									// setter function for the total piece worker payment
	void callChart(Worker);									// function to access the private barChart function
};