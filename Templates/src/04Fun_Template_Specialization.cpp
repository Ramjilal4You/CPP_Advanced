// C++ template specialization
#include <iostream>
using namespace std;

// Generic template
template <typename T> 
void MyPrint(T value)
{
    cout <<"Value :" << value <<endl;
}

// Full Template specialization for int
template <> 
void MyPrint(int value)
{
    cout << "Value int: " << value <<endl;
}

// Partial Template specialization for int subtype
template <class T> 
void MyPrint(T* value)
{
    cout << "Value T*: " << *value <<endl;
}

int main()
{
    MyPrint(3);
    MyPrint(3.1415);
    int var = 10;
    MyPrint(&var);
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
