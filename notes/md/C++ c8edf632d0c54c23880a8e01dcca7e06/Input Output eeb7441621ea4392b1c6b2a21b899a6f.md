# Input/Output

- [Input/Output](#inputoutput)
- [Input/Output in C++](#inputoutput-in-c)
  - [Input](#input)
  - [Output](#output)
  - [Error reporting](#error-reporting)
- [\***\*I/O Library Header Files\*\***](#io-library-header-files)

# Input/Output in C++

Input and Output (I/O) in C++ is an essential part of the language that allows us to interact with the user and the system. In C++, there are three types of I/O streams: cin for input, cout for output, and cerr for error reporting.

## Input

The `cin` stream is used to read data from the user or a file. The `>>` operator is used to extract data from the stream and store it in a variable.

```cpp
#include <iostream>

using namespace std;

int main() {
   char name[50];

   cout << "Please enter your name: ";
   cin >> name;
   cout << "Your name is: " << name << endl;

}
```

When the above code is compiled and executed, it will prompt you to enter a name.

We can also read multiple values in a single line using the `>>` operator. For example:

```cpp
int num1, num2;
cin >> num1 >> num2;

```

## Output

The `cout` stream is used to print data to the console or a file. The `<<` operator is used to insert data into the stream. For example, the following code prints a string to the console:

```cpp
cout << "Hello, world!";

```

We can also print multiple values in a single line using the `<<` operator. For example:

```cpp
int num1 = 10, num2 = 20;
cout << "num1 = " << num1 << ", num2 = " << num2;

```

## Error reporting

The `cerr` stream is used to report errors to the console or a file. The `<<` operator is used to insert error messages into the stream. For example:

```cpp
#include <iostream>

using namespace std;

int main() {
   char str[] = "Unable to read....";

   cerr << "Error message : " << str << endl;
}
```

When the above code is compiled and executed, it produces the following result −

```
Error message : Unable to read....
```

# \***\*I/O Library Header Files\*\***

There are following header files important to C++ programs −

| Sr.No                                                                                                                                                                                                                          | Header File & Function and Description |
| ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ | -------------------------------------- |
| 1                                                                                                                                                                                                                              | <iostream>                             |
| This file defines the cin, cout, cerr and clog objects, which correspond to the standard input stream, the standard output stream, the un-buffered standard error stream and the buffered standard error stream, respectively. |
| 2                                                                                                                                                                                                                              | <iomanip>                              |
| This file declares services useful for performing formatted I/O with so-called parameterized stream manipulators, such as setw and setprecision.                                                                               |
| 3                                                                                                                                                                                                                              | <fstream>                              |
| This file declares services for user-controlled file processing.                                                                                                                                                               |
