# Numbers, Arrays and Strings

- [Numbers, Arrays and Strings](#numbers-arrays-and-strings)
- [Numbers](#numbers)
  - [\***\*Math Operations\*\***](#math-operations)
  - [Random Numbers](#random-numbers)
- [Arrays](#arrays)
  - [**Declaring Arrays**](#declaring-arrays)
  - [**Initializing Arrays**](#initializing-arrays)
  - [**Accessing Array Elements**](#accessing-array-elements)
  - [\***\*Passing Arrays to Functions\*\***](#passing-arrays-to-functions)
  - [\***\*Pointer to an Array\*\***](#pointer-to-an-array)
  - [Multi-dimensional Arrays](#multi-dimensional-arrays)
    - [**Two-Dimensional Arrays**](#two-dimensional-arrays)
    - [**Initializing Two-Dimensional Arrays**](#initializing-two-dimensional-arrays)
  - [\***\*Return Array from Functions\*\***](#return-array-from-functions)
- [Strings](#strings)
  - [**The C-Style Character String**](#the-c-style-character-string)
  - [\***\*The String Class in C++\*\***](#the-string-class-in-c)

# Numbers

A number of different number types are available in C++. The code below gives some examples:

```cpp
#include <iostream>
using namespace std;

int main () {
   // number definition:
   short  s;
   int    i;
   long   l;
   float  f;
   double d;

   // number assignments;
   s = 10;
   i = 1000;
   l = 1000000;
   f = 230.47;
   d = 30949.374;

   // number printing;
   cout << "short  s :" << s << endl;
   cout << "int    i :" << i << endl;
   cout << "long   l :" << l << endl;
   cout << "float  f :" << f << endl;
   cout << "double d :" << d << endl;

   return 0;
}
```

## \***\*Math Operations\*\***

You can use the `<cmath>` header to work with math operations:

```cpp
#include <iostream>
#include <cmath>
using namespace std;

int main () {
   // number definition:
   short  s = 10;
   int    i = -1000;
   long   l = 100000;
   float  f = 230.47;
   double d = 200.374;

   // mathematical operations;
   cout << "sin(d) :" << sin(d) << endl;
   cout << "abs(i)  :" << abs(i) << endl;
   cout << "floor(d) :" << floor(d) << endl;
   cout << "sqrt(f) :" << sqrt(f) << endl;
   cout << "pow( d, 2) :" << pow(d, 2) << endl;

   return 0;
}
```

## Random Numbers

There are actually two functions you will need to know about random number generation. The first is **rand()**, this function will only return a pseudo random number. The way to fix this is to first call the **srand()** function.

```cpp
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main () {
   int i,j;

   // set the seed
   srand( (unsigned)time( NULL ) );

   /* generate 10  random numbers. */
   for( i = 0; i < 10; i++ ) {
      // generate actual random number
      j = rand();
      cout <<" Random Number : " << j << endl;
   }

   return 0;
}
```

# Arrays

C++ provides a data structure, **the array**, which stores a fixed-size sequential collection of elements of the same type. An array is used to store a collection of data, but it is often more useful to think of an array as a collection of variables of the same type.

## **Declaring Arrays**

To declare an array in C++, the programmer specifies the type of the elements and the number of elements required by an array as follows −

```cpp
type arrayName [ arraySize ];
```

This is called a single-dimension array. The **arraySize** must be an integer constant greater than zero and **type** can be any valid C++ data type. For example, to declare a 10-element array called balance of type double, use this statement −

```cpp
double balance[10];
```

## **Initializing Arrays**

You can initialize C++ array elements either one by one or using a single statement as follows −

```cpp
double balance[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
```

The number of values between braces { } can not be larger than the number of elements that we declare for the array between square brackets [ ].

If you omit the size of the array, an array just big enough to hold the initialization is created. Therefore, if you write −

```cpp
double balance[] = {1000.0, 2.0, 3.4, 17.0, 50.0};
```

## **Accessing Array Elements**

An element is accessed by indexing the array name. This is done by placing the index of the element within square brackets after the name of the array. For example −

```cpp
double salary = balance[9];
```

The above statement will take 10th element from the array and assign the value to salary variable. Following is an example, which will use all the above-mentioned three concepts viz. declaration, assignment and accessing arrays −

```cpp
#include <iostream>
using namespace std;

#include <iomanip>
using std::setw;

int main () {

   int n[ 10 ]; // n is an array of 10 integers

   // initialize elements of array n to 0
   for ( int i = 0; i < 10; i++ ) {
      n[ i ] = i + 100; // set element at location i to i + 100
   }
   cout << "Element" << setw( 13 ) << "Value" << endl;

   // output each array element's value
   for ( int j = 0; j < 10; j++ ) {
      cout << setw( 7 )<< j << setw( 13 ) << n[ j ] << endl;
   }

   return 0;
}
```

This program makes use of **setw()** function to format the output. When the above code is compiled and executed, it produces the following result −

```
Element        Value
      0          100
      1          101
      2          102
      3          103
      4          104
      5          105
      6          106
      7          107
      8          108
      9          109
```

## \***\*Passing Arrays to Functions\*\***

C++ does not allow to pass an entire array as an argument to a function. However, You can pass a pointer to an array by specifying the array's name without an index.

If you want to pass a single-dimension array as an argument in a function, you would have to declare function formal parameter in one of following three ways and all three declaration methods produce similar results because each tells the compiler that an integer pointer is going to be received.

```cpp
void myFunction(int *param) {
   .
   .
   .
}
```

```cpp
void myFunction(int param[10]) {
   .
   .
   .
}
```

```cpp
void myFunction(int param[]) {
   .
   .
   .
}
```

Now, consider the following function, which will take an array as an argument along with another argument and based on the passed arguments, it will return average of the numbers passed through the array as follows −

```cpp
double getAverage(int arr[], int size) {
  int i, sum = 0;
  double avg;

   for (i = 0; i < size; ++i) {
      sum += arr[i];
   }
   avg = double(sum) / size;

   return avg;
}
```

Now, let us call the above function as follows −

```cpp
#include <iostream>
using namespace std;

// function declaration:
double getAverage(int arr[], int size);

int main () {
   // an int array with 5 elements.
   int balance[5] = {1000, 2, 3, 17, 50};
   double avg;

   // pass pointer to the array as an argument.
   avg = getAverage( balance, 5 ) ;

   // output the returned value
   cout << "Average value is: " << avg << endl;

   return 0;
}
```

When the above code is compiled together and executed, it produces the following result −

```
Average value is: 214.4
```

## \***\*Pointer to an Array\*\***

An array name is a constant pointer to the first element of the array. Therefore, in the declaration −

```cpp
double balance[50];
```

**balance** is a pointer to &balance[0], which is the address of the first element of the array balance. Thus, the following program fragment assigns **p** the address of the first element of **balance** −

```cpp
double *p;
double balance[10];

p = balance;
```

It is legal to use array names as constant pointers, and vice versa. Therefore, `*(balance + 4)` is a legitimate way of accessing the data at balance[4].

Once you store the address of first element in p, you can access array elements using `*p`, `*(p+1)`, `*(p+2)` and so on. Below is the example to show all the concepts discussed above:

```cpp
#include <iostream>
using namespace std;

int main () {
   // an array with 5 elements.
   double balance[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
   double *p;

   p = balance;

   // output each array element's value
   cout << "Array values using pointer " << endl;

   for ( int i = 0; i < 5; i++ ) {
      cout << "*(p + " << i << ") : ";
      cout << *(p + i) << endl;
   }
   cout << "Array values using balance as address " << endl;

   for ( int i = 0; i < 5; i++ ) {
      cout << "*(balance + " << i << ") : ";
      cout << *(balance + i) << endl;
   }

   return 0;
}
```

## Multi-dimensional Arrays

C++ allows multidimensional arrays. Here is the general form of a multidimensional array declaration −

```cpp
type name[size1][size2]...[sizeN];
```

For example, the following declaration creates a three dimensional 5 . 10 . 4 integer array −

```cpp
int threedim[5][10][4];
```

### **Two-Dimensional Arrays**

The simplest form of the multidimensional array is the two-dimensional array. A two-dimensional array is, in essence, a list of one-dimensional arrays. To declare a two-dimensional integer array of size x,y, you would write something as follows −

```cpp
type arrayName [ x ][ y ];
```

### **Initializing Two-Dimensional Arrays**

Multidimensioned arrays may be initialized by specifying bracketed values for each row. Following is an array with 3 rows and each row have 4 columns.

```cpp
int a[3][4] = {
   {0, 1, 2, 3} ,   /*  initializers for row indexed by 0 */
   {4, 5, 6, 7} ,   /*  initializers for row indexed by 1 */
   {8, 9, 10, 11}   /*  initializers for row indexed by 2 */
};

```

The nested braces, which indicate the intended row, are optional. The following initialization is equivalent to previous example −

```cpp
int a[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
```

## \***\*Return Array from Functions\*\***

C++ does not allow to return an entire array as an argument to a function. However, you can return a pointer to an array by specifying the array's name without an index.

If you want to return a single-dimension array from a function, you would have to declare a function returning a pointer as in the following example:

```cpp
int * myFunction() {
   .
   .
   .
}
```

Second point to remember is that C++ does not advocate to return the address of a local variable to outside of the function so you would have to define the local variable as `static` \*\*\*\*variable.

The functin below will generate 10 random numbers and return them using an array:

```cpp
#include <iostream>
#include <ctime>

using namespace std;

// function to generate and retrun random numbers.
int * getRandom( ) {

   static int  r[10];

   // set the seed
   srand( (unsigned)time( NULL ) );

   for (int i = 0; i < 10; ++i) {
      r[i] = rand();
      cout << r[i] << endl;
   }

   return r;
}

// main function to call above defined function.
int main () {

   // a pointer to an int.
   int *p;

   p = getRandom();

   for ( int i = 0; i < 10; i++ ) {
      cout << "*(p + " << i << ") : ";
      cout << *(p + i) << endl;
   }

   return 0;
}
```

# Strings

C++ provides following two types of string representations −

- The C-style character string.
- The string class type introduced with Standard C++.

## **The C-Style Character String**

The C-style character string originated within the C language and continues to be supported within C++. This string is actually a one-dimensional array of characters which is terminated by a **null** character '\0'. Thus a null-terminated string contains the characters that comprise the string followed by a **null**.

The following declaration and initialization create a string consisting of the word "Hello". To hold the null character at the end of the array, the size of the character array containing the string is one more than the number of characters in the word "Hello."

```cpp
char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
```

You can write the above statement as follows −

```cpp
char greeting[] = "Hello";
```

Consider the code

```cpp
#include <iostream>

using namespace std;

int main () {

   char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};

   cout << "Greeting message: ";
   cout << greeting << endl;

   return 0;
}
```

When the above code is compiled and executed, it produces the following result:

```
Greeting message: Hello

```

C++ supports a wide range of functions that manipulate null-terminated strings −

| Sr.No                                                                               | Function & Purpose |
| ----------------------------------------------------------------------------------- | ------------------ |
| 1                                                                                   | strcpy(s1, s2);    |
| Copies string s2 into string s1.                                                    |
| 2                                                                                   | strcat(s1, s2);    |
| Concatenates string s2 onto the end of string s1.                                   |
| 3                                                                                   | strlen(s1);        |
| Returns the length of string s1.                                                    |
| 4                                                                                   | strcmp(s1, s2);    |
| Returns 0 if s1 and s2 are the same; less than 0 if s1<s2; greater than 0 if s1>s2. |
| 5                                                                                   | strchr(s1, ch);    |
| Returns a pointer to the first occurrence of character ch in string s1.             |
| 6                                                                                   | strstr(s1, s2);    |
| Returns a pointer to the first occurrence of string s2 in string s1.                |

## \***\*The String Class in C++\*\***

The standard C++ library provides a **string** class type that supports all the operations mentioned above, additionally much more functionality. Let us check the following example:

```cpp
#include <iostream>
#include <string>

using namespace std;

int main () {

   string str1 = "Hello";
   string str2 = "World";
   string str3;
   int  len ;

   // copy str1 into str3
   str3 = str1;
   cout << "str3 : " << str3 << endl;

   // concatenates str1 and str2
   str3 = str1 + str2;
   cout << "str1 + str2 : " << str3 << endl;

   // total length of str3 after concatenation
   len = str3.size();
   cout << "str3.size() :  " << len << endl;

   return 0;
}
```

When the above code is compiled and executed, it produces result something as follows −

```
str3 : Hello
str1 + str2 : HelloWorld
str3.size() :  10
```
