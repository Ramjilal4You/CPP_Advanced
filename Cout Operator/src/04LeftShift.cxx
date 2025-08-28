// File: 04LeftShift.cxx
// Demonstration of bitwise left shift operator and overloading it for a custom class
#include <iostream>
#include <bitset>

// Custom class
class Point {
public:
    int x;
    explicit Point(int x_) : x(x_) {}

    // Overload bitwise left shift operator for Point (member function)
    // Point operator<<(int shift) const {
    //     std::cout << "Bitwise left shift operator called for Point" << std::endl;
    //     return Point(x << shift);
    // }

};

// Overload bitwise left shift operator for Point (non-member)
Point operator<<(const Point& p, const int shift) {
    return Point(p.x << shift);
}

// Overload output stream operator for Point
std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "Point(x=" << p.x << ")";
    return os;
}

// Usage examples
int main() {
    // Basic left shift
    int a = 5; // 0000 0101
    int b = a << 1; // 0000 1010 (10)
    std::cout << "5 << 1 = " << b << std::endl;


    // Left shift and bitset visualization
    std::bitset<8> bits(a);
    std::cout << "Original bits: " << bits << std::endl;
    std::bitset<8> shifted = bits << 2;
    std::cout << "Bits after left shift by 2: " << shifted << std::endl;

    // Overloaded operator<< example (output stream)
    Point pt(1);    // 0000 0001
    std::cout << "Custom type output: " << pt << std::endl;

    // Overloaded bitwise left shift operator (member)
    Point pt2 = pt << 2;    // 0000 0100 (4)
    std::cout << "Bitwise left shift (member): " << pt2 << std::endl;

    return 0;
}

/*
    ===========================================================================
    // Key Concepts Demonstrated:
    ===========================================================================
    - Bitwise left shift operator (<<) usage
    - Basic left shift operation on integers
    - Using std::bitset to visualize bit patterns before and after left shift
    - Overloading the left shift operator for a custom class (both member and non-member versions)
    - Overloading the output stream operator for the custom class to enable easy printing

    ===========================================================================
    // Differences between bitwise left shift operator & output stream operator:
    ===========================================================================
    - Bitwise left shift operator (<<) is used to shift bits of an integer to the left, effectively multiplying the number by 2 for each shift position.
    - Output stream operator (<<) is used to send data to output streams like std::cout for displaying information.     
    - The bitwise left shift operator can be overloaded for custom types to define how they should behave when their bits are shifted.  
    - The output stream operator is typically overloaded to define how a custom type should be represented as a string when printed.
    - The bitwise left shift operator is a binary operator that takes two operands (the value to shift and the number of positions to shift).
    - The output stream operator is also a binary operator, but it takes an output stream as its left operand and the value to be output as its right operand.
    
*/