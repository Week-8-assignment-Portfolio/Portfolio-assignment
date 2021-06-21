#include <vector>
#include <iostream>
#include "Calculations.h"
#include "InvestmentInformation.h"

using namespace std;

const long MAX_AMOUNT = 9999999999999999;

// Default constructor
Calculations::Calculations() {}

// Takes user input and builds InvestmentInformation object that contains user balance and interests 
InvestmentInformation Calculations::calculateAnnualInvestment(DataInput& t_userData, bool t_monthlyDep) {
	double openAmt = t_userData.getMInitialInvestAmt();
	double depAmt = t_userData.getMMonthlyDep();
	int intRate = t_userData.getMAnnualInt();
	int numYears = t_userData.getMNumYears();
	vector<int> years;
	vector<vector<double>> yearEndBals;

	// create an object to store data for our report
	InvestmentInformation investmentDetails;

	try {// return years as array of ints for display to output for the user
		for (int i = 0; i < numYears; ++i) {
			years.push_back(i + 1);
		}
		if (t_monthlyDep == false) {
			// calculate without monthly deposit
			yearEndBals = annualBalWithInt(openAmt, 0, intRate, numYears);
		}
		else {
			// calculate with monthly deposits
		yearEndBals = annualBalWithInt(openAmt, depAmt, intRate, numYears);
}

		// populates investment object properties
		investmentDetails.setMYears(years);
		investmentDetails.setMYearEndEarnedInterests(yearEndBals.at(0));
		investmentDetails.setMYearEndBalances(yearEndBals.at(1));
		return investmentDetails;
	}
	catch (runtime_error& except) {
		cout << except.what() << endl;
	}
}

// Calculates annual account balance and earned interest
vector<vector<double>> Calculations::annualBalWithInt(double t_openAmount, double t_depositAmount, int t_intRate, int t_years) {
	vector<vector<double>> balanceAndInts;
	vector<double> annualInterestOnly;
	vector<double> annualBalWithInterest;
	double newBal;
	double yearEndInt{};
	double precIntRate = (t_intRate / 100.00) / 12.00;
	double intTracker = 0;
	double intOnly = 0;

	// loop over months in requested time frame and calculates the annual balance and earned interests
	for (int i = 0; i < (t_years * 12); ++i) {
		yearEndInt += ((intTracker + t_openAmount) + (t_depositAmount * (i + 1))) * precIntRate;
		//allows tracking earned interest back into principle
		intTracker = yearEndInt;
		if (((i + 1) % 12) == 0) {
			annualInterestOnly.push_back(yearEndInt - intOnly); // add annual interest to one vector first 
			intOnly = yearEndInt;
			newBal = t_openAmount + (t_depositAmount * (i + 1)) + yearEndInt; // add interest opening and monthly amount
			annualBalWithInterest.push_back(newBal); // add annual bal with interest to second vector
		}
	} // error if newBal is more than MAX_AMOUNT
	if (newBal > MAX_AMOUNT) {
		throw runtime_error("Unable to complete calculations. Amount too large");
	}
	balanceAndInts.push_back(annualInterestOnly); // one vector for tracking interest
	balanceAndInts.push_back(annualBalWithInterest); // one vector for tracking interest plus balance

	// pass vectors back to fill out InvestmentInformation objects
	return balanceAndInts;
	}



