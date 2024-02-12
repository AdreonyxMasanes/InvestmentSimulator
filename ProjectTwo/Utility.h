#ifndef UTILITY_H
#define UTILITY_H
#include "Account.h"
#include <iomanip>
#include <string>
#include <stdlib.h>
#include "sstream"
class Utility
{
	private:
		static const int LINE_LENGTH = 61;
		static void printHeader(const std::string& t_header, const int& t_lineWidth);
		static void printDashedLine(const char& t_char);
		
	public:
		static void printAccountStats(Account& t_account);
		static void printInputScreen(const double& t_initialInvest, const double& t_monthlyDeposit, const double& t_annualInterest, const double& t_yearsOfGrowth);
		static double GetUserInput(const std::string& t_inputMsg);
		
};
#endif

