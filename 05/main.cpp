#include <iostream>
#include <fstream>
#include <string>

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

    int count = 0;
    string word;
    while (inputFile >> word) {
        count++;
    }

    inputFile.close();

    cout << "The file contains " << count << " words.\n";
    return 0;
}
