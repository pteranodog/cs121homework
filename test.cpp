#include <iostream>

using namespace std;

int main()
{
    int cents;
    int hundreds = 0, fifties = 0, twenties = 0, tens = 0, fives = 0, twos = 0, ones = 0;
    int halves = 0, quarters = 0, twimes = 0, dimes = 0, nickels = 0, doubles = 0, pennies = 0;
    cout << "Enter the remaining value in cents: ";
    cin >> cents;
    while (cents > 0) {
        pennies += 1;
        if (pennies == 2) {
            pennies = 0;
            doubles += 1;
        }
        if (doubles == 2 && pennies == 1) {
            doubles = 0;
            pennies = 0;
            nickels += 1;
        }
        if (nickels == 2) {
            nickels = 0;
            dimes += 1;
        }
        if (dimes == 2) {
            dimes = 0;
            twimes += 1;
        }
        if (twimes == 1 && nickels == 1) {
            twimes = 0;
            nickels = 0;
            quarters += 1;
        }
        if (quarters == 2) {
            quarters = 0;
            halves += 1;
        }
        if (halves == 2) {
            halves = 0;
            ones += 1;
        }
        if (ones == 2) {
            ones = 0;
            twos += 1;
        }
        if (twos == 2 && ones == 1) {
            twos = 0;
            ones = 0;
            fives += 1;
        }
        if (fives == 2) {
            fives = 0;
            tens += 1;
        }
        if (tens == 2) {
            tens = 0;
            twenties += 1;
        }
        if (twenties == 2 && tens == 1) {
            twenties = 0;
            tens = 0;
            fifties += 1;
        }
        if (fifties == 2) {
            fifties = 0;
            hundreds += 1;
        }
        // cout << hundreds << "\t" << fifties << "\t" << twenties << "\t" << tens << "\t" << fives << "\t" << twos << "\t" << ones << "\t" << halves << "\t" << quarters << "\t" << dimes << "\t" << nickels << "\t" << pennies << endl;
        cout << hundreds + fifties + twenties + tens + fives + twos + ones + halves + quarters + twimes + dimes + nickels + doubles + pennies << endl;
        cents -= 1;
    }
    cout << "Hundreds:\t" << hundreds << "\t" << endl;
    cout << "Fifties:\t" << fifties << "\t" << endl;
    cout << "Twenties:\t" << twenties << "\t" << endl;
    cout << "Tens:\t\t" << tens << "\t" << endl;
    cout << "Fives:\t\t" << fives << "\t" << endl;
    cout << "Twos:\t\t" << twos << "\t" << endl;
    cout << "Ones:\t\t" << ones << "\t" << endl;
    cout << "Halves:\t\t" << halves << "\t" << endl;
    cout << "Quarters:\t" << quarters << "\t" << endl;
    cout << "Twimes:\t\t" << twimes << "\t" << endl;
    cout << "Dimes:\t\t" << dimes << "\t" << endl;
    cout << "Nickels:\t" << nickels << "\t" << endl;
    cout << "Doubles:\t" << doubles << "\t" << endl;
    cout << "Pennies:\t" << pennies << "\t" << endl;       
    system("pause");
    return 0;
}