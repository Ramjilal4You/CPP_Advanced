// C++ Function Template specialization
#include <iostream>
using namespace std;

/*
    C++ Function Template Specialization
    =====================================
    * Function template specialization allows us to customize the behavior of a function template for specific data types.
    * We can create full specializations for a specific type or partial specializations for a subset of types.
*/

// Generic template
template <typename T> 
void MyPrint(T value)
{
    cout <<"Value :" << value <<endl;
}

// Full Template specialization for int
// Full specialization customizes the template for a specific type.
template <> 
void MyPrint(int value)
{
    cout << "Value int: " << value <<endl;
}

// Partial Template specialization for pointer types
// Partial specialization allows customization for a subset of types.
template <typename T> 
void MyPrint(T* value)
{
    cout << "Value T*: " << *value <<endl;
}

int main()
{
    MyPrint<int>(3);
    MyPrint<double>(3.1415);
    int var = 10;
    MyPrint<int>(&var);
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
