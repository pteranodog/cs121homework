//
// C++ Program Template
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main(void) {

    // define

    double length = 0.0;
    double width = 0.0;
    double area = 0.0;
    double perimeter = 0.0;

    // use cout to output information to the screen

    cout << "Program to compute and output the perimeter "
         << "and area of a rectangle "
         << "to the screen." << endl;

    // get user input for length and width

    cout << "Enter values for length and width:" << endl;
    cin >> length >> width;

    // calculate

    perimeter = length * 2 + width * 2;
    area = length * width;

    // display

    cout << "Length = " << length << endl;
    cout << "Width = " << width << endl;
    cout << "Perimeter = " << perimeter << endl;
    cout << "Area = " << area << endl;

    system("pause");
    return 0;
}
