// Variadic Functions in C++ - Supported Types

/*
** C-style variadic functions (... and va_list) only support POD types (Plain Old Data), 
    like: * int , float, double, pointers (e.g., char*, int*, etc.)

* They do not support non-POD types like:
    * std::string, std::vector, user-defined types (e.g., classes, structs)
*/

#include <iostream>
#include <cstdarg>

// Variadic function to print numbers
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

// variadic function to print numbers with words
void printMixedNumbers(std::string str, int count, ...) {

    std::cout << str << "\n";    // Print the string variable
    
    // process the variadic arguments
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count/2; i++) {
        int num = va_arg(args, int);
        char* word = va_arg(args, char*);
        std::cout << num << " - " << word << "\n";
    }

    va_end(args);

    std::cout << "\n";
}

int main() {
    std::cout << "\n";

    printNumbers("Numbers:", 4, 1, 2, 3, 4);

    printMixedNumbers("Mixed:", 6, 1, "One", 2, "Two", 3, "Three");

    std::cout << "\n";
    return 0;
}
