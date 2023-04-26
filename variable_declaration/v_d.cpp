#include <iostream>
using namespace std;

// Variable declaration:
extern int a, b;
extern int c;
extern float f;
const int D = 20; // constant

int main()
{
    // Variable definition:
    int a, b;
    int c;
    float f;
    20;   // this is a literal
    20.0; // this is another literal
    -20.0;

    // actual initialization
    a = 10;
    b = 20;
    c = a + b;
    // D = 30; // error: assignment of read-only variable 'D'

    cout << c << endl;

    f = 70.0 / 3.0;
    cout << f << endl;

    return 0;
}