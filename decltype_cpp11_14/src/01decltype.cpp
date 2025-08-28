#include <iostream>
#include <vector>
#include <typeinfo>

// Example 1: Basic decltype usage
int add(int a, int b) {
    return a + b;
}

int main() {
    int x = 5;
    double y = 3.14;

    // decltype with variables
    decltype(x) a = 10;        // a is int
    decltype(y) b = 2.71;      // b is double

    std::cout << "a: " << a << ", b: " << b << std::endl;

    // decltype with expressions
    decltype(x + y) c = x + y; // c is double
    std::cout << "c: " << c << std::endl;

    // decltype with function return type
    decltype(add(1, 2)) d = add(7, 8); // d is int
    std::cout << "d: " << d << std::endl;

    // decltype with containers
    std::vector<int> vec = {1, 2, 3};
    decltype(vec)::value_type e = vec[0]; // e is int
    std::cout << "e: " << e << std::endl;

    // decltype with references
    int& ref = x;
    decltype(ref) f = x; // f is int&
    f = 20;
    std::cout << "x after f assignment: " << x << std::endl;

    // decltype(auto) in C++14
    auto lambda = [](int i, double d) -> decltype(i + d) {
        return i + d;
    };
    std::cout << "lambda(2, 2.5): " << lambda(2, 2.5) << std::endl;

    return 0;
}