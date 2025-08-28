#include <iostream>
#include <string>

// A global variable to act as our reference target
int global_value = 100;

// Function returning a reference to the global variable
int& get_global_ref() {
    return global_value;
}

// Function with decltype(auto) return type
// This will correctly deduce the return type as int&
decltype(auto) get_via_decltype_auto() {
    return get_global_ref();
}

// Function with plain auto return type
// This uses template type deduction, which strips the reference
// It will return a copy (int), not a reference (int&)
auto get_via_plain_auto() {
    return get_global_ref();
}

int main() {
    // Calling the decltype(auto) function
    decltype(auto) a = get_via_decltype_auto();
    std::cout << "Initial value of `a` (from decltype(auto)): " << a << std::endl; // Prints 100

    // Modifying the variable through the reference returned by decltype(auto)
    a = 200;
    std::cout << "New value of `a`: " << a << std::endl; // Prints 200
    std::cout << "Value of global_value after modification: " << global_value << std::endl; // Prints 200 (The reference worked!)

    std::cout << "\n----------------------------------\n" << std::endl;

    // Calling the plain auto function
    auto b = get_via_plain_auto();
    std::cout << "Initial value of `b` (from auto): " << b << std::endl; // Prints 200

    // Modifying the variable that is a copy (returned by plain auto)
    b = 300;
    std::cout << "New value of `b`: " << b << std::endl; // Prints 300
    std::cout << "Value of global_value after attempted modification: " << global_value << std::endl; // Prints 200 (The reference was lost!)

    return 0;
}