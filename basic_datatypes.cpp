//Author Jeffrey Williams

#include <iostream>

using namespace std;

int main( int argc, char* argv[] )
{
    int basic_int;
    long basic_long;
    char basic_char;
    float basic_float;
    double basic_double;

    cout << "Please follow the instruction for input." << endl;
    cout << "Enter an integer." << endl;
    cin >> basic_int;
    cout << "Enter a long." << endl;
    cin >> basic_long;
    cout << "Enter a char." << endl;
    cin >> basic_char;
    cout << "Enter a float." << endl;
    cin >> basic_float;
    cout << "Enter a double." << endl;
    cin >> basic_double;

    cout << endl << basic_int << endl << basic_long << endl << basic_char << 
    endl << basic_float << endl << basic_double << endl;

    return 1;
}
