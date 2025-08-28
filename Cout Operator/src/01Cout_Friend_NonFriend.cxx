// File: 01Cout_Friend_NonFriend.cxx
// Demonstrates overloading the output stream operator (<<) as both a friend and non-friend function.
#include <iostream>
#include <string>

// 1. Non-member friend function
class MyClassFriend {

private:
    int value;
    std::string name;
public:
    

    MyClassFriend(int v, const std::string& n) : value(v), name(n) {}
    friend std::ostream& operator<<(std::ostream& os, const MyClassFriend& obj);
};
// Definition of the friend function outside the class scope
std::ostream& operator<<(std::ostream& os, const MyClassFriend& obj) {
    os << "MyClassFriend(value=" << obj.value << ", name=" << obj.name << ")";
    return os;
}


// 2. Non-member non-friend function
class MyClassNonFriend {
    int value;
    std::string name;
public:
   
    MyClassNonFriend(int v, const std::string& n) : value(v), name(n) {}
    int getValue() const { return value; }
    std::string getName() const { return name; }
};
// Definition of the non-friend operator<< outside the class scope
std::ostream& operator<<(std::ostream& os, const MyClassNonFriend& obj) {
    os << "MyClassNonFriend(value=" << obj.getValue() << ", name=" << obj.getName() << ")";
    return os;
}

// Usage examples
int main() {
    
    MyClassFriend b(7, "Bob");
    MyClassNonFriend c(99, "Charlie");
    
    // Using friend operator<<
    std::cout << b << std::endl;

    // Using non-friend operator<<
    std::cout << c << std::endl;

    return 0;
}

/*
    * Cout (<<) Operator
    - The output stream operator (<<) can be overloaded as a non-member function to enable
      custom output behavior for user-defined types.    
    - When defined as a friend function, it can access private and protected members of the class.  
    - When defined as a non-friend function, it can only access public members or use public getter methods.  
    - This operator is typically used with std::ostream (like std::cout) to print objects of custom types.  
    - Overloading this operator enhances the usability of custom types by allowing them to be printed directly
      using standard output streams.    
    - The operator should return a reference to the output stream to allow chaining of output operations.  
    - Example usage:
      MyClass obj(42, "Example");
      std::cout << obj << std::endl; // Outputs: MyClass(value=42, name=Example)


*/