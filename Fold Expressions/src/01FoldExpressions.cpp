// Fold Expressions in C++17
/*
    Author: Ramjilal4You
    Description: This program demonstrates all aspects of Fold Expressions in C++.
    * Need of Fold Expressions?
    * How to create/use a Fold Expressions?
    * How it works internally?
    * Supported argument types in Fold Expressions?
    * Limitations of Fold Expressions?
    * 
    * 
*/
/*
* Need of Fold Expressions?
    * Prior to C++17, handling variadic templates often required recursion or helper functions to process parameter packs.
    * This could lead to complex and hard-to-read code.
    * Fold expressions simplify the process of applying operations to all elements in a parameter pack.
    * They provide a more readable and concise syntax for common operations like summation, logical operations, etc.

* What is fold expression?
    * Fold expressions provide a concise way to apply binary operators to all elements in a parameter pack
    * without the need for recursion or helper functions.
    * They can be used with unary and binary operators, and can be left-fold or right-fold.
    * Syntax:   (pack op ...)   // Unary right fold
                (... op pack)   // Unary left fold
                (init op ... op pack) // Binary Left fold with initial value
                (pack op ... op init) // Binary Right fold with initial value
    * Example operators: +, *, &&, ||, , (comma operator), etc.
    * Example usage:
    *   template<typename... Args>
        auto sum(Args... args) {
            return (args + ...); // Right fold expression
        }

*How it works internally?
    * The compiler expands the fold expression by applying the specified operator between all elements of the parameter pack.
    * For example, (args + ...) with args = {1, 2, 3} expands to (1 + (2 + 3)).
    * This expansion is done at compile-time, resulting in efficient code without runtime overhead.
    * The compiler ensures that the operations are valid for the types in the parameter pack.
    * If the parameter pack is empty, the behavior depends on the operator used and whether an initial value is provided.
    * For example, (args + ...) with an empty pack results in a compilation error, while (0 + ... + args) with an empty pack results in 0.
    * Fold expressions can be nested and combined with other template features, allowing for complex operations on parameter packs.

* Supported argument types in Fold Expressions?
    * Fold expressions can work with any types that support the specified binary operator.
    * Commonly used types include:
        * Arithmetic types (int, float, double, etc.) for operators like +, *, etc.
        * Boolean types (bool) for logical operators like &&, ||.
        * User-defined types that overload the relevant operators.
        * Pointers and smart pointers for pointer arithmetic and comparisons.
    * The operator must be valid for all types in the parameter pack; otherwise, a compilation error will occur.
    * Fold expressions can also work with mixed types as long as the operator is defined for those combinations.

    * Limitations of Fold Expressions?
    * Fold expressions can only be used with binary operators; unary operators cannot be directly applied to parameter packs.
    * They require at least one element in the parameter pack unless an initial value is provided.
*/
#include <iostream>
#include <string>

// Example 1: Sum of all arguments using fold expression
template<typename... Args>
auto sum(Args... args) {
    return (args + ...);    // Right fold expression
}

// Example 2: Logical AND of all arguments
template<typename... Args>
bool allTrue(Args... args) {
    return (args && ...);   // Right fold expression
}

// Example 3: Print all arguments (using fold with comma operator)
template<typename... Args>
void printAll(Args&&... args) {
    (std::cout << ... << args) << '\n'; //left fold expression
}

// Example 4: Concatenate strings
template<typename... Args>
std::string concat(Args&&... args) {
    return (std::string{} + ... + args);    //left fold expression
}

int main() {
    std::cout << "Sum: " << sum(1, 2, 3, 4, 5) << '\n';
    std::cout << "All True: " << std::boolalpha << allTrue(true, true, false) << '\n';
    std::cout << "Print All: ";
    printAll("Hello, ", "world!", " Fold expressions are cool.\n");
    std::cout << "Concat: " << concat("C++ ", "17 ", "fold ", "expressions") << '\n';
    return 0;
}