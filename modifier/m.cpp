#include <iostream>
using namespace std;

/* This program shows the difference between
 * signed and unsigned integers.
 */
int main()
{
    short int i;          // a signed short integer
    short unsigned int j; // an unsigned short integer
    long int k;           // a signed long integer
    long unsigned int l;  // an unsigned long integer

    j = 50000;

    i = j;
    cout << i << " " << j << endl;

    l = 17446744073709551615;
    k = l;
    cout << k << " " << l << endl;

    return 0;
}