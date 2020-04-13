/**
* @section License
*
* The MIT License (MIT)
*
* Copyright (c) 2017, Pradeep Siddagangaiah
*
* Permission is hereby granted, free of charge, to any person
* obtaining a copy of this software and associated documentation
* files (the "Software"), to deal in the Software without
* restriction, including without limitation the rights to use, copy,
* modify, merge, publish, distribute, sublicense, and/or sell copies
* of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be
* included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
* BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
* ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
* CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
*/

// In a large string find the distance between substrings corresponding to the word "programmer". The characters need not be in the same order in the string and can be permutated.

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <functional>
#include <stack>
#include <unordered_map>

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

/**
* input: grammerproxxcvprogrammer
* output: 4
*/
