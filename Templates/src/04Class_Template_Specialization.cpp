// C++ class template specialization
#include <iostream>
using namespace std;

// Primary template
template <typename T>
class Printer {
public:
    void print(T value) {
        cout << "Generic Printer: " << value << endl;
    }
};

// Specialization for int
template <>
class Printer<int> {
public:
    void print(int value) {
        cout << "Integer Printer: " << value << endl;
    }
};

// Partial Specialization for int
template <class T>
class Printer<T*> {
public:
    void print(T value) {
        cout << "Partial spl Printer: " << value << endl;
    }
};

int main() {
    Printer<double> p1;
    p1.print(3.14);  // Uses generic template

    Printer<int> p2;
    p2.print(42);    // Uses full (int) specialization

    double val = 10.123;
    Printer<double*> p3;
    p3.print(val); // Uses partial specialization

    return 0;
}



/* In powershell window
g++ [option] <input file> -o <output file>
-E                       Preprocess only; do not compile, assemble or link. (.i)
-S                       Compile only; do not assemble or link. (.s)
-c                       Compile and assemble, but do not link. (.o)
-o <file>                Place the output into <file>. (.exe)
*/

//g++ -std=c++17 -fdump-tree-original your_file.cpp     --> dump compiled code with comments
