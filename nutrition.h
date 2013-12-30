#ifndef NUTRITION_H
#define NUTRITION_H

// Header file for the Nutrition class

#include <string>
#include "Macro.h"

using std::string;
using std::istream;
using std::ostream;

const int NUM_MACROS = 4;

// A default Nutrition has this number of points for all macros.
const int DEFAULT_POINTS = 0;

const string MACRO_NAMES[NUM_MACROS] = { "Calories", "Carbohydrates",
                                                 "Proteins", "Fats"};

// The Nutrition class manages the different macros of a
// Nutrition profile. In this project, there are points on each
// nutrition macro, whose names are listed in the MACRO_NAMES array. 
// The Nutrition class has one private member variable, the points array,
// that stores how many points this Nutrition profile has in each of the
// NUM_MACROS categories (macros). A Nutrition's default state is 
// such that all of its macros have an initial point value of 
// DEFAULT_POINTS. A Nutrition is modified using the adjustNutrition()
// member function, which takes a Macro as an argument. Whenever the user
// answers a quiz question, the Macros associated with that answer is passed
// to the adjustNutrition() member function. Therefore, a Nutrition is 
// shaped by how the user answers each question.

class Nutrition {

// Print out the nutrition profile.
friend ostream& operator<< (ostream& out, const Nutrition& n);

public:
    // Default constructor initializes the points array to its default state.
    Nutrition();
    
    // reset() resets the points array to its default state.
    void reset();

    // Add the value of the answer into the Nutrition profile. 
	// The Macros index corresponds
    // to the index of the points[] array, while its point value determines
    // the value that should be added to that element in the array.
	void adjustNutrition(Macro m);

private:
    // Array of the macro points. For example, points[0] refers to 
    // how many "Calories" points this Nutrition has.
    int points[NUM_MACROS];

	// Print out the nutrition profile.
	// Print the nutrition profile header  "Your Nutrition Profile"
	// Print the name of each macro followed by the number of points.
	//  Example:
	//Your Nutrition Profile
    //   Calories:2000
    //   Carbohydrates:300
    //   Proteins:50
    //   Fats:50
	void write(ostream& out) const;
};


#endif
