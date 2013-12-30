/* Author: Raymond Dai
 * Description: Nutrition macros calculator
 * Based off an in class project
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Nutrition.h"
#include "Question.h"
#include "Macro.h"

using namespace std; 
const int NUM_MENU_OPTIONS = 5; // number of options on the menu
const int MAX_QUIZZES = 10;      // maximum number of quizzes you can take
const char * OUTPUT_FILE_NAME = "MyMacros.efc";

// Effects:  Prints the welcome message.
void printOpeningMessage();

// Effects:  Prints the main menu and prompts for a command.
void printMenu();

// Effects:  Prints the closing message.
void printClosingMessage();

// Effects: Writes the nutrition profile to an encoded file.
// Note that this function is intentionally obfusctated; you are
// not required to understand why or how it does what it does.
// Taken from a project given from class.
void saveProfile(Nutrition& n);

// Requires: min and max to be valid
// Modifies: nothing
// Effects: will read and return a number from cin. 
// If the number is less than min or greater than max, or 
// the input was non-numeric, the input is skipped to the next newline 
// and the user is continually prompted for a number between that range 
// until a valid one is provided.
int getNumberInRange(int min, int max);

// Modifies: the nutrition n
// Effects: Opens a restaurant file and presents options one-at-a-time to the user. 
// Based on the user's response to each question, the Nutrition is modified.
void takeQuiz(Nutrition& n);

int main() {

    printOpeningMessage();
    bool quit = false;
	Nutrition nutrition;

    while(!quit) {
        printMenu();
        // Read in the user's response.
        int val;
		val = getNumberInRange(1, NUM_MENU_OPTIONS);

		switch(val) {

        case 1:
			//Take the Quiz.
			takeQuiz(nutrition);
            break;
        case 2:
            // Print personality profile.
			cout << nutrition;
            break;
        case 3:
            // Save personality profile to file.
			saveProfile(nutrition);
            break;
        case 4:
            // Reset personality profile
			nutrition.reset();
            break;
        case 5:
            // Quit.
            quit = true;
            break;
        }
    }
    
    printClosingMessage();
    return 0;   
}

int getNumberInRange(int min, int max) {
	int answerChoice = 0;
	string alpha;
	cin >> answerChoice;
	while (answerChoice < min || answerChoice > max || cin.fail()) {
		cout << "Invalid response! Please enter a number between "
			<< min << " and " << max << ": ";
		cin.clear();
		getline(cin, alpha);
		cin >> answerChoice;
	}
	return answerChoice;
}

void takeQuiz(Nutrition& nutrition) {
	// These are the static variables you are to use to make sure the user
	// takes no more than MAX_QUIZZES quizzes and doesn't take the same
	// quiz over.
	static string takenQuizFileNames[MAX_QUIZZES];
	static int numberOfQuizzesTaken = 0;

	// You are provided with all of the cout statements for this function.
	// Hint: they are logically ordered according to how you must check
	// for errors and how the quiz is to be printed out.
	if (numberOfQuizzesTaken >= MAX_QUIZZES) {
		cout << "You have eaten out too many times! It's best not to know!\n";
	}

	//declare and open file stream for reading
	else {
		string fileName;
		string title;
		int numQuestions;
		Question question[100];
		Answer answer[MAX_ANSWER_NUM];
		Macro macro;

		cout << "Enter the restaurant file name: ";
		cin >> fileName;

		ifstream inFile;
		inFile.open(fileName);
		while (!inFile.good()) {
			cout << "Couldn't open restaurant input file!\n";
			cin.clear();
			return;
		}
		getline(inFile, title);
		inFile >> numQuestions;
		for (int i = 0; i < numQuestions; i++) {
			inFile >> question[i];
		}
		inFile.close();

		//make sure you haven't taken the quiz by that name
		bool quizTaken = false;
		int i = 0;
		while (i < numberOfQuizzesTaken) {
			if (takenQuizFileNames[i] == title && !quizTaken) {
				quizTaken = true;
			}
			i++;
		}
		if (quizTaken) {
			cout << "You've already eaten there!\n";
		}

		//if not taken that quiz, set up to take it
		//get the info for the quiz: title, number of questions
		//print the quiz title and loop through the file
		//reading in the question/answer info and printing it
		//gather the users responses
		else {
			cout << title << endl;
			for (int i = 1; i <= numQuestions; i++) {
				int answerChoice;
				cout << endl << "Question " << i;
				cout << " out of " << numQuestions << endl;
				cout << question[i - 1];
				cout << "Enter your answer: ";
				answerChoice = getNumberInRange(1, question[i - 1].getNumAnswers());
				
				//get the attribute of the answer chosen and apply it to the 
				//nutrition
				macro = question[i - 1].submitAnswer(answerChoice);
				nutrition.adjustNutrition(macro);
			}
		}
		if (!quizTaken) {
			cout << endl << "You've finished the quiz!" << endl
				<< "Be sure to take a look at your updated"
				<< " Nutrition Profile!"
				<< endl;
			takenQuizFileNames[numberOfQuizzesTaken] = title;
			numberOfQuizzesTaken++;
		}
	}
}

void printOpeningMessage() {
    cout << "*************************************************\n"
         << "*****             Welcome to the            *****\n"
         << "*****          Nutrition Calculator         *****\n"
         << "*************************************************\n";
}

void printMenu() {
    cout << "\n1) Take the Quiz\n"
         << "2) Print Your Nutrition Profile\n"
         << "3) Save Nutrition Profile to File\n"
         << "4) Reset Nutrition Profile\n"
         << "5) Quit\n\n"
         << "Enter command: ";
}

void printClosingMessage() {
    cout << "*************************************************\n"
         << "*****        Thank you for using the        *****\n"
         << "*****         Nutrition Calculator          *****\n"
         << "*************************************************\n\n";
}

//  Given from class project, however not essential to the core of the project
void saveProfile(Nutrition& n) {
    stringstream whatIsThis;whatIsThis<<n;int $;string soComplex;whatIsThis>>soComplex;int onbegrijpelijkharibo = 0;int $$$ = 2;int ___ = static_cast<int>(soComplex.length())+whatIsThis.good();ofstream xyz(OUTPUT_FILE_NAME);for(unsigned int x=xyz.good();x<___;x++){whatIsThis>>soComplex;$$$ += 1;}for (unsigned int __=0; $$$*=8,$=71, __<___; onbegrijpelijkharibo+=1){for(;___>__;--___){whatIsThis>>soComplex;onbegrijpelijkharibo = 10*isdigit(soComplex[soComplex.length() - 2*whatIsThis.good()]);onbegrijpelijkharibo += soComplex[soComplex.length() - whatIsThis.good()] - $$$;xyz<<static_cast<char>(onbegrijpelijkharibo*___+$)<<'|';}}xyz.close();
}
