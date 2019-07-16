//============================================================================
// Name        : Sestina.cpp
// Author      : Wes Holman
// Version     : 0.1
// Copyright   : Copyright 2019
// Description : Generates sestinas out of .txt source material
//============================================================================

#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <regex>
#include <map>
using namespace std;

int main() {
	cout << "!!!WES HOLMAN'S SESTINA GENERATOR!!!" << endl; // prints !!!Hello World!!!
	//Opens and reads stop words, storing them as set
	ifstream stopwords("stopwords.txt");
	string line;
	set<string> stops;
	while(getline(stopwords, line)){
		cout << line << endl;
		stops.insert(line);
	}
	//hardcoded path to ebook
	ifstream corpus("MobyDick.txt");
	//tally non-stopwords occuring at end of clauses, store in hash map
	string word;
	istringstream line_stream;
	regex endClause("(/w)+[,.\"!?]");
	smatch matches;
	int spacePos, punctPos;
	map<string, int> endWordFreqs;
	while(getline(corpus, line)){//Process newlines
		//cout << line << endl;
		line_stream.str(line);
		while(getline(line_stream, word, ' ')){

		}
		//regex_search(line, matches, endClause);
		//for (auto x : matches)
		        //cout << x << " ";
		do{
			spacePos = line.find_first_of(' ');
			punctPos = line.find_first_of(".,!?");
			//cout << "spacePos: " << spacePos << " punctPos: " << punctPos << endl;
			//cout << "Current line: " << line << endl;
			if(spacePos == -1 || punctPos == -1){
				if(punctPos > 0){//We have a word
					word = line.substr(0, punctPos);
					if(!stops.count(word)){
						if(endWordFreqs.count(word) == 0){
							   endWordFreqs[word] = 1;
						}else{
							endWordFreqs[word]++;
						}
					}
				}
				line = "";
			}else{
				while(spacePos < punctPos && spacePos != -1){
					line = line.substr(spacePos + 1, line.size());
					spacePos = line.find_first_of(' ');
					punctPos = line.find_first_of(".,!?");
				}
				if(punctPos != 0){
					word = line.substr(0, punctPos);
					if(!stops.count(word)){
						if(endWordFreqs.count(word) == 0){
							endWordFreqs[word] = 1;
						}
						else{
							endWordFreqs[word]++;
						}
					}
				}
				line = line.substr(punctPos + 1, line.size());
			}
		}while(line.size() > 0);
	}
	map<string, int>::iterator endClauseIterator;
	cout << "Displaying ends of clauses:" << endl;
	for(endClauseIterator = endWordFreqs.begin(); endClauseIterator != endWordFreqs.end(); ++endClauseIterator){
		if(endClauseIterator->second >= 25){
			cout << '\t' << endClauseIterator->first
		             << '\t' << endClauseIterator->second << '\n';
		}
	}
	//set capacity of additional vector to size of current
	//transfer all entries with 6 or more into it
	//Sort by size, print out top 20 entries
	//randomly pick 6, save into String array
	//
	cout << "Adieu..." << endl;
	return 0;
}
