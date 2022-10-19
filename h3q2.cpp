#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <math.h>

using namespace std;

string reverse(string line);

int main(void) {
    char answer = 'n';
    bool repeat = false;

    do {
        cout << "Enter a binary number to convert to decimal: ";
        string binary;
        cin >> binary;
        int decimal = 0;
        int power = 0;
        for (int i = binary.length() - 1; i >= 0; i--) {
            if (binary[i] == '1') {
                decimal += pow(2, power);
            }
            power++;
        }
        cout << "Decimal: " << decimal << endl;
        cout << "Would you like to try again? (y/n) ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y') {
            repeat = true;
        } else {
            repeat = false;
        }
    } while (repeat);
}