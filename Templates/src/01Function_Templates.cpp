// C++ Function template
#include <iostream>
using namespace std;

// One function works for all data types.
template <typename T> 
void myfun(T x, T y)
{
    cout<< x <<" : "<< y <<endl;
}

int main()
{
    myfun<int>(3, 7); // Call myfun for int
    
    myfun<double>(3.3, 7.7);  // call myfun for double
    
    myfun<char>('h', 'i');    // call myfun for char

    return 0;
}

/* In powershell window
g++ [option] <input file> -o <output file>
-E                       Preprocess only; do not compile, assemble or link. (.i)
-S                       Compile only; do not assemble or link. (.s)
-c                       Compile and assemble, but do not link. (.o)
-o <file>                Place the output into <file>. (.exe)
*/