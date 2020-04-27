/*!**************************************************************************/
/*	\file 		lexicographicallyLargestSubstring.cpp
 *
 *	\description 	Find the lexicographically largest substring
 *	\author		Pradeep Siddagangaiah
 *	\date		17-April-2020
 */
/***************************************************************************/

/** Test case
 * input: sadrszz
 * output: zz
*/

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

int main() {
	string line;

	cout << "Enter the string:" << endl;

	getline(cin, line);
	string largestSubstring = "\0";

	for (int j = 0;j < line.size();j++) {
		largestSubstring = max(line.substr(j), largestSubstring);
	}

	cout << "The largest substring is " << largestSubstring << endl;
	return 0;
}

/**
* input: sadrszz
* output: zz
*/
