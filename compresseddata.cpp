//
// Program to input and output mixed data types.
// Types: unsigned int and char
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main(void)
{
	// Variables for packed data YYYY.MM.DDPLXDC

    unsigned int year;              // YYYY : Year
    unsigned int month;             // MM : Month
    unsigned int day;               // DD : Day
    char product_id;                // P : Product ID
    unsigned int factory_loc;       // L : Factory Location (integer)
    char quality_flag;              // X : Quality Flag
    char inspector;                 // D : Inspector
    char package_type;              // C : Package Type
	char dot;

	cout << "PRODUCT CODE" << endl << endl;
	cout << "Enter the product code as YYYY.MM.DDPLXDC" << endl;

	cin >> year >> dot >> month >> dot >> day >> product_id >> factory_loc >> quality_flag >> inspector >> package_type;

    cout << endl << year << endl << month << endl << day << endl << product_id << endl << factory_loc <<
    endl << quality_flag << endl << inspector << endl << package_type;

    cout << left << endl << endl;
    cout << setw(17) << "Date:" << year << dot << month << dot << day << endl;
    cout << setw(17) << "Product ID:" << product_id << endl;
    cout << setw(17) << "Factory Location:" << factory_loc << endl;
    cout << setw(17) << "Quality Flag:" << quality_flag << endl;
    cout << setw(17) << "Inspector:" << inspector << endl;
    cout << setw(17) << "Package Type:" << package_type;


    cout << endl << endl;
	system("pause"); // Windows only
	return 0;
}