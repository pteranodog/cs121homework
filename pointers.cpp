// Pointer intro

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int main(void) {
    int *ptr = new int;
    while (true) {
        cout << *ptr << endl;
        ptr += 1;
    }
}