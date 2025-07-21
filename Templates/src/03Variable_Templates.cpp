// C++ Variable template
#include <iostream>
using namespace std;

double val = 4.14159;

// Template variable with constexpr
template <typename T> 
T myVar = val;


int main()
{
    // Using myVar with different types
    cout << "myVar as float: " << myVar<float> << endl;
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