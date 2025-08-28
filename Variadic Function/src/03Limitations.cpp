// Variadic Functions in C++ - Limitations

/*
// Limitations of Variadic Functions in C++
   * 1. Type Safety: Variadic functions do not provide type safety. 
        The compiler cannot check if the types of the arguments passed match the expected types. 
        This can lead to runtime errors if the types are mismatched.
   * 2. Argument Count: There is no built-in way to determine the number of arguments passed to a variadic function. 
        The programmer must provide a way to specify the count, often by passing an additional parameter.
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

int main() {
    std::cout << "\n";
    
    printNumbers("Numbers:(type mismatch)", 4, 1, 2, 3.6, 4.4); // will lead to undefined behavior due to type mismatch

    printNumbers("Numbers:(less count value)", 2, 10, 20, 30); // only first 2 values will be printed

    printNumbers("Numbers:(more count value)", 4, 10, 11); // will lead to undefined behavior

    std::cout << "\n";
    return 0;
}
