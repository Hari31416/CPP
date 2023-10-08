# Data and Variable

- [Data and Variable](#data-and-variable)
- [Data Types in C++](#data-types-in-c)
  - [Basic Data Types](#basic-data-types)
  - [Derived Data Types](#derived-data-types)
  - [User-Defined Data Types](#user-defined-data-types)
- [\***\*C++ Variable Types\*\***](#c-variable-types)
  - [\***\*Variable Definition in C++\*\***](#variable-definition-in-c)
  - [\***\*Variable Declaration in C++\*\***](#variable-declaration-in-c)
  - [**Lvalues and Rvalues**](#lvalues-and-rvalues)
- [\***\*Variable Scope\*\***](#variable-scope)
  - [Variable Scope](#variable-scope-1)
  - [\***\*Local Variables\*\***](#local-variables)
  - [\***\*Global Variables\*\***](#global-variables)
- [\***\*Constants/Literals\*\***](#constantsliterals)
  - [\***\*Integer Literals\*\***](#integer-literals)
  - [**Floating-point Literals**](#floating-point-literals)
  - [**String Literals**](#string-literals)
  - [\***\*Defining Constants\*\***](#defining-constants)
    - [\***\*The #define Preprocessor\*\***](#the-define-preprocessor)
  - [**The const Keyword**](#the-const-keyword)
- [\***\*Modifier Types\*\***](#modifier-types)

# Data Types in C++

In C++, data types are used to define the type of data that a variable can hold. The type of data determines the size of the variable and the operations that can be performed on it. C++ supports various data types that can be broadly classified as:

## Basic Data Types

C++ has the following basic data types:

- **int**: used to store integer values.
- **float**: used to store floating-point numbers.
- **double**: used to store double-precision floating-point numbers.
- **char**: used to store single character values.
- **bool**: used to store either true or false.

| Type                  | Keyword |
| --------------------- | ------- |
| Boolean               | bool    |
| Character             | char    |
| Integer               | int     |
| Floating point        | float   |
| Double floating point | double  |
| Valueless             | void    |
| Wide character        | wchar_t |

The following table shows the variable type, how much memory it takes to store the value in memory, and what is maximum and minimum value which can be stored in such type of variables.

| Type                   | Typical Bit Width | Typical Range                               |
| ---------------------- | ----------------- | ------------------------------------------- |
| char                   | 1byte             | -127 to 127 or 0 to 255                     |
| unsigned char          | 1byte             | 0 to 255                                    |
| signed char            | 1byte             | -127 to 127                                 |
| int                    | 4bytes            | -2147483648 to 2147483647                   |
| unsigned int           | 4bytes            | 0 to 4294967295                             |
| signed int             | 4bytes            | -2147483648 to 2147483647                   |
| short int              | 2bytes            | -32768 to 32767                             |
| unsigned short int     | 2bytes            | 0 to 65,535                                 |
| signed short int       | 2bytes            | -32768 to 32767                             |
| long int               | 8bytes            | -9223372036854775808 to 9223372036854775807 |
| signed long int        | 8bytes            | same as long int                            |
| unsigned long int      | 8bytes            | 0 to 18446744073709551615                   |
| long long int          | 8bytes            | -(2^63) to (2^63)-1                         |
| unsigned long long int | 8bytes            | 0 to 18,446,744,073,709,551,615             |
| float                  | 4bytes            |                                             |
| double                 | 8bytes            |                                             |
| long double            | 12bytes           |                                             |
| wchar_t                | 2 or 4 bytes      | 1 wide character                            |

The size of variables might be different from those shown in the above table, depending on the compiler and the computer you are using.

```cpp
#include <iostream>
using namespace std;

int main() {
   cout << "Size of char : " << sizeof(char) << endl;
   cout << "Size of int : " << sizeof(int) << endl;
   cout << "Size of short int : " << sizeof(short int) << endl;
   cout << "Size of long int : " << sizeof(long int) << endl;
   cout << "Size of float : " << sizeof(float) << endl;
   cout << "Size of double : " << sizeof(double) << endl;
   cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;

   return 0;
}
```

This example uses **`endl`**, which inserts a new-line character after every line and `<<` operator is being used to pass multiple values out to the screen. We are also using **`sizeof()`** operator to get the size of various data types.

## Derived Data Types

C++ has the following derived data types:

- **arrays**: used to store a collection of values of the same data type.
- **pointers**: used to store the memory addresses of variables.
- **structures**: used to store a collection of variables of different data types.
- **classes**: used to store a collection of variables and functions that operate on those variables.

## User-Defined Data Types

C++ allows users to define their own data types using the **typedef** keyword. This allows users to create new data types with meaningful names that can be easily understood by other programmers.

For example, the following tells the compiler that feet is another name for int −

```cpp
typedef int feet;
```

Now, the following declaration is perfectly legal and creates an integer variable called distance −

```cpp
feet distance;
```

# \***\*C++ Variable Types\*\***

A variable provides us with named storage that our programs can manipulate. Each variable in C++ has a specific type, which determines the size and layout of the variable's memory; the range of values that can be stored within that memory; and the set of operations that can be applied to the variable.

The name of a variable can be composed of letters, digits, and the underscore character. It must begin with either a letter or an underscore. Upper and lowercase letters are distinct because C++ is case-sensitive. The variable types are the same as defined [above](Data%20and%20Variable%20a22da134dd154dcaaca46d1d655dc08b.md).

## \***\*Variable Definition in C++\*\***

The syntax is:

`type variable_list;`

For example:

```cpp
int    i, j, k;
char   c, ch;
float  f, salary;
double d;
```

Variables can be initialized (assigned an initial value) in their declaration. The initializer consists of an equal sign followed by a constant expression as follows:

```cpp
extern int d = 3, f = 5;    // declaration of d and f.
int d = 3, f = 5;           // definition and initializing d and f.
byte z = 22;                // definition and initializes z.
char x = 'x';               // the variable x has the value 'x'.
```

## \***\*Variable Declaration in C++\*\***

A variable declaration provides assurance to the compiler that there is one variable existing with the given type and name so that compiler proceed for further compilation without needing complete detail about the variable.

A variable declaration is useful when you are using multiple files and you define your variable in one of the files which will be available at the time of linking of the program. You will use **`extern`** keyword to declare a variable at any place. Though you can declare a variable multiple times in your C++ program, but it can be defined only once in a file, a function or a block of code.

```cpp
#include <iostream>
using namespace std;

// Variable declaration:
extern int a, b;
extern int c;
extern float f;

int main () {
   // Variable definition:
   int a, b;
   int c;
   float f;

   // actual initialization
   a = 10;
   b = 20;
   c = a + b;

   cout << c << endl ;

   f = 70.0/3.0;
   cout << f << endl ;

   return 0;
}
```

When the above code is compiled and executed, it produces the following result −

```
30
23.3333
```

## **Lvalues and Rvalues**

There are two kinds of expressions in C++ −

- **lvalue** − Expressions that refer to a memory location is called "lvalue" expression. An lvalue may appear as either the left-hand or right-hand side of an assignment.
- **rvalue** − The term rvalue refers to a data value that is stored at some address in memory. An rvalue is an expression that cannot have a value assigned to it which means an rvalue may appear on the right- but not left-hand side of an assignment.

Variables are lvalues and so may appear on the left-hand side of an assignment. Numeric literals are rvalues and so may not be assigned and can not appear on the left-hand side. Following is a valid statement −

```cpp
int g = 20;
```

But the following is not a valid statement and would generate a compile-time error −

```cpp
10 = 20;
```

# \***\*Variable Scope\*\***

## Variable Scope

The scope of a variable refers to where in the program the variable can be accessed. In C++, there are three types of variable scope:

- Global scope: Variables declared outside of any function are considered to have global scope. This means that they can be accessed from anywhere within the program.
- Local scope: Variables declared within a function have local scope. This means that they can only be accessed within the function in which they are declared.
- Block scope: Variables declared within a block of code, such as within a loop or if statement, have block scope. This means that they can only be accessed within that block of code.

## \***\*Local Variables\*\***

Variables that are declared inside a function or block are local variables. They can be used only by statements that are inside that function or block of code.

```cpp
#include <iostream>
using namespace std;

int main () {
   // Local variable declaration:
   int a, b;
   int c;

   // actual initialization
   a = 10;
   b = 20;
   c = a + b;

   cout << c;

   return 0;
}
```

## \***\*Global Variables\*\***

Global variables are defined outside of all the functions, usually on top of the program. The global variables will hold their value throughout the lifetime of your program.

```cpp
#include <iostream>
using namespace std;

// Global variable declaration:
int g;

int main () {
   // Local variable declaration:
   int a, b;

   // actual initialization
   a = 10;
   b = 20;
   g = a + b;

   cout << g;

   return 0;
}
```

When a variable is declared with the same name in multiple scopes, the variable in the innermost scope takes precedence. This is known as variable hiding.

```cpp
#include <iostream>
using namespace std;

int x = 10; // global variable

int main() {
   int x = 5; // local variable
   cout << "Local variable x: " << x << endl;
   cout << "Global variable x: " << ::x << endl; // using the scope resolution operator to access the global variable
   return 0;
}

```

In the above example, the local variable x takes precedence over the global variable x within the main function. The scope resolution operator (::) is used to access the global variable x.

# \***\*Constants/Literals\*\***

Constants refer to fixed values that the program may not alter and they are called **literals**.

Constants can be of any of the basic data types and can be divided into Integer Numerals, Floating-Point Numerals, Characters, Strings, and Boolean Values.

Constants are treated just like regular variables except that their values cannot be modified after their definition.

## \***\*Integer Literals\*\***

Here are some examples of integer literals −

```cpp
212         // Legal
215u        // Legal
0xFeeL      // Legal
078         // Illegal: 8 is not an octal digit
032UU       // Illegal: cannot repeat a suffix

```

Following are other examples of various types of Integer literals −

```cpp
85         // decimal
0213       // octal
0x4b       // hexadecimal
30         // int
30u        // unsigned int
30l        // long
30ul       // unsigned long
```

## **Floating-point Literals**

A floating-point literal has an integer part, a decimal point, a fractional part, and an exponent part. You can represent floating point literals either in decimal form or exponential form.

Here are some examples of floating-point literals −

```cpp
3.14159       // Legal
314159E-5L    // Legal
510E          // Illegal: incomplete exponent
210f          // Illegal: no decimal or exponent
.e55          // Illegal: missing integer or fract
```

## **String Literals**

String literals are enclosed in double quotes. A string contains characters that are similar to character literals: plain characters, escape sequences, and universal characters.

You can break a long line into multiple lines using string literals and separate them using whitespaces.

Here are some examples of string literals. All the three forms are identical strings.

```cpp
"hello, dear"

"hello, \

dear"

"hello, " "d" "ear"
```

## \***\*Defining Constants\*\***

### \***\*The #define Preprocessor\*\***

Following is the form to use #define preprocessor to define a constant −

```cpp
#define identifier value
```

Here is an example:

```cpp
#include <iostream>
using namespace std;

#define LENGTH 10
#define WIDTH  5
#define NEWLINE '\n'

int main() {
   int area;

   area = LENGTH * WIDTH;
   cout << area;
   cout << NEWLINE;
   return 0;
}
```

## **The const Keyword**

You can use **const** prefix to declare constants with a specific type as follows −

```cpp
const type variable = value;
```

The following example explains it in detail −

```cpp
#include <iostream>
using namespace std;

int main() {
   const int  LENGTH = 10;
   const int  WIDTH  = 5;
   const char NEWLINE = '\n';
   int area;

   area = LENGTH * WIDTH;
   cout << area;
   cout << NEWLINE;
   return 0;
}
```

When the above code is compiled and executed, it produces the following result −

```
50
```

Note that it is a good programming practice to define constants in CAPITALS.

# \***\*Modifier Types\*\***

C++ allows the **char, int,** and **double** data types to have modifiers preceding them. A modifier is used to alter the meaning of the base type so that it more precisely fits the needs of various situations.

The data type modifiers are listed here −

- signed
- unsigned
- long
- short

The modifiers **signed, unsigned, long,** and **short** can be applied to integer base types. In addition, **signed** and **unsigned** can be applied to char, and **long** can be applied to double.

```cpp
unsigned x;
unsigned int y;
```

To understand the difference between the way signed and unsigned integer modifiers are interpreted by C++, you should run the following short program

```cpp
#include <iostream>
using namespace std;

/* This program shows the difference between
   * signed and unsigned integers.
*/
int main() {
   short int i;           // a signed short integer
   short unsigned int j;  // an unsigned short integer

   j = 50000;

   i = j;
   cout << i << " " << j;

   return 0;
}
```

When this program is run, the following is the output −

```
-15536 50000
```

The above result is because the bit pattern that represents 50,000 as a short unsigned integer is interpreted as -15,536 by a short.
