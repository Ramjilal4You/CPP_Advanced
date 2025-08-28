#include <iostream>
using namespace std;
/*
    C++ Function Templates
    =======================
    * Function templates allow us to write generic functions that can operate on different data types.
    * Instead of writing separate functions for each data type, we can define a single function template.
*/

// One function works for all data types.
template <class T1, class T2> 
void myfun(T1 x, T2 y)
{
    cout<< x << " " << y << endl;
}

int main()
{
    myfun<int, int>(3, 5); // Call myfun for int
    
    myfun<char, char>('h', 'i');    // call myfun for char

    myfun<double, double>(3.123, 5.123); // Call myfun for double

    return 0;
}




/* In powershell window
g++ -fdump-tree-original .\01Function_Templates.cpp
g++ [option] <input file> -o <output file>
-E                       Preprocess only; do not compile, assemble or link. (.i)
-S                       Compile only; do not assemble or link. (.s)
-c                       Compile and assemble, but do not link. (.o)
-o <file>                Place the output into <file>. (.exe)
*/