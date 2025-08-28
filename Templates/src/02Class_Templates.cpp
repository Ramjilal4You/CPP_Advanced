// C++ class template
#include <iostream>
using namespace std;

/*
    C++ Class Templates
    ====================
    * Class templates allow us to create classes that can handle any data type.
    * Instead of defining a class for each data type, we can define a single class template.
*/

// Defining class template
template <typename T1, typename T2> 
class MyClass {
  public:
    T1 x;
    T2 y;

    // Constructor
    MyClass(T1 val1, T2 val2) : x(val1), y(val2) {}

    // Method to get values
    void getValues() {
        cout << x << " " << y;
    }
};

int main() {
    // Creating objects of MyClass with different data types
    MyClass<double, int> obj_int(3.14, 20);
    MyClass<int, double> obj_double(10, 6.28);

    // Access the templates values
    obj_int.getValues();
    cout << endl;
    obj_double.getValues();

    return 0;
}






/* In powershell window
g++ [option] <input file> -o <output file>
-E                       Preprocess only; do not compile, assemble or link. (.i)
-S                       Compile only; do not assemble or link. (.s)
-c                       Compile and assemble, but do not link. (.o)
-o <file>                Place the output into <file>. (.exe)
*/