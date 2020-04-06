#include<iostream>
#include <algorithm>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int romanToInt(string s) {
    map<char, int> roman;
    roman['L'] = 50;
    roman['X'] = 10;
    roman['V'] = 5;
    roman['I'] = 1;

    int intValue = 0;
    for (int i = 0; i < s.size() - 1; ++i)
    {
        if (roman[s[i]] < roman[s[i + 1]])
            intValue -= roman[s[i]];
        else
            intValue += roman[s[i]];
    }
    intValue += roman[s[s.size() - 1]];
    return intValue;
}

bool compare(string S1, string S2){
    char* charS1 = &S1[0];
    char* charS2 = &S2[0];
    while (*charS1 != ' ' && *charS2 != ' '){
        if (*charS1 < *charS2){
            return true;
        }
        else if (*charS1 > *charS2){
            return false;
        }
        else{
            charS1++;
            charS2++;
        }
    }
    if (*charS1 != ' ') return false;
    else if (*charS2 != ' ') return true;
    else{
        charS1++;
        charS2++;
        string tempS1(charS1);
        int intS1 = romanToInt(tempS1);
        string tempS2(charS2);
        int intS2 = romanToInt(tempS2);
        if (intS1 > intS2) return false;
        else return true;
    }
}

vector<string> getSortedList(const vector<string>& names) {
    vector<string> result = names;
    sort(result.begin(), result.end(), compare);
    return result;
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));
	string names_count_temp;
	getline(cin, names_count_temp);
	int names_count = stoi(ltrim(rtrim(names_count_temp)));
	vector<string> names(names_count);
	for (int i = 0; i < names count; i++) {
		string names_item;
		getline(cin, names_item);
		names[i] = names_item;
	}
	vector<string> res = getSortedList(names);
	for (int i = 0; i < res.size(); i++) {
		fout << res[i];
		if (i != res.size() - 1) {
			fout << "\n";
		}
	}
	fout << "\n";
	fout.close();
	return 0;
}
string ltrim(const string &str) {
	string s(str);
	s.erase(
	s.begin(),
	find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
	return s;
}
string rtrim(const string &str) {
	string s(str);
	s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),s.end());
	return s;
}
