#include <iostream>
using namespace std;

int arr[3] = {1, 2, 3};
int sum(int *arr, int size);

int main()
{
    int all_sum;
    all_sum = sum(arr, 3);
    cout << "Sum is: " << all_sum << endl;
}

int sum(int *arr, int size)
{
    int i, sum = 0;

    for (i = 0; i < size; ++i)
    {
        sum += arr[i];
    }

    return sum;
}
