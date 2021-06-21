#include <string>
#include <iostream>
#include "DataInput.h"
#include "Calculations.h"
#include "ReportAnnual.h"
#include "InvestmentInformation.h"

using namespace std;

void start() {
	bool restart = true;

	try {
		do {
			// prompt user for input and store results
			DataInput userData;
			userData.promptUser();

			// pass the user input on to make calculations
			Calculations calculations;
			InvestmentInformation accWithNoMonthlyDep = calculations.calculateAnnualInvestment(userData);
			InvestmentInformation accWithMonthlyDep = calculations.calculateAnnualInvestment(userData, true);

			// use ReportGenerator objects to relay interest info back to the user
			ReportAnnual balanceAndInterestReport;
			balanceAndInterestReport.reportAnnual(accWithNoMonthlyDep, accWithMonthlyDep);

			// prompt the user to continue or exit program
			restart = balanceAndInterestReport.additionalSessionCheck();
		} while (restart);
		}
		catch (runtime_error& except) {
			cout << "Oops! Something went wrong. Exception:  " << except.what() << endl;
		}
	}
	int main() {
		start();
		
		return 0;
	}