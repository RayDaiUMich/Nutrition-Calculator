//  Raymond Dai
//  Nutrition calculator
//  Answer.cpp
//  Credit given to mdorf for the template:
//		Created by mdorf on 11/27/13.
//		Copyright (c) 2013 mdorf. All rights reserved.

#include "Answer.h"
#include <iostream>
using namespace std;

istream& operator>> (istream& ins, Answer& ans) {
    ans.read(ins);
    return ins;
}

ostream& operator<< (ostream& out, const Answer& ans) {
    ans.write(out);
    return out;
}

//implementation of all private and public member functions begins here

Answer::Answer() {
	Macro macro;
	text = ' ';
}

Macro Answer::getMacro() const {
	return macro;
}

string Answer::getText() const {
	return text;
}

void Answer::setMacro(Macro inAttribute) {
	macro = inAttribute;
}

void Answer::setText(string inText) {
	text = inText;
}

void Answer::read(istream& ins) {
	ins >> macro;
	getline(ins, text);
}

void Answer::write(ostream& outs) const {
	outs << text;
}
