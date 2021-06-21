#pragma once
#ifndef AIRGEAD_BANKING_REPORTANNUAL_H
#define AIRGEAD_BANKING_REPORTANNUAL_H

#include <vector>
#include "DataInput.h"
#include "Calculations.h"
#include "InvestmentInformation.h"

using namespace std;

class ReportAnnual {
public:
	ReportAnnual();

	void reportAnnual(InvestmentInformation& t_dataOne, InvestmentInformation &dataTwo);

	bool additionalSessionCheck();

private:
	void printColHeader();

	void annualReport(InvestmentInformation &t_data);

};

#endif //AIRGEAD_BANKING_REPORTANNUAL_H