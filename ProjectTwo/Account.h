#ifndef Account_H
#define Account_H
#include "iostream"
class Account 
{
	private:
		double m_initalInvest = 0;
		double m_monthlyDeposit = 0;
		double m_annualInterestRate = 0;
		double m_interestEarnedAnnually = 0;
		double m_currentBalance = 0;
		double m_yearsOfGrowth = 0;
		double roundToHundredths(const double& t_value);
		
	public:
		Account(const double& t_initalInvest, const double& t_monthlyDeposit, const double& t_annualInterest, const int& t_yearsOfGrowth);
		const double GetMonthlyDeposit() const;
		const double GetYearsOfGrowth() const;
		const double GetAnnualInterestEarned() const;
		const double GetCurrentBalance() const;
		void CalculateAnnualInterest();
};
#endif
