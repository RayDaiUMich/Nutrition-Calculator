//  Raymond Dai
//  Nutrition calculator
//  Nutrition.cpp
//  Credit given to mdorf for the template:
//		Created by mdorf on 11/27/13.
//		Copyright (c) 2013 mdorf. All rights reserved.

#include "Nutrition.h"
#include <iostream>
using namespace std;

ostream& operator<< (ostream& out, const Nutrition& n) {
    n.write(out);
    return out;
}

//implementation of all private and public member functions begins here

Nutrition::Nutrition() {
	for (int i = 0; i < NUM_MACROS; i++) {
		points[i] = DEFAULT_POINTS;
	}
}

void Nutrition::reset() {
	for (int i = 0; i < NUM_MACROS; i++) {
		if (points[i] != DEFAULT_POINTS) {
			points[i] = DEFAULT_POINTS;
		}
	}
}

void Nutrition::adjustNutrition(Macro m) {
	int index1 = m.getIndex1();
	int changePoints1 = m.getPoints1();
	points[index1] = points[index1] + changePoints1;

	int index2 = m.getIndex2();
	int changePoints2 = m.getPoints2();
	points[index2] = points[index2] + changePoints2;

	int index3 = m.getIndex3();
	int changePoints3 = m.getPoints3();
	points[index3] = points[index3] + changePoints3;

	int index4 = m.getIndex4();
	int changePoints4 = m.getPoints4();
	points[index4] = points[index4] + changePoints4;

}

void Nutrition::write(ostream& out) const {
	out << "Your Nutrition Profile" << endl;
	for (int i = 0; i < NUM_MACROS; i++) {
		out << "   " << MACRO_NAMES[i] << ":" << points[i] << endl;
	}
}
