//
// Program to input and output mixed data types.
// Types: String, Char, Integer, Float, Double
//
// Output format operations: left, setprecision(), setfill( ), setw( ) and fixed.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int main(void)
{
	string firstname;
	string lastname;
	char initial;
	unsigned int employee_no;
	float wage, hours;
	double pay;

    

    // Open a file for output

    ofstream outfile; // file pointer
    outfile.open("C:/Temp/employee_dat.txt");
    // Test to see if file opened successfully
    if (!outfile) {
        outfile << "Unable to open the output file." << endl;
        return 1;
    }

    outfile << fixed << setprecision(2);
    cout << "File opened successfully." << endl;
    system("pause");


	cout << "Employee Record Database\n\n";

	cout << "Enter the following information for each employee:\n\n";
	cout << "Last Name  First Name  Middle Initial  ID Number  Wage  Hours Worked";
	cout << endl << endl;

	cin >> lastname >> firstname >> initial >> employee_no >> wage >> hours ;

	outfile << endl;
    outfile << setfill('.');
	outfile << left << setw(20) << "Last Name:" << lastname << endl;
	outfile << left << setw(20) << "First Name:" << firstname << endl;
	outfile << left << setw(20) << "Initial:" << initial << endl;
	outfile << left << setw(20) << "Employee Number" << employee_no << endl;
    outfile << fixed << setprecision (2);
	outfile << left << setw(20) << "Wage Per Hour:"  << wage << endl;
	outfile << left << setw(20) << "Hours Worked:" << hours << endl << endl;

	pay = hours * wage;

	outfile << endl << "Pay for the week $" << fixed << setprecision(2) << pay << endl << endl;

    outfile.close();
    cout << "Data saved and file closed." << endl;
	system("pause");
	return 0;
}