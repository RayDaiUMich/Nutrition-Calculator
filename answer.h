#ifndef ANSWER_H
#define ANSWER_H

// Header file for the Answer class

#include <iostream>
#include <string>

#include "Macro.h"

using std::istream;
using std::ostream;
using std::string;

// The Answer class represents the choose-able answers to questions the
// nutrition calculator will present. Each Answer contains the text of 
// the answer as well as the nutrition Macro associated with this answer. 
// For example, if a question asks, "White Rice?", the answer "Yes" would have
// a "Carbohydrates" macro of 50 points while "No" would
// have a "Carbohydrates" macro of 0 points. 

class Answer {
	// Initialize private data members from the input stream.
friend istream& operator>> (istream& ins, Answer& ans);

// Print the answer text to the output stream.
friend ostream& operator<< (ostream& out, const Answer& ans);

public:
    // Default constructor initializes private members to default
    // or empty values.
    Answer();
    
    // Accessors
    Macro getMacro() const;
    string getText() const;
    
    // Modifiers
    void setMacro(Macro inMacro);
    void setText(string inText);
    
    
private:
    // The personality attribute associated with this answer.
    Macro macro;

    // The text for this Answer.
    string text; 

	// Initialize private data members from the input stream
	// in the order: attribute first followed by the text
	//Example:
	//0 100 1 25 2 10 3 15yes
    void read(istream& ins);
    
    // Print the answer text to the output stream.
    void write(ostream& out) const;

};


#endif

