#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 3) return -1;

	std::fstream copied_file, new_file;
	copied_file.open(argv[1], ios::in);
	new_file.open(argv[2], ios::out);

	if (new_file.is_open()) cout << "Opened: " << argv[2] << endl;
	if (copied_file.is_open()) cout << "Opened: " << argv[1] << endl;


	std::string buffor;
	while (getline(copied_file, buffor)) {
		cout << buffor << endl;
		new_file << buffor;
	}

	copied_file.close();
	new_file.close();
	return 0;
}