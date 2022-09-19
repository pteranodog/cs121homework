//
// Program to illustrate functions on the input stream - cin
// Functions: getline, get, ignore, peek, putback, 
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main(void)
{
	// Variables

	string indata = "";
    string remainder = "";
	char ch1 = ' ', ch2 = ' ', ch3 =' ', ch4 = ' ', ch5 = ' ';
	unsigned int j = 0;
	int number = 0;
    unsigned int hrs, mins, seconds;
    float value;
	
	cout << "PROCESSING DATA FROM the INPUT BUFFER" << endl << endl;
    cout << "CASE 1. Read all the data one character at a time with cin.get()" << endl;
    cout << "Enter this data exactly as shown" << endl;
    cout << "QXR03:30:15U150.33" << endl;

    while (ch1 != '\n') {
        cin.get(ch1);
        cout << ch1;
    }

    cout << endl << endl;
    cout << "CASE 2. Read all the data at once with getline(cin, indata)." << endl;
    cout << "Enter this data exactly as shown" << endl;
    cout << "QXR03:30:15U150.33" << endl;

    getline(cin, indata);
    cout << indata;

    cout << endl << endl;
	cout << "CASE 3. Ignore the first 3 characters then read the time. " << endl;
    cout << "Enter this data exactly as shown" << endl;
    cout << "QXR03:30:15U150.33" << endl;

    cin.ignore(3);
    while (ch1 != 'U') {
        cin.get(ch1);
        cout << ch1;
    }
    getline(cin,remainder);
    cout << endl << "Remainder of IB:" << remainder;

    cout << endl << endl;
    cout << "CASE 4. Ignore the first 3 characters, peek at each one until U is reached. " << endl;
    cout << "        Read the time again. " << endl;
    cout << "Enter this data exactly as shown" << endl;
    cout << "QXR03:30:15U150.33" << endl;








    cout << endl << endl;

    cout << "CASE 5. cin. Putback(ch) "
		 << "        Extract the time leaving the rest of the data in the input buffer " << endl;
    cout << "Enter this data exactly as shown" << endl;
    cout << "QXR03:30:15U150.33" << endl;








    cout << endl << endl;

    cout << "CASE 6. Read the mixed input with cin" << endl;
    cout << "Enter this data exactly as shown" << endl;
    cout << "QXR03:30:15U150.33" << endl;







	system("pause"); // Windows only
	return 0;

  }  