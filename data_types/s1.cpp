#include <iostream>

using namespace std;

int main()
{

    char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    int nums[3] = {1, 2, 3};

    cout << "Greeting message: ";
    cout << greeting << endl;
    cout << "nums: ";
    cout << *(nums + 1) << endl;

    return 0;
}