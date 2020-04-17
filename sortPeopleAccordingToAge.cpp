/*!**************************************************************************/
/*	\file 		distanceBetweenPuzzledSubstrings.cpp
 *
 *	\description 	Given a list of people and their ages, sort them in the descending order of their ages
 *	\author		Pradeep Siddagangaiah
 *	\date		17-April-2020
 */
/**
 * Example input: 
 * Enter the number of people
 * 5
 * Enter data in the format: Name Age
 * Akshay 24
 * Gowtham 25
 * Bharath 27
 * Suhas 26
 * Pradeep 27

 * Example output:
 * The list of people in the decreasing order of their age is:
 * Bharath 27
 * Pradeep 27
 * Suhas 26
 * Gowtham 25
 * Akshay 24
*/
/***************************************************************************/

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
