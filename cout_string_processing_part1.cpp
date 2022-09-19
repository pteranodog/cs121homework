//
// Program to illustrate functions on a string constant
// Functions: length, size, find, substr, at
//


#include    <iostream>
#include    <fstream>
#include    <iomanip>
#include    <string>

using       namespace   std;

int         main(void)
{
	// Variables

	string sentence = "CS 121 meets from 1:00 to 2:20 on Monday and Wednesday.";
	string ecnetnes = "";
	char letter;                                             
	unsigned int len = 0, position = 0, i = 0;
	
	cout << "STRING PROCESSING FUNCTIONS" << endl << endl;
	cout << "The sentence is:" << endl;
	cout << sentence << endl << endl;

	cout << "length "<< endl;
    len = sentence.length();
    cout << "The length of the sentence is " << len << endl;

	cout << "size "<< endl;
    cout << "The size of the sentence is " << sentence.size() << endl;
	
	cout << "find "<< endl;
    position = sentence.find("1234");
    // ALWAYS DO A TEST FOR string::npos AFTER A FIND OPERATION
    if (position == string::npos) {
        cout << "The substring '1234' was not found" << position << endl;
    } else {
        cout << "The substring '1234' is at position " << position << endl;
    }
    cout << "find all" << endl;
    position = sentence.find("1");
	if (position > sentence.length()) {
        cout << "The substring '1' was not found" << position << endl;
    } else {
        cout << "The substring '1' is at position " << position << endl;
        while (position <= sentence.length()) {
            position = sentence.find("1", position + 1);
            if (position > sentence.length()) {
                cout << "All substrings found." << endl;
            } else {
                cout << "The substring '1' is at position " << position << endl;
            }
        }
    }

	cout << "The substring of 10 characters at position 7 is: "<< endl;
    // substr()

	cout << "The character at position 20 is: "; 
    // at()
    // string[]


	cout << "Reverse the sentence." << endl << endl;

	system("pause");
	return 0;
}