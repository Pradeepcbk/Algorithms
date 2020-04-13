#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <functional>
#include <stack>
#include <unordered_map>

#define MAXCOUNTER 2

using namespace std;

vector<char> myVector = { 'p','r','o','g','r','a','m','m','e','r' };
int stringCounter;

map<char, int> expectedCharOccurence;
map<char, int> charOccurence;
int indexLastCharacterFirstStringOccurence, indexFirstCharacterSecondStringOccurence;


bool findChar(char ch, int index) {
	if (charOccurence[ch] < expectedCharOccurence[ch]) {
		charOccurence[ch]++;
	}
	if (charOccurence[ch] <= expectedCharOccurence[ch]) {
		// If the string has already occured and if it is the first character of the second occurence of the string, store the idnex
		if (stringCounter == 1) {
			if (!indexFirstCharacterSecondStringOccurence) {
				indexFirstCharacterSecondStringOccurence = index;
			}
		}
	}
	if (charOccurence == expectedCharOccurence) {
		stringCounter++;
		charOccurence.clear();
		return true;
	}
	else return false;
}

int main() {

	string line;
	int result = -1;

	cout << "Enter the string" << endl;

	getline(cin, line);

	for (int i = 0;i<myVector.size();i++) {
		expectedCharOccurence[myVector[i]]++;
	}

	for (int i = 0;i < line.size();i++) {
		char character = line[i];
		// Check if the character makes the string "programmer" in any permutation
		if (find(myVector.begin(), myVector.end(), character) != myVector.end()) {
			bool compare = findChar(character, i);
			if (compare) {
				// if the string appears for the first time, store its index
				if (stringCounter == 1) {
					indexLastCharacterFirstStringOccurence = i;
				}
				else if (stringCounter == 2) {
					result = indexFirstCharacterSecondStringOccurence - indexLastCharacterFirstStringOccurence;
				}
			}
		}
	}

	if (result != -1) {
		cout << "The result is " << result - 1 << endl;
	}
	else {
		cout << "No string found" << endl;
	}

	return 0;
}
