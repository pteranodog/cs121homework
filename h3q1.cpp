#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int main(void) {
    unsigned int page = 0;
    unsigned int column = 0;
    unsigned int line = 0;
    unsigned int entry = 0;
    char answer = 'n';
    bool repeat = false;

    do {
        cout << "What entry are you looking for? ";
        cin >> entry;
        page = entry / 180 + 1;
        column = (entry % 180) / 60 + 1;
        line = (entry % 180) % 60;
        cout << "Page: " << page << endl;
        cout << "Column: " << column << endl;
        cout << "Line: " << line << endl;
        cout << "Would you like to try again? (y/n) ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y') {
            repeat = true;
        } else {
            repeat = false;
        }
    } while (repeat);
    cout << "Thank you for using the telephone book!" << endl;
    system("pause");
    return 0;
}