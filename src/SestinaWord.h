/*
 * SestinaWord.h
 *
 *  Created on: Jul 16, 2019
 *      Author: Kapusta
 */

#ifndef SESTINAWORD_H_
#define SESTINAWORD_H_
#include <iostream>
#include <vector>
using namespace std;

class SestinaWord {
public:

	string word;
	vector<string> endings;
	SestinaWord(string w);
	virtual ~SestinaWord();
};

#endif /* SESTINAWORD_H_ */
