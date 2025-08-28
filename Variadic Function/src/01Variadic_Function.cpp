// Variadic Functions in C++ - Basics
// C++ program to demonstrate variadic functions using <cstdarg>

/*
*   Author: Ramjilal4You
*   Description: This program demonstrates every aspects of variadic functions in C++.
    * Need of variadic function ?
    * How to create a variadic function ?
    * How to call a variadic function ?
    * How it works internally ?
    * Supported argument types in variadic functions ?
    * Limitations of variadic functions ?
*/

#include <iostream>
#include <cstdarg>

// Non-variadic function to print two numbers
void printNumber_nonV(int arg1, int arg2) {
    // Non-variadic version
    std::cout << arg1 << " ";
    std::cout << arg2 << " ";
    std::cout << "\n";
}

// Non-variadic function to print two numbers
void printNumber_nonV(int arg1) {
    // Non-variadic version
    std::cout << arg1 << " ";
    std::cout << "\n";
}

/*
* A variadic function is a function (printf) that accepts a variable number of arguments.
* we can create variadic functions using the macros defined in the <cstdarg> header file.
* The macros are:
    * 1. va_list: declare a variable that will hold the arguments.
    * 2. va_start: initializes the va_list variable to retrieve the arguments. It must be called before any calls to va_arg.
    * 3. va_arg: retrieves the next argument in the list. It takes two parameters: the va_list variable and the type of the argument to retrieve.
    * 4. va_end: cleans up the va_list variable. It must be called before the function returns.
*/

// Variadic function to print numbers
void printNumbers(int count, ...) {
    va_list args;   // declare a variable that will hold the arguments
    va_start(args, count);  // initialize the va_list variable to retrieve the arguments

    for (int i = 0; i < count; i++) {
        int num = va_arg(args, int);    // retrieves the next argument in the list
        std::cout << num << " ";
    }

    va_end(args);   //  cleans up the va_list variable

    std::cout << "\n";
}

// Variadic function to print numbers with additional arguments
void printNumbers(std::string str, int count, ...) {

    std::cout << str << " ";    // Print the string variable
    
    // process the variadic arguments
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++) {
        int num = va_arg(args, int);
        std::cout << num << " ";
    }

    va_end(args);

    std::cout << "\n";
}

int main() {

    printNumber_nonV(10, 20);   // Calls the non-variadic version

    printNumbers(2, 11, 12);    // Calls the variadic version

    printNumbers(3, 11, 12, 13);    // Calls the variadic version

    printNumbers("Numbers:", 4, 1, 2, 3, 4);    // Calls the variadic version with string

    printNumbers("Numbers:", 1, 11);    // Calls the variadic version with string

    return 0;
}
