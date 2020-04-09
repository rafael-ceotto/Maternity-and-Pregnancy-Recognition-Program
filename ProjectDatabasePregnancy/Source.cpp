#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

//Global Variables

const int ROWS = 4;
const int COLS = 4;

//Prototype functions


void showPatientInformation(string[], string[][COLS]);

void showBabyInformation(string[], string[][COLS]);

void showMaternityInformation();

void showWeightInformation();

//Variables

double dbl, dbl1, dbl2, dbl3;

int menuChoice;

//Main function

int main() {


	ifstream patientName, patientInfo, babyName, babyInfo;
	patientName.open("patientName.txt");
	patientInfo.open("patientInfo.txt");
	babyName.open("babyName.txt");
	babyInfo.open("babyInfo.txt");

	string PATIENT_IDENTIFICATION[ROWS];
	string PATIENT_DATA[ROWS][COLS];
	string BABY_IDENTIFICATION[ROWS];
	string BABY_DATA[ROWS][COLS];

	string  momsData, nameIn, babyData;
	string momsName, specificBabyName;

	if (patientName && patientInfo) {
		for (int row = 0; row < ROWS; row++) {
			patientName >> momsName;
			
			PATIENT_IDENTIFICATION[row] = momsName;
			
			for (int col = 0; col < COLS; col++) {
				patientInfo >> momsData;
				PATIENT_DATA[row][col] = momsData;

			}
		}

	} else{
		cout << "Sorry, the database file wasn't found" << "\n";
	}

	if (babyName && babyInfo) {
		for (int row = 0; row < ROWS; row++) {
			babyName >> specificBabyName;

			BABY_IDENTIFICATION[row] = specificBabyName;

			for (int col = 0; col < COLS; col++) {
				babyInfo >> babyData;
				BABY_DATA[row][col] = babyData;

			}
		}

	}
	else {
		cout << "Sorry, the database file wasn't found" << "\n";
	}






	do {

		cout << "Welcome to Baby Boom World" << "\n";

		cout << "Press one of the numbers below to display the information requested" << "\n";

		cout << "1 - Display information about Baby's Mom" << "\n" << "2 - Display information about the Baby" << "\n"

			<< "3 - Display information about Maternity" << "\n" << "4 - Display the average of the current weight of the babies" << "\n"
			<< "5 - Terminate the program" << "\n\n";

		cin >> menuChoice; cout << "\n";

		switch (menuChoice) {
		case 1:

			cout << "You've selected information about the Mom" << "\n";
			showPatientInformation(PATIENT_IDENTIFICATION, PATIENT_DATA);
			break;

		case 2:

			cout << "You've selected information about the Baby" << "\n";
			showBabyInformation(BABY_IDENTIFICATION, BABY_DATA);
			break;

		case 3:

			cout << "You've selected information about the Maternity" << "\n";
			showMaternityInformation();
			break;

		case 4:
			
			cout << "You've selected information about the weight average" << "\n\n";
			showWeightInformation();

		default:
			break;
		}

	} while (menuChoice != 5);

	patientName.close();
	patientInfo.close();
	babyName.close();
	babyInfo.close();

	system("pause");

	return 0;



}




void showPatientInformation(string PATIENT_IDENTIFICATION[ROWS], string PATIENT_DATA[ROWS][COLS]) {
	int match = 0;
	string patientName;

	cout << "Enter the name of the patient" << "\n\n";
	cin >> patientName;
	cout << "\n";
	for (int i = 0; i < ROWS; i++) {
		
		if (patientName == PATIENT_IDENTIFICATION[i]) {
			match = 1;
			
			cout << patientName << setw(5) << "Age" << setw(10) << "ZipCode" << setw(13) << "First Child" << setw(16) << "Has Coverage?";
			cout << endl;
			for (int k = 0; k < COLS; k++) {
				cout << right << setw(10) <<  PATIENT_DATA[i][k];
			}
			
		}
		

	}
	if (match == 0) {
		cout << "Sorry, we couldn't find the name of the patient";
	}

	cout << "\n\n";
}


void showBabyInformation(string BABY_IDENTIFICATION[ROWS], string BABY_DATA[ROWS][COLS]) {
	int babyMatch = 0;
	string babyName;

	cout << "Enter the name of the baby" << "\n\n";
	cin >> babyName;
	cout << "\n";
	for (int i = 0; i < ROWS; i++) {

		if (babyName == BABY_IDENTIFICATION[i]) {
			babyMatch = 1;

			cout << babyName << setw(7) << "Sex" << setw(10) << "Weeks" << setw(10) << "Weight" << setw(10) << "Height";
			cout << endl;
			for (int k = 0; k < COLS; k++) {
				cout << right << setw(10) << BABY_DATA[i][k];
			}

		}


	}
	if (babyMatch == 0) {
		cout << "Sorry, we couldn't find the name of the baby";
	}

	
	cout << "\n\n";
}

void showMaternityInformation() {
	
	double incomeValue;
	
	cout << "Welcome to Baby Boom Clinical Center" << "\n";
	cout << "We're specialized on low income patients and can only offer help if your income is lower than $1500.00" << "\n";
	cout << "Please, type your income information" << "\n\n";
	cin >> incomeValue;
	cout << "\n";
	if (incomeValue > 1500.00) {
		cout << "Sorry, you're not eligible for getting some help from us. Please, go to St John Hospital." << "\n\n";
	}
	else {
		cout << "Congratulations! You will receive a call soon!" << "\n";
		cout << "If you have an emergency, please call 955-656-9980." << "\n";
		cout << "We're located at Rainbow Road, 676 - Ohio." << "\n\n";
	}

}

void showWeightInformation() {

	
		
	cout << "Enter the weight of the babies to check the average " << "\n\n";
	cin >> dbl;
	cin >> dbl1;
	cin >> dbl2;
	cin >> dbl3;	
	cout << "\n";	
	cout << "The total weight of the babies on the database is " << setprecision(3) << dbl+dbl1+dbl2+dbl3 << " pounds" << "\n";
	cout << "The average weight of the babies on the database is " << setprecision(3) << (dbl + dbl1 + dbl2 + dbl3)/4.0 << " pounds" << "\n\n";
}
