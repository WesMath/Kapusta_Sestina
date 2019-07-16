//============================================================================
// Name        : Sestina.cpp
// Author      : Wes Holman
// Version     : 0.1
// Copyright   : Copyright 2019
// Description : Generates sestinas out of .txt source material
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

int main() {
	cout << "!!!WES HOLMAN'S SESTINA GENERATOR!!!" << endl; // prints !!!Hello World!!!
	//Opens and reads stop words, storing them as set
	ifstream stopwords("stopwords.txt");
	string line;
	while(getline(stopwords, line)){
		cout << line << endl;
	}
	//hardcoded path to ebook
	//tally non-stopwords occuring at end of clauses, store in vector
	//set capacity of additional vector to size of current
	//transfer all entries with 6 or more into it
	//Sort by size, print out top 20 entries
	//randomly pick 6, save into String array
	//
	cout << "Adieu..." << endl;
	return 0;
}
