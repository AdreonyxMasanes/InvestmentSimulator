#include "Utility.h"
int main() 
{
	//TODO ADD USERINPUT SCREEN

	double initalInvestment = Utility::GetUserInput("Please enter a number greater than 0 for  your inital investment: ");
	double monthlyDeposit = Utility::GetUserInput("Please enter a number greater than 0 for  your monthly deposits: ");
	double annualInterest = Utility::GetUserInput("Please enter a number greater than 0 for  your annual interest rate: ");
	double yearsOfGrowth = Utility::GetUserInput("Please enter a number greater than 0 for how long you would like your money to grow: ");

	Utility::printInputScreen(initalInvestment, monthlyDeposit, annualInterest, yearsOfGrowth);
	system("pause");
	system("CLS");

	Account accountWithDeposits(initalInvestment, monthlyDeposit, annualInterest, yearsOfGrowth);
	Account accountWithOutDeposits(initalInvestment, 0.0, annualInterest, yearsOfGrowth);
	Utility::printAccountStats(accountWithDeposits);
	Utility::printAccountStats(accountWithOutDeposits);
}