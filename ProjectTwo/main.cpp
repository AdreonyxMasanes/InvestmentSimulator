/*
	Adreonyx Masanes
	Project Two
	Feb 11 2024
*/

#include "Utility.h"
int main() 
{
	// Get User Input
	double initalInvestment = Utility::GetUserInput("Please enter a number greater than 0 for  your inital investment: ");
	double monthlyDeposit = Utility::GetUserInput("Please enter a number greater than 0 for  your monthly deposits: ");
	double annualInterest = Utility::GetUserInput("Please enter a number greater than 0 for  your annual interest rate: ");
	double yearsOfGrowth = Utility::GetUserInput("Please enter a number greater than 0 for how long you would like your money to grow: ");
	// Print User Data Formatted
	Utility::printInputScreen(initalInvestment, monthlyDeposit, annualInterest, yearsOfGrowth);
	system("pause");
	system("CLS");
	// Create Accounts
	Account accountWithDeposits(initalInvestment, monthlyDeposit, annualInterest, yearsOfGrowth);
	Account accountWithOutDeposits(initalInvestment, 0.0, annualInterest, yearsOfGrowth);
	// Print User Stats
	Utility::printAccountStats(accountWithDeposits);
	Utility::printAccountStats(accountWithOutDeposits);
}