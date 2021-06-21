#include <string_view>
#include <iostream>
#include <iomanip>
#include "ReportAnnual.h"
#include "Calculations.h"
#include <string>
using namespace std;

const char* YEAR = "Year";
const char* YEAR_END_BAL = "Year End Balance";
const char* YEAR_END_INTEREST = "Year End Earned Interest";

// constructor 
ReportAnnual::ReportAnnual() {}


// to print the report header
void ReportAnnual::printColHeader() {
	cout << string(66, '=') << endl;
	cout << setw(9) << YEAR << setw(26) << YEAR_END_BAL << setw(27) << YEAR_END_INTEREST <<  endl;
	cout << string(66, '-') << endl;
}

void ReportAnnual::reportAnnual(InvestmentInformation& t_dataOne, InvestmentInformation& t_dataTwo) {
	cout << "       Balance and Interest without Additional Monthly Deposits     \n" << endl;
	annualReport(t_dataOne);

	cout << "       Balance and Interest with Additional Monthly Deposits     \n" << endl;
	annualReport(t_dataTwo);
}

// print rows of financial info for the report
void ReportAnnual::annualReport(InvestmentInformation& t_Data) {
	// set local variables to producing a report
	vector<int> years = t_Data.getMYears();
	vector<double> yearEndBalances = t_Data.getMYearEndBalances();
	vector<double> yearEndEarnedInterests = t_Data.getMYearEndEarnedInterests();

	printColHeader();

	// loop over InvestmentInformation object to fill out report
	for (int i = 0; i < years.size(); ++i) {
		cout << endl;
		cout << setw(9) << years.at(i) << fixed << setprecision(2);
		cout << setw(26) << yearEndBalances.at(i) << fixed << setprecision(2);
		cout << setw(27) << yearEndEarnedInterests.at(i) << fixed << setprecision(2) << endl;
	}
	cout << endl << endl;
}

// Prompt the user for another session
bool ReportAnnual::additionalSessionCheck() {
	string text;

	cout << "Press enter to try more values (press q to quit)\n";
	getline(cin, text);

	if (text.empty()) {
		return true;
	}
	else {
		return false;
	}
}