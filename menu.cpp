// Author - Jeffrey Williams - 2019
// This program demonstrates a text based menu using a switch statement and recursion.
// Random number generation is also used to play a simple game.

#include <iostream> // Used for input/output to terminal
#include <cstdlib> // Used for random number generation
#include <ctime> // Used for initializing random number generator
#include <unistd.h> // Used for usleep( microseconds ) to add delay 

using namespace std;

void menu()
{
	// menuIndex used for switch statement
	// validInput used to check for valid user input
	// userGuess and randNumber used for the silly game (random number generation guessing)
	int menuIndex, userGuess, randNumber;
	bool validInput;

	//Initializing random number generator
	srand(time(0));

	// Printing menu to terminal
	cout << "-----------------------------------------------" << endl;
	cout << "Welcome to the menu." << endl << endl;
	cout << "Please select from the following options." << endl << endl;
	cout << "1 - See a picture of a rose." << endl;
	cout << "2 - Play a silly game." << endl;
	cout << "0 - Exit program." << endl;
	cout << "-----------------------------------------------" << endl;

	// Input from user
	validInput = false;
	while( !validInput )
	{
		cin >> menuIndex;
		if( menuIndex > 2 || menuIndex < 0 )
		{
			cout << endl << "invalid input. Please try again." << endl;
		}
		else
		{
			validInput = true;
		}
	}

	// Switch statement for menu options
	switch ( menuIndex )
	{
		// Case of silly game using random number generation
		case 2:
		{
			cout << endl << "Guess the number I am thinking of between 1 and 10" << endl;
			randNumber = (rand() % 10) + 1;
			cin >> userGuess;
			if( randNumber == userGuess )
				cout << endl << "You won! Please pat yourself on your back." << endl << endl;
			else
				cout << endl << "You lost. Better luck next time!" << endl << endl;
			usleep(2000000);
			menu();
			break;
		}
		case 1:
		{
			cout << endl << "@))>------------" << endl << endl;
			usleep(2000000);
			menu();
			break;
		}
		case 0:
		{
			break;
		}
	}
}
