# Advanced Stuffs

- [Advanced Stuffs](#advanced-stuffs)
- [\***\*Exception Handling\*\***](#exception-handling)
  - [\***\*Throwing Exceptions\*\***](#throwing-exceptions)
  - [**Catching Exceptions**](#catching-exceptions)
  - [**C++ Standard Exceptions**](#c-standard-exceptions)
  - [\***\*Define New Exceptions\*\***](#define-new-exceptions)
- [\***\*Dynamic Memory\*\***](#dynamic-memory)
  - [\***\*`new` and `delete` Operators**](#new-and-delete-operators)
  - [\***\*Dynamic Memory Allocation for Arrays\*\***](#dynamic-memory-allocation-for-arrays)
  - [**Dynamic Memory Allocation for Objects**](#dynamic-memory-allocation-for-objects)
- [\***\*Namespaces\*\***](#namespaces)
  - [\***\*Defining a Namespace\*\***](#defining-a-namespace)
  - [\***\*The `using` directive**](#the-using-directive)
  - [**Nested Namespaces**](#nested-namespaces)

# \***\*Exception Handling\*\***

Exceptions provide a way to transfer control from one part of a program to another. C++ exception handling is built upon three keywords: **try, catch,** and **throw**.

- **throw** − A program throws an exception when a problem shows up. This is done using a **throw** keyword.
- **catch** − A program catches an exception with an exception handler at the place in a program where you want to handle the problem. The **catch** keyword indicates the catching of an exception.
- **try** − A **try** block identifies a block of code for which particular exceptions will be activated. It's followed by one or more catch blocks.

Assuming a block will raise an exception, a method catches an exception using a combination of the **try** and **catch** keywords. A try/catch block is placed around the code that might generate an exception. Code within a try/catch block is referred to as protected code, and the syntax for using try/catch as follows −

```cpp
try {
   // protected code
} catch( ExceptionName e1 ) {
   // catch block
} catch( ExceptionName e2 ) {
   // catch block
} catch( ExceptionName eN ) {
   // catch block
}

```

You can list down multiple **catch** statements to catch different type of exceptions in case your **try** block raises more than one exception in different situations.

## \***\*Throwing Exceptions\*\***

Exceptions can be thrown anywhere within a code block using **throw** statement. The operand of the throw statement determines a type for the exception and can be any expression and the type of the result of the expression determines the type of exception thrown.

```cpp
double division(int a, int b) {
   if( b == 0 ) {
      throw "Division by zero condition!";
   }
   return (a/b);
}
```

## **Catching Exceptions**

The **catch** block following the **try** block catches any exception. You can specify what type of exception you want to catch and this is determined by the exception declaration that appears in parentheses following the keyword catch.

```cpp
try {
   // protected code
} catch( ExceptionName e ) {
  // code to handle ExceptionName exception
}
```

Above code will catch an exception of **ExceptionName** type. If you want to specify that a catch block should handle any type of exception that is thrown in a try block, you must put an ellipsis, ..., between the parentheses enclosing the exception declaration as follows −

```cpp
try {
   // protected code
} catch(...) {
  // code to handle any exception
}
```

Here is an example:

```cpp
#include <iostream>
using namespace std;

double division(int a, int b) {
   if( b == 0 ) {
      throw "Division by zero condition!";
   }
   return (a/b);
}

int main () {
   int x = 50;
   int y = 0;
   double z = 0;

   try {
      z = division(x, y);
      cout << z << endl;
   } catch (const char* msg) {
     cerr << msg << endl;
   }

   return 0;
}
```

Because we are raising an exception of type **const char\***, so while catching this exception, we have to use const char\* in catch block.

## **C++ Standard Exceptions**

C++ provides a list of standard exceptions defined in **<exception>** which we can use in our programs. These are arranged in a parent-child class hierarchy shown below:

![https://www.tutorialspoint.com/cplusplus/images/cpp_exceptions.jpg](https://www.tutorialspoint.com/cplusplus/images/cpp_exceptions.jpg)

| Sr.No                                                                                             | Exception & Description |
| ------------------------------------------------------------------------------------------------- | ----------------------- |
| 1                                                                                                 | std::exception          |
| An exception and parent class of all the standard C++ exceptions.                                 |
| 2                                                                                                 | std::bad_alloc          |
| This can be thrown by new.                                                                        |
| 3                                                                                                 | std::bad_cast           |
| This can be thrown by dynamic_cast.                                                               |
| 4                                                                                                 | std::bad_exception      |
| This is useful device to handle unexpected exceptions in a C++ program.                           |
| 5                                                                                                 | std::bad_typeid         |
| This can be thrown by typeid.                                                                     |
| 6                                                                                                 | std::logic_error        |
| An exception that theoretically can be detected by reading the code.                              |
| 7                                                                                                 | std::domain_error       |
| This is an exception thrown when a mathematically invalid domain is used.                         |
| 8                                                                                                 | std::invalid_argument   |
| This is thrown due to invalid arguments.                                                          |
| 9                                                                                                 | std::length_error       |
| This is thrown when a too big std::string is created.                                             |
| 10                                                                                                | std::out_of_range       |
| This can be thrown by the 'at' method, for example a std::vector and std::bitset<>::operator[](). |
| 11                                                                                                | std::runtime_error      |
| An exception that theoretically cannot be detected by reading the code.                           |
| 12                                                                                                | std::overflow_error     |
| This is thrown if a mathematical overflow occurs.                                                 |
| 13                                                                                                | std::range_error        |
| This is occurred when you try to store a value which is out of range.                             |
| 14                                                                                                | std::underflow_error    |
| This is thrown if a mathematical underflow occurs.                                                |

## \***\*Define New Exceptions\*\***

You can define your own exceptions by inheriting and overriding **`exception`** class functionality. Following is the example, which shows how you can use `std::exception` class to implement your own exception in standard way

```cpp
#include <iostream>
#include <exception>
using namespace std;

struct MyException : public exception {
   const char * what () const throw () {
      return "C++ Exception";
   }
};

int main() {
   try {
      throw MyException();
   } catch(MyException& e) {
      std::cout << "MyException caught" << std::endl;
      std::cout << e.what() << std::endl;
   } catch(std::exception& e) {
      //Other errors
   }
}
```

```
MyException caught
C++ Exception
```

# \***\*Dynamic Memory\*\***

Memory in your C++ program is divided into two parts −

- **The stack** − All variables declared inside the function will take up memory from the stack.
- **The heap** − This is unused memory of the program and can be used to allocate the memory dynamically when program runs.

You can allocate memory at run time within the heap for the variable of a given type using a special operator in C++ which returns the address of the space allocated. This operator is called  **`new`**  operator.

If you are not in need of dynamically allocated memory anymore, you can use **`delete`** operator, which de-allocates memory that was previously allocated by new operator.

## \***\*`new` and `delete` Operators**

There is following generic syntax to use **new** operator to allocate memory dynamically for any data-type.

```cpp
new data-type;
```

Here, **data-type** could be any built-in data type including an array or any user defined data types include class or structure.

At any point, when you feel a variable that has been dynamically allocated is not anymore required, you can free up the memory that it occupies in the free store with the ‘delete’ operator as follows −

```cpp
delete pvalue;
```

Here is an example:

```cpp
#include <iostream>
using namespace std;

int main () {
   double* pvalue  = NULL; // Pointer initialized with null
   pvalue  = new double;   // Request memory for the variable

   *pvalue = 29494.99;     // Store value at allocated address
   cout << "Value of pvalue : " << *pvalue << endl;

   delete pvalue;         // free up the memory.

   return 0;
}
```

## \***\*Dynamic Memory Allocation for Arrays\*\***

Consider you want to allocate memory for an array of characters, i.e., string of 20 characters. Using the same syntax what we have used above we can allocate memory dynamically as shown below.

```cpp
char* pvalue  = NULL;         // Pointer initialized with null
pvalue  = new char[20];
```

## **Dynamic Memory Allocation for Objects**

Objects are no different from simple data types. For example, consider the following code where we are going to use an array of objects to clarify the concept −

```cpp
#include <iostream>
using namespace std;

class Box {
   public:
      Box() {
         cout << "Constructor called!" <<endl;
      }
      ~Box() {
         cout << "Destructor called!" <<endl;
      }
};
int main() {
   Box* myBoxArray = new Box[4];
   delete [] myBoxArray; // Delete array

   return 0;
}
```

If you were to allocate an array of four Box objects, the Simple constructor would be called four times and similarly while deleting these objects, destructor will also be called same number of times.

If we compile and run above code, this would produce the following result −

```
Constructor called!
Constructor called!
Constructor called!
Constructor called!
Destructor called!
Destructor called!
Destructor called!
Destructor called!
```

# \***\*Namespaces\*\***

You might be writing some code that has a function called xyz() and there is another library available which is also having same function xyz(). Now the compiler has no way of knowing which version of xyz() function you are referring to within your code.

A **namespace** is designed to overcome this difficulty and is used as additional information to differentiate similar functions, classes, variables etc. with the same name available in different libraries. Using namespace, you can define the context in which names are defined. In essence, a namespace defines a scope.

## \***\*Defining a Namespace\*\***

A namespace definition begins with the keyword **namespace** followed by the namespace name as follows −

```
namespace namespace_name {
   // code declarations
}

```

To call the namespace-enabled version of either function or variable, prepend (::) the namespace name as follows −

```
name::code;  // code could be variable or function.
```

For example:

```cpp
#include <iostream>
using namespace std;

// first name space
namespace first_space {
   void func() {
      cout << "Inside first_space" << endl;
   }
}

// second name space
namespace second_space {
   void func() {
      cout << "Inside second_space" << endl;
   }
}

int main () {
   // Calls function from first name space.
   first_space::func();

   // Calls function from second name space.
   second_space::func();

   return 0;
}
```

If we compile and run above code, this would produce the following result −

```
Inside first_space
Inside second_space
```

## \***\*The `using` directive**

You can also avoid prepending of namespaces with the **using namespace** directive. This directive tells the compiler that the subsequent code is making use of names in the specified namespace. The namespace is thus implied for the following code:

```cpp
#include <iostream>
using namespace std;

// first name space
namespace first_space {
   void func() {
      cout << "Inside first_space" << endl;
   }
}

// second name space
namespace second_space {
   void func() {
      cout << "Inside second_space" << endl;
   }
}

using namespace first_space;
int main () {
   // This calls function from first name space.
   func();

   return 0;
}
```

If we compile and run above code, this would produce the following result −

```
Inside first_space
```

The `usin` directive can also be used to refer to a particular item within a namespace. For example, if the only part of the std namespace that you intend to use is cout, you can refer to it as follows −

```cpp
using std::cout;

```

Subsequent code can refer to cout without prepending the namespace, but other items in the **`std`** namespace will still need to be explicit as follows

## **Nested Namespaces**

Namespaces can be nested where you can define one namespace inside another name space as follows −

```cpp
namespace namespace_name1 {
   // code declarations
   namespace namespace_name2 {
      // code declarations
   }
}

```

You can access members of nested namespace by using resolution operators as follows −

```cpp
// to access members of namespace_name2
using namespace namespace_name1::namespace_name2;

// to access members of namespace:name1
using namespace namespace_name1;

```

In the above statements if you are using namespace_name1, then it will make elements of namespace_name2 available in the scope as follows −

```cpp
#include <iostream>
using namespace std;

// first name space
namespace first_space {
   void func() {
      cout << "Inside first_space" << endl;
   }

   // second name space
   namespace second_space {
      void func() {
         cout << "Inside second_space" << endl;
      }
   }
}

using namespace first_space::second_space;
int main () {
   // This calls function from second name space.
   func();

   return 0;
}
```

If we compile and run above code, this would produce the following result −

```
Inside second_space
```
