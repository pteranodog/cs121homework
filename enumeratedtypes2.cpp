
//
// More Enumeration Examples
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;
enum months { JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
enum state_codes {AL, AK, AZ, AR, CA, CO, CT, DE, DC, FL,
	              GA, HI, ID, IL, IN, IA, KS, KY, LA, ME,
	              MD, MA, MI, MN, MS, MO, MT, NE, NV, NH,
	              NJ, NM, NY, NC, ND, OH, OK, OR, PA, RI,
	              SC, SD, TN, TX, UT, VT, VA, WA, WV, WI, WY};

string get_month_name(months mm);
int main(void)
{
	ifstream infile;
	unsigned int month_days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31 , 30, 31 };
	string month_names[12] = {"January","February","March","April","May","June",
					  "July","August","September","October","November","December" };
	unsigned int population[51] = { 0 };
	unsigned int k = 0, southpop = 0;

	infile.open("C:/Data/population.txt");
	if (!infile)
	{
		cout << "Error opening file." << endl;
		return 1;
	}
	cout << "File opened for reading." << endl;



	cout << setw(8) << "MONTH" << setw(5) << "DAYS" << endl;



	cout << endl << endl;

	// A different way that prints the name of the month
	cout << setw(10) << "MONTH" << setw(5) << "DAYS" << endl;


	// Get the population of the southern states

	cout << "The population of the southern states is: " << southpop << endl;
	cout << endl << endl;


	// Print out the months of spring
	cout << "Spring Months" << endl;
	cout << setw(10) << "MONTH" << setw(5) << "DAYS" << endl;

	cout << endl << endl;

	// Print out the names of the spring months using a function

	cout << "Spring Months" << endl;
	cout << setw(10) << "MONTH" << setw(5) << "DAYS" << endl;


	cout << endl << endl;
	system("pause");
	return 0;
}


string get_month_name(months mm)
{
	string name;

	switch (mm)
	{
	case JAN: name = "January"; break;
	case FEB: name = "February"; break;
	case MAR: name = "March"; break;
	case APR: name = "April"; break;
	case MAY: name = "May"; break;
	case JUN: name = "June"; break;
	case JUL: name = "July"; break;
	case AUG: name = "August"; break;
	case SEP: name = "September"; break;
	case OCTG: name = "October"; break;
	case NOV: name = "November"; break;
	case DEC: name = "December"; break;
	}
	return name;
}