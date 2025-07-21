// C++ Default & non-type template arguments
#include <iostream>
using namespace std;

// Defining function template with default type
template <class T>
class MyClass {
  T x;

  public:
    MyClass(T val) : x(val) { }  // Constructor to initialize data members

    void getValues() {  cout << x << endl ;  }  // Method to get values
};

template <class T>
void myfun(T var){
  cout<<var<<endl;
}

int main() {

    // Creating objects of MyClass with different data types
    MyClass intFloat_Obj(10);  //MyClass<int> intFloat_Obj(10); //compiler does not support C++17 here, use online compiler

    intFloat_Obj.getValues();

    myfun(20);  //without specifing template arguments eg. myfun<int>(10);

    return 0;
}

/* In powershell window
g++ [option] <input file> -o <output file>
-E                       Preprocess only; do not compile, assemble or link. (.i)
-S                       Compile only; do not assemble or link. (.s)
-c                       Compile and assemble, but do not link. (.o)
-o <file>                Place the output into <file>. (.exe)
*/