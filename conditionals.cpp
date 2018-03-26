//Author Jeffrey Williams

#include <iostream>

using namespace std;

int main( int argc, char* argv[] )
{
    int integer_input;

    cout << "Please enter a natural number." << endl;
    cin >> integer_input;
    if( integer_input < 10 )
    {
        cout << "You entered ";
	if( integer_input == 1  )
            cout << "one";
        if( integer_input == 2  )
	    cout << "two";
	if( integer_input == 3  )
            cout << "three";
	if( integer_input == 4  )
  	    cout << "four";
	if( integer_input == 5  )
	    cout << "five";
	if( integer_input == 6  )
 	    cout << "six";
	if( integer_input == 7  )
	    cout << "seven";
	if( integer_input == 8  )
	    cout << "eight";
	if( integer_input == 9  )
	    cout << "nine";
        cout << '.' << endl; 
    }  
    else 
    {
	cout << "Entered number is greater than nine." << endl;
    }
    return 1;
}
