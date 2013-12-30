#ifndef QUESTION_H
#define QUESTION_H

// Header file for the Question class

#include <iostream>
#include <string>

#include "Answer.h"
#include "Macro.h"
#include "Nutrition.h"

using std::string;
using std::istream;
using std::ostream;

// The total possible number of choose-able answers a Question can have.
// Subject to change.
const int MAX_ANSWER_NUM = 20;

// The Question class represents a quiz question that will be presented to
// the user. A Question object contains the text prompt of that question
// (i.e. "What is your favorite color?") as well as an array of the 
// choose-able answers to this question (i.e. "Red", "Blue", etc).

class Question {

// Initialize private members from the given input stream.
// a great way to input a Question
friend istream& operator>> (istream& ins, Question& q);

// Print the question and numbered answers to the output stream.
friend ostream& operator<< (ostream& out, const Question& q);

public:
    // Initializes Question object to a completely empty/blank Question
    Question();
    
    // Accessors
    int getNumAnswers() const;
    string getQuestionPrompt() const;
    
    // Modifiers
    void setNumAnswers(int inNumAnswers);
    void setQuestionPrompt(string inQuestionPrompt);
    
    // Requires: 1 <= chosenAnswers <= numAnswers
    // Effects:  Submit the answer to this question (supplied by the user). 
	// All this does is return the macro associated with the chosen answer 
	// so that it can be accumulated into the Nutrition.
    Macro submitAnswer(int chosenAnswer);
    
    
private:
    // The number of chooseable answers for this question. 
	// Must be less than or equal to MAX_ANSWER_NUM.
    int numAnswers;
    
    // The prompt, i.e. "What's your favorite color?"
    // Note: as a general rule, you're not supposed to put
    // "using namespace std;" into header files, 
	// so we need used "using std::string"
	string questionPrompt;
    
    // The array of chooseable Answers to the question.
    Answer answers[MAX_ANSWER_NUM];

	// Print the question and numbered answers to the output stream.
	// example:
	// Lettuce?             <--this is the question
	// 1) Yes               <--these are the numbered answers
	// 2) No
	// 3) Extra lettuce
    void write(ostream& out) const;
    
    // Initialize private members from the given input stream.
	// the stream will most likely be a file, but could be keyboard
	// this will be setup in the calling program
	// format: #of answers followed by the question prompt
	// the next lines are the answers (remember these are in the format of an Answer)
	// Example:
	//2Orange chicken?
	//0 420 1 43 2 15 3 21Yes
	//0 0 1 0 2 0 3 0No
    void read(istream& ins);

};

#endif
