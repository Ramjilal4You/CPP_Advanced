/*
    C++ Templates
    =======================
    * Template Introduction
    * Function, Class and Variable templates
    * Template parameters (type, non-type, default)
    * Template specialization (Full & partial)
*/

// C++ template requirements
#include <iostream>
using namespace std;

void myfun(int x, int y)
{
    cout<< x << " " << y << endl;
}
void myfun(char x, char y)
{
    cout<< x << " " << y << endl;
}

void myfun(double x, double y)
{
    cout<< x << " " << y << endl;
}

int main()
{
    myfun(3, 5); // Call myfun for int
    
    myfun('h', 'i');    // call myfun for char

    myfun(3.123, 5.123); // Call myfun for double

    return 0;
}




/* In powershell window
g++ [option] <input file> -o <output file>
-E                       Preprocess only; do not compile, assemble or link. (.i)
-S                       Compile only; do not assemble or link. (.s)
-c                       Compile and assemble, but do not link. (.o)
-o <file>                Place the output into <file>. (.exe)
*/