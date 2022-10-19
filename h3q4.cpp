#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

string reverse(string line);

int main(void) {
    ifstream dictionaryfile;
    dictionaryfile.open("datafiles/dictionary.txt");
    if (!dictionaryfile) {
        cout << "Unable to open dictionary file." << endl;
        system("pause");
        return 1;
    }
    string dictionary[4030];
    for (int i = 0; i < 4030; i++) {
        dictionaryfile >> dictionary[i];
    }
    for (int i = 0; i < 4030; i++) {
        if (reverse(dictionary[i]) == dictionary[i]) {
            cout << dictionary[i] << endl;
        }
    }
    system("pause");
    return 0;
}

string reverse(string line) {
	string invert_line = "";
	int position = 0;

	for (position = line.length() - 1; position >= 0; position--)
		invert_line += line.at(position);

	return invert_line;
}