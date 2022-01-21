#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <random>
#include <algorithm>

using namespace std;

int main(int argc, char **argv) {

	if (argc != 3) {
		cout << "Error: expecting 2 arguments!" << '\n';
		return 1;
	}

	int minChar, maxChar;
	
	cout << "Minimum number of characters:";
	cin >> minChar; 
	cout << "Maximum number of characters:";
	cin >> maxChar;

	cout << "Type \"EXIT\" or \"Ctrl + Z\" to exit." << "\n\n";

	string word;

	vector <string> wordarr;

	random_device rd;
	mt19937 gen(rd());

	string filepath = "words/";

	ifstream wordfile (filepath.append(argv[1]));

	while (getline(wordfile, word)) {
		if (word.size() >= minChar && word.size() <= maxChar) {
			wordarr.push_back(word);
		}
	}

	string input;
	cin.ignore();
	while (input.compare("EXIT") != 0) {

		shuffle(wordarr.begin(), wordarr.end(), gen);
		
		for (int i = 0; i < stoi(argv[2]); i++) {
			cout << wordarr[i] << ' ';
		}
		cout << '\n';
		getline(cin, input);
	}

	return 0;
}
