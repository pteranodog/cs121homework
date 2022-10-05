//
// CS 121 Introduction to character arrays
// This program illustrates single dimensional character arrays
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main(void) 
{
	//
	// Part One: Declare some arrays and print out elements
	//

	char ch1 = 'A', ch2 = 'B', ch3 = 'C', ch4 = 'D';
	char letters[15] = "CS 121";
	char items[15];
	char alphabet[27];
	short int ch5;
	unsigned int j = 0, k = 0;
	string name_one = "Briana", name_two = "Roger";

	cout << "CHARACTER ARRAY EXAMPLES" << endl << endl;

    items[1] = ch2;
    items[2] = ch3;

	cout <<  "Initial data in array items : " << items << endl;

	// Add string terminator
    items[3] = '\0';

	cout <<  "items with string terminator: " << items << endl;

	cout << "Use cin: Enter a series of letters: " << endl;


	cout << "The letters array contains " << letters << endl;

	cin.ignore(100, '\n'); // Clear the rest of the buffer

	cout << "Use cin.get: Enter a string for array letters: " << endl;



	cout << "The letters array contains " << letters << endl;

	cin.ignore(100, '\n'); // Clear the rest of the buffer

	// Print the array with a loop 



	// Compare and copy character arrays.



	// Compare two character arrays.


	cout << endl << endl;

	cout << "Case 1: Initialize the letters array using ASCII codes." << endl;

	// Initialize the character array



	// Print out the character array
	
	cout << alphabet;

	cout << endl << endl;

	cout << "Case 2: Initialize the alphabet array using characters." << endl;


	// Print out the character array
	
	cout << alphabet;
	cout << endl << endl;

	cout << "Case 3: Initialize the alphabet using characters as indices." << endl;

	

	// Print out the character array

	

	cout << endl << endl;

	// Characters can be integers and integers can be characters


	cout << endl << endl;
	system("pause");
	return 0;
	}