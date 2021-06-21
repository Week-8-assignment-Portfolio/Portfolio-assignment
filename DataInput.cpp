#include <iostream>
#include <vector>
#include "DataInput.h"

using namespace std;

// Default constructor
DataInput::DataInput() {
	DataInput::m_userPrompts = {
		"Initial Investment Amount:   ",
				"Monthly Amount:   ",
				"Annual Interest:   ",
				"Number of years:    "
	};
};

const vector<string> &DataInput::getMUserPrompts() const {
	return m_userPrompts;
}

//Getters and Setters

double DataInput::getMInitialInvestAmt() const {
	return m_initialInvestAmt;
}

void DataInput::setMInitialInvestAmt(double t_initialInvestAmt) {
	m_initialInvestAmt = t_initialInvestAmt;
}
double DataInput::getMMonthlyDep() const {
	return m_monthlyDep;
}

void DataInput::setMMonthlyDep(double t_monthlyDep) {
	m_monthlyDep = t_monthlyDep;
}
double DataInput::getMAnnualInt() const {
	return m_annualInt;
}

void DataInput::setMAnnualInt(double t_annualInt) {
	m_annualInt = t_annualInt;
}
double DataInput::getMNumYears() const {
	return m_numYears;
}

void DataInput::setMNumYears(double t_numYears) {
	m_numYears = t_numYears;
}

// print header for user input prompt
void DataInput::printHeader() {
	cout << string(36, '*') << endl;
	cout << string(12, '*') << " Data Input " << string(12, '*') << endl;
}

// capture user input and set class members
void DataInput::promptUser() {
	vector<double> depositDetails;
	char quitCmd = 'a'; // Indicates infinite loop until the user types correct input requirements

	while (quitCmd != 'q') {
		try {
			// clears any previous unfinished collections of user input
			depositDetails.clear();
			printHeader();
			depositDetails = inputCapture();
		}
		// catch any invalid input 
		catch (invalid_argument& except) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // clear out the input buffer
			cout << except.what()  << endl;
		}
		// check that depositDetails vector is full and user decides to continue
		if (depositDetails.size() == 4 && enterCheck()) {
			// sets classes private members
			setMInitialInvestAmt(depositDetails.at(0));
			setMMonthlyDep(depositDetails.at(1));
			setMAnnualInt(depositDetails.at(2));
			setMNumYears(depositDetails.at(3));

			// exit button to return to main
			quitCmd = 'q';
		}
	}
}

// loop over user prompts and store responses 
vector<double> DataInput::inputCapture() {
	// collect user input and organize in a vector
	vector<double> responses;
	vector<string> prompts = getMUserPrompts();

	for (int i = 0; i < prompts.size(); ++i) {
		string prompt = prompts.at(i);
		double userInput;
		cout << prompt;
		cin >> userInput;

		// check for valid user input to be more than 0.01
		if (!cin || userInput < 0.01) {
			throw invalid_argument("\n\nAlphabetical characters and amounts less than 0.01 not allowed. \n\n"
				"Please try again. \n\n");
		}

		// add user input to vector
		responses.push_back(userInput);
	}
	return responses;
}

// Abstract method for validating specific enter key presses
bool DataInput::enterCheck() {
	cout << "Press enter to continue . . . \n\n\n";
	return cin.get() == '\n';
}