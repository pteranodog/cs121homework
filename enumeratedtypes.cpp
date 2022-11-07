//
// CS 121 Enumeration Types
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

enum days {SUN, MON, TUE, WED, THU, FRI, SAT};

int main(void) {

	double high_temp[7];
	double low_temp[7];
	int k;

	typedef float real; // Created alias for "float"

	typedef double temperature[7]; 
	temperature high, low;
	high[1] = 89.0;
	low[1] = 75.2;

	days my_week = MON;
	days today = FRI;

	cout << "Today is " << today << endl;

	for (k = SUN; k <= SAT; k++) {
		cout << "Enter high temp for day " << k << ": ";
		cin >> high_temp[k];
		cout << "Enter low temp for day " << k << ": ";
		cin >> low_temp[k];
	}
	
	cout << endl << endl;
	system("pause");
}

