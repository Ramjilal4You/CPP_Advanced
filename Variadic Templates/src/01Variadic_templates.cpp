// Variadic Templates - Basic
// C++ program to demonstrate variadic templates
/*
    Author: Ramjilal4You
    Description: This program demonstrates all aspects of variadic templates in C++.
    * Need of variadic templates?
    * How to create a variadic templates?
    * How to call a variadic templates?
    * How it works internally?
    * Supported argument types in variadic templates?
    * Limitations of variadic templates?
*/

#include <iostream>
#include <cstdarg>  // For va_list, va_start, va_arg, va_end

// Variadic function to print 2 numbers
void printNumbers(int count, ...) {
    va_list args;
    va_start(args, count);

    int num = va_arg(args, int);    // Fetching an integer
    char* word = va_arg(args, char*);   // Fetching a string
    std::cout << num << " ";
    std::cout << word << std::endl;

    va_end(args);
}

/*
    ============================================================================
    Variadic Templates in C++
    ============================================================================

    What are Variadic Templates?
    ----------------------------
    Variadic templates are a feature in C++ (introduced in C++11) that allow 
    functions and classes to accept an arbitrary number of template arguments. 
    This enables writing generic code that can operate on any number and type 
    of parameters.

    Why Use Variadic Templates?
    ---------------------------
    - To write functions/classes that can handle multiple arguments of varying types.
    - To replace older C-style variadic functions (using va_list) with type-safe alternatives.
    - To enable recursive processing of arguments at compile time.

    How to Create Variadic Templates?
    ---------------------------------
    - Use template parameter packs: `template<typename... Args>`
    - Expand parameter packs in function arguments: `void func(Args... args)`
    - Use recursion or fold expressions to process each argument.

    Supported Argument Types
    -----------------------
    - Variadic templates can accept any type: int, double, string, char, user-defined types, etc.

    Limitations
    -----------
    - Cannot partially specialize function templates with parameter packs.
    - Recursion may lead to deep call stacks for large numbers of arguments (use fold expressions in C++17+ for efficiency).
    - Error messages can be complex for incorrect usage.


    References
    ----------
    - C++11 Standard: Variadic Templates
    - cppreference.com: https://en.cppreference.com/w/cpp/language/parameter_pack

    ============================================================================
*/

// Variadic template function to print any number of arguments of any type 
// Base case: function to handle a single argument
template<typename T>
void print(T t) {
    std::cout << t << std::endl;
}

// Recursive variadic template function to print multiple arguments
template<typename T, typename... Args>
void print(T t, Args... args) 
{
    std::cout << t << " ";  // Print the first argument

    print(args...);     // Recursive call with remaining arguments
}

int main() {

    printNumbers(2, 42, "hello");   // Using C-style variadic function

    print(1, 2.5, "hello", 'A');    // Using variadic template function

    print(1, 2.5, "hello", 'A', 12, 15);    // Using variadic template function

    return 0;
}

//g++ -fdump-tree-original .\01Function_Templates.cpp