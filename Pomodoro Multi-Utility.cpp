#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void Timing(int& lengthMin, char repOrBreak)
{
	clock_t start = clock();
	clock_t duration = 0;
	int seconds = 0;
	int minutes = 0;
	while (lengthMin > minutes) {
		duration = clock() - start;
		seconds = duration / CLOCKS_PER_SEC;
		minutes = seconds / 60;
	}

	if (repOrBreak == 'r') {
		cout << "Pomodoro rep completed!" << endl;
	}
	else if (repOrBreak == 'b') {
		cout << "Break completed!" << endl;
	}
}

int main()
{
	// maybe add rogue-like functionality to the program
	
	//setting variables
	int reps = 0;
	int timePerRep = 0;
	int numBreaks = 0;
	int timePerBreak = 0;
	
	cout << "Welcome to the Pomodoro Multi-Utility Program!" << endl;
	cout << "This program will help you manage your time effectively using the Pomodoro Technique." << endl;

	/*
	* Create, select, and define settings for a profile. 
	* This should maybe be a switch case or a menu system with an option including start pomodoro session.
	*/

	// settings for the profile
	cout << "Reps: ";
	cin >> reps;
	cout << "time min per rep: ";
	cin >> timePerRep;
	cout << "time min per break: ";
	cin >> timePerBreak;
	numBreaks = reps - 1;
	cout << "Number of breaks = " << numBreaks << endl;

	// session variables
	int choice = NULL;
	int plusReps = 0;
	int currentRep = 0;
	int lastStop = 0;

	// if statement will be deprecated later for menu switch case functionality
	cout << "Start? (1 start or 0 no)" << endl;
	cin >> choice;
	if (choice) {
		while (currentRep < reps) {
			cout << "Starting Pomodoro session..." << endl;
			// go to reminders
			Timing(timePerRep, 'r');
			currentRep++;

			if (currentRep < reps) {
				// go to reminders
				cout << "make sure to 20/20!" << endl; // reminder example, hard coded for now
				cout << "Taking a break..." << endl;
				Timing(timePerBreak, 'b');
			} else {
				//exiting the program
				cout << "Last call to add reps to the current session.(1 exit, 0 add)" << endl;
				cin >> choice;
				if (choice == 1) {
					cout << "You finished all your pomodoros!" << endl;
					cout << "Exiting the program..." << endl;
					break;
				}

				// adding reps in the future will be a menu option that can be called at any time
				// Overdrive for adding reps to current session and asking if the reps should be added to the current profile permanently
				cout << "How many reps would you like to add to the current session? " << endl;
				cin >> plusReps;
				reps += plusReps;

				// Add reminder functionality
				// Can be called at any time to add reminders to current profile, across profiles, or for the current session
			}
		}
	}
	return 0;
}