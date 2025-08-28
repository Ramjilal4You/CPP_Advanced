// File: 02Cout_Templated.cxx
// Demonstrates overloading the output stream operator (<<) using a templated function.
#include <iostream>
#include <string>
#include <type_traits>

// 1. Non-member friend function
class MyClassFriend {
public:
    int value;
    std::string name;
    MyClassFriend(int v, const std::string& n) : value(v), name(n) {}
};

// Non-member non-friend function
class MyClassNonFriend {
public:
    int value;
    std::string name;
    MyClassNonFriend(int v, const std::string& n) : value(v), name(n) {}
};


// Templated operator<< (for generic types)
// Uses SFINAE to ensure T has 'value' and 'name' members 
template<typename T>
auto operator<<(std::ostream& os, const T& obj) -> decltype(obj.value, obj.name, os) {
    os << "Templated (value=" << obj.value << ", name=" << obj.name << ")";
    return os;
}


// Usage examples
int main() {
    
    MyClassFriend b(7, "Friend");
    MyClassNonFriend c(99, "NonFriend");
    
    std::cout << b << std::endl;    // Using Templated operator<<
    std::cout << c << std::endl;    // Using Templated operator<<

    return 0;
}