#include <vector>
#include "InvestmentInformation.h"

using namespace std;

// constructor
InvestmentInformation::InvestmentInformation() {}

const  vector<int>& InvestmentInformation::getMYears() const {
	return m_years;
}
void InvestmentInformation::setMYears(const vector<int>& t_years) {
	m_years = t_years;
}

const vector<double>& InvestmentInformation::getMYearEndBalances() const {
	return m_yearEndBalances;
}

void InvestmentInformation::setMYearEndBalances(const vector<double>& t_yearEndBalances) {
	m_yearEndBalances = t_yearEndBalances;
}

const vector<double>& InvestmentInformation::getMYearEndEarnedInterests() const {
	return m_yearEndEarnedInterests;
}

void InvestmentInformation::setMYearEndEarnedInterests(const vector<double>& t_yearEndEarnedInterests) {
	m_yearEndEarnedInterests = t_yearEndEarnedInterests;
}