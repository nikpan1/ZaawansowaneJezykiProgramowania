#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    ifstream inputFile(filename.c_str());
    if (!inputFile.is_open()) {
        cerr << "Failed to open the file.\n";
        return 1;
    }

    map<string, int> wordMap;
    string word;
    while (inputFile >> word) {
        wordMap[word]++;
    }

    inputFile.close();

    cout << "The file contains " << wordMap.size() << " different words.\n";
    return 0;
}
