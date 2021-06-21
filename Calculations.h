#pragma once
#ifndef AIRGEAD_BANKING_CALCULATIONS_H
#define AIRGEAD_BANKING_CALCULATIONS_H
#include <vector>
#include "DataInput.h"
#include "InvestmentInformation.h"

using namespace std;

class Calculations {
public:
	Calculations();

	InvestmentInformation calculateAnnualInvestment(DataInput& data, bool t_monthlyDep = false);

private:
	vector<vector<double>> annualBalWithInt(double t_openAmount, double t_depositAmount, int t_intRate, int t_years);
};

#endif //AIRGEAD_BANKING_CALCULATIONS_H