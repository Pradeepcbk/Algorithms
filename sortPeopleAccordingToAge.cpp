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

/**
Problem statement: Given a list of people and their ages, sort them in the descending order of their ages
*/

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

class Person {
	private:
		int age;
		std::string name;
	public:
		Person(std::string s, int n): name(s), age(n){}
		int getAge() {
			return age;
		}
		std::string getName() {
			return name;
		}
};

bool compare(Person p1, Person p2) {
	return p1.getAge() > p2.getAge();
}

int main() {
	int n, age;																				// Number of people, their age
	std::string name;																		// Name of the people
	std::cout << "Enter the number of people \n";
	std::cin >> n;
	std::cout << "Enter data in the format: Name Age \n";
	std::vector<Person> myVector;
	for (int i = 0; i < n;i++) {
		std::cin >> name >> age;
		Person p(name, age);
		myVector.push_back(p);
	}
	// Use the in-build sort library in STL with a custom predicate "compare"
	sort(myVector.begin(), myVector.end(), compare);
	std::cout << "The list of people in the decreasing order of their age is: \n";
	for (auto personCounter : myVector) {
		std::cout << personCounter.getName() + " " << personCounter.getAge() << std::endl;
	}

	return 0;
}

/**
Example input: 
Enter the number of people
5
Enter data in the format: Name Age
Akshay 24
Gowtham 25
Bharath 27
Suhas 26
Pradeep 27

Example output:
The list of people in the decreasing order of their age is:
Bharath 27
Pradeep 27
Suhas 26
Gowtham 25
Akshay 24
*/
