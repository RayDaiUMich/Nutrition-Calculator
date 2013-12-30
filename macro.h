#ifndef MACRO_H
#define MACRO_H

// Header file for the Macro class

#include <iostream>

using std::istream;
using std::ostream;

// The Macro class represents nutrition macros or attributes
// that can be applied to the nutrition class. It consists of two things:
// the code, which uniquely identifies a Macro (for example, in this
// project, "Carbohydrates" would have a code of 0, since it is the first
// listed attribute), and the point value, which determines how much the 
// nutrition will be affected when this Macro is applied to it. 

// Notice that the Answer class has a private member that is a Macro so
// that the Nutrition will be altered in different ways according to which
// answers are chosen.

class Macro {

//Initialize private members from the given input stream.
// a great way to read in a Macro
friend istream& operator>> (istream& ins, Macro& m);

//Write the index and point to the given output stream.
// a great way to print out a Macro
friend ostream& operator<< (ostream& outs, const Macro& m);


public:
    
    // Constructors
    Macro(); // initializes private member variables to 0
    Macro(int inIndex, int inPoints);
    
    // Accessors
    int getIndex1() const;
	int getIndex2() const;
	int getIndex3() const;
	int getIndex4() const;
    int getPoints1() const;
	int getPoints2() const;
	int getPoints3() const;
	int getPoints4() const;
    
    // Modifiers
    void setIndex1(int inIndex);
	void setIndex2(int inIndex);
	void setIndex3(int inIndex);
	void setIndex4(int inIndex);
    void setPoints1(int inPoints);
	void setPoints2(int inPoints);
	void setPoints3(int inPoints);
	void setPoints4(int inPoints);
    
private:
    // Every nutrition macro has a unique index, from 0 to the maximum
    // number of nutrition macros minus one. 
    int index1;
	int index2;
	int index3;
	int index4;

    // The points associated with this macro
    int points1;
	int points2;
	int points3;
	int points4;

	// Initialize private members from the given input stream.
	// expected format: index first followed by points and repeat
    void read(istream& ins);
    
    // Write index and points to the given output stream, separated by a space.
    void write(ostream& outs) const;

   
};

#endif
