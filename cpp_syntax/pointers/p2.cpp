#include <iostream>

using namespace std;

int main()
{
    int var = 20; // actual variable declaration.
    int *ip;      // pointer variable

    ip = &var; // store address of var in pointer variable

    cout << "Value of var variable: ";
    cout << var << endl;

    // print the address stored in ip pointer variable
    cout << "Address stored in ip variable: ";
    cout << ip << endl;
    // convert to decimal number
    cout << "Address stored in ip variable: ";
    cout << (long)ip << endl;

    ip++; // increment the pointer

    // print the address stored in ip pointer variable
    cout << "Address stored in ip variable: ";
    cout << ip << endl;
    // convert to decimal number
    cout << "Address stored in ip variable: ";
    cout << (long)ip << endl;

    ip++; // increment the pointer

    // print the address stored in ip pointer variable
    cout << "Address stored in ip variable: ";
    cout << ip << endl;
    // convert to decimal number
    cout << "Address stored in ip variable: ";
    cout << (long)ip << endl;
    return 0;
}