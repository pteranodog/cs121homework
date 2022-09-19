//
// Program to read and print data from a file
//
// Introduces fstream, file open, file read, file close.
//
// NOTE: The data file temps.txt
// must be saved into the Temp/Data directory before running this program.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main(void)
{

	ifstream infile;	
    float temperature_F;

    infile.open("C:/Temp/temps.txt");
    if (!infile) {
        cout << "Unable to open input file." << endl;
        system("pause");
        return 2;
    }

    cout << "File opened successfully." << endl;

    infile >> temperature_F;
    cout << temperature_F << endl;

	system("pause");
	return 0;
}