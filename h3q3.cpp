#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <math.h>

using namespace std;

string capitalizeFirst(string line);
string toLowerCase(string line);

int main(void) {
    char answer = 'n';
    bool repeat = false;
    ifstream dictionaryfile;
    dictionaryfile.open("D:\\GitHubRepos\\cs121homework\\datafiles\\dictionary.txt");
    if (!dictionaryfile) {
        cout << "Unable to open dictionary file." << endl;
        system("pause");
        return 1;
    }
    string dictionary[4030];
    for (int i = 0; i < 4030; i++) {
        dictionaryfile >> dictionary[i];
    }
    do {
        cout << "Enter a four-letter word to check if it is spelled correctly: ";
        string word;
        cin >> word;
        word = toLowerCase(word);
        bool found = false;
        for (int i = 0; i < 4030; i++) {
            if (word == dictionary[i]) {
                found = true;
                break;
            }
        } 
        word = capitalizeFirst(word);
        if (found) {
            cout << word << " is spelled correctly." << endl;
        } else {
            cout << word << " is not spelled correctly." << endl;
        }
        cout << "Would you like to try again? (y/n) ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y') {
            repeat = true;
        } else {
            repeat = false;
        }
    } while (repeat);
    system("pause");
    return 0;
}

string toLowerCase(string line)
{
    string lower_line = "";
    int position = 0;
    for (position = 0; position < line.length(); position++)
        lower_line += tolower(line.at(position));
    return lower_line;
}

string capitalizeFirst(string line)
{
    line[0] = toupper(line[0]);
    return line;
}