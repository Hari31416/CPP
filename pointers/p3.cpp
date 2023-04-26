#include <iostream>

using namespace std;
const int MAX = 3;

// int main()
// {
//     int var[MAX] = {10, 100, 200};
//     int *ptr;

//     // let us have array address in pointer.
//     ptr = var;

//     for (int i = 0; i < MAX; i++)
//     {
//         cout << "Address of var[" << i << "] = ";
//         cout << ptr << endl;

//         cout << "Value of var[" << i << "] = ";
//         cout << *ptr << endl;

//         // point to the next location
//         ptr++;
//     }

//     return 0;
// }

int main()
{
    int var[MAX] = {10, 100, 200};
    int *ptr;

    // let us have address of the first element in pointer.
    ptr = var;
    int i = 0;

    while (ptr <= &var[MAX - 1])
    {
        cout << "Address of var[" << i << "] = ";
        cout << ptr << endl;

        cout << "Value of var[" << i << "] = ";
        cout << *ptr << endl;

        // point to the previous location
        ptr++;
        i++;
    }

    return 0;
}