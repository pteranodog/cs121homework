#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Function prototypes
unsigned int leap(unsigned int year);
unsigned int days_in_month(unsigned int month, unsigned int year);
bool valiDATE(unsigned int mm, unsigned int dd, unsigned int yyyy);

int main() {
    unsigned int mm = 0, dd = 0, yyyy = 0;
    unsigned int i = 0;
    char answer = 'Y';

    do {
        cout << "Enter a date in the form MM DD YYYY: ";
        cin >> mm >> dd >> yyyy;
        
        while (!valiDATE(mm, dd, yyyy)) {
            cout << "Invalid date. Please re-enter: ";
            cin >> mm >> dd >> yyyy;
        }
        cout << "The date is valid." << endl;
        cout << "Do you want to enter another date? (Y/N): ";
    } while (answer == 'Y' || answer == 'y');

    return 0;
}

// functions go here

//
// Function: leap
// Input: year, type unsigned int
// Output: 1 if year is a leap year, 0 otherwise

unsigned int leap(unsigned int year) {
    if (year % 400 == 0) {
        return 1;
    } else if (year % 100 == 0) {
        return 0;
    } else if (year % 4 == 0) {
        return 1;
    } else {
        return 0;
    }
}

//
// Function: days_in_month
// Input: month, type unsigned int
//        year, type unsigned int
// Output: number of days in month, type unsigned int

unsigned int days_in_month(unsigned int month, unsigned int year) {
    if (month == 2) {
        return 28 + leap(year);
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

//
// Function: valiDATE
// Input: mm, type unsigned int
//        dd, type unsigned int
//        yyyy, type unsigned int
// Output: true if date is valid, false otherwise

bool valiDATE(unsigned int mm, unsigned int dd, unsigned int yyyy) {
    if (mm < 1 || mm > 12) {
        cout << "Invalid month" << endl;
        return false;
    } else if (dd < 1 || dd > days_in_month(mm, yyyy)) {
        cout << "Invalid day" << endl;
        return false;
    } else if (yyyy < 1900 || yyyy > 2100) {
        cout << "Invalid year" << endl;
        return false;
    } else {
        cout << "Valid date" << endl;
        return true;
    }
}
