// C++ Template Argument Deduction
#include <iostream>
using namespace std;

/*
    C++ Template Argument Deduction
    ================================
    * Template argument deduction allows the compiler to automatically deduce the template parameters based on the function arguments.
    * This can simplify the usage of templates by allowing users to omit explicit template arguments.
*/

// C++ class template
template <class T>
class MyClass {
  T x;

  public:
    MyClass(T val) : x(val) { }  // Constructor to initialize data members

    void getValues() {  cout << x << endl ;  }  // Method to get values
};

// C++ function template
template <class T>
void myfun(T var){
  cout<<var<<endl;
}

int main() {

    // Using class template
    MyClass<int> intFloat_Obj(10); //compiler does not support C++17 here, use online compiler

    intFloat_Obj.getValues();

    // Using function template
    myfun(20);  //without specifing template arguments eg. myfun<int>(10);
    myfun(20.123); //without specifing template arguments eg. myfun<double>(20.123);

    return 0;
}






/* In powershell window
g++ [option] <input file> -o <output file>
-E                       Preprocess only; do not compile, assemble or link. (.i)
-S                       Compile only; do not assemble or link. (.s)
-c                       Compile and assemble, but do not link. (.o)
-o <file>                Place the output into <file>. (.exe)
*/