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
* There are 4 people sitting in a library - Gowtham, Sandeep, Suhas and Pradeep. Each of them like to read books of certain genre. The task is to find genre liked by each of them. Keep in mind that a person might like more than 1 genre.

* Data:
* Books: Mookajjiya Kanasugalu, Jugaari Cross, Yana, Martian, What got you here won't get you there, A Murder is announced, A girl on the train
* Genre: Intellectual, Suspense Thriller, Personality development, Science Fiction, Family Drama

* Intellectual: Mookajjiya Kanasugalu
* Personality Development: What got you here won't get you there
* Suspense Thriller: Jugaari Cross, A Murder is announced
* Family Drama: A girl on the train
* Science Fiction: Yana, Martian

* Information Provided: 
* Gowtham likes "A girl on the train" and "What got you here won't get you there"
* Pradeep likes "Yana", "Martian" and "Jugaari Cross"
* Sandeep likes "Mookajjiya Kanasugalu", "Jugaari Cross" and "A Murder is announced"
* Suhas likes "A girl on the train" and "Yana"
*/

#include "stdafx.h"
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

class Genre2books {
public:
	string genre;
	vector<string> books;
	Genre2books(string s, vector<string> sv) :genre(s), books(sv) {}
};

int main() {
	map<string, vector<string>> name2Books;
	map<int, string> countMap = { {0,"Intellectual"},{1,"Personality Development"},{2,"Suspense Thriller"},{3,"Family Drama"},{4,"Science Fiction"} };
	map<int,int> counter;
	vector<Genre2books> genre2BooksVector;
	name2Books.insert({ "Gowtham",{ "A girl on the train", "What got you here won't get you there" } });
	name2Books.insert({ "Pradeep",{ "Yana", "Martian", "Jugaari Cross" } });
	name2Books.insert({ "Sandeep",{ "Mookajjiya Kanasugalu", "Jugaari Cross", "A Murder is announced" } });
	name2Books.insert({ "Suhas",{ "A girl on the train", "Yana" } });
	Genre2books intellectual("Intellectual", { "Mookajjiya Kanasugalu" });
	Genre2books pd("Personality Development", { "What got you here won't get you there" });
	Genre2books suspense("Suspense Thriller", { "Jugaari Cross", "A Murder is announced" });
	Genre2books drama("Family Drama", { "A girl on the train" });
	Genre2books scifi({ "Science Fiction",{ "Yana", "Martian" } });
	genre2BooksVector.push_back(intellectual);
	genre2BooksVector.push_back(pd);
	genre2BooksVector.push_back(suspense);
	genre2BooksVector.push_back(drama);
	genre2BooksVector.push_back(scifi);
	for (auto it = name2Books.begin();it != name2Books.end();it++) {
		vector<string> booksName = it->second;
		counter.clear();
		for (vector<string>::iterator b = booksName.begin();b != booksName.end();b++) {
			for (int i = 0;i < genre2BooksVector.size();i++) {
				auto result = find(genre2BooksVector[i].books.begin(), genre2BooksVector[i].books.end(), *b);
				if (result != genre2BooksVector[i].books.end()) {
					counter[i]++;
				}
			}
		}
		auto genre = max_element(counter.begin(), counter.end());
		int temp = 0;
		for (int i = 0;i < counter.size();i++) {
			if (genre->second == counter[i]) {
				if (temp == 0) {
					cout << it->first << " likes books of genre " << countMap[i];
					temp = 1;
				}
				else cout << " & " << countMap[i];
			}
			if(i == counter.size()-1) cout << "\n";
		}
	}
	return 0;
}

/**
* Expected output:
* Gowtham likes Family Drama and Personality Development books
* Pradeep likes Science Fiction
* Sandeep likes Suspense Thriller
* Suhas likes Family Drama and Science Fiction
*/
