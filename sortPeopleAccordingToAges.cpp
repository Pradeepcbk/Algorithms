/**
* @section License
*
* The MIT License (MIT)
*
* Copyright (c) 2017, Prajwal Nagaraja
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

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include<fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <functional>
#include<string>

using namespace std;

class Person {
	private:
		int age;
		string name;
	public:
		Person(string s, int n): name(s), age(n){}
		int getAge() {
			return age;
		}
		string getName() {
			return name;
		}
};

bool compare(Person p1, Person p2) {
	return p1.getAge() > p2.getAge();
}

int main() {
	int n, age;				// Number of people, their age
	string name;			// Name of the people
	cout << "Enter the number of people \n";
	cin >> n;
	cout << "Enter data in the format: Name Age \n";
	vector<Person> myVector;
	for (int i = 0; i < n;i++) {
		cin >> name >> age;
		Person p(name, age);
		myVector.push_back(p);
	}
	sort(myVector.begin(), myVector.end(), compare);
	cout << "The list of people in the decreasing order of their age is: \n";
	for (auto personCounter : myVector) {
		cout << personCounter.getName() + " " << personCounter.getAge() << endl;
	}

	return 0;
}
