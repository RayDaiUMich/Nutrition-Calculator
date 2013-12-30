//  Raymond Dai
//  Nutrition calculator
//  Question.cpp
//  Credit given to mdorf for the template:
//		Created by mdorf on 11/27/13.
//		Copyright (c) 2013 mdorf. All rights reserved.

#include "Question.h"
#include <iostream>
using namespace std;

istream& operator>> (istream& ins, Question& q) {
    q.read(ins);    // once you implement member function "read" uncomment this line
    return ins;
}

ostream& operator<< (ostream& out, const Question& q) {
    q.write(out);  // once you implement member function "write" uncomment this line
    return out;
}

//implementation of all private and public member functions begins here

Question::Question() {
	numAnswers = 0;
	questionPrompt = ' ';
	answers[MAX_ANSWER_NUM];
}

int Question::getNumAnswers() const {
	return numAnswers;
}

string Question::getQuestionPrompt() const {
	return questionPrompt;
}

void Question::setNumAnswers(int inNumAnswers) {
	numAnswers = inNumAnswers;
}

void Question::setQuestionPrompt(string inQuestionPrompt) {
	questionPrompt = inQuestionPrompt;
}

Macro Question::submitAnswer(int chosenAnswer) {
	Answer answerAttribute;
	Macro type;
	answerAttribute = answers[chosenAnswer - 1];
	type = answerAttribute.getMacro();
	return type;
}

void Question::write(ostream& out) const {
	out << questionPrompt << endl;
	for (int i = 0; i < numAnswers; i++) {
		out << i + 1 << ") " << answers[i] << endl;
	}
}

void Question::read(istream& ins) {
	ins >> numAnswers;
	getline(ins, questionPrompt);
	for (int i = 0; i < numAnswers; i++) {
		ins >> answers[i];
	}
}
