//
// Program to input and output mixed data types.
// Types: String, Char, Integer, Float, Double
//
// Output format operations: left, setprecision(), setfill( ), setw( ) and fixed.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main(void)
{
	string firstname = "";
	string lastname = "";
	char initial;
	unsigned int employee_no = 0;
	float wage = 0.0, hours = 0.0;
	double pay = 0.0;

	cout << fixed << setprecision(2);

	cout << "Employee Record Database\n\n";

	cout << "Enter the following information for each employee:\n\n";
	cout << "Last Name  First Name  Middle Initial  ID Number  Wage  Hours Worked";
	cout << endl << endl;

	cin >> lastname >> firstname >> initial >> employee_no >> wage >> hours;
	cout << endl << left << setfill('-');
	cout << setw(20) << "Last Name:" << lastname << endl;
	cout << setw(20) << "First Name:" << firstname << endl;
	cout << setw(20) << "Middle Initial:" << initial << endl;
	cout << setw(20) << "ID Number:" << employee_no << endl;
	cout << setw(19) << "Wage:" << '$' << wage << endl;
	cout << setw(20) << "Hours Worked:" << hours << endl;

	pay = wage * hours;

	cout << setw(19) << "Weekly Pay:" << '$' << pay << endl;




	cout << endl << endl;
	system("pause"); // Windows only
	return 0;
}