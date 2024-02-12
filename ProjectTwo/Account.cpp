#include "Account.h"
#include <cmath>
void Account::CalculateAnnualInterest()
{
	const int MAX_MONTH = 12;
	// Calculate Monthly interset
	const double MONTHLY_INTEREST_RATE = (m_annualInterestRate / 100.00f) / MAX_MONTH;
	// Each Year starts at zero interest earned
	m_interestEarnedAnnually = 0;
	// For each month calculate the interest earned and add it to the current balance and the interest earned annualy
	for (int currentMonth = 1; currentMonth <= MAX_MONTH; currentMonth++)
	{
		m_currentBalance = m_currentBalance + m_monthlyDeposit;
		double interestGained = m_currentBalance * MONTHLY_INTEREST_RATE;

		m_currentBalance = m_currentBalance + interestGained;
		m_interestEarnedAnnually += interestGained;
	}
	m_interestEarnedAnnually = roundToHundredths(m_interestEarnedAnnually);
	m_currentBalance = roundToHundredths(m_currentBalance);
}
// Round to the nearest cent
double Account::roundToHundredths(const double& t_value)
{

	double roundedValue = 0.0;
	roundedValue = std::round(t_value * 100) / 100.0;
	return roundedValue;
}
// Constructor
Account::Account(const double& t_initalInvest, const double& t_monthlyDeposit, const double& t_annualInterest, const int& t_yearsOfGrowth)
	:m_initalInvest(t_initalInvest),
	 m_monthlyDeposit(t_monthlyDeposit),
	 m_annualInterestRate(t_annualInterest),
	 m_yearsOfGrowth(t_yearsOfGrowth)
{
	m_currentBalance = m_initalInvest;
}

const double Account::GetMonthlyDeposit() const
{
	return m_monthlyDeposit;
}

const double Account::GetYearsOfGrowth() const
{
	return m_yearsOfGrowth;
}

const double Account::GetAnnualInterestEarned() const
{
	return m_interestEarnedAnnually;
}

const double Account::GetCurrentBalance() const
{
	return m_currentBalance;
}
