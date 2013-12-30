//  Raymond Dai
//  Nutrition calculator
//  Macro.cpp
//  Credit given to mdorf for the template:
//		Created by mdorf on 11/27/13.
//		Copyright (c) 2013 mdorf. All rights reserved.

#include "Macro.h"
#include <iostream>
using namespace std;

istream& operator>> (istream& ins, Macro& m) {
    m.read(ins);
    return ins;
}

ostream& operator<<(ostream& outs, const Macro& m) {
    m.write(outs);
    return outs;
}

//implementation of all private and public member functions begins here

Macro::Macro() {
	index1 = 0;
	index2 = 1;
	index3 = 2;
	index4 = 3;
	points1 = 0;
	points2 = 0;
	points3 = 0;
	points4 = 0;
}

Macro::Macro(int inIndex, int inPoints) {
	setIndex1(inIndex);
	setIndex2(inIndex);
	setIndex3(inIndex);
	setIndex4(inIndex);
	setPoints1(inPoints);
	setPoints2(inPoints);
	setPoints3(inPoints);
	setPoints4(inPoints);
}

int Macro::getIndex1() const {
	return index1;
}

int Macro::getIndex2() const {
	return index2;
}

int Macro::getIndex3() const {
	return index3;
}

int Macro::getIndex4() const {
	return index4;
}

int Macro::getPoints1() const {
	return points1;
}

int Macro::getPoints2() const {
	return points2;
}

int Macro::getPoints3() const {
	return points3;
}

int Macro::getPoints4() const {
	return points4;
}

void Macro::setIndex1(int inIndex) {
	index1 = inIndex;
}

void Macro::setIndex2(int inIndex) {
	index2 = inIndex;
}

void Macro::setIndex3(int inIndex) {
	index3 = inIndex;
}

void Macro::setIndex4(int inIndex) {
	index4 = inIndex;
}

void Macro::setPoints1(int inPoints) {
	points1 = inPoints;
}

void Macro::setPoints2(int inPoints) {
	points2 = inPoints;
}

void Macro::setPoints3(int inPoints) {
	points3 = inPoints;
}

void Macro::setPoints4(int inPoints) {
	points4 = inPoints;
}

void Macro::read(istream& ins) {
	ins >> index1 >> points1 >> index2 >> points2 >> index3 
		>> points3 >> index4 >> points4;
}

void Macro::write(ostream& outs) const {
	outs << index1 << ' ' << points1 << ' ' << index2 << ' ' << points2 
		<< ' ' << index3 << ' ' << points3 << ' ' << index4 << ' ' << points4;
}
