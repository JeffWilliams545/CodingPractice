// Author - Jeffrey Williams
// tweakLetters coding challenge published by Helen Yu on edabit.com

#include <iostream>
#include <string>

using namespace std;

// tweakLetters is a function that modifies the inputString by changing the letters in the string based on the
// 	values found in tweakValues. -1 changes a letter back one letter in the alphabet, 0 ingores a letter,
// 	and 1 changes a letter forward one letter in the alphabet.
string tweakLetters( string inputString, int tweakValues[] );

int main( int argc, char* argv[] )
{
	string userString, tweakedString;	
	int count;

	cout << "Please enter a string you would like to tweak." << endl;
	cin >> userString;
	
	int userValues[userString.length()];
	
	cout << endl <<  "Please enter values -1, 0, or 1 to control the tweaking." << endl;
	cout << "-1 tweaks a letter back, 0 ignores a letter, and 1 tweaks a letter forward" << endl;
	for( count = 0; count < userString.size(); count++ )
	{
		cin >> userValues[count];
	}

	tweakedString = tweakLetters( userString, userValues);
	cout << endl << "Your tweaked string: " << tweakedString << endl;
	return 1;
}

string tweakLetters( string inputString, int tweakValues[] )
{
	string outputString;
	int count;

	outputString = inputString;
	for( count = 0; count < inputString.length(); count++ )
	{
		outputString[count] = inputString[count] + tweakValues[count];
	}
	return outputString;
}
