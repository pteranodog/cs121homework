#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

const unsigned int dim = 10;
const unsigned int wordSize = 4;
const unsigned int dictLength = 4030;
void loadDictionary(string dict[]);
void findWords(string line, string dict[]);
void findWordsInLine(string line, string dict[], bool reversed);
string getRow(string line, int row);
string getColumn(string line, int column);
string transpose(string line);
string reverse(string line);

int main(void) {
    string dictionary[dictLength];
    loadDictionary(dictionary);
    string puzzle = "prubackegsesoreeatedemoodlcentktllableadmsrkradmafflootijotvsarxstmicenmtalktsudoxquitxmubdatasetlas";
    findWords(puzzle, dictionary);
    system("pause");
    return 0;
}

void loadDictionary(string dict[]) {
    ifstream dictionaryfile;
    dictionaryfile.open("D:\\GitHubRepos\\cs121homework\\datafiles\\dictionary.txt");
    if (!dictionaryfile) {
        cout << "Unable to open dictionary file." << endl;
        system("pause");
        return;
    }
    for (int i = 0; i < dictLength; i++) {
        dictionaryfile >> dict[i];
    }
}

void findWords(string line, string dict[]) {
    for (int i = 0; i < dim; i++) {
        cout << "Row " << i + 1 << ":\t\t";
        findWordsInLine(getRow(line, i), dict, false);
        findWordsInLine(getRow(line, i), dict, true);
        cout << endl;
    }
    line = transpose(line);
    for (int i = 0; i < dim; i++) {
        cout << "Column " << i + 1 << ":\t";
        findWordsInLine(getRow(line, i), dict, false);
        findWordsInLine(getRow(line, i), dict, true);
        cout << endl;
    }
}

void findWordsInLine(string line, string dict[], bool reversedWords) {
    if (reversedWords) {
        line = reverse(line);
    }
    for (int i = 0; i < dictLength; i++) {
        if (line.find(dict[i]) != string::npos) {
            cout << dict[i] << " ";
        }
    }
}

string getRow(string line, int row) {
    string rowString = "";
    for (int i = 0; i < dim; i++) {
        rowString += line.at(row * dim + i);
    }
    return rowString;
}

string getColumn(string line, int column) {
    string columnString = "";
    for (int i = 0; i < dim; i++) {
        columnString += line.at(i * dim + column);
    }
    return columnString;
}

string transpose(string line) {
    string transposed = "";
    for (int i = 0; i < dim; i++) {
        transposed += getColumn(line, i);
    }
    return transposed;
}

string reverse(string line) {
	string invert_line = "";
	int position = 0;

	for (position = line.length() - 1; position >= 0; position--)
		invert_line += line.at(position);

	return invert_line;
}