#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    ifstream inputFile(filename.c_str()); // open the input file
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

    for (auto& pair : wordMap) {
        cout << pair.first << ": " << pair.second << endl;
    }
    return 0;
}
