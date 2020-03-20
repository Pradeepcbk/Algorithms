#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <functional>
#include <string>

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

	return 0;
}
