#include "stdafx.h"
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

class Node{
public:
	char data;
	map<char, Node*> children;
	map<char, Node*> parents;
	Node(char d) : data(d){}
};

// Depth First search algorithm
void DFS(Node* node){
	cout << "(" << node->data;
	for (map<char, Node*>::iterator it = node->children.begin(); it != node->children.end(); it++){
		DFS(it->second);
	}
	cout << ")";
}

int main() {
	string line;
	getline(cin, line);

	// Create a set to check for duplicate pairs
	set<pair<char, char>> set4DuplicatePairs;

	// A map for all the nodes
	map<char, Node*> nodes;

	// A map for the root node
	map<char, Node*> roots;

	// A set of error strings
	set<string> errorString;

	Node* parentNode = NULL, *childNode = NULL;

	// Check for leading and trailing spaces
	if (!(line[0] != ' ' && line[line.size() - 1] != ' ')){
		cout << "E1";
		return 0;
	}

	// Loop through all characters
	for (int i = 0; i < line.size(); i++){
		if (line[i] == '('){

			// Check for invalid input format
			if (!((line[i + 1]>64 && line[i + 1] < 91) && (line[i + 3] > 64 && line[i + 3] < 91) && line[i + 2] == ',' && line[i + 4] == ')')){
				errorString.insert("E1");
			}
			char parent = line[i + 1];
			char child = line[i + 3];

			// Check for duplicate pairs
			if (set4DuplicatePairs.insert({ parent, child }).second == false){
				errorString.insert("E2");
			}

			// Update the parent node
			if (nodes.find(parent) == nodes.end()){
				parentNode = new Node(parent);
				nodes[parent] = parentNode;
			}
			else{
				parentNode = nodes[parent];
			}

			// Update the child node
			if (nodes.find(child) == nodes.end()){
				childNode = new Node(child);
				nodes[child] = childNode;

			}
			else{
				childNode = nodes[child];
			}

			// Update the root node
			if (parentNode->parents.size() == 0) roots[parent] = parentNode;
			if (roots.find(child) != roots.end()) roots.erase(child);

			// Update the children of the parent node 
			parentNode->children[child] = childNode;
			// Check for more than 2 children
			if (parentNode->children.size() > 2){
				errorString.insert("E3");
			}

			// Check if a parent is already present for the child node,
			if (childNode->parents.size()) {
				errorString.insert("E4");
			}
			// Update the parent of the child node
			else{
				childNode->parents[parent] = parentNode;
			}
		}
	}
	// Check for cycle in the tree
	if (!roots.size()){
		errorString.insert("E4");
	}
	// Check for multiple roots
	else if (roots.size() > 1){
		errorString.insert("E5");
	}

	// If no errors are present, perform Depth First Search on the tree
	if (!errorString.size()){
		DFS(roots.begin()->second);
	}
	// If errors are present, print the error with the highest priority
	else{
		cout << *errorString.begin();
	}
	return 0;
}
