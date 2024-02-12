#include "Utility.h"
// Print A Title line
void Utility::printHeader(const std::string& t_header, const int& t_lineWidth)
{
	std::cout << std::setw(t_lineWidth) << t_header << std::setw(LINE_LENGTH-t_lineWidth) << "" << std::endl;
}

// Print a line
void Utility::printDashedLine(const char& t_char)
{
	std::cout << std::setfill(t_char) << std::setw(LINE_LENGTH) << "" << std::endl;
	std::cout << std::setfill(' ');
}

// Print yearly account growth
void Utility::printAccountStats(Account& t_account)
{
	// Determine the heading
	if (t_account.GetMonthlyDeposit() > 0)
	{
		printHeader("Balance and Interest With Additional Monthly Deposits", 57);
	}
	else
	{
		printHeader("Balance and Interest Without Additional Monthly Deposits", 59);
	}
	// Print Line Break
	printDashedLine('=');
	// Print Column Headings
	std::cout << "Year" << std::setw(25) << "Year End Balance" << std::setw(32) << "Year End Earned Interest" << std::endl;
	// Print Line Break
	printDashedLine('-');

	// FOr each year calculate annual Interest and print its growth stats
	for (int currentYear = 1; currentYear <= t_account.GetYearsOfGrowth(); currentYear++)
	{
		t_account.CalculateAnnualInterest();

		std::ostringstream balanceStream;
		std::ostringstream annualInterestStream;
		balanceStream << std::fixed << std::setprecision(2) << std::noshowpoint << t_account.GetCurrentBalance();
		annualInterestStream << std::fixed << std::setprecision(2) << std::noshowpoint << t_account.GetAnnualInterestEarned();
		
		std::cout << std::setw(4) << std::to_string(currentYear);
		std::cout << std::setw(25) << ("$" + balanceStream.str());
		std::cout << std::setw(32) << ("$" + annualInterestStream.str()) << std::endl;
	}


}

// Print Input data in a formatted way
void Utility::printInputScreen(const double& t_initialInvest, const double& t_monthlyDeposit, const double& t_annualInterest, const double& t_yearsOfGrowth)
{
	printDashedLine('-');
	printHeader("Data Input",35);
	printDashedLine('-');
	std::cout << std::setprecision(2) << std::fixed << "Initial Investment Amount: $" << t_initialInvest << std::endl;
	std::cout << std::setprecision(2) << "Monthly Deposit Amount: $" << t_monthlyDeposit << std::endl;
	std::cout << std::setprecision(2) << "Annual Interest Rate: %" << t_annualInterest << std::endl;
	std::cout << std::setprecision(2) << "Years of Growth: " << t_yearsOfGrowth << std::endl;
}

// Get Input from user
double Utility::GetUserInput(const std::string& t_inputMsg)
{
	double userValue = 0.0;

	do
	{
		std::cout << t_inputMsg << std::endl;
		std::cin >> userValue;
	} while (userValue < 0);
	system("CLS");
	return userValue;
}
