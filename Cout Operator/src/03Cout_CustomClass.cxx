// File: 03Cout_CustomClass.cxx
// Demonstrates using the output stream operator (<<) with a custom class that does not overload it.
#include <iostream>
#include <string>

// Custom class
class MyClass {
private:
    int value;
    std::string name;

public:
    MyClass(int v, const std::string& n) : value(v), name(n) {}

    // Member function version (not used by std::cout, but possible for custom streams)
    void print(std::ostream& os) const {
        os << "MyClass(value=" << value << ", name=" << name << ")";
    }
};

// Usage examples
int main() {
    
    MyClass a(42, "Alice");
    // Using member function (requires explicit call)
    a.print(std::cout);

    return 0;
}