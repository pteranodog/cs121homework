//
// Program to illustrate cout options with a type double constant
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main(void)
{
	double PI = 3.14159256;
    double bignum = 34876.237;

	cout << "OUTPUT OPTIONS" << endl << endl;
	cout << "PI in Scientific Format "<< endl;

	// Set scientific 
	cout << scientific;
    cout << PI << endl;
    cout << bignum << endl;

	// Set fixed
    cout << endl << "Fixed format" << endl;
    cout << fixed;
    cout << PI << endl;
    cout << bignum << endl;

	// Set field width and precision
	cout << endl << "PI in Fixed Format with width and precision set "<< endl;
	// 4 digits right of decimal
	cout << setprecision(4);
    cout << PI << endl;
    cout << bignum << endl;
	// 10 space output field
    cout << setw(10);
    cout << PI << endl;
    cout << bignum << endl;

	// Width of 6 with 2 digits right of decimal
    cout << setprecision(2) << setw(6) << PI << endl << bignum << endl;


	// Width of 6 with 6 digits right of decimal. Output expands to cover the number.
    cout << setprecision(2) << setw(6) << PI << endl << setw(6) << bignum << endl;
			

	system("pause"); // Windows only
	return 0;
}