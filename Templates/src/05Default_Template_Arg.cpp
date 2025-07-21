// C++ Default & non-type template arguments
#include <iostream>
using namespace std;

// Defining function template with default type
template <class T1, class T2 = double, class T3 = string>
class MyClass {
  public:
    T1 x;
    T2 y;
    T3 z;

    // Constructor to initialize data members
    MyClass(T1 val1, T2 val2, T3 val3) : x(val1), y(val2), z(val3) { }

    // Method to get values
    void getValues() {  cout << x << " " << y << " " << z;  }
};

template <class T, int N>
void myfun(T var){
  cout<<"\n";
  for(int i=0; i<N; i++){
    cout<<var+i<<" ";
  }
  cout<<"\n";
}
int main() {

    // Creating objects of MyClass with different data types
    MyClass<int, float, string> intFloatString_Obj(10, 5.67f, "Hello");
    MyClass<char> charDoubleString_Obj('A', 3.14, "World");

    // error: wrong number of template arguments --> if remove default args in definition

    intFloatString_Obj.getValues();
    cout << endl;
    charDoubleString_Obj.getValues();

    const int n = 10;
    myfun<int, n>(10);

    return 0;
}

/* In powershell window
g++ [option] <input file> -o <output file>
-E                       Preprocess only; do not compile, assemble or link. (.i)
-S                       Compile only; do not assemble or link. (.s)
-c                       Compile and assemble, but do not link. (.o)
-o <file>                Place the output into <file>. (.exe)
*/