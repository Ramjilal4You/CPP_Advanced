// C++ Variable template
#include <iostream>
using namespace std;

/*
    C++ Variable Templates
    =======================
    * Variable templates allow us to define variables that can be used with different data types.
    * They are similar to function templates but for variables.
*/

double val = 4.14159;

// Template variable with constexpr
template <typename T> 
T myVar = val;


int main()
{
    // Using myVar with different types
    cout << "myVar as float: " << myVar<bool> << endl;
    cout << "myVar as double: " << myVar<double> << endl;
    cout << "myVar as int: " << myVar<int> << endl;
    return 0;
}






/* In powershell window
g++ [option] <input file> -o <output file>
-E                       Preprocess only; do not compile, assemble or link. (.i)
-S                       Compile only; do not assemble or link. (.s)
-c                       Compile and assemble, but do not link. (.o)
-o <file>                Place the output into <file>. (.exe)
*/