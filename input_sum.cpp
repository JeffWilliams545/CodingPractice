//Author Jeffrey Williams

#include <iostream>

using namespace std;

int main( int argc, char* argv[] )
{
    int input_1, input_2, input_3;
    cout << "Please enter 3 integers to be summed." << endl;
    cin >> input_1;
    cin >> input_2;
    cin >> input_3;
    cout << "The sum of the three inputted integers is ";
    cout << input_1 + input_2 + input_3 << '.' << endl;
    return 1;
}
